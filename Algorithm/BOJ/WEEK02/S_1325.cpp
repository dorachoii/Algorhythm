#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;

vector<pair<int, int>> ret;
vector<int> computerN;

vector<int> adj[10004];
bool visited[10004];

int hack(int node)
{
    int cnt = 1;
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]])
            continue;
        cnt += hack(adj[node][i]);
    }
    return cnt; 
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> v >> u;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        // 초기화 잘 해주기
        memset(visited, false, sizeof(visited));

        if (!visited[i])
        {
            int k = hack(i);    //무슨 차이지, 한번 돌리면 memset안되니까 결과가 다르지.
            
            //cout << "현재 방문 노드는 " << i << '\n';
            //cout << "방문 노드로 부터 해킹한 컴퓨터는 " << k << "대\n";
            
            ret.push_back({k, i});
        }
    }

    for(int i = 0; i < ret.size(); i++){
        //cout << ret[i].first << "," << ret[i].second<<'\n';
    }

    // ret<해킹가능한 컴퓨터 대수, 컴퓨터 번호>
    sort(ret.begin(), ret.end(), greater<pair<int, int>>());

    for (int i = 0; i < ret.size(); i++)
    {
        //cout <<"정렬 후 \n";
        //cout << ret[i].first << "," << ret[i].second << '\n';
    }

    int max_hack_cnt = ret[0].first;//여기가 4가 되어야 해..
    //cout << "해킹할 수 있는 최대 컴퓨터는 " << max_hack_cnt <<'\n';

    for (int i = 0; i <ret.size() ; i++)
    {
        if (ret[i].first == max_hack_cnt)
        {
            //cout << ret[i].first <<"대 해킹할 수 있는 컴퓨터의 번호는 " << ret[i].second <<'\n';
            computerN.push_back(ret[i].second);
        }
    }

    sort(computerN.begin(), computerN.end());

    for (int a : computerN)
        cout << a << " ";

    return 0;
}
//테스트 통과는 했음