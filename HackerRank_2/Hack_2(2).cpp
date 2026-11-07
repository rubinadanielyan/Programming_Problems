#include <string>
using namespace std;

int countingValleys(int steps, string path)
{
    int height = 0;
    int count = 0;

    for (int step = 0; step < steps; step++)
    {
        if (path[step] == 'U')
        {
            height++;

            if (height == 0)
                count++;
        }
        else
        {
            height--;
        }
    }

    return count;
}