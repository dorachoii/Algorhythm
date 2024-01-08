#include <bits/stdc++.h>
using namespace std;

int main(){

    //*** 예제 1.
    int a[] = {1,2,3};  //2,1,3으로 순서를 바꾸면 결과가 제대로 나오지 않음

    // vector<int> a = {2,1,3};
    // 순열을 사용할 때는 꼭 정렬을 이용 sort
    // sort(a.begin(), a.end());

    do{
        for(int i : a) cout << i << " ";
        cout << '\n';
    } // while(next_permutation(&a[0], &a[0] + 3));

    while(next_permutation(a, a+ 3));
    //while(next_permutation(a.begin(), a.end()));

    //*** 예제 2.
    vector<int> b = {2,1,3,100,200};
    sort(b.begin(),b.end());

    do{
        for(int i = 0; i<2;i++){
            cout << b[i] << " ";
        }
        cout << '\n';
    }while (next_permutation(b.begin(),b.end()));

    //왜 중복이 되나?

    return 0;
}