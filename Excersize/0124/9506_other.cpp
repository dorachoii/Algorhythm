#import <iostream>
main()
{   // 완전수를 이미 알고 푼 경우
    int i, j;
    while (std::cin >> i && i > -1)
    {
        j = 1;
        if (i == 6 || i == 28 || i == 496 || i == 8128)
        {
            std::cout << i << " = 1";
            while (++j <= i / 2)
            {
                if (i % j == 0)
                    std::cout << " + " << j;
            }
        }
        else
            std::cout << i << " is NOT perfect.";
        std::cout << "\n";
    }
}

