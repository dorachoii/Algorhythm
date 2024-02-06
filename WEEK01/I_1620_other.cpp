#include <bits/stdc++.h>
using namespace std;

//문제 포인트
// str <-> int 
// atoi, stoi
// atoi : 입력받은 문자열이 문자라면 0, 숫자라면 1
// atoi는 0은 체크 못함

//string -> int로 바꿀 때
// 배열 find - O(N)
// Map - O(logN)

//int -> string으로 바꿀 때
// 배열 - O(1)
// Map - O(logN)
// 크게 차이나는 것은 아님

int N,M;
string s;

map <string, int> mp;
string a[100004];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  //이거 안썼다고 ?

    //iostream 라이브러리를 빠르게 만들어주기 위한 것
    //대량의 입력을 처리하는 경우에 사용

    //stdio랑 비동기화시켜서 C의 입출력버퍼와 상호작용하지 않아도 됌
    //cin.tie/cout.tie도 마찬가지
    // 기본 기능 같은 연결 끊어주는 의미인 듯

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> s;
        mp[s] = i+1;
        a[i+1] = s;
    }

    for(int i = 0; i < M; i++){
        cin >> s;
        
        if(atoi(s.c_str())==0){
            cout << mp[s] <<'\n';

        }else{

            cout << a[atoi(s.c_str())]<<'\n';
        }
    }


}