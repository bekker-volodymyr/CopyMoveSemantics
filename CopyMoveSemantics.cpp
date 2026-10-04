#include <iostream>

class IntArray {
private:
    int* arr;
    int size;
public:
    IntArray():size(0), arr(nullptr){}
    explicit IntArray(int size) : size(size) {
        arr = new int[size] {0};
    }
    ~IntArray() {
        if (arr != nullptr) delete[] arr;
    }

    IntArray(const IntArray& other) : size(other.size) {
        if (other.size > 0) {
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        else {
            arr = nullptr;
        }
    }
    IntArray& operator=(const IntArray& other) {
		if (this == &other) return *this;

        if (arr != nullptr) delete[] arr;

        size = other.size;

        if (size != 0) {
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        else {
            arr = nullptr;
        }

        return *this;
    }

    IntArray(IntArray&& other) noexcept
        : arr(other.arr), size(other.size) {
        other.arr = nullptr;
        other.size = 0;
    }
    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) return *this;

        if (arr != nullptr) delete[] arr;

        arr = other.arr;
        size = other.size;

        other.arr = nullptr;
        other.size = 0;

        return *this;
    }

    int operator[](int index) const {
        return arr[index];
    }
    int& operator[](int index) {
        return arr[index];
    }
};

// Фабрична функція
IntArray createFilledArray(int size) {
    IntArray newArr(size);
    //for(int i = 0; i < size; )
    return newArr;
}

int main()
{
    IntArray arr1(5);
    IntArray arr2(arr1);

    IntArray arr3(4);

    arr3 = arr2;

    IntArray newArr = createFilledArray(5);

    std::cout << newArr[3] << '\n';

    //int size = 0;

    //std::cout << "Enter size: ";
    //std::cin >> size;

    //int* arr = new int[size];

    //delete[] arr;
}