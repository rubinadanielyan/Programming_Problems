
#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* arr;
    int length;
    int capacity;

    void grow()
    {
        int newCapacity = capacity * 2;
        if (newCapacity == 0)
            newCapacity = 1;

        int* temp = new int[newCapacity];

        for (int i = 0; i < length; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    DynamicArray()
    {
        arr = nullptr;
        length = 0;
        capacity = 0;
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void push_back(int value)
    {
        if (length == capacity)
            grow();

        arr[length] = value;
        length++;
    }

    void pop_back()
    {
        if (length > 0)
            length--;
    }

    int& operator[](int index)
    {
        return arr[index];
    }

    int get_size() const
    {
        return length;
    }

    int get_capacity() const
    {
        return capacity;
    }

    void print() const
    {
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    DynamicArray numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    cout << "Array: ";
    numbers.print();

    numbers.pop_back();

    cout << "After pop_back: ";
    numbers.print();

    cout << "Size: " << numbers.get_size() << endl;
    cout << "Capacity: " << numbers.get_capacity() << endl;

    return 0;
}
