#include "analyze.h"
#include "algorithm.h"

//
// Private
//
static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void shuffleTheArray(int *a, int n){
    for(int i = n - 1; i > 0; i--){
        int randomNumber = rand() % i;
        int temp = a[i];
        a[i] = a[randomNumber];
        a[randomNumber] = temp;
    }
}

static void generateSortedArray(int *a, int n){
    for(int i = 0; i < n; i++){
        a[i] = i;
    }
}

static void generateReverseArray(int *a, int n){        
    for(int i = 0; i < n; i++){
        a[i] = n - i - 1;
    }
}

static void swapToGetBestCase(int *a, int low, int high){
    if(low < high){
        int index = low + ((high - low) / 2);
        swap(&a[index], &a[low]);
        swapToGetBestCase(a, low + 1, index);
        swapToGetBestCase(a, index + 1, high);
    }
}
static void genrateArray(int *arr, int n, const case_t c, const algorithm_t a){
    switch(c){
        case best_t:
        case average_t:
            generateSortedArray(arr,n);
            break;
        case worst_t:
        if(a == bubble_sort_t || a == insertion_sort_t)
            generateReverseArray(arr, n);
        
        else if(a == quick_sort_t || a == binary_search_t || a == linear_search_t)
            generateSortedArray(arr,n);
        break;
    }
}

static int findTheTarget(int *arr, int n, const case_t c, const algorithm_t a){
    if(c == best_t)
        return (a == linear_search_t) ? arr[0] : (arr[n / 2 - 1] + arr[n / 2]) / 2;
    else if(c == worst_t)
        return (a == linear_search_t) ? n + 1 : n - 1; // I Binary serach worst case target värdet måste vara antegen sista eller första elementet i arrayn i det här fallet är n-1 på grund av att vår array börjar från 0 och inte 1 så slut värdet blir (n - 1). 
    else
        return (a == linear_search_t) ? rand() % n : rand() % n;
}

static void executeTheAlgorithms(int *arr, int n, const algorithm_t a, int target, double *total, const case_t c){
    struct timespec start, stop;
    for(int i = 0; i <= ITERATIONS; i++){
        if(c == best_t && a == quick_sort_t && !(c == average_t)){
            swapToGetBestCase(arr, 0, n - 1);
        }
        if(c == average_t && !(a == binary_search_t)){
            srand(time(NULL));
            shuffleTheArray(arr, n);
        }
        clock_gettime(CLOCK_MONOTONIC, &start);
        switch(a){
            case bubble_sort_t: 
                bubble_sort(arr, n);
                break;
            case insertion_sort_t:
                insertion_sort(arr, n);
                break;
            case quick_sort_t:
                quick_sort(arr, n);
                break;
            case linear_search_t:
                linear_search(arr, n, target); 
                break;
            case binary_search_t:
                binary_search(arr, n, target);                        
                break;
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);
        *total += (stop.tv_sec * BILLION + stop.tv_nsec) - (start.tv_sec * BILLION + start.tv_nsec);
    }
}


//
// Public
//

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
   double total = 0;
   int i = 0;
    for(n = SIZE_START; n <= SIZE_END; n*= two){
        int *arr = (int *)malloc(n * sizeof(int));
        int target =  findTheTarget(arr, n, c, a);
        genrateArray(arr, n, c, a);
        executeTheAlgorithms(arr, n, a, target, &total, c);
        buf[i].size = n;
        total = total / BILLION / MAX;
        buf[i].time = total/ITERATIONS;
        i++;
        free(arr);
    }
}
