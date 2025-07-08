#include <bits/stdc++.h>
using namespace std;

int n, teamN, otherN, minute, second, winN = -1;
string timeS;
bool isSame;

int prevGoalTime;
map<int, int> goalCntMap; // team, goalcnt
map<int, int> winTimeMap; // team, winTime

string formatTime(int min, int sec){
    ostringstream oss;
    oss << setfill('0') << setw(2) << min <<":" << setw(2) << sec;
    return oss.str();
}


int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> teamN;
        cin >> timeS;

        goalCntMap[teamN]++;
        minute = stoi(timeS.substr(0, 2));
        second = stoi(timeS.substr(3, 2));


        if (teamN == 1)
            otherN = 2;
        else
            otherN = 1;

        if (winN != teamN && goalCntMap[teamN] > goalCntMap[otherN])
        {            
            prevGoalTime = minute * 60 + second;
            winTimeMap[winN] += (minute * 60 + second) - prevGoalTime;
            winN = teamN;
        }
        else if (winN != teamN && goalCntMap[teamN]  == goalCntMap[otherN]){

            winTimeMap[winN] += (minute * 60 + second) - prevGoalTime;
            prevGoalTime = minute * 60 + second;
            //winN = teamN;
        }
    }

    winTimeMap[winN] += 48 * 60 - prevGoalTime;

    //숫자 표기


    cout << formatTime(winTimeMap[1]/60, winTimeMap[1]%60) << '\n';
    cout << formatTime(winTimeMap[2] / 60, winTimeMap[2] % 60) << '\n';
}