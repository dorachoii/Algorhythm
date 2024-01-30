#include <bits/stdc++.h>
using namespace std;
string str;
char k;

int main()
{

    getline(cin, str);
    string temp;

    for (char c : str)
    {

        if (c >= '0' && c <= '9'){
            temp += c;
        }else if(c == ' '){
            temp += c;
        }   
        else if(c >= 'a' && c<='z'){

            if(c+13 > 'z'){
                k = c+13 -'a'; // 얘랑 차이가 뭐지
            }else{
                k = c + 13;
            }
            temp += k;
        }else if(c >='A' && c<= 'Z'){

            if(c+13>'Z'){
                k = c+13 - 'A';
            }else{
                k = c+ 13;
            }

            temp += k;
        }
            
    }

    cout << temp;
}