#import <iostream>
main()
{
    std::string d;
    float i, h, p, t = 0.0, T = 0.0;
    for (; i < 20.0; i += 1.0)
    {
        std::cin >> d >> h;
        getchar();
        p = 69 - getchar() + (getchar() == '+' ? 0.5 : 0.0);
        if (p >= -1.0)
        {
            if (p < 0.0)
                p = 0.0;
            else
                getchar();
            t += h * p;
            T += h;
        }
    }
    std::cout << t / T;
}