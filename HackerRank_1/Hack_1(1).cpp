#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int best = INT_MIN;

    for (int r = 1; r <= 4; r++) {
        for (int c = 1; c <= 4; c++) {
            int sum = arr[r][c];

            for (int d = -1; d <= 1; d++) {
                sum += arr[r-1][c+d] + arr[r+1][c+d];
            }

            best = max(best, sum);
        }
    }

    return best;
}