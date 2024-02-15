//100글자니까 longlong안되는구나 판단해야함.

#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s, ret;

void go()
{
    while (true)
    {
        if (ret.size() && ret.front() == '0')
            ret.erase(ret.begin());
        else
            break;
    }
    if (ret.size() == 0)    //0000을 
        ret = "0";
    v.push_back(ret);
    ret = "";
}

// 문자열 기반으로 숫자 정렬하려면
// 아스키 코드 기반으로 하게되니까

bool cmp(string a, string b)
{
    //size 즉 자릿수 먼저 비교
    if (a.size() == b.size())
        return a < b;

    //왼쪽 끝에서부터 아스키 코드 기반 비교
    return a.size() < b.size();
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ret = "";

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] < 65)// 숫자 판단하는 것
                ret += s[j];
            else if (ret.size())
                go();
        }
        if (ret.size())
            go();
    }
    sort(v.begin(), v.end(), cmp);

    for (string i : v)
        cout << i << "\n";

    return 0;
}