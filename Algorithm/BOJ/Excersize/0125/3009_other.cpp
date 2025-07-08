#import <iostream>
using namespace std;
int a, b, c, d;

main()
{
    for (; cin >> a >> b; d ^= b)
        c ^= a;
    cout << c << ' ' << d;
}

// 다르면 그것을 할당하는 방식