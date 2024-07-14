#include <iostream>
#include <vector>

using namespace std;

//오름차순 정렬
//k번째 숫자 선택

int n, m;
int a[10004];
vector<int> v;
int b,c,k;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
   

    for(int i = 0; i < m; i++){
        v.clear();
        cin >> b >> c >> k;

        for(int j = b; j < c; j++){
            v.push_back(a[j]);
        }

        sort(v.begin(), v.end());
        cout << v[k] <<'\n';
    }
}
