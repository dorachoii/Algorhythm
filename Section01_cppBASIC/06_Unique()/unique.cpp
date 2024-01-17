#include <bits/stdc++.h>
using namespace std;

// 중복된 요소 제거하는 로직(2)
// 1. map 사용, cnt (count)배열 만들기
// 2. unique 사용

map<int, int> mp;
vector<int> vv;

int main(){

    vector<int> v {1,1,2,2,3,3};


    // 1. map을 사용하는 것 {요소, 있다 없다 표시}

    for(int i:v){           // map의 value값을 있다,없다로 사용
        if(mp[i]){          // true = 1, false = 0
            continue;
        }else{
            mp[i] = 1;
        }
    }

    vector<int> ret;        // 중복 요소 제거해서 넣어줄 정답 1차원 벡터 공간
    for(auto it : mp){
        ret.push_back(it.first);
    }

    for(int i : ret) cout << i << " ";

    cout << '\n';



    // 2. unique 함수 사용 -1
    for(int i = 1; i <=5;i++){
        vv.push_back(i);
        vv.push_back(i);
    }                                       //{1,1,2,2,3,3,4,4,5,5}

    for(int i :vv) cout << i << " ";
    cout << '\n';

    auto it = unique(vv.begin(), vv.end()); //{1,2,3,4,5 << 여기까지 중복되지 않은 배열 만든 후 뒤엔 codna}
    cout << it - vv.begin() << '\n';    // unique는 0~4까지 중복되지 않은 것 채우고 그 다음 이터레이터 즉 5를 반환한다

    for(int i : vv) cout << i << " ";
    cout << '\n';


    // 3. unique 함수 사용 -2

    vector<int> vvv { 1,1,2,2,3,3,5,6,7,8,9};

    auto itt = unique(vvv.begin(), vvv.end());
    for(int i : vvv) cout << i << " ";
    cout << '\n';

    //unique는 sort와 함께 써야함.

    sort(vvv.begin(), vvv.end());

    auto ittt = vvv.erase(unique(vvv.begin(), vvv.end()),vvv.end());
    

    return 0;
}