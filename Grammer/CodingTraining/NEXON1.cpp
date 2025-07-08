#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

int Moves(vector<int> arr) {
    int moves = 0;

    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i] % 2 == 0) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % 2) {
                    swap(arr[i], arr[j]);
                    moves++;
                    break;
                }
            }
        }
    }

    return moves;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));
        arr[i] = arr_item;
    }

    int result = Moves(arr);

    fout << result << "\n";
    fout.close();

    return 0;
}
