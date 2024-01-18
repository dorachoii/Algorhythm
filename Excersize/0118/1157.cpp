#include <bits/stdc++.h>
using namespace std;

//a: 97 이상이라면 32를 빼서 동일 취급 후 카운트
//A: 65 Z: 90

string t;

int str[150];
int strS[150];
int k;

char ret;

int main(){

    cin >> t;

    for(char c : t){
        if((int)c >96){ k = (int)c - 32; }
        else{k = (int)c;}

        str[k]++;
        strS[k]++;
    }

    // cnt가 큰 것 출력
    // 같으면 ? 출력

    vector<int> sortedStrS(strS, strS + 150);
    sort(sortedStrS.begin(), sortedStrS.end(), greater<int>());

    if (sortedStrS[0] == sortedStrS[1])
    {
        ret = '?';
    }
    else
    {
        for (int i = 0; i < 150; i++)
        {
            if (str[i] == sortedStrS[0])
            {
                ret = (char)i;
                break;
            }
        }
    }

    cout << ret;
}