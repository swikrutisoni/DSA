#include<iostream>
using namespace std;

class BinarySearch{
    public:
       void b_search(int arr[], int n, int item){
        int b=0;
        int e=n-1;
        while(b<=e){
            int mid=(b+e)/2;
            if(arr[mid]==item){
                cout<<"Element found at index: "<<mid<<endl;
                return;
            }
            else if(arr[mid]<item){
                b=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        cout<<"Element not found in the array."<<endl;

   }
};

int main(){
    BinarySearch bs;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" sorted elements in ascending order: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int item;
    cout<<"Enter the element to be searched: ";
    cin>>item;
    bs.b_search(arr, n, item);
    return 0;
}