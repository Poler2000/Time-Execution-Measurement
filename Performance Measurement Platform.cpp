
#include <iostream>
#include "SortingMachine.h"
#include "Test.h"

int main() {
    size_t size = 50000;
    SortingMachine<int> sortingMachine;
    std::cout << "[INT]" << std::endl;
    void (*bubble)(int[], int) = SortingMachine<int>::bubbleSort;
    void (*insert)(int[], int) = SortingMachine<int>::insertSort;
    void (*quick)(int[], int) = SortingMachine<int>::quickSort;
    void (*merge)(int[], int) = SortingMachine<int>::mergeSort;
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, bubble);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, insert);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, quick);
    Test<int>::testPerformance(Test<int>::generateArrayInt(size), size, merge);

    std::cout << "[FLOAT]" << std::endl;
    void (*bubbleF)(float[], int) = SortingMachine<float>::bubbleSort;
    void (*insertF)(float[], int) = SortingMachine<float>::insertSort;
    void (*quickF)(float[], int) = SortingMachine<float>::quickSort;
    void (*mergeF)(float[], int) = SortingMachine<float>::mergeSort;
    Test<float>::testPerformance(Test<float>::generateArrayFloat(size), size, bubbleF);
    Test<float>::testPerformance(Test<float>::generateArrayFloat(size), size, insertF);
    Test<float>::testPerformance(Test<float>::generateArrayFloat(size), size, quickF);
    Test<float>::testPerformance(Test<float>::generateArrayFloat(size), size, mergeF);

    std::cout << "[DOUBLE]" << std::endl;
    void (*bubbleD)(double[], int) = SortingMachine<double>::bubbleSort;
    void (*insertD)(double[], int) = SortingMachine<double>::insertSort;
    void (*quickD)(double[], int) = SortingMachine<double>::quickSort;
    void (*mergeD)(double[], int) = SortingMachine<double>::mergeSort;
    Test<double>::testPerformance(Test<double>::generateArrayDouble(size), size, bubbleD);
    Test<double>::testPerformance(Test<double>::generateArrayDouble(size), size, insertD);
    Test<double>::testPerformance(Test<double>::generateArrayDouble(size), size, quickD);
    Test<double>::testPerformance(Test<double>::generateArrayDouble(size), size, mergeD);

    std::cin.get();
    return 0;
}



