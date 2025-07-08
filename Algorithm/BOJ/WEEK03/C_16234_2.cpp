#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r, ppl, a[51][51];
vector<vector<int>> adj; // 인접 리스트

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void connect(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        // 인접한 국가 간의 인구 차이가 범위 내에 있는지 확인
        if (abs(a[nx][ny] - a[x][y]) >= l && abs(a[nx][ny] - a[x][y]) <= r)
        {
            adj[x * n + y].push_back(nx * n + ny); // 좌표를 1차원으로 변환하여 노드로 사용
        }
    }
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    adj.resize(n * n); // 인접 리스트 초기화

    // 모든 좌표에 대해 연결 여부 확인
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            connect(i, j);
        }
    }

    // 인접 리스트 출력
    for (int i = 0; i < adj.size(); i++)
    {
        cout << "Node " << i << " is connected to: ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

