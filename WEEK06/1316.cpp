// chk[26]
// 앞의 단어와 같은지 체크하여 chk['b' - 'a'] = 0
// 있으면 1, 없으면 0으로!



#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        set<char> st;
        char prevv = 0;
        bool isGroupWord = true;

        for (char c : s) {
            if (c != prevv && st.find(c) != st.end()) {
                isGroupWord = false;
                break;
            }
            st.insert(c);
            prevv = c;
        }

        if (isGroupWord) {
            cnt++;
        }
    }

    cout << cnt << endl;
}
