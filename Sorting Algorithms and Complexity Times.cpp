#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <chrono>

/*
For 100.000 elements
merge sort performs more optimezed with a time complexity of O(n log(n))	but,              
mergeSort took 46879100 nanoseconds


bubble sort preforms O(n*n) which is so worst than merge sort so there is 3 decimal difference between them 
bubbleSort took 10468433600 nanoseconds //NEED A BIT WAIT TO COMPILE
AS EXPECTED, bubble sort takes 223 times bigger time complexity
*/

//Serkan KOCOGLU 25/02/2020

using namespace std;

//int linearsearch(int A[], int key, int size) {
//	int result = -1;
//	for (int i = 0; i<size; i++) {
//		if (key == A[i])
//			result = i;
//	}
//	return result;}

//int binarysearch(int A[], int key, int size) {
//	int low, mid, high, result;
//	result = -1;
//	low = 0;
//	high = size - 1;
//	while (low <= high && result == -1) {
//		mid = (high + low) / 2;
//		if (A[mid] == key)
//			result = mid;
//		else if (key <A[mid])
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	return result;}
//-------------------------MERGE------------------------------------------------------
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 

        
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    }

} 

//-------------------------------------------------------------------------------

//********************optimized bubble_sort*********************************

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
  

void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
//********************bubble*********************************



int main() {

	




	int arr[100000];
	cout << "FOR 100.000 ELEMENTS The array : ";
	for (int i = 0; i<100000; i++) {
	 	arr[i] =  rand();
	}
	
	int size = sizeof(arr) / sizeof(int);
	
	//clock_t start = clock();
	auto start = std::chrono::high_resolution_clock::now();
//	int result = mergeSort(arr, 0,size ); 
mergeSort(arr, 0,size -1 );
	//clock_t finish = clock();
	auto finish = std::chrono::high_resolution_clock::now();
	//double elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000;
	cout << "mergeSort took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
//	cout << "The searched key is found in the index " << result << endl;


	//start = clock();
  start = std::chrono::high_resolution_clock::now();
//	result = bubbleSort(int &arr[], int &size);
bubbleSort(arr, size); 
	//finish = clock();
  finish = std::chrono::high_resolution_clock::now();
	//elapsed_time = (double)(finish - start) / double(CLOCKS_PER_SEC) * 1000;
	cout << "bubbleSort took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
//	cout << "The searched key is found in the index " << result << endl;

	system("pause");
	return 0;

}

