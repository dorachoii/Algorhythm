#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;

        int five = 0;
        //일단 무조건 약수 중 2의 개수가 5의 개수보다 많을 것으로 예상하고 짜봄

        for(int j = 0; j < k; k++){

            int n = j;
            //소인수 중 5의 개수
            if (n % 5 == 0){
                while (n >= 4)

                {
                    five++;
                    n /= 5;
                }
            }
            }
                 
        }

        cout << five <<'\n';
    }

    return 0;
}