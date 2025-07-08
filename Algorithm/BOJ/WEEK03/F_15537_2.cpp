#include <bits/stdc++.h>
using namespace std;

int n; 
string s;

// int bracket(string s){
//     string temp = s;

//     for(int i = 0; i < temp.size()-3; i+2){
//         for(int j = i + 2; j < temp.size(); j+2){

//             string frt = temp.substr(i,j-i+1);
//             string op = temp[j+1];
//             string bck = temp.substr(j+2);

//             bracket(bck);
//         }
//     }
// }

// 문자 넣으면 연산해주는 함수
// 문자를 연산기호로 바꾸는 건 어떻게 해야하지.
int cal (string s){
    int ret = s[0] -'0';
    int num = 1;

    for(int i = 1; i < s.size(); i++){
        if(i%2 == 0){
            num = s[i] - '0';
        }else{
            if(s[i] == '*'){                
                ret *= num;
            }else if(s[i] == '+'){
                ret += num;
            }else if(s[i] == '-'){
                ret -= num;
            }
        }
    }

    return ret;
}


int main(){
    cin >> n >> s;
    cout << cal(s);
}