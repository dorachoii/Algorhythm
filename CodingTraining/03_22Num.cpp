#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> nums;
int a;

int main() {

    cout << "Enter the first number: ";
    cin >> a;
    nums.push_back(a);

    cout << "Enter the second number: ";
    cin >> a;
    nums.push_back(a);

    cout << "Enter the third number: ";
    cin >> a;
    nums.push_back(a);

    sort(nums.begin(), nums.end());

    cout << "The largest number is " + to_string(nums[nums.size()-1]);

}