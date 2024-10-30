#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// push_back, pop_back
// clear
// sort, reverse
// erase

vector<int> a;

void printVector(vector<int> v){
    cout << "{";
    for(int a : v){
        cout << to_string(a) + " ";
    }
    cout << "}\n";
}

int main() {

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    // {1,2,3,4,5}
    printVector(a);

    a.pop_back();
    // {1,2,3,4}
    printVector(a);

    a.clear();
    //{}
    printVector(a);

    a.push_back(3);
    a.push_back(1);
    a.push_back(7);
    a.push_back(5);
    // {3,1,7,5}
    printVector(a);

    sort(a.begin(),a.end());
    // {1,3,5,7}
     printVector(a);

    sort(a.rbegin(), a.rend());
    // {7,5,3,1}
     printVector(a);

      reverse(a.begin(), a.end());
    // {1,3,5,7}
     printVector(a);

    a.erase(a.begin() + 2);
    // {1,3,7}
     printVector(a);
}