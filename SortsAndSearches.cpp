#include <iostream>
#include <cstdlib>

using namespace std;

void bubblesort(int *A, int n)
{
	int swapped;
	for (int k=n;k>0;k--)
	{
		swapped = 0;
		for (int j=0;j<k-1;j++)
		{
			if(A[j] > A[j+1])
			{
				swap(A[j],A[j+1]);
				swapped=1;
			}

		}
		if(swapped==0)
			break;
	}
}

void insertionsort(int *A, int n)
{
	int key;
	int i;

	for(int j=1;j<n;j++)
	{
		key = A[j];
		i = j-1;
		while(i>=0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

void selectionSort(int *A, int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (A[j] < A[min_idx]) 
            min_idx = j; 

        swap(A[min_idx], A[i]); 
    } 
} 

void merge(int *A,int p, int q, int r)
{
	int n1 = q - p + 1; // number of elements in the LEFT Array
	int n2 = r - q; // number of elements in the RIGHT Array

	int *L = new int[n1+1];
	int *R = new int[n2+1];

	for(int i=0;i<n1;i++)
		L[i] = A[p+i];

	for(int i=0;i<n2;i++)
		R[i] = A[q+i+1];

	L[n1] = 65000;
	R[n2] = 65000;
	int i = 0;
	int j = 0;

	for(int k = p; k<=r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k]=L[i];
			i++;

		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}

}

void mergesort(int *A,int p, int r)
{
	if (p<r)
	{
		int q = (p + r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);

		merge(A,p,q,r);
	}
}

int partition(int *A, int p, int r){
	int i, j;
	i = p - 1;
	int x = A[r];
	
	for(j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			int aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = x;
	
	return i + 1;
}

void quick_sort(int *A, int p, int r){
	if(p < r){
		int q = partition(A,p,r);
		quick_sort(A,p, q - 1);
		quick_sort(A,q + 1,r);
	}	
}

void linearsearch(int *A, int key, int n){
	int flag = 0;
	for (int i=0; i<n; i++){
		if(A[i] == key)
			cout<<"The searched item is found at index: "<< i <<endl;
			flag = 1;
	}
	if(flag == 0){
		cout << " The item is not found in the array" << endl;
	}
}

int binarysearch(int *A, int key, int low, int high){
	int flag = 0;
	int mid;
	if(low > high){
		return 0;
	}
	else{
		mid = (low + high) / 2;
		if(key == A[mid]){
			return mid;
		}
		else if(key < A[mid]){
			return binarysearch (A, key, low, mid-1);
		}
		else{
			return binarysearch (A, key, mid+1, high);
		}
	}
}

int main()
{
	int A[] = {9,8,5,7,10,1,2,4,12,11};
	selectionSort(A,10);
	//insertionsort(A,10);
	//quick_sort(A,0,9);
	for(int i=0;i<10;i++)
		cout << A[i] << " ";
	cout << endl;
	//linearsearch(A,10,10);
	//int n = binarysearch(A,10,0,10);
	//cout <<"the item is found at index: " << n << endl;
	system("PAUSE");
	return 1;

}
