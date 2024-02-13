#include <bits/stdc++.h>
using namespace std;
string t;
char s[] = {'a','e','i','o','u'};

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    while (cin >> t)
    {
        if(t =="end") break;

        int cnt = 0;
        //1번 조건: 모음이 반드시 하나는 포함되어야 한다.
        for(char c : s){
            if (t.find(c)!= string::npos) cnt++;
        }

        if(cnt == 0) {
            cout << "<" <<t << ">" << " is not acceptable."<<'\n';
            continue;
        }

        int vowelConnect = 1;
        int consonantConnect = 1;
        char prev = '\0';
        //2번 조건 : 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
        for(char c : t){
            
            if (prev != '\0' && isVowel(prev) && isVowel(c))
            {
                vowelConnect++;
            }

            if (prev != '\0' && !isVowel(prev) && !isVowel(c))
            {
                consonantConnect++;
            }
            prev = c;

            if (vowelConnect >= 3 || consonantConnect >= 3)
            {
                cout << "<" << t << ">"
                     << " is not acceptable." << '\n';
                break;
            }
        }

        if (vowelConnect >= 3 || consonantConnect >= 3)
            continue;

        //3번 조건 : 같은 글자가 연속적으로 두번 오면 안된다.

        bool thirdConditionChecked = false;
        for(int i = 0; i < t.length()-1; i++){
            string tt = t.substr(i, 2);
            if(tt[0]== tt[1] && tt != "ee" && tt != "oo"){
                cout << "<" << t << ">"
                     << " is not acceptable." << '\n';
                     thirdConditionChecked = true;
                     break;
            }
        }

        if(thirdConditionChecked) continue;

        cout << "<" << t << ">"
             << " is acceptable." << '\n';
    }
}