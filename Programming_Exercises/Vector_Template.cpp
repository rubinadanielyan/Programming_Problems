#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Vector
{
private:
    T* data;
    size_t count;
    size_t maxSize;

    void expand()
    {
        size_t newSize = (maxSize == 0) ? 2 : maxSize + maxSize / 2;

        T* temp = new T[newSize];

        for (size_t i = 0; i < count; i++)
            temp[i] = data[i];

        delete[] data;
        data = temp;
        maxSize = newSize;
    }

    void swap(Vector& other)
    {
        std::swap(data, other.data);
        std::swap(count, other.count);
        std::swap(maxSize, other.maxSize);
    }

public:
    Vector()
    {
        data = nullptr;
        count = 0;
        maxSize = 0;
    }

    Vector(const Vector& other)
    {
        count = other.count;
        maxSize = other.count;
        data = (maxSize == 0) ? nullptr : new T[maxSize];

        for (size_t i = 0; i < count; i++)
            data[i] = other.data[i];
    }

    ~Vector()
    {
        delete[] data;
    }

    void push_back(const T& value)
    {
        if (count == maxSize)
            expand();

        data[count] = value;
        count++;
    }

    void pop_back()
    {
        if (count != 0)
            count--;
    }

    void reserve(size_t newSize)
    {
        if (newSize <= maxSize)
            return;

        T* temp = new T[newSize];

        for (size_t i = 0; i < count; i++)
            temp[i] = data[i];

        delete[] data;
        data = temp;
        maxSize = newSize;
    }

    size_t ret_size() const
    {
        return count;
    }

    size_t ret_cap() const
    {
        return maxSize;
    }

    T& operator[](size_t index)
    {
        return data[index];
    }

    const T& operator[](size_t index) const
    {
        return data[index];
    }

    Vector& operator=(Vector other)
    {
        swap(other);
        return *this;
    }

    Vector operator+(const Vector& other) const
    {
        Vector result;

        if (count != other.count)
            return result;

        result.reserve(count);

        for (size_t i = 0; i < count; i++)
            result.push_back(data[i] + other.data[i]);

        return result;
    }

    bool operator==(const Vector& other) const
    {
        if (count != other.count)
            return false;

        for (size_t i = 0; i < count; i++)
            if (data[i] != other.data[i])
                return false;

        return true;
    }

    bool operator!=(const Vector& other) const
    {
        return !(*this == other);
    }
};

int main()
{
    Vector<int> a, b;

    a.push_back(10);
    a.push_back(20);

    b.push_back(3);
    b.push_back(4);

    Vector<int> c = a + b;

    for (size_t i = 0; i < c.ret_size(); i++)
        cout << c[i] << " ";

    cout << endl;

    Vector<double> d;
    d.push_back(2.5);
    d.push_back(4.5);

    for (size_t i = 0; i < d.ret_size(); i++)
        cout << d[i] << " ";

    return 0;
}
