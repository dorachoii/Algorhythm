#include <bits/stdc++.h>
using namespace std;

const int max_n = 65;
int n, a[max_n][max_n];

string quadTree(int size, int r, int c)
{
    if (size == 1)
        return to_string(a[r][c]);

    string ret = "(";
    int half = size / 2;

    ret += quadTree(half, r, c);               // 좌상
    ret += quadTree(half, r, c + half);        // 우상
    ret += quadTree(half, r + half, c);        // 좌하
    ret += quadTree(half, r + half, c + half); // 우하

    if (ret == "(0000)" || ret == "(1111)") // 한 영역에 동일한 숫자만 있는 경우
        ret = ret.substr(0, 1);             // 영역을 한 문자로 압축

    return ret + ")";
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = line[j] - '0';
        }
    }

    cout << quadTree(n, 0, 0);
    return 0;
}
