#include <iostream>
#include <string>
#include <vector> // vector를 사용하기 위해 추가
#include <algorithm> // sort를 사용하기 위해 추가

using namespace std;

bool isAnagram(string a, string b) {
    // 문자열의 길이가 다르면 애너그램이 아님
    if (a.length() != b.length()) return false;

    // 벡터를 초기화
    vector<char> str(a.begin(), a.end());
    vector<char> str2(b.begin(), b.end());

    // 두 문자열을 정렬
    sort(str.begin(), str.end());
    sort(str2.begin(), str2.end());

    // 정렬된 두 문자열이 같으면 애너그램
    return str == str2;
}

int main() {
    string first, second;

    cout << "Enter two strings and I'll tell you if they are anagrams:\n";

    cout << "Enter the first string: ";
    cin >> first;

    cout << "Enter the second string: ";
    cin >> second;

    if (isAnagram(first, second)) {
        cout << "\"" + first + "\"" + " and " + "\"" + second + "\"" + " are Anagrams." << endl;
    } else {
        cout << "\"" + first + "\"" + " and " + "\"" + second + "\"" + " are not Anagrams." << endl;
    }

    return 0;
}
