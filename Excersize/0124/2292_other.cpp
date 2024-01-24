#import <iostream>
main()
{
    int n, c = 1;
    for (std::cin >> n; n > 1;)
        n -= 6 * c++;   // 합을 계속 빼주면 반대로 몇번째 원인지 구할 수 있구나
    std::cout << c;
}


main2()
{
    int n, i = 1;
    for (std::cin >> n; n > 1; i++)
        n -= 6 * i;
    std::cout << i;
}

//등비수열의 합

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    int cnt = 1;
    while (n > i)
    {
        i += (6 * cnt);
        cnt++;
    }
    cout << cnt;
}
//count로 늘려주기