#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], b[51][51], visited[51][51], CD, cityCD, minCityCD = 2500;

vector<pair<int, int>> cPos;
vector<pair<int, int>> hPos;

int cnt;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

//이거 돌릴 필요 없이 좌표 빼서 더하면 되네..


// m 개 이하까지만  뽑아주기
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
                if (b[i][j] == 2)
                    cCnt++;
            }
        }

        if (cCnt <= m)
        {
            //cout << cnt << "번째 조합이 " << cCnt << "개의 치킨집으로 m보다 작아서 가능\n";
            // 선별된 것 마다, 도시의 치킨 거리 구할 것.
            cityCD = 0;
            

            for (int i = 0; i < hPos.size(); i++)
            {
                int minCD = 2500;
                //cout << i << "번째 집에서 치킨 집까지 거리 재기\n";

                for (int j = 0; j < cPos.size(); j++)
                {
                    CD  = abs(hPos[i].first - cPos[j].first) + abs(hPos[i].second - cPos[j].second);
                    minCD = min(CD, minCD);
                   
                }

                cityCD += minCD;
                //cout << i <<"번째 치킨 도시 거리는 "<<cityCD<<'\n'; 
            }

            //cout << cnt << "번째 조합의 치킨 도시 거리는 " << minCityCD <<'\n';
            minCityCD = min(minCityCD, cityCD);
        }

        // cout << "치킨집 리셋\n";
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

    if(m > 1){

        for (int i = 0; i < cPos.size(); i++)
        {
            pick(i, true);

            // cout << "치킨집 리셋\n";

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (b[i][j] == 2)
                        b[i][j] = 0;
                }
            }
        }
    }else if(m==1){

        

        for (int i = 0; i < cPos.size(); i++)
        {
            int minCD = 2500;
            //cout << i << "번째 치킨집을 골랐을 때\n";
            cityCD = 0;
            for (int j = 0; j < hPos.size(); j++)
            {

                CD = abs(hPos[j].first - cPos[i].first) + abs(hPos[j].second - cPos[i].second);
                //minCD = min(CD, minCD);
                cityCD += CD;
            }

            //cout <<" 치킨 도시 거리는 " << cityCD << '\n';

            minCityCD = min(minCityCD, cityCD);
        }
        //cout << cnt << "번째 조합의 치킨 도시 거리는 " << minCityCD << '\n';       
    }

   
    cout << minCityCD;
}