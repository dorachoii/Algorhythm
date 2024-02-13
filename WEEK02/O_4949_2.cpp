#include <bits/stdc++.h>
using namespace std;

char a[] = {'(', ')', '[', ']'};
string s;
stack<char> stk;

int main(){
    
    getline(cin, s,'.');
    cout << "입력받은 s는 " << s <<'\n';

    for (char c : s)
    {
        if (!stk.empty() && c == a[1] && stk.top() == a[0])
        {
            stk.pop();
            cout << "()pop" << '\n';
        }
        else if (!stk.empty() && c == a[3] && stk.top() == a[2])
        {
            stk.pop();
            cout << "[]pop" << '\n';
        }
        else if (c == a[0] || c == a[2])
        {
            stk.push(c);
            cout << "( [ pushed" << '\n';
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