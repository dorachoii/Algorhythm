#include <bits/stdc++.h>
using namespace std;

int m,n,k;
int xx,yy,xxx,yyy;

const int max_n = 104;
int a[max_n][max_n];
bool visited[max_n][max_n];

vector<int> cntV;

int num,cnt;

int main(){

    cin >> m >> n >> k;

    for(int i = 0; i < k; i++){

        cin>>xx>>yy>>xxx>>yyy;

        for(int x = xx ; x<xx; x++){
            for(int y = yy; y<yyy; y++){
                a[x][y]++;
                visited[x][y] = true;
            }
        }       
    }

    
    for(int x = 0 ; x< m; x++){
        for(int y = 0; y < n; y++){
            cnt = 0;
            if(a[x][y]>0) continue;
            else{
                //오른쪽
                if (a[x + 1][y] == 0 && !visited[x + 1][y])
                {
                    visited[x + 1][y] = true;
                    cnt++;
                    x++;
                }
                //왼쪽
                else if (a[x - 1][y] == 0 && !visited[x - 1][y])
                {
                    visited[x - 1][y] = true;
                    cnt++;
                    x--;
                }
                //위쪽
                else if (a[x][y + 1] == 0 && !visited[x][y+1])
                {
                    visited[x][y+1] = true;
                    cnt++;
                    y++;
                }
                //아래쪽
                else if (a[x][y - 1] == 0 && !visited[x][y-1])
                {
                    visited[x][y - 1] = true;
                    cnt++;
                    y--;
                }
                else
                {
                    cntV.push_back(cnt);
                    num++;
                    break;
                }
            }
        }

        cout << num<<'\n';
        for(int a: cntV){
            cout << a <<" ";
        }
    }

}