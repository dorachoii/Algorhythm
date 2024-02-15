#include <bits/stdc++.h>
using namespace std;

int n, teamN, fulltime = 48 * 60, T1win, T2win, currentT1score, currentT2score;
string s;

// <시간,팀번호>
map<int, int> mp;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> teamN >> s;

        int minute = stoi(s.substr(0, 2));
        int second = stoi(s.substr(3, 2));

        mp[minute * 60 + second] = teamN;
    }

    int prevWin = -1;

    for (auto p : mp)
    {
        if (p.second != prevWin)
        {
            if (prevWin == -1)
            {
                if (p.second == 1)
                {
                    T1win = fulltime - p.first;
                    currentT1score ++;
                }
                else
                {
                    T2win = fulltime - p.first;
                    currentT2score++;
                }
            }
            else
            {
                if (p.second == 2 && currentT2score > currentT1score)
                {
                    currentT2score++;
                    T1win -= (fulltime - p.first);
                    T2win = fulltime - p.first;
                    // cout << "전에 1번팀이 이겼어서, 2번팀의 시간을 빼주겠음"<<'\n';
                }
                else if (p.second == 1 && currentT1score > currentT2score)
                {
                    currentT1score++;
                    T2win -= (fulltime - p.first);
                    T1win = fulltime - p.first;
                }
            }
        }else{

        }
        prevWin = p.second;
    }

    // 분으로 변환 00으로 나타내야 함..
    // 동점일 때도 계산해야함.
    cout << T1win / 60 << ":" << T1win % 60 << '\n';
    cout << T2win / 60 << ":" << T2win % 60 << '\n';
}