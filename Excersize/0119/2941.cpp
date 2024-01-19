#include <bits/stdc++.h>
using namespace std;

string a[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
string s;
int cnt;

int main()
{

    cin >> s;

    // find 후 erase 하고 없으면 string size
    // 찾고 00으로 만들어줌
    for (int i = 0; i < 8; i++)
    {
        size_t pos = s.find(a[i]); // find는 이터레이터 반환, size_t 자료형이 뭐지?

        // pos가 겹치는지 검사
        // erase는 앞에 것을 다 삭제
        // pos 띄엄띄엄이면 중간 카운트

        while (pos != string::npos)
        {
            cnt++;
            // s.erase(pos,a[i].length());     // 두번째 매개변수는 지울 개수 의미
            //  지워버리면 붙어서 새로운 게 만들어질 수 있음
            for (int j = pos; j < pos + a[i].length(); j++)
            {
                s[j] = '0';
            }

            pos = s.find(a[i]);
        }
    }

    size_t pos = s.find('0');

    while (pos != string::npos)
    {
        s.erase(pos);
    }

    cnt += s.length(); //*문자열 길이, 배열의 사이즈 등

    cout << cnt;
}