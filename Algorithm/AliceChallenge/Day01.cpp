#include <bits/stdc++.h>
using namespace std;

// 이거 다시 정리하고 올리기!
// 시간 복잡도랑 아무 관련이 없더라~

int nextProblemCount(int todayCount) {
    string todayStr = to_string(todayCount);

    bool hasNext = next_permutation(todayStr.begin(), todayStr.end());
    
    if (hasNext) {
        return stoi(todayStr);
    }
    return -1;
}

int main() {
    int todayCount;
    
    cin >> todayCount;
    
    int nextCount = nextProblemCount(todayCount);
    
    if (nextCount != -1) {
        cout << nextCount << endl;
    } else {
        
    }
    
    return 0;
}