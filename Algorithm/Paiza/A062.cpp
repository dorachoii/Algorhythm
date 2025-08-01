#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<vector<int>> ores(N, vector<int>(L));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            cin >> ores[i][j];
        }
    }



    int answer = L;

    for (int mask = 1; mask < (1 << L); mask++) {
        unordered_set<string> seen;

        bool can_distinguish_all = true;

        for (int i = 0; i < N; i++) {
            string key = "";
            for (int bit = 0; bit < L; bit++) {
                if (mask & (1 << bit)) {
                    key += (ores[i][bit] + '0'); 
                }
            }

            if (seen.count(key)) {
                can_distinguish_all = false;
                break;
            }
            seen.insert(key);
        }

        if (can_distinguish_all) {
            int bit_count = __builtin_popcount(mask);
            if (bit_count < answer) {
                answer = bit_count;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
