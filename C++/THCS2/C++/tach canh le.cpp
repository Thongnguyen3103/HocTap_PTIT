#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> chan, le;

    for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0) chan.push_back(A[i]);
    else le.push_back(A[i]);
}

    for (int i = 0; i < chan.size(); i++) {
        cout << chan[i];
        if (i < chan.size() - 1) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < le.size(); i++) {
        cout << le[i];
        if (i < le.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
