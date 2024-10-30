#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a;
vector<int> v;

void insertionSort(vector<int> v){
    int key, i, j;

    for(i= 1; i < v.size(); i++){
        key = v[i];
        for(j = i - 1; j >= 0 && v[j] > key; j--){
            v[j + 1] = v[j];
        }
        v[j+1] = key;
    }
}

void quickSort(vector<int>& data, int start, int end) {  // 참조로 전달
    if (start >= end) return;
    
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && data[i] <= data[pivot]) i++;
        while (j > start && data[j] >= data[pivot]) j--;

        if (i > j) {
            swap(data[j], data[pivot]);
        } else {
            swap(data[i], data[j]);
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 0 ; i < n; i++){
        cin >> a;
        v.push_back(a);
    }

    // 방법 1: Sort
    //sort(v.begin(), v.end());

    // 방법 2: Insertion Sort : 시간 초과
    //insertionSort(v);

    // 방법 3: Quick Sort
    quickSort(v, 0, v.size() - 1);

    cout << v[k-1] << endl;    
}
