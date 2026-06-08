#include <bits/stdc++.h>
using namespace std;

struct Fraction {
    long long num;
    long long den;

    Fraction(long long n = 0, long long d = 1) {
        num = n;
        den = d;
        normalize();
    }

    void normalize() {
        if (den == 0) {
            den = 1;
            return;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        long long g = gcd(abs(num), abs(den));
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

    static long long gcd(long long a, long long b) {
        while (b != 0) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    Fraction operator+(const Fraction &other) const {
        long long n = num * other.den + other.num * den;
        long long d = den * other.den;
        return Fraction(n, d);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d))
        return 0;

    Fraction p(a, b);
    Fraction q(c, d);
    Fraction sum = p + q;

    cout << sum.num << "/" << sum.den;
    return 0;
}
