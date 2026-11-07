#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {4, 1, 7, 9, 4, 6, 2, 1,
                     8, 7, 6, 2, 9, 8, 3, 5};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    int xorResult = 0;

    for (int i = size - 1; i >= 0; i--)
        xorResult ^= numbers[i];

    int differentBit = xorResult & (~(xorResult - 1));

    int number1 = 0;
    int number2 = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        if ((numbers[i] & differentBit) != 0)
            number1 ^= numbers[i];
        else
            number2 ^= numbers[i];
    }

    cout << "First number: " << number1 << endl;
    cout << "Second number: " << number2 << endl;

    return 0;
}