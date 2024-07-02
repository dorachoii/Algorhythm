#include <bits/stdc++.h>
using namespace std;

// ad-Hoc: 구현문제라고 퉁쳐지기도 함.
// 스페셜 저지: input을 넣고 output이 나올 때 validator에 한번더 돌림!

// 함정 문제: P넣으면 되지않냐!

int a, p;

int main(){
    cin >> a >> p;
    cout << p;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, cnt = 0; // Initialize num and cnt
    int a[6] = {500, 100, 50, 10, 5, 1}; // Array of coin denominations

    cin >> num; // Read the input amount

    for(int i = 0; i < 6; i++){ // Loop through each denomination
        cnt += num / a[i]; // Add the number of coins of this denomination
        num = num % a[i]; // Update the remaining amount
    }

    cout << cnt; // Output the total count of coins
    return 0;
}
