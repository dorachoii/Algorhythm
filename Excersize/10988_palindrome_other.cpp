#import <bits/stdc++.h>
std::string a;

int a, b;
std::string s;
bool c = 1;

main()
{
    std::cin >> a;
    std::cout << equal(a.begin(), a.end(), a.rbegin());

    // *** 이거 알아두기
    std::string s, r;
    std::cin >> s;
    r = s;
    reverse(r.begin(), r.end());
    std::cout << (r == s);

    //
    std::cin >> s;
    for (b = s.size() - 1; a < b; a++, b--)
        if (s[a] != s[b])
            c = 0;
    std::cout << c;
}