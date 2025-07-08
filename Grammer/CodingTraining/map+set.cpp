#include <iostream>
#include <map>
#include <set>

using namespace std;

// map: key-value쌍, 자동 오름차순 정렬
// set: 중복을 허용하지 않음, 자동 오름차순 정렬

map<string, int> mp;
string a[] = {"A", "B", "C"};

int main() {
    for(int i = 0; i <3; i++){
        mp.insert({a[i], i+1});
        mp[a[i]] = i+1;
    }

    cout << mp["D"] << '\n';
    mp["D"] = 4;
    cout << mp.size() <<'\n';
    mp.erase("D");

    mp["D"] = 100;

    for(auto it : mp){
        cout << (it).first << " : " << (it).second << '\n';
    }

    //set
    set<pair<string, int>> st;
    st.insert({"test",1});
    st.insert({"test",1});
    st.insert({"test",1});
    cout << st.size() << "\n";
}