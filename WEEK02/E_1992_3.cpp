#include <bits/stdc++.h>
using namespace std;
// 작은 덩이 부터 큰덩이로 탐색해야할지
// 큰덩이부터 쪼개가야할지 헷갈림

int n, a[2][2] = {{1, 0},{ 0, 1}},cnt;
string ret;

int dx[] = {0, 1, -1, 1};
int dy[] = {0, 0, 1, 1};

//1일 때까지 4덩이로 쪼개는 로직.

void quadTree(int x, int y)
{
    ret += "(";
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
    // 덩어리 안에 요소들 모두 검사하는 로직 짜야 함.
        if (a[ny][nx])
        {
            cnt++;
            ret += "1";
        }
        else
        {
            ret += "0";
        }
    }

    if (cnt == 4){
        ret = "(1)";
    }else if(cnt == 0){
        ret = "(0)";
    }else{
        ret +=")";
    }
}

int main(){
    quadTree(0,0);
    cout << ret;
}