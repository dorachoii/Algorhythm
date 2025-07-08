#include <bits/stdc++.h>
using namespace std;

// gpt가 제시한 성능 향상법
// 1. unordered map 자료구조 사용
//  배열 탐색 vs map 탐색 (logN)시간 복잡도 비교
// 2. ==대신 compare 사용

int N, M;
map<string, int> mp;
map<int, string> mpp;
string s;

int main()
{
    cin >> N >> M;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        mp.insert({s, i + 1});
        mpp.insert({i + 1, s});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> s;

        if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z'))){
            int k = stoi(s);
        }
            

        auto it = mp.find(s);

        if(it == mp.end()){

            auto mpp_it = mpp.find(k);

            if(mpp_it !=mpp.end()){
                cout << it->second << '\n';
            }else{

            }

            
        }else{
            cout << it->first <<'\n';

        }

    }
}
// map으로 시도했으나 key를 int로 사용, stoi 사용이 헷갈림