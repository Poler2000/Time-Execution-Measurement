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
	static void testPerformance(T arr[], size_t size, F func);
	static void printArray(T arr[], size_t size);

	static int*  generateArrayInt(size_t length);
	static float* generateArrayFloat(size_t length);
	static double* generateArrayDouble(size_t length);

private:
	Test();
	static Rnd rnd;
};

template<typename T>
int* Test<T>::generateArrayInt(size_t length) {
	
	int* arr = new int[length];

	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 10000;
	}

	return arr;
}

template<typename T>
float* Test<T>::generateArrayFloat(size_t length) {

	float* arr = new float[length];

	for (int i = 0; i < length; i++) {
		arr[i] = static_cast <float> (static_cast <double>(rand()) / rand());
	}

	return arr;
}

template<typename T>
double* Test<T>::generateArrayDouble(size_t length) {

	double* arr = new double[length];

	for (int i = 0; i < length; i++) {
		arr[i] = static_cast <double>(static_cast <double>(rand()) / rand());
	}

	return arr;
}

template <typename T>
Test<T>::Test() {}

template <typename T>
Test<T>::~Test() {}

template <typename T>
template <typename F>
void Test<T>::testPerformance(T arr[], size_t size, F func) {
	//printArray(arr, size);
	
	auto start = std::chrono::high_resolution_clock::now();
	func(arr, size);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	
	//printArray(arr, size);
	std::cout << "[EXECUTION TIME]: " << (duration.count()) << " miliseconds" << std::endl;

	delete[] arr;
}

template <typename T>
void Test<T>::printArray(T arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

#endif 

