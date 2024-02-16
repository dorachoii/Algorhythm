#include <bits/stdc++.h>
using namespace std;

int n;
string s;
stack<char> vps;

int main()
{
    cin >> n;
    cin.ignore(); // 개행 문자를 처리하기 위해 추가
    // 입력이 젤 어려움

    for (int i = 0; i < n; i++)
    {
        getline(cin, s);

        //cout <<"s는 " << s <<'\n';

        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '(')
            {
                //cout << "( 쌓임\n";
                vps.push(s[j]);
            }
            else if (!vps.empty() && vps.top() == '(')
            {
                vps.pop();
                //cout << "() 완성이라 pop\n";
            }
            else
            {
                //cout << ") 쌓임\n";
                vps.push(s[j]);
            }
        }

        if(vps.empty())cout <<"YES\n";
        else cout << "NO\n";

        while(!vps.empty()){
            vps.pop();
        }
    }


}
