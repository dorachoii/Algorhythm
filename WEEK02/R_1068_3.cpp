#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[51];
bool removed[51];

int countLeafNodes(int node)
{
    if (adj[node].empty()) // 자식이 없는 경우
        return 1;

    int cnt = 0;
    for (int child : adj[node])
    {
        if (!removed[child]) // 지워지지 않은 자식만 고려
            cnt += countLeafNodes(child);
    }
    return cnt;
}

int main()
{
    cin >> n;

    int root = -1; // 루트 노드 찾기
    for (int i = 0; i < n; ++i)
    {
        int parent;
        cin >> parent;
        if (parent == -1)
        {
            root = i;
        }
        else
        {
            adj[parent].push_back(i);
        }
    }

    cin >> k;
    removed[k] = true; // 주어진 노드를 제거했다고 표시

    if (root != k)
    { // 루트 노드가 아니면
        int parent = -1;
        for (int i = 0; i < n; ++i)
        {
            if (find(adj[i].begin(), adj[i].end(), k) != adj[i].end())
            {
                parent = i;
                break;
            }
        }
        adj[parent].erase(find(adj[parent].begin(), adj[parent].end(), k)); // 부모 노드에서 주어진 노드 제거
    }

    cout << countLeafNodes(root) << endl; // 남은 트리에서 리프 노드의 개수 출력

    return 0;
}
