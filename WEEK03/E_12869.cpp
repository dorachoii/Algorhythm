//수빈 : 뮤탈리스크 1개
//강호 : SCV N개

// m : 1 , s : 3
// 9,3,1

#include <bits/stdc++.h>
using namespace std;

int n, hp;
vector<int> hpList;


// 세개 순서 뽑아서 감소시키고 저장하는 함수
void attack(){

    // 조합으로 3개 뽑음
    for(int i = 0; i < hpList.size()-2; i++){
        for(int j = i+1; j < hpList.size()-1; j++){
            for(int k = j+1; k < hpList.size(); k++){
                
            }
        }
    }
}


int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >>hp;
        hpList.push_back(hp);
    }



}