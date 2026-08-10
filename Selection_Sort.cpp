/*jo sab se minimum element hai usko phele postion par
le aata hai = this is called pass 1

first element ko minimum consider karta hai
then if koi bhi element usse chota ho toh
usko minimum rakhte hai, and this goes in loop

ab ye first pass ke liye tha, same cheej ab i=2 ke saath hongi 

TIME COMPLEXITY: O(n^2)
BEST CASE: O(1) swaps
WORST CASE: O(n) swaps

selection sort is in place cause it does not require any extra memory space 
selection sort is not stable= similar elements may change their relative order 
*/

#include<iostream>
using namespace std;

int main(){
  int n, i, j, min_index, temp;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(i=0; i<n; i++){
    cin>>arr[i];
  }

  for(i=0; i<n-1; i++){
    min_index = i;
    for(j=i+1; j<n; j++){
      if(arr[j] < arr[min_index]){
        min_index = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }

  cout<<"The sorted array is: ";
  for(i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}