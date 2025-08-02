#include <vector> 
#include <iostream> 

void merge(std::vector<int>& arr, int start, int mid, int end) {
    std::vector<int> L = {arr.begin() + start, arr.begin() + mid + 1}; 
    std::vector<int> R = {arr.begin() + mid + 1, arr.begin() + end + 1}; 

    int i = 0, j = 0, k = start; 

    while (i < L.size() && j < R.size()) {
        if (L[i] < R[j]){
            arr[k] = L[i++]; 
        } else {
            arr[k] = R[j++]; 
        }
        k++;
    }
    while (i < L.size()){
        arr[k++] = L[i++];
    }
    while (j < R.size()){
        arr[k++] = R[j++]; 
    }

}

void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start >= end){
        return; 
    }
    int mid = (start + end) / 2; 

    mergeSort(arr, start, mid); 
    mergeSort(arr, mid + 1, end); 

    merge(arr, start, mid, end); 
}

int main(){
    std::vector<int> arr = {1, 5, 4, 3, 2, 8, 0}; 

    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    for (int num : arr){
        std::cout << num << " "; 
    }
    std::cout << "\n";

    return 0;
}

