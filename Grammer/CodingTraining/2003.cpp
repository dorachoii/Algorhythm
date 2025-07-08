#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m, a;
vector<int> v;

int sum(int s, int e){
    int sum = 0;
    for(int i = s; i <= e; i++){
        sum += v[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m ;
    

    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }

    int start, end, cnt = 0;

    for(int i = 0; i < v.size() -1; i++){
        start = i;

        for(int j = i; j < v.size(); j++){
            end = j;
            if(sum(start, end) == m){
                cnt++;
            }
        }
    }

    cout << cnt;
}
