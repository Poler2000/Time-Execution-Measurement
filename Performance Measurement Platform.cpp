
#include <iostream>
#include "SortingMachine.h"
#include "Test.h"

int main() {
    size_t size = 2500;
    SortingMachine<int> sortingMachine;
    void (*bubble)(int[], int) = SortingMachine<int>::bubbleSort;
    void (*insert)(int[], int) = SortingMachine<int>::insertSort;
    void (*quick)(int[], int) = SortingMachine<int>::quickSort;
    void (*merge)(int[], int) = SortingMachine<int>::mergeSort;
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, bubble);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, insert);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, quick);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, merge);

    std::cin.get();
    return 0;
}



