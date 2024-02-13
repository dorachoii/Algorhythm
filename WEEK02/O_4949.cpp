#include <bits/stdc++.h>
using namespace std;
// 입력 .까지 받아야 한다는 거
//  queue로 두개 만나면 pop 하고 마지막에 남아있으면 no나오도록 해야하는듯?
// queue 가 아니라 stack 써야 함.
// 또 stack을 초기화하지 않는 문제.
// 공백문자도 간과

char a[] = {'(', ')', '[', ']'};

int main()
{
    string s ='';

    getline(cin, s, '.');

        stack<char> stk = {};
        cout<< "입력받은 s는 " << s <<'\n';

        for (char c : s)
        {
            if (!stk.empty()&&c == a[1] && stk.top() == a[0])
            {
                stk.pop();
                cout <<"()pop"<<'\n';
            }
            else if (!stk.empty() && c == a[3] && stk.top() == a[2])
            {
                stk.pop();
                cout << "[]pop" << '\n';
            }
            else if (c == a[0] || c == a[2])
            {
                stk.push(c);
                cout << "( [ pushed"<<'\n';
            }
            else
            {
                continue;
            }
        }

        if (stk.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
  
