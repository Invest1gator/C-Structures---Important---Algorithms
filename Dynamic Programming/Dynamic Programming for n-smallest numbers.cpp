//SERKAN KOÇOÐLU 17070006004
//Finds number of concesutive smallest elements.
	 #include <iostream>
	 #include<time.h>
using namespace std;
	 void nSmallest(int array[], int size){
int min= INT_MAX ;    
    int n;
	cout<< "\n" << "Enter #smallest elements do you want to find: "  ;
      scanf ("%d",&n);
	                 
    for (int i = n; i < size; i++){    //O(N)
        min = 0;
        for (int j = 0; j < n; j++){   // O(k) 
            if(array[j] > array[min]){             //minimum element found
                min = j;
                array[min] = array[j];   
            }
        }       
        if (array[min] > array[i]){                //  swap to temporary array

            int temp = array[min];      
            array[min] = array[i];
            array[i] = temp;
        }
    }
    cout << "\n\n" << n << " Smallest Numbers:  ";
    for (int i = 0; i < n; i++){                      
       cout << array[i] << " ";
    }
	
}
	int main(int argc, char** argv){
	// where n is size of array and k is #smallest elements;
		//O(n*k) because nested loops has size of n and k
	
	 srand (time(NULL));
 int size=10;
 int array[size];
 
  cout << "Original array is: ";
 for (int i =0; i <size ; i++){
   array[i]=(rand() % 100);
   cout <<" - " << array[i];
 }
		nSmallest(array,size);
	}
	
