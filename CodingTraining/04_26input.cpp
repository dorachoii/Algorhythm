#include <iostream>
#include <string>
#include <cctype> // for isdigit

using namespace std;

bool isValidEmployeeID(const string& id) {
    // 길이가 7인지 확인 (AA-1234)
    if (id.length() != 7) {
        return false;
    }
    
    // 첫 두 문자가 알파벳인지 확인
    if (!isalpha(id[0]) || !isalpha(id[1])) {
        return false;
    }
    
    // 세 번째 문자가 하이픈인지 확인
    if (id[2] != '-') {
        return false;
    }
    
    // 마지막 네 문자가 숫자인지 확인
    for (int i = 3; i < 7; ++i) {
        if (!isdigit(id[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    string firstName, lastName, zipCode, employeeID;
    bool hasError = false;

    cout << "Enter the first name: ";
    getline(cin, firstName);

    cout << "Enter the last name: ";
    getline(cin, lastName);

    cout << "Enter the ZIP code: ";
    getline(cin, zipCode);

    cout << "Enter an employee ID: ";
    getline(cin, employeeID);

    // 이름 체크
    if (firstName.empty()) {
        cout << "The first name must be filled in." << endl;
        hasError = true;
    } else if (firstName.length() < 2) {
        cout << "\"" << firstName << "\" is not a valid first name. It is too short." << endl;
        hasError = true;
    }

    // 성 체크
    if (lastName.empty()) {
        cout << "The last name must be filled in." << endl;
        hasError = true;
    } else if (lastName.length() < 2) {
        cout << "\"" << lastName << "\" is not a valid last name. It is too short." << endl;
        hasError = true;
    }

    // 우편번호 체크
    if (zipCode.empty() || !all_of(zipCode.begin(), zipCode.end(), ::isdigit)) {
        cout << "The ZIP code must be numeric." << endl;
        hasError = true;
    }

    // 사번 체크
    if (!isValidEmployeeID(employeeID)) {
        cout << employeeID << " is not a valid ID." << endl;
        hasError = true;
    }

    // 오류가 없으면 성공 메시지 출력
    if (!hasError) {
        cout << "There were no errors found." << endl;
    }

    return 0;
}
