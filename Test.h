#ifndef TEST_H
#define TEST_H
 
#include <functional>
#include <chrono> 
#include <stdlib.h> 
#include <time.h>

class Rnd {
public:
	Rnd() { srand(time(NULL)); }
};

template <typename T>
class Test {
public:
	~Test();
	
	template <typename F> 
	static void testPerformance(T arr[], size_t count, F func);
	static void printArray(T arr[], size_t count);

	template <typename R>
	static R* generateArray(size_t length);
private:
	Test();
	static Rnd rnd;
};

template <typename T>
template <typename R>
static R* Test<T>::generateArray(size_t length) {
	std::cout << "type not supported" << std::endl;
}

template <>
template <>
static int* Test<int>::generateArray(size_t length) {
	int* arr = new int[length];

	for (size_t i = 0; i < length; i++) {
		arr[i] = rand() % 10000;
	}

	return arr;
}

template <>
template <>
static float* Test<float>::generateArray(size_t length) {
	float* arr = new float[length];

	for (size_t i = 0; i < length; i++) {
		arr[i] = static_cast <float> (static_cast <double>(rand()) / rand());
	}

	return arr;
}

template <>
template <>
static double* Test<double>::generateArray(size_t length) {
	double* arr = new double[length];

	for (size_t i = 0; i < length; i++) {
		arr[i] = static_cast <double>(static_cast <double>(rand()) / rand());
	}

	return arr;
}

template <typename T>
Test<T>::Test() {}

template <typename T>
Test<T>::~Test() {}

/**
 * @brief 
 * @tparam T type of array 
 * @tparam F type of function to test
 * @param arr array
 * @param count number of elements
 * @param func function to test
*/
template <typename T>
template <typename F>
void Test<T>::testPerformance(T arr[], size_t count, F func) {
	//printArray(arr, count);
	
	/* 
	 * We measure time twice, before and after function's 
	 * execution and take difference in miliseconds
	 */
	auto start = std::chrono::high_resolution_clock::now();
	func(arr, count);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	
	//printArray(arr, count);
	std::cout << "[EXECUTION TIME]: " << (duration.count()) << " miliseconds" << std::endl;
}

/**
 * @brief Prints all elements of array to the console. 
 * Primarly for debugging purposes
 * @tparam T type of array
 * @param arr array
 * @param count number of elements
*/
template <typename T>
void Test<T>::printArray(T arr[], size_t count) {
	for (size_t i = 0; i < count; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

#endif 

