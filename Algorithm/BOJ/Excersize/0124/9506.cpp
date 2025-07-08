
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nn;

int main(){

    while(cin >> n){    // 입력 두 번씩 받지 않게?

        if(n == -1) break;
        
        int sum = 0;

        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                nn.push_back(i);
                sum += i;
            }
        }
        // cout << "sum은 " << sum;

        if (sum == n)
        {
            cout << n << " = ";

            for (int i = 0; i < nn.size() - 1; i++)
            {
                cout << nn[i] << " + ";
            }

            cout << nn.back() << '\n'; // nn[nn.size()]인 이유?
        }
        else
        {
            cout << n << " is NOT perfect." << '\n';
        }

        nn.clear();
    }

    

    

}