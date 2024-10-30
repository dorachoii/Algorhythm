#include <iostream>
#include <string>
using namespace std;

string password;

// 영문, 숫자, 특수문자 구분 어떻게? 
string checkPassword(string password){
    int alphabet = 0, num = 0, special = 0;

    for(char c : password){
        if(c >= 'a' && c <= 'z'){
            alphabet++;
        }else if(c >= 'A' && c <= 'Z'){
            alphabet++;
        }else if(c >= '0' && c <= '9'){
            num++;
        }else{
            special++;
        }
    }

    if(password.length() < 8){
        if(alphabet == 0 && special == 0) return "very weak password.";
        if(num == 0 && special == 0) return "weak password.";
    }else{
        if(alphabet > 0 && num > 0 && special > 0) return "very strong password";
        if(alphabet > 0 && num > 0) return "strong weak password";
        return "";
    }

}

int main() {

    cout << "Input Password";
    cin >> password;

    cout << "The password '" + password + "' is a " + checkPassword(password);  
    
    return 0;
}