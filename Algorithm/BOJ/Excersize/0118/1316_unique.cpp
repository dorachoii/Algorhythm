#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> vv {1,1,2,2,3,3,5,6,7,8,9};

int main(){
    for(int i = 1; i <=5; i++){
        v.push_back(i);
        v.push_back(i);
    }

    for(int i : v) cout << i << " ";    // {1,1,2,2,3,3,4,4,5,5}
    cout << '\n';

    auto it = unique(v.begin(), v.end());   //{1,2,3,4,5,3,4,4,5,5}
    cout << it - v.begin() << '\n';         // 5 - 0 (반복 다음 이터레이터를 반환하니까)

    for(int i : v) cout << i << " ";        
    cout << '\n';


    //
    auto itt = unique(vv.begin(), vv.end());
    for(int i : v) cout << i << " ";
    cout << '\n';                   //{1,2,3,5,6,7,8,9,7,8,9}


    return 0;
}