#include <vector>
using namespace std;

// Array Manipulation

long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> numbers(n + 2, 0);

    for (int i = 0; i < queries.size(); i++)
    {
        int start = queries[i][0];
        int finish = queries[i][1];
        int value = queries[i][2];

        numbers[start] = numbers[start] + value;
        numbers[finish + 1] = numbers[finish + 1] - value;
    }

    long result = 0;
    long biggest = 0;

    for (int i = 1; i <= n; i++)
    {
        result = result + numbers[i];

        if (result > biggest)
            biggest = result;
    }

    return biggest;
}