#include <iostream>
#include <cstdlib>
using namespace std;

int globalValue = 100;

int& getStaticValue()
{
    static int value = 10;
    return value;
}

int* createArray(int size)
{
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = i * 10;

    return arr;
}

int main()
{
    int localValue = 50;
    static int staticValue = 200;
    const int constantValue = 300;

    int* dynamicValue = new int(400);
    int* array = createArray(5);

    cout << "Global: " << globalValue << endl;
    cout << "Local: " << localValue << endl;
    cout << "Static: " << staticValue << endl;
    cout << "Constant: " << constantValue << endl;
    cout << "Dynamic: " << *dynamicValue << endl;

    cout << "\nArray: ";
    for (int i = 0; i < 5; i++)
        cout << array[i] << " ";

    getStaticValue() += 50;

    cout << "\nStatic function value: "
         << getStaticValue() << endl;

    delete dynamicValue;
    delete[] array;

    return 0;
}