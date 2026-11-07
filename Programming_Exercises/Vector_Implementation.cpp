
#include <iostream>
#include <cstdlib>
using namespace std;

class Vector
{
private:
    int* data;
    size_t size, capacity;

public:
    Vector()
    {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    Vector(const Vector& other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];

        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Vector()
    {
        delete[] data;
    }

    void reserve(size_t newCapacity)
    {
        if (newCapacity <= capacity) return;

        int* newData = new int[newCapacity];

        for (size_t i = 0; i < size; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void push_back(int value)
    {
        if (size == capacity)
            reserve(capacity * 2);

        data[size++] = value;
    }

    void pop_back()
    {
        if (size > 0) size--;
    }

    size_t ret_size() const { return size; }
    size_t ret_cap() const { return capacity; }

    int& operator[](size_t index)
    {
        if (index >= size) exit(1);
        return data[index];
    }

    const int& operator[](size_t index) const
    {
        if (index >= size) exit(1);
        return data[index];
    }

    Vector& operator=(const Vector& other)
    {
        if (this == &other) return *this;

        int* newData = new int[other.capacity];

        for (size_t i = 0; i < other.size; i++)
            newData[i] = other.data[i];

        delete[] data;
        data = newData;
        size = other.size;
        capacity = other.capacity;

        return *this;
    }

    Vector operator+(const Vector& other) const
    {
        Vector result;

        if (size != other.size) return result;

        for (size_t i = 0; i < size; i++)
            result.push_back(data[i] + other.data[i]);

        return result;
    }

    bool operator==(const Vector& other) const
    {
        if (size != other.size) return false;

        for (size_t i = 0; i < size; i++)
            if (data[i] != other.data[i]) return false;

        return true;
    }

    bool operator!=(const Vector& other) const
    {
        return !(*this == other);
    }
};

int main()
{
    Vector v1, v2;

    v1.push_back(5);
    v1.push_back(20);
    v1.push_back(100);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    Vector v3 = v1 + v2;
    Vector v4;
    v4 = v1;

    cout << "v1: ";
    for (size_t i = 0; i < v1.ret_size(); i++)
        cout << v1[i] << " ";

    cout << "\nv1 + v2: ";
    for (size_t i = 0; i < v3.ret_size(); i++)
        cout << v3[i] << " ";

    cout << "\nCopied vector: ";
    for (size_t i = 0; i < v4.ret_size(); i++)
        cout << v4[i] << " ";

    cout << "\nEqual: " << (v1 == v2);
    cout << "\nNot equal: " << (v1 != v2);
    cout << "\nSize: " << v1.ret_size();
    cout << "\nCapacity: " << v1.ret_cap();

    return 0;
}
