#include <bits/stdc++.h>
using namespace std;

int h, w, a[101][101], ret[101][101]; // ret 배열도 굳이 필요 없음 cnt를 바로 출력하면 됌.
char s;

int main()
{

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s;
            if (s == 'c')
            {
                a[i][j] = 1;
            }
        }
    }


    for (int i = 0; i < h; i++)
    {
        int cnt = -1;

        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 1)
            {
                cnt = 0;
            }else if(cnt!=-1){
                cnt++;
            }

            ret[i][j] = cnt;
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
}