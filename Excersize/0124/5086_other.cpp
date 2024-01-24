#include <iostream>
main()
{
    for (int a, b; std::cin >> a >> b && a ^ b;)   
    //a,b 선언하고 0으로 해둠

    // ^논리합 연산자 XOR 
    // 서로 다르면 1 , 같으면 0

        printf(b % a ? a % b ? "neither\n" : "multiple\n" : "factor\n");
        // 3항 연산자 중첩 활용
    if (b % a != 0)
    {
        if (a % b != 0)
        {
            std::cout << "neither\n";
        }
        else
        {
            std::cout << "multiple\n";
        }
    }
    else
    {
        std::cout << "factor\n";
    }
}

#import <iostream>
main()
{
    int a, b;
    while (std::cin >> a >> b && a != 0)
        std::cout << (a % b ? b % a ? "neither\n" : "factor\n" : "multiple\n");
}

// 나머지 연산과 나누기 연산 다르다는거