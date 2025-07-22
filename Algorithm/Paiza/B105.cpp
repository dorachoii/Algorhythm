#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// n : 턴 수, h,w
// 3 * n동안
// x,y 좌표, s : 정방형 길이


int main() {
    int n,h,w;
    cin >> n >> h >> w;

    int grid[h][w] ;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            grid[i][j] = 3;
        }
    }

    for(int k = 0; k < n * 3; k++){
        int current = k % 3;
        int x, y, s;
        cin >> x >> y >> s;

        for(int i = y; i< y + s ; i++){
            for(int j = x; j < x + s; j++){

                if(grid[i][j] == current) continue;
                if(i >= h || j >= w) continue;

                switch(grid[i][j]){
                    case 3: 
                        grid[i][j] = current;
                        break;
                    case 2:
                        grid[i][j] = 3 - 2 - current;
                        break;
                    case 1:
                        grid[i][j] = 3 - 1 - current;
                        break;
                    case 0:
                        grid[i][j] = 3 - 0 - current;
                        break;
                }
            }
        }
        
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 0) cnt1++;
            else if(grid[i][j] == 1) cnt2++;
            else if(grid[i][j] == 2) cnt3++;
        }
    }

    cout << cnt1 << " "<< cnt2 <<" " << cnt3 <<endl;
}
