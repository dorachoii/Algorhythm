#include <bits/stdc++.h>
using namespace std;

int N, B;// 분석 및 고치기
int k;

string num, K;

int main()
{
    cin >> N >> B;

    while (N > 0)
    {
        k = N % B;

        if (k > 9)
        {
            K = 'A' + k - 10;
        }
        else
        {
            K = to_string(k);
        }

        num += K;
        N /= B;
    }

    reverse(num.begin(), num.end());

    cout << num;
    return 0;
}
