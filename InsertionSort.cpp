/*
algorithm for insertion sort:
In each iteration, select an element from the unsorted part of the array using an outer loop.
Place this selected element in its correct position within the sorted part of the array.
Use an inner loop to shift the remaining elements, if necessary, to accommodate the selected element. This involves shifting elements by one position until the selected element can be placed in the correct position.
Continue this process until the entire array is sorted.

*/

#include<iostream>
using namespace std;

int main(){
    int n, i,j,key;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
 for(i=1; i<n; i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--; 
    }
    arr[j+1]=key;
 }

 cout<<"The sorted array is: ";
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 return 0;
}