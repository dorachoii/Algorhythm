#include <bits/stdc++.h>
using namespace std;

// 1. 2명을 선택해서 뺐을 때 100이 된다?

int h[9],sum;
int n,k;

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> h[i];
        sum += h[i];
    }

    for(int i = 1; i < 9; i++){
        for(int j = 0; j < i; j++){
            if(sum - h[j]-h[i] == 100){
                n=j;
                k=i;
            }
        }
    }

    // 배열 remove 메소드 모름..
    h[n] = 0;
    h[k] = 0;

    sort(h,h+9);

    for(int i = 2; i < 9; i++){
        cout << h[i] << '\n'; 
    }
}