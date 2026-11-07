#include <vector>
using namespace std;



vector<int> rotLeft(vector<int> a, int d)
{
    int n = a.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int index = i + d;

        if (index >= n)
            index -= n;

        result.push_back(a[index]);
    }

    return result;
}