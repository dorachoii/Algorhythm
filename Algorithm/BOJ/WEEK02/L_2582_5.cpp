#include <bits/stdc++.h>
using namespace std;

int n, teamN, fullTime = 48 * 60;
string s;

//<골 시간, 팀 번호>
map<int, int> mpTime;
//<팀 번호, 골 시간>
map<int, int> mpTeam;
//<팀 번호, 이긴 시간>
map<int, int> mpWin;
//<팀 번호, 골 카운트>
map<int, int> mpGoalCnt;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> teamN >> s;

        int minute = stoi(s.substr(0, 2));
        int second = stoi(s.substr(3, 2));

        mpTime[minute * 60 + second] = teamN;
    }

    int prevWin = -1;
    bool isReversal = false;

    for (auto p : mpTime)
    {
        mpGoalCnt[p.second]++;
        cout << p.second << " 팀이 골을 넣어서" << p.second << "팀은 현재 " << mpGoalCnt[p.second] << "골\n";
        cout << "현재 이기고 있는 팀은 " << prevWin << '\n';
        mpTeam[p.second] = p.first;

        if (prevWin == -1)
        {
            mpWin[p.second] = p.first;
            cout << p.second << " 팀이 첫골을 넣어서" << p.second << "팀의 winning Time은 " << mpTeam[p.second] / 60 << ":" << mpTeam[p.second] % 60 << '\n';
            prevWin = p.second;
        }
        else if (p.second != prevWin && mpGoalCnt[p.second] > mpGoalCnt[prevWin])
        {
            isReversal = true;
            cout << p.second << "팀의 역전" << '\n';
            mpWin[p.second] = fullTime - p.first;
            mpWin[prevWin] = mpTeam[p.second] - mpTeam[prevWin];

            prevWin = p.second;
            cout << p.second << "팀의 winning Time은 " << mpTeam[p.second] / 60 << ":" << mpTeam[p.second] % 60 << '\n';
        }
    }

    if(!isReversal) mpWin[prevWin] = fullTime - mpWin[prevWin];

    cout << mpWin[1] / 60 << ":" << mpWin[1] % 60 << '\n';
    cout << mpWin[2] / 60 << ":" << mpWin[2] % 60 << '\n';
}