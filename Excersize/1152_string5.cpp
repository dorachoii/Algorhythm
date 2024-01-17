#include <bits/stdc++.h>
using namespace std;

string t;

vector<string> split(string input, string delimiter){

    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter))!= string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos + delimiter.length());
    }
    ret.push_back(input);

    return ret;
}

vector<string> split2(const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);

    while(end != string::npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }

    result.push_back(input.substr(start));
    return result;
}


int main(){
    getline(cin,t);

    vector<string> v;
    v = split2(t," ");

    cout << v.size();
}