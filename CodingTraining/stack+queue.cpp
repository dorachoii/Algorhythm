#include <iostream>
#include <queue>
#include <stack>
using namespace std;

stack<string> stk;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stk.push("a");
    stk.push("b");
    stk.push("c");
    stk.push("d");
    stk.pop();


    for(int i = 1; i <= 10; i++) q.push(i);

    while(q.size()){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}