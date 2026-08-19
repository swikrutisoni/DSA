/* we start with the first element and compare it with the next element
if the next element is smaller, we swap them
and if the element is not smaller, we move to the next element
 *
 in pass 1 the largest element bubbles up to the last position
 and then we do not bother with it in subsequent passes
 in next passes, we continue bubble sorting the remaining elements
 
 
 QUESTIONS THAT CAN BE ASKED ABOUT BUBBLE SORT
 1. How will array look like after third passs?
 2.how many swaps will be made in total? 
 time complexity: O(n^2)
 best case: O(n)
 worst case: O(n^2)
 */

#include<iostream>
using namespace std;

int main(){
  int n, i, j, temp;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(i=0; i<n; i++){
    cin>>arr[i];
  }

  for(i=0; i<n-1; i++){
    for(j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  cout<<"The sorted array is: ";
  for(i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}