#include <vector>
#include <algorithm>
using namespace std;

// Minimum Swaps 2

int minimumSwaps(vector<int> arr)
{
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] != i + 1)
        {
            int index = arr[i] - 1;

            swap(arr[i], arr[index]);
            count++;
        }
    }

    return count;
}