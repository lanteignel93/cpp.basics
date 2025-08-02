#include <iostream> 
#include <vector> 

void bucketSort(std::vector<int>& arr, int min, int max){
    std::vector<int> count(1 + max - min, 0); 

    for (int n : arr){
        count[n]++; 
    }

    int i = 0; 
    for (int n = 0; n < count.size(); n++){
        for (int j = 0; j < count[n]; j++){
            arr[i] = n;
            i++;
        }
    }
}

int main() {
    std::vector<int> arr = {1, 5, 4, 3, 2, 8, 0}; 

    bucketSort(arr, 0, 8);

    for (int num : arr){
        std::cout << num << " "; 
    }
    std::cout << "\n";

    return 0;
}
