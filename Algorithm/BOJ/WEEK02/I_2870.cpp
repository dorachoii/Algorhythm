#include <bits/stdc++.h>
using namespace std;

// 입력 숫자니? 문자니?
// 002 는 2와 같아.
// 비내림차순 정렬
// segment fault 발생 두번째 예제에서

// 양쪽 다 비교해야함.

int n;
string s;

vector<int> ret;

bool isNum(char s)
{
    if (s - '0' >= 0 && s - '0' <= 9)
    {
        return true;
    }
    return false;
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        queue<char> q;
        string num;

        if(isNum(s[0])) num+= s[0];

        for (int j = 1; j < s.size(); j++)
        {
            if (isNum(s[j]))
            {
                if (isNum(s[j-1]))
                {
                    //cout << "현재 j는 " << j << " s[j]의 값은 " << s[j]<<'\n';
                    q.push(s[j]);
                }
                else
                {
                    //cout << "string num에 저장된 숫자는" << num << '\n';
                    //cout << "그걸 숫자로 변환한 값은" << stoi(num) << '\n';
                    q.push(s[j]);

                    if(!q.empty()){
                        while (q.front() == '0')
                        {
                            q.pop();
                        }

                        while (!q.empty())
                        {
                            num += q.front();
                            q.pop();
                        }

                        ret.push_back(stoi(num)); 
                        num = "";
                    }

                    
                }
            }
        }

        if(!q.empty()) {
            while (q.front() == '0')
            {
                q.pop();
            }

            while (!q.empty())
            {
                num += q.front();
                q.pop();
            }

            ret.push_back(stoi(num)); 
            num = "";
    }

    sort(ret.begin(), ret.end());

    for(int a : ret){
        cout << a <<'\n';
    }
}}
