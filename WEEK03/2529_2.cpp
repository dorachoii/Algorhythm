#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// 10! = 362만, 1억보단 작다.
// 즉 완탐해도 되는구나 하고 들어가기!

int n, check[10];
char a[20];
vector<string> ret;  


bool good(char x, char y, char op){ 
	if(x < y && op == '<') return true; 
	if(x > y && op == '>') return true; 
	return false; 
}

void go(int idx, string num){ 

	if(idx == n + 1){
		
		ret.push_back(num); return;
	}

	for(int i = 0; i <= 9; i++){
		if(check[i]) continue; //해당 숫자 썼는지 체크
        
        // idx == 
        // num[idx -1] : 
        // i + '0' : 숫자 + 아스키코드 (0 ~127까지 존재) : 대소비교를 위해 아스키 코드화한 거
        // a[idx - 1] : 이전 부등호 

        // 0번 처리하는 방법 배우기
        // 0 넣고, 다음 거 넣고 

		if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1])){
            //cout << "현재 " << num[idx - 1] << "다음 " << i + '0' << "부등호 " << a[idx - 1] <<'\n';
            // 문자열에 쌓아두고
			check[i] = 1;
			go(idx + 1, num + to_string(i));
			check[i] = 0;
		}
	}

	return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin >> n; 
    for(int i = 0; i < n; i++) cin >> a[i]; 

    go(0, "");

    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}

// 문자열 대소비교 size먼저 체크하는 것이 중요!
// 23, 123 비교하면 23이 더 크게 판단되기 때문!

// 문자 vs 숫자 : 아스키코드 순으로 비교하게 되기 때문