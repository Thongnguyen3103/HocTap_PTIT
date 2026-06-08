#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector< vector<int> > segments;
        vector<int> cur;
        cur.push_back(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                cur.push_back(a[i]);
            } else {
                if ((int)cur.size() > 1) segments.push_back(cur);
                cur.clear();
                cur.push_back(a[i]);
            }
        }
        if ((int)cur.size() > 1) segments.push_back(cur);

        
        int maxLen = 0;
        for (int i = 0; i < (int)segments.size(); i++) {
            if ((int)segments[i].size() > maxLen) 
                maxLen = segments[i].size();
        }

        cout << "Test " << t << ":\n";
        cout << maxLen << "\n";
        for (int i = 0; i < (int)segments.size(); i++) {
            if ((int)segments[i].size() == maxLen) {
                for (int j = 0; j < (int)segments[i].size(); j++) {
                    cout << segments[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}

