#include <bits/stdc++.h>
using namespace std;

//첫글자 혹은 마지막 문자가 대문자
int N,M;
string s;
vector<string> pokemon;

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> s;
        pokemon.push_back(s);
    }

    for(int i = 0; i < M; i++){
        cin >> s;

        if((s[0]>='a'&& s[0]<='z')||(s[0]>='A'&&s[0]<='Z')){
            for(int j = 0; j <N; j++){
                if(s== pokemon[j]) cout <<j+1<<'\n';
            }
        }else{
            int k = stoi(s);
            cout << pokemon[k]<<'\n';
        }
    }

}

//시간초과