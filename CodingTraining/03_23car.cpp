#include <iostream>
#include <string>
using namespace std;

string answer;
int main() {
    cout << "열쇠를 꽂고 돌렸을 때 차가 조용한가?";
    cin >> answer;

    if(answer == "y"){
        cout <<"배터리 단자가 부식되었는가?";
        cin >> answer;

        if(answer == "y"){
            cout <<"단자를 깨끗하게 하고 다시 시도하라";
        }else{
            cout <<"케이블을 교체하고 다시 시도하라";
        }

    }else{
        cout << "차에서 달깍거리는 소리가 나는가?";
        cin >> answer;

        if(answer == "y"){
            cout << "배터리를 교체하고 다시 시도하라";
        }else{
            cout << "시동이 완전히 걸리지 않는가?";
            cin >> answer;
            if(answer == "y"){
                cout << "점화 플러그 연결 상태를 점검하라.";
            }else{
                cout << "엔진이 동작한 후 바로 꺼지는가?";
                cin >> answer;
                if(answer == "y"){
                    cout << "차에 연료 분사 장치가 있는가?";
                    cin >> answer;
                        if(answer == "y"){
                            cout << "초크가 제대로 여닫히는지 확인하라.";
                        }else{
                            cout << "서비스 센터에 의뢰하라.";
                        }
                }else {
                    cout << "x";
                }
            }
        }
    }

}


switch(){
    case 0: ; break;
}
vector<int> a; 
a.push_back(num);