#include <bits/stdc++.h>
using namespace std;

int a[9];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //01. permutation으로 푸는 방법
    for(int i = 0; i < 9; i++){
        cin >> a[i];
    }

    sort(a,a+9);

    do{
        for(int i : a) cout << i << " ";
        cout << '\n';

        int sum = 0;

        for(int i = 0; i < 7; i++) sum += a[i];

        if(sum == 100)break;
    }

#include <bits/stdc++.h>
    using namespace std;

    int a[9];

    int main()
    {
        for (int i = 0; i < 9; i++)
        {
            cin >> a[i];
        }
        sort(a, a + 9);

        do
        {
            if (accumulate(a, a + 7, 0) == 100)
                break;
        } while (next_permutation(a, a + 9));

        for (int i = 0; i < 7; i++)
        {
            cout << a[i] << '\n';
        }
    }
}