#include "algorithm.h"

//
// Private
//
static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *a, int low, int high){
    int pivot = a[low];
    int i = high;
    for(int j = high; j > low; j--){
        if(a[j] >= pivot){
            swap(&a[i], &a[j]);
            i--;
        }
    }
    swap(&a[i], &a[low]);
    return i;
}

static void quickSortRecursive(int *a, int low, int high){
    if(low < high){
        int loc = partition(a, low, high);
        quickSortRecursive(a, low, loc - 1);
        quickSortRecursive(a, loc + 1, high);
    }
}

//
// Public
//

void bubble_sort(int *a, int n)
{
	// TODO: bubble sort
    int swapped = 1;
    for(int i = 0; swapped && i < n - 1; i++){
        swapped = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j +1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
    }
}
void insertion_sort(int *a, int n)
{
	// TODO: insertion sort
    int temp;
    int i, j;    
    for(i = 1; i < n; i++){
        temp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = temp;
    }
}

void quick_sort(int *a, int n)
{
	// TODO: quick sort
    quickSortRecursive(a, 0, n - 1);
}

bool linear_search(const int *a, int n, int v)
{
    // TODO: linear search
    for(int i = 0; i < n; i++){
        if(a[i] == v){
            return true;
        }
    }
	return false; 
}

bool binary_search(const int *a, int n, int v)
{
    // TODO: binary search
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int middle = low + (high - low) / 2;
        if(a[middle] == v){
            return true;
        }
        else if(a[middle] < v){
            low = middle + 1;
        }
        else{
            high = middle - 1;
        }
        
    }
    
	return false; 
}
