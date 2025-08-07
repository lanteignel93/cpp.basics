#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Pair { // Use struct for public members by default
    std::string _key;
    std::string _val;

    Pair(const std::string &key, const std::string &val)
        : _key(key), _val(val) {}
};

class StringHashMap {
  private:
    int _capacity = 8;
    int _size = 0;
    std::vector<std::optional<Pair>> _map;

    int _hash(const std::string &key) {
        int index = 0;
        for (char c : key) {
            index += static_cast<int>(c);
        }
        return index % this->_capacity;
    }

    void rehash() {
        int old_capacity = this->_capacity;
        this->_capacity *= 2;
        std::vector<std::optional<Pair>> old_map = std::move(this->_map);

        this->_map.assign(this->_capacity, std::nullopt);
        this->_size = 0;
        for (int i = 0; i < old_capacity; ++i) {
            if (old_map[i].has_value()) {
                this->put(old_map[i]->_key, old_map[i]->_val);
            }
        }
    }

  public:
    StringHashMap() { _map.resize(_capacity); }

    std::string get(const std::string &key) {
        int index = this->_hash(key);
        int original_index = index;

        while (this->_map[index].has_value()) {
            if (this->_map[index]->_key == key) {
                return this->_map[index]->_val;
            }
            index++;
            index %= this->_capacity;
            // If we've circled back to the start, key isn't there.
            if (index == original_index) {
                break;
            }
        }
        return "";
    }

    void put(const std::string &key, const std::string &val) {
        if (this->_size >= this->_capacity / 2) {
            this->rehash();
        }

        int index = this->_hash(key);
        while (true) {
            if (!this->_map[index].has_value()) {
                this->_map[index] = Pair(key, val);
                this->_size++;
                return;
            } else if (this->_map[index]->_key == key) {
                this->_map[index]->_val = val;
                return;
            }
            index++;
            index %= this->_capacity;
        }
    }

    void remove(const std::string &key) {
        if (this->get(key) == "") {
            return;
        }

        int index = this->_hash(key);
        while (true) {
            if (this->_map[index]->_key == key) {
                this->_map[index] = std::nullopt;
                this->_size--;
                return;
            }
            index++;
            index %= this->_capacity;
        }
    }
};

int main() {
    StringHashMap my_map;

    std::cout << "Putting key-value pairs into the map..." << std::endl;
    my_map.put("name", "Alice");
    my_map.put("city", "Chicago");
    my_map.put("item", "Laptop");
    my_map.put("language", "C++"); // This should trigger a rehash

    std::cout << "\nRetrieving values:" << std::endl;
    std::cout << "Name: " << my_map.get("name") << std::endl;
    std::cout << "City: " << my_map.get("city") << std::endl;
    std::cout << "Item: " << my_map.get("item") << std::endl;

    std::cout << "\nRemoving 'city'..." << std::endl;
    my_map.remove("city");

    std::cout << "\nAttempting to retrieve 'city' again:" << std::endl;
    std::string city_val = my_map.get("city");
    if (city_val == "") {
        std::cout << "Value for 'city' was not found (correctly removed)."
                  << std::endl;
    } else {
        std::cout << "Value for 'city' is: " << city_val << std::endl;
    }

    return 0;
}
