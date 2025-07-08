#include <bits/stdc++.h>
using namespace std;

int M,N;
int sum;
bool isPrime;

vector<int> k;

int main(){     //flag 쓰는 노하우
    
    cin >> M >> N;

    if(M == 1) M++;

    for(int i = M ; i <= N ; i++){

        isPrime = true;

        for(int j = 2; j <M; j++){
            if(i % j == 0){
                isPrime = false;
                break;                
            }      
        }

        if(isPrime)
        {
            k.push_back(i);
            sum += i;
        }
    }

    if(k.empty()){
        cout << -1;    
    }
    else
    {
        cout << sum<< '\n';
        cout << k[0];
    }
}