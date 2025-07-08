#include <iostream>
using namespace std;

bool check2(int n)
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
    long testNumber = 2147536801;
    cout << check2(testNumber) << endl; // 기대값: false

    return 0;
}
