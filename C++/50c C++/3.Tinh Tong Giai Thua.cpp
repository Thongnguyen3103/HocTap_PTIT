# include <iostream>
using namespace std;    

int main (){
    int n;
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Nhap sai gia tri!" << endl;
        return 0;
    }
    long long fact = 1;
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        S += fact;
    }
    cout << S << endl;
    return 0;
}