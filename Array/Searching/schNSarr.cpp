#include <iostream>
using namespace std;


void printArr(int *arr, int n){
    // Print elements of the array
    cout << "Elements of the array are:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int searchNearlySortedArr(int *arr, int n, int k){
    int s=0;int e=n-1;
    int i=1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid-1]==k){
            return mid-1;
        }
        else if(arr[mid+1]==k){
            return mid+1;
        } 
        else if(arr[mid]>k){
            e=mid-2;
        }
        else s= mid+2;
    }
    return -1;
}

int main() {
     int arr[]={20,10,30,50,40,70,60};
     cout<<searchNearlySortedArr(arr,7,60);
    
 
    
    return 0;
}
