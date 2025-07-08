#import <iostream>
main()
{
    int a = 100, p[a][a] = {}, x, y, i, t = 0;
    for (std::cin >> x; std::cin >> x >> y;)
        for (i = a; i--; p[x + i / 10][y + i % 10] = 1)
            t += !p[x + i / 10][y + i % 10];
    std::cout << t;
}