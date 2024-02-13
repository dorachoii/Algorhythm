#include <bits/stdc++.h>
using namespace std;
const int max_n = 64;
int n, a[max_n][max_n];

string ret;

void quadTree(int n){

    if(n == 1) return;
    n/=2;

    int x[n][n];
    int y[n][n];
    int z[n][n];
    int w[n][n];
    
    //4분할
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            x[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = n; j < n*2; j++){
            y[i][j] = a[i][j];
        }
    }

    for(int i = n; i < n *2; i++){
        for(int j = 0; j < n ; j++){
            z[i][j] = a[i][j];
        }
    }

    for(int i = n; i < n * 2; i++){
        for(int j = 0; j < n; j++){
            w[i][j] = a[i][j];
        }
    }

    

    // 검사
    
   
        ret += "(";

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(x[i][j]){
                    cnt++;
                }
            }
        }

        if(cnt == n*n){
            ret += "1";

        }else if(cnt == 0){
            ret += "0";

        }else{
            quadTree(n/2);
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (y[i][j])
                {
                    cnt++;
                }
            }
        }

        if (cnt == n * n)
        {
            ret += "1";
        }
        else if (cnt == 0)
        {
            ret += "0";
        }
        else
        {
            quadTree(n / 2);
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (z[i][j])
                {
                    cnt++;
                }
            }
        }

        if (cnt == n * n)
        {
            ret += "1";
        }
        else if (cnt == 0)
        {
            ret += "0";
        }
        else
        {
            quadTree(n / 2);
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (w[i][j])
                {
                    cnt++;
                }
            }
        }

        if (cnt == n * n)
        {
            ret += "1";
        }
        else if (cnt == 0)
        {
            ret += "0";
        }
        else
        {
            quadTree(n / 2);
        }

        ret += ")";  
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    quadTree(n);

    cout << ret;

}