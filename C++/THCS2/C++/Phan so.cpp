#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

struct Fraction {
    int tu, mau;
};

void rutgon(Fraction &f) {
    int g = gcd(f.tu, f.mau);
    f.tu /= g;
    f.mau /= g;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        Fraction p, q;
        cin >> p.tu >> p.mau >> q.tu >> q.mau;

        rutgon(p);
        rutgon(q);

        cout << "Case #" << tc << ":\n";

       
        Fraction pqd, qqd;
        pqd.tu = p.tu * q.mau;
        pqd.mau = p.mau * q.mau;
        qqd.tu = q.tu * p.mau;
        qqd.mau = q.mau * p.mau;
        cout << pqd.tu << "/" << pqd.mau << " " << qqd.tu << "/" << qqd.mau << "\n";

        
        Fraction tong;
        tong.tu = p.tu * q.mau + q.tu * p.mau;
        tong.mau = p.mau * q.mau;
        rutgon(tong);
        cout << tong.tu << "/" << tong.mau << "\n";

      
        Fraction thuong;
        thuong.tu = p.tu * q.mau;
        thuong.mau = p.mau * q.tu;
        rutgon(thuong);
        cout << thuong.tu << "/" << thuong.mau << "\n";
    }
    return 0;
}

