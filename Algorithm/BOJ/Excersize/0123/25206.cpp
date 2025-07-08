#include <bits/stdc++.h>
using namespace std;

//학점 * 과목 평점의 합 / 학점의 총합

string name, scoreA;
double credit, creditSum, scoreSum;

string score[] = {"A+","A0", "B+", "B0", "C+","C0","D+","D0","F"};
int k;
double score2Num[] = {4.5,4.0,3.5,3.0,2.5,2.0,1.5,1.0,0.0};

int main(){

    for (;cin >> name >> credit>> scoreA;){

        if(scoreA == "P" )continue;

        cout << "name은 " << name << '\n';
        cout << "credit은 " << credit << '\n';
        cout << "scoreA는 " << scoreA << '\n';

        creditSum += credit;

        for(int i = 0; i < 10; i++){
            if(scoreA == score[i]) {
                k = i;
            break;
            }
        }

        scoreSum += score2Num[k] *  credit;

    }

    cout << "점수 총 합은 " << scoreSum << '\n';
    cout << "학점 총 합은 " << creditSum << '\n';

    cout << scoreSum / creditSum;
        
}