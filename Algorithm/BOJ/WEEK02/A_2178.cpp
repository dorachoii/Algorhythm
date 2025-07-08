#include <bits/stdc++.h>
using namespace std;

int n,m,cnt,x,y;
string s;


int main(){
    cin >> n >> m;

    int a[n][m];
    bool visited[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    cout << '\n';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << "n은 " << n << ", m은 " << m <<'\n';

    while (x >= 0 && x < n && y >= 0 && y < m)
    {

        cout << "현재 x는 " << x << "현재 y는 " << y <<'\n';
        cout << "a[x][y]는 " << a[x][y]<<'\n';

        if(a[x+1][y]==1 && visited[x+1][y] == false){
            cout << "아래쪽으로 1칸 이동해요"<<'\n';
            visited[x+1][y] = true;
            cnt ++;
            x++;
            
        }else if(a[x][y+1]==1 && visited[x][y+1] == false){ 
            cout << "오른쪽으로 1칸 이동해요"<<'\n';
            visited[x][y+1] = true;
            cnt++; 
            y++;
        }else if(a[x-1][y] == 1 && visited[x-1][y] == false)
        {
            cout << "위쪽으로 1칸 이동해요" << '\n';
            visited[x-1][y] = true;
            cnt++;
            x--;
        }
        else if (a[x][y-1] == 1 && visited[x][y-1] == false)
        {
            cout << "왼쪽으로 1칸 이동해요" << '\n';
            visited[x][y-1] = true;
            cnt++;
            y--;
        }
        else
        {
            cout << "아래와 오른쪽 모두 0이네요?" << '\n';
            // cnt =0;
            break;
        }
    }

    cout << cnt;

    return 0;
}

// 2차원 배열 초기화 방법과
// 붙어서 입력되는 것을 간과한 결과
// 입력받아 2차원 배열 만드는 것에도 어려움을 겪음 계속 000이 더 붙어서 나옴.. 심지어는 n,m 까지도 안옴
// 알고리즘 테스트조차 해볼 수가 없네 ..
// 어휴 입력이 젤 까다롭네
// 해결은 했는데 내가 구현한건 위로 이동도 있어야 함. 그래서 방문했니 안했니 체크리스트도 만들어줘야 하는 것.

// 내가 구현한건 상하좌우 돌아가며 1이니? 방문한적있니? 물어보면서 이동하는 로직
