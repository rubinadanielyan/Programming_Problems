#include <iostream>
using namespace std;

double geometricProgression(double a, double q, int n)
{
    if (n == 0)
        return 0;

    return a + q * geometricProgression(a, q, n - 1);
}

int main()
{
    double a, q;
    int n;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter q: ";
    cin >> q;

    cout << "Enter n: ";
    cin >> n;

    cout << "Sum = " << geometricProgression(a, q, n);

    return 0;
}