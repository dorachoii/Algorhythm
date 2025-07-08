#include <bits/stdc++.h>
using namespace std;

// 벡터의 모든 원소를 출력하는 함수
// &(reference)로 전달하는 이유: vector가 클 경우 복사를 막고 원본 이용하기 위해서

void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        cout << "\n";
    }
}

int main()
{
    int a[3] = {1, 2, 3};
    vector<int> v;

    // 배열 a의 모든 원소를 벡터 v에 집어넣음.
    for (int i = 0; i < 3; i++) v.push_back(a[i]);

    // next_permutation : 순열을 생성한 후 true, 더 이상 다음 순열이 없을 때는 false 반환
    do
    {
        printV(v);
    } while (next_permutation(v.begin(), v.end()));
    // 1. printV 수행 {1,2,3}
    // 2. next_permutation 실행 후 printV 수행 ...

    cout << "-----------" << '\n';
    // 벡터 초기화
    v.clear();


    // 배열 a의 원소를 내림 차순으로 벡터 v에 집어 넣음
    for (int i = 2; i >= 0; i--) v.push_back(a[i]);

    // 내림차순으로 순열을 뽑는다.
    do
    {
        printV(v);
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}