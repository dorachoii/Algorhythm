#include <bits/stdc++.h>
using namespace std;
// there가 없고 here만 있는 경우

int n, r, temp, root;
vector<int> adj[54];

int dfs(int here)   // 리프노드의 수를 구하는 함수
{
    int ret = 0;
    int child = 0;
    for (int there : adj[here])
    {
        if (there == r)
            continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0)
        return 1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == -1)
            root = i;
        else
            adj[temp].push_back(i);
    }

    cin >> r;

    if (r == root)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}
