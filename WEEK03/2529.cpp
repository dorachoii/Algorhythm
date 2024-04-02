#include <bits/stdc++.h>
using namespace std;

vector<int> a = {0,1,2,3,4,5,6,7,8,9};
int n;
char c;
vector<char> p;
string ret;
vector<string> b;

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> c;
        p.push_back(c);
    }

    do{     

        // cout << "현재 순열은 " ;
        // for(int i : a) {cout << i;}
        // cout << endl;

        ret = "";

        if(p[0] == '<'){
            if(a[0] > a[1]) continue;
            //cout << "첫번째 요소 합격\n";
            ret += to_string(a[0]);
            ret += to_string(a[1]);
        }

        if(p[0] == '>')
        {
            if(a[0] < a[1]) continue;
            //cout << "첫번째 요소 합격\n";
            ret += to_string(a[0]);
            ret += to_string(a[1]);
        }

        for(int i = 1; i < n; i++){

            if(p[i] == '<'){
                
                if(a[i] > a[i+1]) break;           
                ret+= to_string(a[i+1]);
            }else if(p[i] == '>') {
                if(a[i] < a[i+1]) break;             
                ret+= to_string(a[i+1]);
            }
        }

        //cout << "현재 ret에 담긴 것은 " << ret <<'\n';

        if(ret.size() == n+1){
            b.push_back(ret);
        }
        
       

    }while(next_permutation(a.begin(),a.end()));


    sort(b.begin(), b.end());

    cout << b[b.size()-1]<<'\n';
    cout << b[0];
}
