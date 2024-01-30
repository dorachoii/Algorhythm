#include <bits/stdc++.h>
using namespace std;

int a[3] = {1,2,3};
int n = 3, r = 3;

// 배열 모든 원소 출력하는 함수
void print(){
    for(int i = 0; i < r; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

// n개 중 r개를 뽑아 순서있게 나열하는 방법
// depth: 트리의 레벨이자 높이 즉, 얼마나 뻗어나가는지.
// 아래의 코드는 depth가 0~n이 될때까지 실행

void makePermutation(int n, int r, int depth){
    if(r == depth){
        print();
        return;
    }

    for(int i = depth; i < n; i++){
        swap(a[i], a[depth]);   // 순서를 swap
        makePermutation(n,r,depth+1);
        swap(a[i], a[depth]);
    }
    return;
}

int main(){

    makePermutation(n,r,0);
    return 0;

}