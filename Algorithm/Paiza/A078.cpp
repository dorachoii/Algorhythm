#include <iostream>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

int h;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> chunk;

void dfs(char a, int x, int y){
    visited[x][y] = true;
    chunk.push_back({x,y});

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= h || ny < 0 || ny >= h || grid[nx][ny] != a || visited[nx][ny]) continue;
        dfs(a, nx,ny);
    }
}

void eraseChunk(){
    for(int i = 0; i < chunk.size(); i++){
        int x = chunk[i].first;
        int y = chunk[i].second;
        grid[x][y] = '.';
    }
}

void drop() {
    for (int col = 0; col < 5; ++col) {          
        int target_row = h - 1;                   

        for (int row = h - 1; row >= 0; row--) { 
            if (grid[row][col] != '.') {
                grid[target_row][col] = grid[row][col]; 
                if (target_row != row)
                    grid[row][col] = '.';              
                target_row--;
            }
        }

        for (int row = target_row; row >= 0; row--) {
            grid[row][col] = '.';
        }
    }
}




int main() {
    cin >> h;

    grid = vector<vector<char>>(h, vector<char>(h));
    
    // 입력
    for(int i = 0; i< h; i++){
        string s;
        cin >> s;

        for(int j = 0; j < h; j++){
            grid[i][j] = s[j];
        }
    }

    // 가능하다면, 연결 요소 찾아서 지우기
    while(true){

        bool exploded = false;
        visited = vector<vector<bool>>(h, vector<bool>(h, false));

        for(int i = 0; i < h; i++){
        for(int j = 0; j < h; j++){

            if(isdigit(grid[i][j])&& !visited[i][j]){
                chunk.clear();
                dfs(grid[i][j],i,j);

                if(chunk.size() >= 3){
                    eraseChunk();
                    exploded = true;
                }
            }
        }
    }
    if(!exploded) break;
    // 지우기
    drop();
    }
    

    // 출력
    for(int i = 0; i < h; i++){
        for(int j = 0; j < h; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }


}
