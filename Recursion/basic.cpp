#include <iostream>
using namespace std;
int counter = 0;
void foo() {
    if(counter == 10) return;
    cout<<counter<<endl;
    counter++;
    foo();
}

int main() {
    foo();
    cout << counter << endl;
    return 0;
}