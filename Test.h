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

	static int*  generateArrayInt(size_t length);
	//static float[] generateArrayFloat(size_t length);
	//static double[] generateIntArrayDouble(size_t length);

private:
	Test();
	static Rnd rnd;
};

template<typename T>
int* Test<T>::generateArrayInt(size_t length) {
	
	int* arr = new int[length];

	for (int i = 0; i < length; i++) {
		arr[0] = rand() % 10000;
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
	int n = sizeof(arr);
	auto start = std::chrono::high_resolution_clock::now();
	func(arr, size);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "[EXECUTION TIME]: " << (duration.count()) << " miliseconds" << std::endl;
}

/*template <typename T>
int[] generateArrayInt(size_t length) {
	return { 1 ,2 };
}*/

#endif 

