#include <iostream>
#include <vector>
using namespace std;

// New Year Chaos

void minimumBribes(vector<int> q)
{
    int count = 0;
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        if (q[i] > i + 3)
        {
            cout << "Too chaotic" << endl;
            return;
        }

        int first = q[i] - 2;

        if (first < 0)
            first = 0;

        for (int j = first; j < i; j++)
        {
            if (q[j] > q[i])
                count++;
        }
    }

    cout << count << endl;
}