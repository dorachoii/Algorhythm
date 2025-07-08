#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

using namespace std;

int stage, randomNum, tryCnt = 0, guessNum = 0;

int main() {
    // 시드 초기화
    srand(static_cast<unsigned int>(time(0)));

    cout << "원하는 단계를 입력하시오.(1~3): ";
    cin >> stage;

    switch(stage) {
        case 1:
            randomNum = rand() % 10 + 1; // 1~10
            break;

        case 2: 
            randomNum = rand() % 100 + 1; // 1~100
            break;

        case 3: 
            randomNum = rand() % 1000 + 1; // 1~1000
            break;

        default:
            cout << "비빔" << endl;
            return 1; 
    }

    while(guessNum != randomNum) {
        cout << "Guess! " << tryCnt + 1<< "번째 시도입니다." << endl;
        cin >> guessNum;
        tryCnt++;
    }

    cout << "정답입니다! " << tryCnt + 1<< "번 만에 맞혔습니다." << endl;

    return 0;
}
