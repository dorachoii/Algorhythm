#include <bits/stdc++.h>
using namespace std;

// 4 : N 1~50
// 0 1 2 3
// 몇개가 참인지!

// 예제1 : 서로 다 다르다면 가장 작은 자연수
// 0개의 말이 참이다.(거짓)
// 1개의 말이 참이다. (참)
// 2개의 말이 참이다. (거짓)
// 3개의 말이 참이다. (거짓)

// 예제2 : 1이라면 -1 모순
// 0개의 말이 참이다.(거짓) 모순

// 예제3 : n개가 n개 있다면 참!
// 0개의 말이 참이다. (거짓)
// 3개의 말이 참이다. (참)
// 1개의 말이 참이다. (거짓)
// 3개의 말이 참이다. (참)
// 2개의 말이 참이다. (거짓)
// 3개의 말이 참이다. (참)

// 예제4 : 
// 1개의 말이 참이다. (거짓)
// 1개의 말이 참이다. (거짓)

int n, a;
int aa[51];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        aa[a]++;
    }

    
    for(int i = n; i > 0 ; i--){
        if(aa[n] == n){
            cout << n;
            return 0;
        }
    }

    // n: 1개라면 -1
    // n이 1개 이상이고 모두 다른 수라면 가장 작은 자연수?
    // n이 1개 이상이고 같은 수가 있다면 같은 수가 n개인지 파악?
}


// 0개가 정답이려면 0
// 1개가 정답이려면 1개수가 1이어야함
// 3개가 정답이라면 3 개수가 3이어야 함!

// 2차원 배열 대신 인덱스 이용해서 3++ 추가 해서 인덱스랑 해당 요소 num 비교하는 방식!

// 뒤에서 부터 찾아서 큰수부터 검사했음! 





// 2,3,5,9 /// 1,4,7  첫번째에서 포인터 옮기면서, 두번째에서 포인터 옮기면서 대소 비교!
// 두 개의 배열의 두 개의 포인트로!