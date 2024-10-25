
#include <bits/stdc++.h>
 
using namespace std;
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int findLargestElementRecursive(int arr[], int n , int i, int maxi) {
if(i==n){
    return maxi;
}
if(arr[i]>maxi){
    maxi=arr[i];
}
return findLargestElementRecursive(arr,n,i+1,maxi);
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  // int max = findLargestElement(arr1, n);
  int max = findLargestElementRecursive(arr1, n, 0, arr1[0]);
  cout << "The largest element in the array is: " << max << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  max = findLargestElement(arr2, n);
  cout << "The largest element in the array is: " << max<<endl;
  return 0;
}


