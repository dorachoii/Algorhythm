#include <bits/stdc++.h>
using namespace std;

// input
int n;
string s;
char prevC = 'z';
string numS = "";

// char이 숫자인지 판단
bool isNum(char c)
{
    if (c - '0' >= 0 && c - '0' <= 9)
        return true;
    return false;
}

// 숫자 넣을 벡터
vector<int> ret;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        numS = "";
        //cout << "현재 s는 " << s << '\n';

        // 숫자가 끊기면, 즉 현재 문자가 숫자가 아닌 순간 넣음
        for (char a : s)
        {
            //cout << "현재 s에서 탐색하는 문자는 " << a<< '\n';

            if (!isNum(prevC) && isNum(a))
            {
                //cout << "이전 문자 : 문자, 현재 문자 : 숫자라서 축적\n";
                numS += a;
                cout << a <<'\n';

            }
            else if (isNum(prevC) && isNum(a))
            {
                //cout << "이전 문자 : 숫자, 현재 문자 : 숫자라서 축적\n";
                numS += a;
                cout << a << '\n';
            }
            else if (isNum(prevC) && !isNum(a))
            {
                //cout << "이전 문자 : 숫자, 현재 문자 : 문자라서 비워야 함\n";

                if (!numS.empty())
                {
                    int i = 0;

                    if(numS[i]== '0'){
                        string k = "";

                        //cout << "numS가 0으로 시작해서 앞부분 잘라줄 것\n";
                        while (numS[i] == '0')
                        {
                            k = numS.substr(i, numS.size());
                            i++;
                        }
                        numS = k;
                    }

                    ret.push_back(stoi(numS));
                    numS = "";
                }
            }else{
                
            }
            prevC = a;
        }
    }

    int i = 0;
    //마지막 숫자 남아있는 경우 처리를 안했네
    if (numS[i] == '0')
    {
        string k = "";

        // cout << "numS가 0으로 시작해서 앞부분 잘라줄 것\n";
        while (numS[i] == '0')
        {
            k = numS.substr(i, numS.size());
            i++;
        }
        numS = k;
    }

    ret.push_back(stoi(numS));
    numS = "";

    sort(ret.begin(), ret.end());

    for(int a : ret) cout << a << '\n';
}