#include <iostream>
#include <vector>

using namespace std;

// input
const int max_m = 101;
int m, n, k, aa[max_m][max_m], a, b, c, d;

//result
int cnt,space;
vector<int> spc;

// dfs - connected component
bool visited[max_m][max_m];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ny <0 || nx <0 || ny >=n || nx>= m) continue;
        if(aa[nx][ny] == 0 && !visited[nx][ny]){
            space++;
            dfs(nx,ny);
        }
    }
    return space;
}

bool visited[max_m][max_n];

int dx[] = {1, -1, 0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ny <0 || nx < 0 || ny >= n || nx >= m) continue;
        if(aa[nx][ny] == 0 && !visited[nx][ny]){
            space++;
            dfs(nx, ny);
        }
    }

    return space;
}

int dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny <0 || nx > m || ny >n) continue;

        if(aa[nx][ny] == 0 && 
        !visited[nx][ny]){
            dfs(nx,ny);
        }
    }
}

int main()
{

    cin >> m >> n >> k;
    // a[m][n]
    //[b][a] ~ [d][c]

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c >> d;

        for (int x = b; x < d; x++)
        {
            for (int y = a; y < c; y++)
            {
                aa[x][y] = 1;
            }
        }
    }   

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            //cout << aa[i][j] << " ";
            space = 1;
            if(aa[i][j]== 0 && !visited[i][j]){
                int k = dfs(i,j);
                cnt++;
                spc.push_back(k);
            }
        }
        //cout << '\n';
    }

    cout << cnt <<'\n';

    sort(spc.begin(), spc.end());

    for(int a : spc){
        cout << a <<" ";
    }
}