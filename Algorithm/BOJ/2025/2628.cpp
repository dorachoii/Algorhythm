#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int w, h, n, cuttingIdx;
    bool isRightCut;
    vector<int> heights = {0};
    vector<int> weights = {0}; 

    cin >> w >> h >> n;
    heights.push_back(h);
    weights.push_back(w);

    for(int i = 0; i < n; i++){
        cin >> isRightCut >> cuttingIdx;
        if(isRightCut == 1) weights.push_back(cuttingIdx);
        else heights.push_back(cuttingIdx);
    }

    sort(heights.begin(), heights.end());
    sort(weights.begin(), weights.end());

    int maxArea = 0;

    for(int i = 0; i < heights.size()-1; i++){
        int height = heights[i+1] - heights[i];
        for(int j = 0; j < weights.size()-1; j++){
            int weight = weights[j+1] - weights[j];
            maxArea = max(maxArea, height * weight);
        }
    }

    cout << maxArea;
}