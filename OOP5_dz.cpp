#include <iostream>
using namespace std;

class IntSet {
    int* _set;
    int _size;
public:
    IntSet() : _size{ 0 }, _set{ nullptr } {}

    IntSet(int* set, int size) {
        _size = size;
        _set = new int[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _set[i] = set[i];
        }
    }

    IntSet(const IntSet& other) {
        _size = other._size;
        _set = new int[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _set[i] = other._set[i];
        }
    }

    ~IntSet() { delete[] _set; }

    bool contains(int num) {
        for (size_t i = 0; i < _size; i++)
        {
            if (num == _set[i]) return true;
            else return false;
        }
    }

    IntSet operator+(int right) {
        return *this += right;
    }
    IntSet& operator+=(int right) {
        if (contains(right) == false) {
            int* temp = new int[_size];
            for (size_t i = 0; i < _size; i++)
            {
                temp[i] = _set[i];
            }
            delete[] _set;
            _size++;
            _set = new int[_size];
            for (size_t i = 0; i < _size - 1; i++)
            {
                _set[i] = temp[i];
            }
            _set[_size - 1] = right;
            delete[] temp;
        }
        return *this;
    }

    IntSet operator+(const IntSet& right) {
        return *this += right;
    }
    IntSet& operator+=(const IntSet& right) {
        for (size_t i = 0; i < right._size; i++)
        {
            *this += right._set[i];
        }
        return *this;
    }

    IntSet operator-(int right) {
        return *this -= right;
    }

    IntSet& operator-=(int right) {
        int index = -1;
        for (size_t i = 0; i < _size; i++)
        {
            if (_set[i] == right) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            int* temp = new int[_size - 1];
            for (size_t i = 0, j = 0; i < _size; i++)
                if (i != index)
                    temp[j++] = _set[i];
            delete[] _set;
            _set = temp;
            _size--;
        }
        return *this;
    }

    IntSet operator-(const IntSet& right) {
        return *this -= right;
    }
    IntSet& operator-=(const IntSet& right) {
        for (size_t i = 0; i < right._size; i++)
        {
            *this -= right._set[i];
        }
        return *this;
    }

    IntSet& operator=(const IntSet& other) {
        if (this != &other) {
            delete[] _set;
            _size = other._size;
            _set = new int[_size];
            for (size_t i = 0; i < _size; i++)
                _set[i] = other._set[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const IntSet& s) {
        out << "{";
        for (size_t i = 0; i < s._size; i++)
        {
            out << s._set[i];
            if (i + 1 < s._size)
                out << ", ";
        }
        out << "}";
        return out;
    }
};

int main()
{
    int* arr1 = new int[5] {1, 2, 3, 4, 5};
    int* arr2 = new int[5] {6, 7, 8};
    IntSet A(arr1, 5);
    IntSet B(arr2, 3);
    cout << A << endl;
    A + 9;
    cout << A << endl;
    A + B;
    cout << A << endl;
    A - 9;
    cout << A << endl;
    A - B;
    cout << A << endl;

    return 0;
}
