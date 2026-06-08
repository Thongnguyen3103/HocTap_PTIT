#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while(b){
        unsigned long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long g = gcd(a,b);
    unsigned long long l = (a/g) * b; 
    cout << g << '\n' << l;
}
