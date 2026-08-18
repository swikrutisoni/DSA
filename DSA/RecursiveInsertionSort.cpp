#include<iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int n){
    if(n<=1){
        return;
    }

    for(int i=1;i<n;i++)
}

int main(){
    int n;
    cout<<"enter no of elements: ";
    cin>>n;
    cout<<"enter the elements";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    recursiveInsertionSort(arr, n);
}