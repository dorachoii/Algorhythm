#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // rand()와 srand()를 사용하기 위해 추가
#include <ctime>    // time()을 사용하기 위해 추가

using namespace std;
string name;
    vector<string> names;
    
int main() {
    

    // 난수 생성을 위한 초기화
    srand(static_cast<unsigned int>(time(0)));

    cout << "대회 참가자 이름을 입력하세요 (아무것도 입력하지 않고 엔터를 누르면 종료):" << endl;

    while (true) {
        cout << "이름 입력: ";
        getline(cin, name); // getline을 사용하여 공백을 포함한 이름을 받을 수 있음

        if (name.empty()) { // 입력이 비어있으면 루프 종료
            break;
        }
        
        names.push_back(name); // 이름을 벡터에 추가
    }

    if (!names.empty()) { // 참가자가 있을 때만 랜덤 선택
        int randomNum = rand() % names.size();
        cout << "수상자는... " << names[randomNum] << "입니다!" << endl;
    } else {
        cout << "입력된 이름이 없습니다." << endl;
    }

    return 0;
}
