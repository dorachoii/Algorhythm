#include <bits/stdc++.h>
using namespace std;

int n, m,a[51][51],b[51][51];

vector<pair<int,int>> cPos;
vector<pair<int,int>> hPos;

int cnt;

void pick(int idx, bool bb){


    if(bb){
        b[cPos[idx].first][cPos[idx].second] = 2;
        cout << cnt + 1 << "번째 조합이고, " << idx << "번 요소는 선택되었다\n";
    }else{
        b[cPos[idx].first][cPos[idx].second] = 0;
        cout << cnt + 1 << "번째 조합이고, " << idx << "번 요소는 선택되지 않았다.\n";
    }

    if(idx == cPos.size()-1){
        cnt++;
        
        cout << cnt <<"번째 조합이고, 치킨집을 표시해보면\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << b[i][j] << " ";
            }
            cout << '\n';
        }

        cout << "치킨집 리셋\n";
        b[cPos[idx].first][cPos[idx].second] = 0;

        return;

    }

    pick(idx+1, true);
    pick(idx+1,false);
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];

            if(a[i][j] == 1) hPos.push_back({i,j});
            if(a[i][j] == 2){cPos.push_back({i,j});
                b[i][j] = 0;
            }
        }
    }


    for(int i = 0; i< cPos.size(); i++){
        pick(i, true);

        cout << "치킨집 리셋\n";
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