// 0~9까지 1세트 : 6 <-> 9 서로 체인지 가능
// N 주어지면 몇 세트 필요한지!

#include <bits/stdc++.h>
using namespace std;

// string s;
// int cnt;
// bool a[1000004];

// int main()
// {
//     // cin >> s;

//     // while (!s.empty())
//     // {
//     //     // 0~ 9까지 돌아가면서
//     //     for (int i = 0; i <= 9; i++)
//     //     {
//     //         vector<int> v;
//     //         for (int j = 0; j < s.length(); j++)
//     //         {
//     //             if (s[j] == i)
//     //             {
//     //                 s[j] = 'a';
//     //             }
//     //         }

//     //         cnt++;
//     //     }
//     // }

//     // // 6에다가 2번 카운트해주는 식으로!
    
//     // // for (int i = 0; i <= 9; i++)
//     // // {
//     // //     for (int j = 0; j < s.length(); j++)
//     // //     {
//     // //         if (s[j] == i)
//     // //         {
//     // //             a[j] = false;
//     // //         }
//     // //     }
//     // //     cnt++;
//     // // }

//     // cout << cnt;


// }

int main() {
    string a = "love is";
    a += " pain!";
    a.pop_back();
    cout << a << " : "<< a.size() << "\n";
}