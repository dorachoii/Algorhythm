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

    // 모든 특징 조합을 비트마스크로 탐색 (1 ~ 2^L - 1)
    for (int mask = 1; mask < (1 << L); mask++) {
        unordered_set<string> seen;

        bool can_distinguish_all = true;

        for (int i = 0; i < N; i++) {
            string key = "";
            for (int bit = 0; bit < L; bit++) {
                if (mask & (1 << bit)) {
                    key += (ores[i][bit] + '0'); // int -> char 변환
                }
            }

            if (seen.count(key)) {
                can_distinguish_all = false;
                break;
            }
            seen.insert(key);
        }

        if (can_distinguish_all) {
            // mask에 포함된 비트 개수(특징 개수) 구하기
            int bit_count = __builtin_popcount(mask);
            if (bit_count < answer) {
                answer = bit_count;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
