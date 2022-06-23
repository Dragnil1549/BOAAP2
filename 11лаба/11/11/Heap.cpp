#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
    std::cout << x;
}
int AAA::getPriority() const
{
    return x;
}
namespace heap
{
    Heap create(int maxsize, CMP(*f)(void*, void*))
    {
        return *(new Heap(maxsize, f));
    }
    int Heap::left(int ix)
    {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
    }
    int Heap::right(int ix)
    {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
    }
    int Heap::parent(int ix)
    {
        return (ix + 1) / 2 - 1;
    }
    void Heap::swap(int i, int j)
    {
        void* buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }
    void Heap::heapify(int ix)
    {
        int l = left(ix), r = right(ix), irl = ix;
        if (l > 0)
        {
            if (isGreat(storage[l], storage[ix])) irl = l;
            if (r > 0 && isGreat(storage[r], storage[irl]))   irl = r;
            if (irl != ix)
            {
                swap(ix, irl);
                heapify(irl);
            }
        }
    }
    void Heap::insert(void* x)
    {
        int i;
        if (!isFull())
        {
            storage[i = ++size - 1] = x;
            while (i > 0 && isLess(storage[parent(i)], storage[i]))
            {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }
    void* Heap::extractMax()
    {
        void* rc = nullptr;
        if (!isEmpty())
        {
            rc = storage[0];
            storage[0] = storage[size - 1];
            size--;
            heapify(0);
        } return rc;
    }
    void* Heap::extractMin()
    {
        void* temp = nullptr;
        int n;
        if (!isEmpty())
        {
            temp = storage[0];
            for (int i = 1; i < size; i++) {
                if (isLess(storage[i], temp)) {
                    temp = storage[i];
                    n = i;
                }
            }
            for (n; n < size - 1; n++) {
                storage[n] = storage[n + 1];
            }
            size--;
            heapify(0);
        }
        return temp;
    }
    void* Heap::extractI(int n) {
        void* temp = storage[n];
        for (n; n < size - 1; n++) {
            storage[n] = storage[n + 1];
        }
        size--;
        heapify(0);
        return temp;
    }
    void* Heap::unionHeap(Heap h) {
        int a = 0;
        for (int i = size; i < (size + h.size); i++) {
            storage[i] = h.storage[a];
            a++;
        }
        size += h.size;
        heapify(0);
        return 0;
    }
    void* Heap::unionHeapMax(Heap h) {
        storage[size] = h.extractMax();
        size++;
        return 0;
    }
    void* Heap::unionHeapMin(Heap h) {
        storage[size] = h.extractMin();
        size++;
        return 0;
    }
    void* Heap::unionHeapI(Heap h, int n) {
        storage[size] = h.extractI(n);
        size++;
        return 0;
    }
    void Heap::scan(int i) const     //����� �������� ��������� �� �����
    {
        int probel = 20;
        std::cout << '\n';
        if (size == 0)
            std::cout << "���� �����";
        for (int u = 0, y = 0; u < size; u++)
        {
            std::cout << std::setw(probel + 10) << std::setfill(' ');
            ((AAA*)storage[u])->print();
            if (u == y)
            {
                std::cout << '\n';
                if (y == 0)
                    y = 2;
                else
                    y += y * 2;
            }
            probel /= 2;
        }
        std::cout << '\n';
    }
}