#include <iostream>
using namespace std;

int arraySum(int arr[3][3], int i, int j, int mSize ) {
    if (i == 0 && j == 0) {
        return arr[i][j]; // condition 3
    }
    if (j == 0) {
        return arr[i][j] + arraySum(arr, i - 1, mSize, mSize); // condition 2
    }
    else {
        return arr[i][j] + arraySum(arr, i, j - 1, mSize); // condition 1
    }
}
int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << arraySum(arr, 2, 2, 2) << endl;
    return 0;
}
/*
 * arr: 2d array data
 * i = current row index(will start from rowSize - 1)
 * j = current column index(will start from columnSize - 1)
 * mSize = Column Size
*/
