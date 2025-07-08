#include <iostream>
#include <vector>
using namespace std;

// 재귀적으로 사분면 처리
string quadTree(vector<vector<int>> &arr, int size)
{
    if (size == 1)
    {
        return to_string(arr[0][0]);
    }

    vector<vector<int>> subarrays[4];
    int newSize = size / 2;

    // 4개의 사분면 생성
    for (int i = 0; i < 4; ++i)
    {
        subarrays[i].resize(newSize, vector<int>(newSize));
    }

    // 사분면에 해당하는 값 할당
    for (int i = 0; i < newSize; ++i)
    {
        for (int j = 0; j < newSize; ++j)
        {
            subarrays[0][i][j] = arr[i][j];
            subarrays[1][i][j] = arr[i][j + newSize];
            subarrays[2][i][j] = arr[i + newSize][j];
            subarrays[3][i][j] = arr[i + newSize][j + newSize];
        }
    }

    // 각 사분면 검사
    string result = "(";
    for (int i = 0; i < 4; ++i)
    {
        string quad = quadTree(subarrays[i], newSize);
        if (quad == "0" || quad == "1")
        {
            result += quad;
        }
        else
        {
            result += "(" + quad + ")";
        }
    }
    result += ")";
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }

    string compressed = quadTree(arr, n);
    cout << compressed << endl;

    return 0;
}
