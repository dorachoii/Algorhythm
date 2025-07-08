#include <bits/stdc++.h>
using namespace std;

// factorial
// 반복문으로 할 수 있는 경우엔 반복문으로 해라!
int factorial(int n){
    if(n == 1 || n == 0) return 1;
    return n * factorial(n-1);
}

int factorial2(int n){

    int ret = 1;

    for(int i = 1; i <=n; i++){
        ret *=i;
    }
}

//  fibonacci
int fibonacci(int n){

    cout << "fibo : " << n << '\n';

    if(n==0 || n == 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int n = 5;

int main() {
    cout << "factorial의 값은" << factorial(n) << " fibonacci의 값은" << fibonacci(n) << '\n';
    return 0;
}

