#include <iostream>
using namespace std;

int fibonacci(int number)
{
    if (number == 0)
        return 0;

    if (number == 1)
        return 1;

    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << fibonacci(n);

    return 0;
}