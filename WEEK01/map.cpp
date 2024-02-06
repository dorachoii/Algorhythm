#include <bits/stdc++.h>
using namespace std;
//mp어떻게 탐색하는지 원리 파악
map<string, int> mp;
string a[] = {"주홍철", "이승철","박종선"};

int main({
    for(int i = 0; i <3 ; i++){
        mp.insert({a[i],i+1});
        mp[a[i]] = i+1;
    }

    cout << mp["kundol"] <<'\n';

    mp["kundol"] = 4;
    cout << mp.size() << '\n';

    mp.erase("kundol");

    auto it = mp.find("kundol");
    if(it == mp.end()){
        cout << "못찾겠네 꾀꼬리\n";
    }

    mp["kundol"] = 100;

    it = mp.find("kundol");

    if(it != mp.end()){
        cout << (*it).first << " : " << (*it).second << '\n';
    }

    for(auto it : mp){
        cout << (it).first << " : " << (it).second << '\n';
    }

    for(auto it = mp.begin(); it != map.end(); it++;){
        cout << (*it).first << " : " << (*it).second << '\n';
    }
    
    mp.clear();

    return 0;
})