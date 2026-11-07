#include <iostream>
using namespace std;

int findSingle(int numbers[], int size)
{
    int result = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        result = result ^ numbers[i];
    }

    return result;
}

int main()
{
    int numbers[] = {4, 6, 9, 2, 6, 4, 2};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Non-repeating number: "
         << findSingle(numbers, size);

    return 0;
}