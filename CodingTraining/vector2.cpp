#include<iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> v2;
int main() {
    for(int i =1; i <= 10; i++) v.push_back(i);
    for(int a : v) cout << a << " ";

    cout << "\n";
    v.pop_back();

    for(int a : v) cout << a << " ";
    cout << "\n";

    v.erase(v.begin(), v.begin() + 3);

    for(int a : v) cout << a << " ";
    cout << "\n";

    auto a = find(v.begin(), v.end(), 100);
    if(a == v.end()) cout << "not found" << "\n";

    fill(v.begin(), v.end(), 10);
    for(int a : v) cout << a << " ";
    cout << "\n";
    v.clear();
    cout << "아무것도 없을까?\n";
    for(int a: v) cout << a << " ";
    cout << "\n";


    // 2번째
    for(int a : v) cout << a << " ";
    cout << "\n";
    for(int i = 0; i < v.size(); i++) cout << v[i] <<'';

    vector<pair<int, int>> v2 = {{1,2},{3,4}};
    for(pair<int, int> a: v2) cout << a.first << " ";

    vector<int> v3[10];     //10행짜리 vector

    // 2차원 배열
    int a[10][10];
    vector<int> a[10];


}