#include <bits/stdc++.h>
using namespace std;

int n ;
string s;
queue<int> mul;

int cal(string s)
{
    // *를 만나면 먼저 계산해서 그부분을 계산값으로 치환해주고 +,- 계산
    string pm = "";
    bool isfrontMul = false;

    for (int i = 0; i < s.size(); i++)
    {

        pm += s[i];
        // cout << "현재 pm에 쌓인 것은 " << pm <<'\n';

        if (s[i] == '*')
        {
            // cout << i << "번째 문자가 *이라서 곱해주겠다.\n";

            int a = s[i - 1] - '0';
            int b = s[i + 1] - '0';

            int k = a * b;
            // cout << "곱한 값은 " << k <<'\n';
            mul.push(k);

            pm = pm.substr(0, pm.size() - 2);
            // cout << "끝에 두글자를 빼면 " << pm <<'\n';

            pm += 'k';
            // cout << "곱한 값을 축적한 뒤 pm에  쌓인 것은 " << pm <<'\n';
            isfrontMul = true;
        }
        else
        {

            if (isfrontMul)
            {
                pm = pm.substr(0, pm.size() - 1);
                // cout << "이전이 곱셈 기호였기 때문에 끝자리 하나 빼면 " << pm << '\n';

                isfrontMul = false;
            }
        }
    }

    // cout << "곱셈 처리를 해준 뒤 식은 " << pm <<'\n';

    int ret = pm[0] - '0';

    if (pm[0] == 'k')
    {
        ret = mul.front();
        mul.pop();
    }

    // cout << "첫 숫자는 " << ret << '\n';

    int num = 1;

    for (int i = 2; i < pm.size(); i += 2)
    {

        if (pm[i] == 'k')
        {

            num = mul.front();
            // cout << i << "번째 숫자는 q에서 꺼내서" << num << '\n';
            mul.pop();
        }
        else
        {
            num = pm[i] - '0';
            // cout << i << "번째 숫자는 " << num << '\n';
        }

        if (pm[i - 1] == '-')
        {
            ret -= num;
            // cout << "- 기호를 만나서 결과값은 " << ret << '\n';
        }

        if (pm[i - 1] == '+')
        {
            ret += num;
            // cout << "+ 기호를 만나서 결과값은 " << ret << '\n';
        }
    }

    // cout << "최종 결과는 " << ret << '\n';
    return ret;
}

int bracket(string s){

    cout << "현재 s는 " << s <<'\n';

    int ret = 1;
    int retMx = INT_MIN;

    for(int i = 0; i < s.size()-3; i+=2){
        for(int j = i+2; j < s.size(); j+=2){

            //cout << "괄호를 " << i << "부터 "<<j<<"까지 해줄 것"<<'\n';

            string frt = s.substr(i, j-i+1);
            ret = cal(frt);

            //cout << "괄호쳐서 자른 앞부분은 " << frt << "이고 계산값은 " << ret << '\n';

            if(s.size() != 1){
                char op = s[j + 1];
                string bck = s.substr(j + 2);

                //cout << "괄호 사이 낀 연산자는 " << op << '\n';
                //cout << "괄호쳐서 자른 뒷부분은 " << bck << '\n';

                if(op == '*'){
                    
                    ret*= bracket(bck);
                    //cout << "연산자가 *이라 " << ret << '\n';
                }else if(op == '+'){
                    ret+= bracket(bck);
                    //cout << "연산자가 +이라 " << ret << '\n';
                }else if(op == '-'){
                    ret-= bracket(bck);
                    //cout << "연산자가 -이라 " << ret << '\n';
                }
            }else{
                char op = s[j - 1];

                if (op == '*')
                {

                    ret *= cal(s);
                    //cout << "연산자가 *이라 " << ret << '\n';
                }
                else if (op == '+')
                {
                    ret += cal(s);
                    //cout << "연산자가 +이라 " << ret << '\n';
                }
                else if (op == '-')
                {
                    ret -= cal(s);
                    //cout << "연산자가 -이라 " << ret << '\n';
                }
            }

            retMx = max(ret, retMx)  ;
            //cout << "연산 결과값의 최대는 " << retMx << '\n';
        }
    }

    return retMx;
}






int main(){
    cin >> n >> s;
    cout << bracket(s);
}