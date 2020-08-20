#include <iostream>
#include "SortingMachine.h"
#include "Test.h"

template <typename T>
void performSortingTests(T* testArray0, size_t count) {
    T* testArray1 = new T[count];
    T* testArray2 = new T[count];
    T* testArray3 = new T[count];

    for (int i = 0; i < count; i++) {
        testArray1[i] = testArray0[i];
        testArray2[i] = testArray0[i];
        testArray3[i] = testArray0[i];
    }

    void (*bubble)(T[], const size_t) = SortingMachine<T>::bubbleSort;
    void (*insert)(T[], const size_t) = SortingMachine<T>::insertSort;
    void (*quick)(T[], const size_t) = SortingMachine<T>::quickSort;
    void (*merge)(T[], const size_t) = SortingMachine<T>::mergeSort;

    Test<T>::testPerformance(testArray0, count, bubble);
    Test<T>::testPerformance(testArray1, count, insert);
    Test<T>::testPerformance(testArray2, count, quick);
    Test<T>::testPerformance(testArray3, count, merge);

    delete[] testArray0;
    delete[] testArray1;
    delete[] testArray2;
    delete[] testArray3;
}

int main() {
    constexpr size_t size = 50000;
    std::cout << "[INT]" << std::endl;
    performSortingTests<int>(Test<int>::generateArray<int>(size), size);
    std::cout << "[FLOAT]" << std::endl;
    performSortingTests<float>(Test<float>::generateArray<float>(size), size);
    std::cout << "[DOUBLE]" << std::endl;
    performSortingTests<double>(Test<double>::generateArray<double>(size), size);

    std::cin.get();
    return 0;
}



