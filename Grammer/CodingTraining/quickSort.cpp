#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    
    cin >> n >> k;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    // 퀵 정렬을 호출하여 정렬
    quickSort(v, 0, n - 1);

    // k번째 원소 출력
    cout << v[k - 1] << endl;
    return 0;
}
