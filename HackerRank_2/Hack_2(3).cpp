#include <vector>
using namespace std;

int jumpingOnClouds(vector<int> c)
{
    int jumpsCount = 0;
    int position = 0;

    while (position < c.size() - 1)
    {
        if (position + 2 < c.size() && c[position + 2] == 0)
            position += 2;
        else
            position++;

        jumpsCount++;
    }

    return jumpsCount;
}