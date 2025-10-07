#include <iostream>
#include <Windows.h>
using namespace std;

template <class T>
class Array {
private:
    T* Data;
    int Size;
    int Count;
    int Grow;

public:
    Array(int size = 0, int grow = 1)
        : Size(size), Grow(grow), Count(0)
    {
        if (Size > 0)
            Data = new T[Size];
        else
            Data = nullptr;
    }

    ~Array() {
        delete[] Data;
    }

    int GetSize() const {
        return Size;
    }

    void SetSize(int newSize, int grow = 1) 
    {
        if (newSize < 0) return;

        T* newData = nullptr;
        if (newSize > 0)
        {
            newData = new T[newSize];

            int elementsToCopy = (newSize < Count) ? newSize : Count;
            for (int i = 0; i < elementsToCopy; ++i)
            {
                newData[i] = Data[i];
            }
            Count = elementsToCopy;
        }

        delete[] Data;
        Data = newData;
        Size = newSize;
        Grow = grow;
    }

    int GetUpperBound() const {
        return (Count > 0) ? Count - 1 : -1;
    }

    bool IsEmpty() const {
        return Count == 0;
    }

    void Compress() {
        if (Count < Size) {
            SetSize(Count, Grow);
        }
    }


    void RemoveAll() {
        delete[] Data;
        Data = nullptr;
        Size = 0;
        Count = 0;
    }

    void Add(const T& value) {
        if (Count >= Size) 
        {
            SetSize(Size + Grow, Grow);
        }
        Data[Count++] = value;
    }


    void Print() const {
        if (IsEmpty()) {
            cout << "����� �������." << endl;
            return;
        }

        cout << "�������� ������: ";
        for (int i = 0; i < Count; ++i) {
            cout << Data[i];
            if (i < Count - 1) cout << ", ";
        }
        cout << endl;

        cout << "ʳ������ ��������: " << Count << endl;
        cout << "�������� �����: " << Size << endl;
    }


    T& operator[](int index) // ��������� ����� ����������� ��� ����
    {
        return Data[index];
    }


    const T& operator[](int index) const // Const ����� ����������� ����� ��� �������
    {
        return Data[index];
    }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Array<int> arr(5, 5);

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    cout << " �� ��������� " << endl;
    arr.Print();

    cout << "������� ������: " << arr.GetUpperBound() << endl;
    cout << "����� �������: " << (arr.IsEmpty() ? "���" : "ͳ") << endl;

    arr.Compress();
    cout << "\n ϳ��� ��������� " << endl;
    arr.Print();

    arr.RemoveAll();
    cout << "\n ϳ��� �������� " << endl;
    arr.Print();


}