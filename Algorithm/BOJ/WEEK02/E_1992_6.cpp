#include <bits/stdc++.h>
using namespace std;

int n; 
string s;
char a[101][101];

string quardTree(int y, int x, int size){

    cout << "현재 (y,x)는 (" <<  y << "," << x <<")"<<'\n';
    cout << "현재 size는 " << size<<'\n';

    if(size == 1) return string(1,a[y][x]);

    char b = a[y][x];
    string ret ="";

    // 일반적 좌표평면에서의 x,y와 2차원 배열에서의 인덱스 i,j가 반대로 매핑되기 때문에
    // y,x 바꿔서 하시는 듯
    // 어차피 탐색 순서(좌상-우상-좌하-우하)가 행별로 탐색우선, 그다음 열으로 가는 2차원 배열 인덱스와 매칭됨
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            cout << "탐색 좌표는 (" << i << "," << j << ")" << '\n';

            if(b!=a[i][j])
            {
                cout << "시작 좌표와 탐색 좌표가 달라서 재귀를 시작할 것임"<<'\n';

                ret += '(';
                cout << "괄호가 열렸다\n";
                //좌상-우상-좌하-우하
                ret += quardTree(y,x,size/2);
                ret += quardTree(y,x+ size/2, size/2);
                ret += quardTree(y + size/2, x, size/2);
                ret += quardTree(y + size /2 , x + size/2, size/2);
                ret +=')';
                cout << "괄호가 닫혔다\n";
                return ret;
            }
        }
    }
    // 마지막에 괄호가 어떻게 닫히지?
    // 4가 아니라 8부터 시작하기 때문! 
    
    cout << "시작 좌표와 탐색 좌표가 모두 같아서 0 또는 1을 출력하겠다" << '\n';
    return string(1,a[y][x]);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << quardTree(0,0,n) << '\n';
    return 0;
}