#include <bits/stdc++.h>
using namespace std;

int n;

void go(,int size){

    int half = size / 2;
    vector<vector<int>> a1;
    vector<vector<int>> a2;
    vector<vector<int>> a3;
    vector<vector<int>> a4;
    bool flag = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (tmp != v[i][j])
            {
                flag = 1;
            }
        }
    }

    if (flag)
    { // 안같으면
        for (int i = 0; i < half; i++)
        {
            vector<int> temp1;
            vector<int> temp2;
            vector<int> temp3;
            vector<int> temp4;

            for (int j = 0; j < half; j++)
            {
                temp1.push_back(v[i][j]);
                temp2.push_back(v[i][j + half]);
                temp3.push_back(v[i + half][j]);
                temp4.push_back(v[i + half][j + half]);
            }
            a1.push_back(temp1);
            a2.push_back(temp2);
            a3.push_back(temp3);
            a4.push_back(temp4);
        }

        cout << "(";
        go(a1, half);
        go(a2, half);
        go(a3, half);
        go(a4, half);
        cout << ")";
        return;
    }
}

int main(){
    cin >> n;
    

}
