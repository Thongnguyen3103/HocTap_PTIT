#include <iostream>
#include <vector>
#include <algorithm>
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

    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end());

    for (int i = 0; i < chan.size(); i++) cout << chan[i] << " ";
    for (int i = 0; i < le.size(); i++) cout << le[i] << " ";

    return 0;
}

