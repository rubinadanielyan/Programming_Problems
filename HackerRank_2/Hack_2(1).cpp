#include <vector>
#include <algorithm>
using namespace std;

int sockMerchant(int n, vector<int> ar)
{
    sort(ar.begin(), ar.end());

    int pairs = 0;

    for (int i = 1; i < n; i++)
    {
        if (ar[i] == ar[i - 1])
        {
            pairs++;
            i++;
        }
    }

    return pairs;
}