#include <bits/stdc++.h>
using namespace std;

// 2와 5로 나누어 떨어지지 않는 정수 n
// 각 자릿수가 모두 1로 이루어진 n의 배수 중 가장 작은 수의 자리수

// 1 - 1 ,  3 - 7, 7 - 3, 9 - 9
// 1의 자리 검사 후 1의 자리 고정 해두고 앞에 수 채워나가며 1111으로만 구성되었는지 검사
// 무조건 시간 초과날 것 같음..

//체력으로 풀어낸 방법.
// long long 범위까지 다확인해야 제대로 돌아가더라.

int n,digit;
long long a,s,k = 10;

//자리수 체크
int check(long long n){
    digit = 0;
    while(n%k){
        digit++;
        k*=10;
        n/=10;
    }

    return digit;
}
//모두 1111으로 이루어졌니? 체크
bool check2(long long n)
{
    bool isOne = true;
    int k = 10; // k를 함수 내에서 선언하고 초기화

    while (n > 0)
    {
        if (n % k != 1)
        {
            isOne = false;
            break;
        }
        n /= 10;
    }

    return isOne;
}

int main()
{
    while(cin>>n)
    {
        if(n%10 == 1) {

            for (long long i = 1; i < LLONG_MAX; i++)
            {
                if(i%10 ==1){
                    s = n*i;
                    
                    if(check2(s)) {
                        cout << "n은 " << n<<'\n';
                        cout << "i는 " << i << '\n';
                        cout << "s는 "<< s << '\n';
                        cout << check(s)<<'\n';break;}
                }
            }
        }else if(n%10 == 3){
            for (long long i = 1; i < LLONG_MAX; i++)
            {
                if (i % 10 == 7)
                {
                    s = n * i;
                    if (check2(s))
                    {
                        cout << "n은 " << n << '\n';
                        cout << "i는 " << i << '\n';
                        cout << "s는 " << s << '\n';
                        cout << check(s) << '\n';
                        break;
                    }
                }
            }
        }else if(n%10 == 7){
            for (long long i = 1; i < LLONG_MAX; i++)
            {
                if (i % 10 == 3)
                {
                    s = n * i;
                    if (check2(s))
                        {
                            cout << "n은 " << n << '\n';
                            cout << "i는 " << i << '\n';
                            cout << "s는 " << s << '\n';
                            cout << check(s) << '\n'; break;}
                }
            }
        }else if(n%10 == 9){
            for (long long i = 1; i < LLONG_MAX; i++)
            {
                if (i % 10 == 9)
                {
                    s = n * i;
                    if (check2(s))
                        {
                            cout << "n은 " << n << '\n';
                            cout << "i는 " << i << '\n';
                            cout << "s는 " << s << '\n';

                            cout << check(s) << '\n';break;}
                }
            }
        }else{
            continue;
        }
    }
}
