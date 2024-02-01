#include <bits/stdc++.h>
using namespace std;

int n;
string s, tc;

//delimiter를 끝까지 순회하며 찾아서 앞에 넣고 그만큼 자르고 뒤에 넣고.
vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos;
    string token = "";

    while((pos = input.find(delimiter))!= string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main(){

    cin >> n >> s;

    vector<string> se = split(s, "*");

    string start = se[0];
    string end = se[1];

    for(int i = 0; i < n; i++){
        cin>>tc;

        if(s.substr(0,start.length()) == start && s.substr(s.length()-end.length(),s.length()-1) == end){
            cout << "DA" << '\n';
        }else{
            cout << "NE" << '\n';
        }
    }

    

}