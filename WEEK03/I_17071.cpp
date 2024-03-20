#include<bits/stdc++.h>
using namespace std;

// 같이 만나는 경우
// 먼저 도착했는데 홀짝이 맞을 경우?

const int max_n = 500000;
//[수빈위치][동생위치]
int visited[2][max_n+4]; //왜 2차원으로 만들었냐면 홀짝 따로 체크하기 위해서

int a,b, ok, turn = 1;  //ok는 만났는지 체크하는 변수

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    if(a==b){cout << 0 << "\n"; return 0;}

    queue<int> q;

    visited[0][a] = 1;
    q.push(a);
    //cout << "수빈이의 처음 위치는 " << a <<"이고 방문배열을 1로 바꾸고, 큐에도 넣었다\n";

    while(q.size()){
        b += turn;
        //cout << "현재 동생의 위치는 " << b << '\n';

        if(b > max_n)break;

        //동생 위치를 먼저 방문했다면
        if(visited[turn %2][b]){
            //cout << "현재 " << turn%2 << "같은 홀짝에 수빈이가 먼저 방문한 적있으므로 " << b << "위치의 동생과 만난다!";
            ok = true;
            break;
        }

        //flood fill: 단계별로 색을 칠하는 과정
        int qSize = q.size();
        //cout << "현재 큐 사이즈는 "<< qSize << '\n';

        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();

            for(int nx: {x+1, x-1, x*2}){
                //오버플로 체크, 
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                
                //cout << "수빈이의 다음 위치는" << nx <<'\n';
                visited[turn % 2][nx] = visited[(turn +1)%2][x]+1;

                // 동생이 와있다면 break?
                if(nx == b){
                    //cout << nx <<"에서 동생과 만났다!\n";
                    ok = 1; break;
                }
                q.push(nx);
            }

            if(ok) break;
        }

        if(ok) break;
        turn++;
    }

    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}