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
            // a[i]을 찾은 위치부터 해당 문자열의 길이만큼 '0'으로 변경
            for (int j = pos; j < pos + a[i].length(); j++)
            {
                s[j] = '0';
                
            }

            pos = s.find(a[i], pos + 1); // 다음 위치부터 다시 검색
        }
    }

    size_t pos = s.find('0');

    while (pos != string::npos)
    {
        s.erase(pos, 1);   // pos 위치의 문자를 1개 삭제
        pos = s.find('0'); // 다음 '0' 찾기
    }

    cnt += s.length(); //*문자열 길이, 배열의 사이즈 등

    cout << cnt;
}