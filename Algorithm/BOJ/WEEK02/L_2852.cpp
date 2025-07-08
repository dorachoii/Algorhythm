// 골이 들어간 시간, 팀
//  경기 48분
//  누가 이기고 있었는지
//  시간 계산
//  입력 받아서 :로 나누고 시 분으로 나누어 입력
//  시간 순 정렬이 또 필요하겠군
//  분 초환산 후 계산

#include <bits/stdc++.h>
using namespace std;

int n, teamN, fulltime = 48 * 60, T1win, T2win;
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
                }
                else
                {
                    T2win = fulltime - p.first;
                }
            }
            else
            {
                if (p.second == 2)
                {
                    T1win -= (fulltime - p.first);
                    //cout << "전에 1번팀이 이겼어서, 2번팀의 시간을 빼주겠음"<<'\n';

                }
                else
                {
                    T2win -= (fulltime - p.first);
                }
            }
        }
        prevWin = p.second;
    }

    // 분으로 변환 00으로 나타내야 함..
    cout << T1win / 60 << ":" << T1win % 60 << '\n';
    cout << T2win / 60 << ":" << T2win % 60 << '\n';
}