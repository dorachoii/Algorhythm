#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fulltime = 48 * 60;
    cin >> n;

    int T1win = 0, T2win = 0;
    int prevWin = -1;

    for (int i = 0; i < n; i++)
    {
        int teamN;
        string s;
        cin >> teamN >> s;

        int minute = stoi(s.substr(0, 2));
        int second = stoi(s.substr(3, 2));

        int currentTime = minute * 60 + second;
        int timeDiff = fulltime - currentTime;

        if (prevWin != -1)
        {
            if (prevWin == 1)
            {
                T1win += timeDiff;
            }
            else
            {
                T2win += timeDiff;
            }
        }

        prevWin = teamN;
    }

    cout << T1win / 60 << ":" << setw(2) << setfill('0') << T1win % 60 << '\n';
    cout << T2win / 60 << ":" << setw(2) << setfill('0') << T2win % 60 << '\n';

    return 0;
}
