#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
   double num, sum = 0;
    vector<double> nums;

    for(int i = 0; i < 5; i++){
        cin >> num;
        nums.push_back(num);
        sum += num;
    }

    cout << sum/5.0 << endl;

    sort(nums.begin(), nums.end());
    cout << nums[2] << endl;
}