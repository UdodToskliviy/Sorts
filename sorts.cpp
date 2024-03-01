#include<iostream>
#include<algorithm>
#include<chrono>



// Bubblesort block
template<class Type>
void bubblesort(Type * arr, int lenght){
        for(int i = 0; i < lenght; i++){
                for(int j = 1; j < lenght; j++){
                        if(arr[j] < arr[j - 1]){
				std::swap(arr[j], arr[j - 1]);
                        }
                }
        }
}


// Quicksort block
int getRandomPivot(int low, int high){
	return std::rand() % (high - low + 1) + low;
}

template<class Type>
Type partition(Type arr[], int low, int high){
        int pivotIndex = getRandomPivot(low, high);
	int pivot = arr[pivotIndex];
	std::swap(arr[pivotIndex], arr[high]);
        int i = low - 1;
        for(int j = low; j < high; j++){
                if(arr[j] < pivot){
                        i++;
                        std::swap(arr[i], arr[j]);
                }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
}

template<class Type>
void quicksort(Type arr[], int low, int high){
        if(low < high){
                int pi = partition(arr, low, high);
                quicksort(arr, low, pi - 1);
                quicksort(arr, pi + 1, high);
        }
}


// Heapsort block

template<class Type>
void maxHeapify(Type heap[], int i, int heapsize){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(left < heapsize && heap[left] > heap[largest]){
                largest = left;
        }
        if(right < heapsize && heap[right] > heap[largest]){
                largest = right;
        }
        if(largest != i){
                std::swap(heap[i], heap[largest]);
                maxHeapify(heap, largest, heapsize);
        }
}

template<class Type>
void buildMaxHeap(Type heap[], int heapsize){
        for(int i = (heapsize / 2); i >= 0; i--){
                maxHeapify(heap, i, heapsize);
        }
}

template<class Type>
void heapsort(Type arr[], int lenght){
        buildMaxHeap(arr, lenght);
        for(int i = lenght - 1; i >= 0; i--){;
                std::swap(arr[0], arr[i]);
                maxHeapify(arr, 0, i);
        }
}


//some convenient functions. Not a sort algorithm
template<class Type>
void printArr(Type  arr[], int lenght){
        for(int i = 0; i < lenght; i++){
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
}

int main(){
	return 0;
}
