#include<iostream>
using namespace std;

void recursiveBubbleSort(int arr[], int n){
    if(n <= 1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    recursiveBubbleSort(arr, n-1);
}

int main(){
    int n, i,j,key;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }

    recursiveBubbleSort(arr, n);

    cout<<"The sorted array is: ";
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}