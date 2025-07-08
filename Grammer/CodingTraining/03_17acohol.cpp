#include <iostream>
#include <string>

using namespace std;

float a,w,rF= 0.6,rM = 0.73,h;
string gender;


float BAC(float a, float w, float h, string gender){
    if(gender == "m"){
        float bac = ( a * 5.14 / w * rM) - 0.015 * h;
        return bac;
    }else{
        float bac = ( a * 5.14 / w * rF) - 0.015 * h;
        return bac;
    }
}

int main() {
    cout << "alcohol";
    cin >> a;

    cout << "weight";
    cin >> w;

    cout << "gender";
    cin >> gender;

    cout << "drinksAfter";
    cin >> h;

    if(BAC(a,w,h,gender)>=0.08){
        cout << "It is not legal for you to drive.";
        return 0;
    }

    cout << "OK";
}
