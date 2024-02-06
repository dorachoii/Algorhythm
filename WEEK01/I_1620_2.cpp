#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;

int main()
{

    cin >> N >> M;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

        string p[N];

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> s;

        if ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z'))
        {
            for (int j = 0; j < N; j++)
            {
                if (p[j] == s)
                {
                    cout << j << '\n';
                    break;
                }
            }
        }
        else
        {
            int k = stoi(s);
            cout << p[k] << '\n';
        }
    }
}
// 시간 초과
// pair을 써볼까?
// 숫자인지 문자인지 판단을 아스키코드로 하는 수 밖에 없나?