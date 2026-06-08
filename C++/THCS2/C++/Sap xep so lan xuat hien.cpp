#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Info {
    int value;
    int freq;
    int firstPos;
};

bool cmp(const Info &a, const Info &b) {
    if (a.freq != b.freq) return a.freq > b.freq;
    return a.firstPos < b.firstPos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        map<int, int> freq;
        map<int, int> firstPos;
        for (int i = 0; i < N; i++) {
            freq[A[i]]++;
            if (firstPos.find(A[i]) == firstPos.end()) {
                firstPos[A[i]] = i;
            }
        }

        vector<Info> infos;
        for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
            Info tmp;
            tmp.value = it->first;
            tmp.freq = it->second;
            tmp.firstPos = firstPos[it->first];
            infos.push_back(tmp);
        }

        sort(infos.begin(), infos.end(), cmp);

        // In ra theo th? t?
        for (int i = 0; i < (int)infos.size(); i++) {
            for (int j = 0; j < infos[i].freq; j++) {
                cout << infos[i].value << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

