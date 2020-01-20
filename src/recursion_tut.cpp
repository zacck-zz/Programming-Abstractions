#include <iostream>
using namespace std;

int fact(int n);

int main(){
    cout << fact(5) << endl;
    return 0;
}


int fact(int n) {
    if(n == 0) {
        return 1;
    } else {
        int result = n * fact(n - 1);
        cout << "Result of " << n <<   " is currently: " << result << endl;
        return result;
    }
}
