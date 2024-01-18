#include <bits/stdc++.h>
using namespace std;

// {2,3,4,5,6,7,8,9} * 2 씩 걸린다
// ABC,DEF,GHI,JKL,MNO,PQRS,TUV, WXYZ, 
// 어떤 자료구조를 써야할까?

int a[8] = {3,3,3,3,3,4,3,4};
int b[8];

string input;
int ret;

int main()
{
    // 누적 배열 만들기
    int sumA = 0;

    for(int i = 0 ; i < 8; i++) {        
        sumA += a[i];
        b[i] = sumA;
        //cout << b[i] << "\n";
    }

    int k,l = 0;


    cin >> input;

    for(char m:input){
        
        //cout<<"현재 m은" << m <<'\n';

        for(int i = 0; i < 8; i++){

            k = m-65;

            if(k >=b[i]){
                continue;
            }else{
                l = i;
                //cout << "l은" << l << '\n';
                break;
            }

        }
        
        ret += l+3;
        //cout << "ret은" << ret <<'\n';
    }

    cout<< ret;


}