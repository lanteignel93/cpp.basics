#include <iostream>
#include <vector> 
#include <utility>

void quickSort(std::vector<int>& arr, int start, int end){
    if (start >= end) {
        return; 
    }

    int pivot = arr[end]; 
    int left = start; 

    for (int i = start; i < end; ++i){
        if (arr[i] < pivot){
            std::swap(arr[left++], arr[i]);
        }
    }
    arr[end] = arr[left]; 
    arr[left] = pivot; 

    quickSort(arr, start, left - 1); 
    quickSort(arr, left + 1, end);

}
int main(){
    std::vector<int> arr = {1, 5, 4, 3, 2, 8, 0}; 

    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);

    for (int num : arr){
        std::cout << num << " "; 
    }
    std::cout << "\n";

    return 0;
}


