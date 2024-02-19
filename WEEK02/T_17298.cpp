#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000004;
int n, a[MAX_N];
bool hasNGE;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        hasNGE = false;

        for(int j = i; j < n; j++){
            if(a[i]<a[j]){
                cout << a[j] <<" ";
                hasNGE = true;
                break;
            }
        }

        if(!hasNGE) cout << "-1" << " ";
    }
    //2중으로 하면 시간초과인가보오.
    //최대가 100만 o(n2) 시간 복잡도 100만 * 100만 너무 크네
    // 문제마다 다르지만 1억 이하, 1000만 이하정도는 괜찮은데
    // 여기는 벌써 100억이 넘어가니까.
}