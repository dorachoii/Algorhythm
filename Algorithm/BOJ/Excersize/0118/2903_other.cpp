#import <iostream>

main(int i)
{
    std::cin >> i;
    i = (1 << i) + 1;
    std::cout << i * i;
}