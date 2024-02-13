#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(true){
        getline(cin, s);
        if (s == ".")
            break;

        stack<char> stk = {};

        for (char c : s)
        {
            if (c == ')' && stk.size() && stk.top() == '(')
            {
                stk.pop();
            }
            else if (c == ']' && stk.size() && stk.top() == '[')
            {
                stk.pop();
            }
            else if (c == '(' || c == '[')
            {
                stk.push(c);
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
}