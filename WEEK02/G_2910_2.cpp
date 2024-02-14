#include <bits/stdc++.h>
using namespace std;

// 어휴, 2차원 배열로 하려니 머리가 터지겠음. map으로 key value로 다시 해보겠다.

// c가 주어지는 이유가 뭘까나

int n, c, k;
vector<int> a;  // 입력 배열
int b[1004][2]; // b[값][개수]

vector<int> cc; // 해당 개수의 요소들 저장할 벡터

int main()
{

    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        a.push_back(k);
    }

    // b[값][개수]
    for (int i = 0; i < a.size(); i++)
    {
        int k = i;

        b[k][0] = a[i];
        b[k][1]++;

        for (int j = 0; j < i; j++)
        {
            if (b[j][0] == a[i])
            {
                b[i][1]++;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j<2; j++){
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }

    // mx 값 부터 하나씩 줄여가며 탐색
    int mx = 0;

    for (int i = 0; i < c + 1; i++)
    {
        mx = max(mx, b[i][1]);
    }

    while (mx > 0)
    {
        for (int i = 0; i < 1004; i++)
        {
            if (b[i][1] == mx)
            {
                for (int k = 0; k < mx; k++)
                {
                    cout << b[i][0] << " ";
                    break;
                }
            }
        }

        mx--;
    }
}
// 인덱스 값을 쓰려니