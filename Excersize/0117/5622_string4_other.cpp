#import <iostream>
char a;
int b;
main()
{
    while (std::cin >> a)
        for (int d : "  CFILOSV")   //* 덩어리 마지막의 것을 순회하는 로직이었음 대박
            b += a > d;
    std::cout << b;
}