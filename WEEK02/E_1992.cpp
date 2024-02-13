#include <bits/stdc++.h>
using namespace std;
// 1을 1로 받는 법 고안
// 재귀를 어떻게 효율적으로 돌릴지가 고민


const int max_n = 65;

int n, a[max_n][max_n];
string l;
string ret;

string quadTree(int n)
{

    int cnt = 0;

    while (n != 1)
    {
        // 좌상
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (a[i][j] == 0)
                    cnt++;
            }
        }

        if (cnt == (n / 2) * (n / 2))
        {
            ret += "(0";
            continue;
        }

        else if (cnt == 0)
        {
            ret += "(1";
            continue;
        }
        else
        {
            quadTree(n / 2);
            n /= 2;
        }

        // 우상
        cnt = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = n / 2; j < n; j++)
            {
                if (a[i][j] == 0)
                    cnt++;
            }
        }

        if (cnt == (n / 2) * (n / 2))
        {
            ret += "0";
            n/=2;
            continue;
        }

        else if (cnt == 0)
        {
            ret += "1";
            n /= 2;
            continue;
        }
        else
        {
            quadTree(n / 2);
            n /= 2;
        }

        // 좌하
        cnt = 0;
        for (int i = n / 2; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (a[i][j] == 0)
                    cnt++;
            }
        }

        if (cnt == (n / 2) * (n / 2))
        {
            ret += "0";
            n /= 2;
            continue;
        }

        else if (cnt == 0)
        {
            ret += "1";
            n /= 2;
            continue;
        }
        else
        {
            quadTree(n / 2);
            n /= 2;
        }

        // 우하
        cnt = 0;
        for (int i = n / 2; i < n; i++)
        {
            for (int j = n / 2; j < n; j++)
            {
                if (a[i][j] == 0)
                    cnt++;
            }
        }

        if (cnt == (n / 2) * (n / 2))
        {
            ret += "0)";
            n /= 2;
            continue;
        }

        else if (cnt == 0)
        {
            ret += "1)";
            n /= 2;
            continue;
        }
        else
        {
            quadTree(n / 2);
            n /= 2;
        }
    }

    return ret;
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> l;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = l[j] - '0';
        }
    }

    string k = quadTree(n);

    cout << k;
}