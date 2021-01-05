/* Serkan Koçoðlu 17070006004 */
/* C implementation QuickSort from https://www.geeksforgeeks.org/cpp-program-for-quicksort/   */

#include<stdio.h> 
#include <stdlib.h>  
#include <time.h>  
using namespace std;



void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void Shuffle(int arr[],int high)
{
           int i = high - 1;
 
    while (i > 0)
     {    	
     	srand (time(NULL));  //provides exactly random
     	
  int j = rand() % (high- 1); 
                  
          swap(&arr[i],&arr[j]);
     
          i--;
     }
}




int partition (int arr[], int low, int high) 
{ 

  int i = (low - 1);  // Index of smaller element 
  
  //srand (time(NULL));  
  //int j = rand() % (high- 1); 
 
    int pivot = arr[high];    // pivot 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
  
} 

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    Shuffle(arr,n);
      printf("Shuffled array: "); 
    printArray(arr, n); 
    
    quickSort(arr, 0, n-1); 
    printf("\nSorted array: "); 
    printArray(arr, n); 
    return 0; 
} 
