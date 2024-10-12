#include <iostream>
using namespace std;

void foo() {
    cout << "foo" << endl;
    foo();
}

int main() {
    foo();
    return 0;
}