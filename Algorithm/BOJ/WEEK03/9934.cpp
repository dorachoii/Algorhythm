#include <bits/stdc++.h>
using namespace std;

int h, n, k = 2, dir = 1;
int sum = 1;
vector<int> node; 
vector<int> tree[10];

void trees(){
    for(int i = 0 ; i <= sum ; i++){

        //cout << i << "번째 검사중\n";

        if(i % 2 == 1){
            //cout << "홀수번째여서 0층";
            tree[0].push_back(node[i]);

        }else if(i % 4 == 0){
            k += dir;

            if(k == h || k == 0){
                dir *= -1;
            }

            tree[k].push_back(node[i]);

        }else{

            tree[1].push_back(node[i]);
        }
    }
}




int main(){

    cin >> h;
    
    
    int two = 1;

    for(int i = 1; i < h; i++ ){
        two *= 2;
        sum += two;
    }

    node.push_back(0);

    for(int i = 0; i < sum; i++){
        cin >> n;
        node.push_back(n);
    }

    trees();

    for(int i = h-1; i >= 0; i--){

        for(int a : tree[i]){
            cout << a << " ";
        }

        cout <<'\n';
    }

}