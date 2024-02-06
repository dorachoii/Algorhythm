#include <bits/stdc++.h>
using namespace std;
string s, result;
int cnt;
vector<char> odd;

int main()
{
    cin >> s;
    int a[26] = {0};

    for (char c : s)
    {
        a[c - 'A']++;
    }

    // cout << a[0] <<" "<<a[1]<<'\n';

    for (int i = 25; i >= 0; i--)
    {
        if (a[i] == 0)
            continue;

        if (a[i] % 2 == 0)
        {
            // 뒤에서부터 검사하며 push하고 이걸 reverse해서 더해주는 string 만들기
            for (int j = 0; j < a[i] / 2; j++)
            {
                result += i + 'A';
                // cout<< result<<'\n';
            }
        }
        else
        {
            cnt++;
            odd.push_back(i + 'A');
            // cout << i <<"번째 요소는 홀수에요 "<<'\n';
        }
    }

    if (result.empty())
    {
        cout << "I'm Sorry Hansoo";
    }
    else
    {
        if (cnt > 1)
        {
            cout << "I'm Sorry Hansoo";
        }
        else if (cnt == 0)
        {
            string temp;
            temp = result;
            // cout << "temp는 " << temp <<'\n';
            reverse(result.begin(), result.end());

            result = result + temp;
            cout << result;
        }
        else if (cnt == 1)
        {
            if (a[odd[0] - 'A'] == 1)
            {
                string temp;
                temp = result;
                reverse(result.begin(), result.end());
                result = result + odd[0] + temp;
                cout << result;
            }
            else
            {
                // cout<< "case3이야"<<'\n';
                //cout << "현재 odd의 사이즈는 " << cnt << '\n';
                // 1보다 큰 홀수라면, 중간에 끼워줘야 함. 위치 찾기
                string temp = result;
                string oddd = "";
                string pre = "";
                string suf = "";

                reverse(temp.begin(), temp.end());

                for (int i = 0; i < result.length(); i++)
                {
                    // 누가 크니?
                    if (max(temp[i], odd[0]) == temp[i])
                    {
                        pre = temp.substr(0, i);
                        suf = temp.substr(i);
                        break;
                    }
                }
                // 넣어줄 홀수 문자 개수 구하기
                for (int i = 0; i < a[odd[0] - 'A'] / 2; i++)
                {
                    oddd += odd[0];
                }

                //cout << "pre는 " << pre << '\n';
                //cout << "suf는 " << suf << '\n';

                result = pre + oddd + suf;

                //cout << "oddd 더한뒤 result는 " << result << '\n';

                temp = result;
                reverse(temp.begin(), temp.end());
                result = result + odd[0] + temp;
                cout << result;
            }
        }
        else
        {
            cout << "I'm Sorry Hansoo";
        }
    }
}
// 무한 루프인지 X가 계속 출력 왜그렇지?
// 지역변수 쓸 땐 항상 초기화 해주기!
// 왜 쓰레기값 들어가는지 공부
