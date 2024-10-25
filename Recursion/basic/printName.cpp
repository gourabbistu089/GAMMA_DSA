#include <iostream>
using namespace std;

void printName(int n, int i) {
    if(i>n) return;
    cout<<i<<" ";
    printName(n,i+1);
}

int main() {
    int n;
    cout<<"Enter number of names: ";
    cin>>n;
    int i=1;
    printName(n,i);
    return 0;
}