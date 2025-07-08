#include <iostream>
#include <string>

using namespace std;

string BMI (float w, float h){
    float bmi = (w / (h * h));

    string answer = "";
    if( bmi>=18.5 && bmi <= 25){
        answer = "You are within the ideal weight range.";
    }else if(bmi > 25){
        answer = "넌 돼지!";
    }else{
        answer = "넌 멸치!";
    }
    return answer;
}

float weight, height;
int main() {
    cout << "Your weight: ";
    cin >> weight;

    cout << "Your height: ";
    cin >> height;

    // m단위라고 함
    height = height / 100;

    cout << BMI(weight, height);
    
}