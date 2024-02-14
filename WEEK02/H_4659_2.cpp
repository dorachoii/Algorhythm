#include <bits/stdc++.h>
using namespace std;
// 드디어 맞았다..

string s;
char vowel[] = {'a','e','i','o','u'};

bool isVowel(char a){
    for(char s : vowel){
        if(a == s){
            return true;
            break;
        }
    }
    return false;
}

void good(string input){
    cout << "<" << input << "> is acceptable.\n"; 
}

void bad(string input)
{
    cout << "<" << input << "> is not acceptable.\n";
}

int main(){

    while(cin >> s && s!="end"){

        //1. 모음 하나를 반드시 포함
        bool hasVowel = 0;

        for(char a : s){
            for(char b : vowel){
                if(a == b) {
                    hasVowel = true;
                    break;
                    }

            }
        }

        if(!hasVowel){
            //cout << "1번 조건 불충족" << '\n';
            bad(s);
            continue;
        }

        //2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다

        bool isConnect = false;
        if(s.size() > 2){
            for(int i = 0; i < s.size() - 2;i++){
                //여기 조건식 합치면 안되었던 이유
                if ((isVowel(s[i]) && isVowel(s[i + 1]) && isVowel(s[i + 2])) )
                {
                    //cout << "모두 모음" <<'\n';
                    isConnect = true;
                    break;
                }

                if( !isVowel(s[i]) && !isVowel(s[i + 1]) && !isVowel(s[i+2])){
                    //cout << "모두 자음" << '\n';
                    isConnect = true;
                    break;
                }
            }
        }

        if(isConnect) {
            //cout << "2번 조건 불충족"<<'\n';
            bad(s);
            continue;}


        //3. 같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용한다.
        bool isDouble = false;

        if(s.size() > 1){
            for(int i = 0; i < s.size() -1; i++){
                if(s[i] == s[i+1] && s[i] != 'e' && s[i] != 'o'){
                    isDouble = true;
                    break;
                }
            }
        }

        if(isDouble){
            //cout << "3번 조건 불충족"<<'\n';
            bad(s);
            continue;
        }

        good(s);

    }

}