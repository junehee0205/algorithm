#include <iostream>
#include <time.h>

using namespace std;


int a1[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77};
int a2[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132};
int a3[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65};
int a4[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555};
int a5[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524};
int a6[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524, 92, 24, 503, 234, 942, 9234, 53, 3, 342, 62};
int a7[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524, 92, 24, 503, 234, 942, 9234, 53, 3, 342, 62, 4, 64, 757, 90, 540, 61, 82, 211, 520, 305};
int a8[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524, 92, 24, 503, 234, 942, 9234, 53, 3, 342, 62, 4, 64, 757, 90, 540, 61, 82, 211, 520, 305, 10, 245, 352, 235, 496, 1023, 2340, 6932, 2304, 502};
int a9[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524, 92, 24, 503, 234, 942, 9234, 53, 3, 342, 62, 4, 64, 757, 90, 540, 61, 82, 211, 520, 305, 10, 245, 352, 235, 496, 1023, 2340, 6932, 2304, 502, 1023, 832, 2395, 923, 8234, 9234, 2839, 4234, 935, 239};
int a10[] = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132, 958, 38, 20, 39, 11, 56, 352, 394, 15, 65, 77, 99, 88, 62, 103, 204, 508, 381, 777, 555, 68, 33, 29, 503, 92, 4, 242, 356, 934, 9524, 92, 24, 503, 234, 942, 9234, 53, 3, 342, 62, 4, 64, 757, 90, 540, 61, 82, 211, 520, 305, 10, 245, 352, 235, 496, 1023, 2340, 6932, 2304, 502, 1023, 832, 2395, 923, 8234, 9234, 2839, 4234, 935, 239, 28, 49, 27, 20, 50, 258, 395, 2304, 853, 2394};


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heap(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
  
        // Recursively heapify the affected sub-tree
        heap(arr, n, largest);
    }
}
  
// main function to do heap sort
void heapsort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
  
        // call max heapify on the reduced heap
        heap(arr, i, 0);
    }
}
  
void show(int A[], int size){
    for(int i=0; i<size; i++){
        if(i!=0 && i%20 == 0) cout << "\n";
        cout << A[i] << " ";
    }
    cout << "\n" << endl;
}



int main(){
    clock_t start, end;
    double result;

    start = clock();
    cout << "a1 heapsort" << endl;
    heapsort(a1, sizeof(a1)/sizeof(a1[0]));    
    show(a1, sizeof(a1)/sizeof(a1[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a1 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a2 heapsort" << endl;
    heapsort(a2, sizeof(a2)/sizeof(a2[0]));    
    show(a1, sizeof(a2)/sizeof(a2[0]-1));    
    end = clock();
    result = (double)(end-start);
    cout << "a2 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a3 heapsort" << endl;
    heapsort(a3, sizeof(a3)/sizeof(a3[0]));    
    show(a3, sizeof(a3)/sizeof(a3[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a3 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a4 heapsort" << endl;
    heapsort(a4, sizeof(a4)/sizeof(a4[0]));    
    show(a4, sizeof(a4)/sizeof(a4[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a4 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a5 heapsort" << endl;
    heapsort(a5, sizeof(a5)/sizeof(a5[0]));    
    show(a5, sizeof(a5)/sizeof(a5[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a5 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a6 heapsort" << endl;
    heapsort(a6, sizeof(a6)/sizeof(a6[0]));    
    show(a6, sizeof(a6)/sizeof(a6[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a6 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a7 heapsort" << endl;
    heapsort(a7, sizeof(a7)/sizeof(a7[0]));    
    show(a7, sizeof(a7)/sizeof(a7[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a8 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a8 heapsort" << endl;
    heapsort(a8, sizeof(a8)/sizeof(a8[0]));    
    show(a8, sizeof(a8)/sizeof(a8[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a8 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a9 heapsort" << endl;
    heapsort(a9, sizeof(a9)/sizeof(a9[0]));    
    show(a9, sizeof(a9)/sizeof(a9[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a9 running time = " << result << "microseconds\n" << endl;

    start = clock();
    cout << "a10 heapsort" << endl;
    heapsort(a10, sizeof(a10)/sizeof(a10[0]));    
    show(a10, sizeof(a10)/sizeof(a10[0]-1));
    end = clock();
    result = (double)(end-start);
    cout << "a10 running time = " << result << "microseconds\n" << endl;

    return 0;
}