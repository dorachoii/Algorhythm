#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], b[51][51], cityCD;

vector<pair<int, int>> cPos;
vector<pair<int, int>> hPos;

int cnt;

//m 개 이하까지만  뽑아주기
void pick(int idx, bool bb)
{

    if (bb)
    {
        b[cPos[idx].first][cPos[idx].second] = 2;

    }
    else
    {
        b[cPos[idx].first][cPos[idx].second] = 0;
    }

    if (idx == cPos.size() - 1)
    {
        cnt++;
        int cCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(b[i][j]==2)  cCnt++;
                
            }
        }

        if(cCnt <= m){
            cout << cnt << "번째 조합이 " << cCnt << "개의 치킨집으로 m보다 작아서 가능\n";
            //선별된 것 마다, 도시의 치킨 거리 구할 것.

        }

        //cout << "치킨집 리셋\n";
        b[cPos[idx].first][cPos[idx].second] = 0;

        return;
    }

    pick(idx + 1, true);
    pick(idx + 1, false);
}


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];

            if (a[i][j] == 1)
                hPos.push_back({i, j});
            if (a[i][j] == 2)
            {
                cPos.push_back({i, j});
                b[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < cPos.size(); i++)
    {
        pick(i, true);

        //cout << "치킨집 리셋\n";
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j] == 2)
                    b[i][j] = 0;
            }
        }
        
    }
}