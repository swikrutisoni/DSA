/*
biggest advantage is that time complexity is nlogn in all cases
works on the principle of divide and conquer
firdt aarray ko 2 parts me divide karte hai
next we sort the 2 parts recursively
*/

#include<iostream>
#include<climits>
using namespace std;
using namespace std;

class solution{
    public:
    void merge(int arr[], int p, int r ){
       if(p<r){
        int q=(p+r)/2;
        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1], R[n2+1];
        for(int i=0;i<n1;i++){
            L[i]=arr[p+i];
        }
        for(int j=0;j<n2;j++){
            R[j]=arr[q+j+1];
        }
        L[n1]=INT_MAX;
        R[n2]=INT_MAX;
        int i=0,j=0;
        for(int k=p;k<=r;k++){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            }
            else{
                arr[k]=R[j];
                j++;
            }
        }
       }
    }
};

int main(){
    int n, i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    solution obj;
    obj.merge(arr,0,n-1);

    cout<<"The sorted array is: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}