#include <functional>
#ifndef SORTINGMACHINE_H
#define SORTINGMACHINE_H

template <typename T> class  SortingMachine {
	public:
		SortingMachine();
		~SortingMachine();

		/**
		 * @brief sorts array using bubble sort algorithm
		 * @param array array to be sorted
		 * @param count number of elements
		 */
		static void bubbleSort(T array[], const size_t count);
		/**
		 * @brief sorts array using insert sort algorithm
		 * @param array array to be sorted
		 * @param count number of elements
		 */
		static void insertSort(T array[], const size_t count);
		/**
		 * @brief sorts array using quick sort algorithm
		 * @param array array to be sorted
		 * @param count number of elements
		 */
		static void quickSort(T array[], const size_t count);
		/**
		 * @brief sorts array using merge sort algorithm
		 * @param array array to be sorted
		 * @param count number of elements
		 */
		static void mergeSort(T array[], const size_t count);
		
	private:
		/**
		 * @brief swaps values of two variables
		 * @tparam T Type
		 * @param a
		 * @param b
		 */
		static void swap(T* a, T* b);
		/**
		 * @brief merges two sorted parts of array in correct order
		 * @param array array to sort
		 * @param low low index
		 * @param middle middle index
		 * @param high high index 
		*/
		static void merge(T array[], const size_t low, const size_t middle, const size_t high);
		/**
		 * @brief internal implementation of merge sort
		 * @param array array to sort
		 * @param low low index
		 * @param high high index
		*/
		static void mergeSort(T array[], const size_t low, const size_t high);
		/**
		 * @brief internal quick sort implementation 
		 * @param array array to sort
		 * @param low low index
		 * @param high high index
		*/
		static void quickSort(T array[], size_t low, const size_t high);
};

template <typename T> 
SortingMachine<T>::SortingMachine() {
}

template <typename T> 
SortingMachine<T>::~SortingMachine() {
}

template <typename T> 
void SortingMachine<T>::bubbleSort(T array[], const size_t count) {
	/*
	 * We start by comparing each element of array with it's right neighbour.
	 * We swap elements if needed. We repeat that, but with each iteration, 
	 * we ignore one more element from the end of array 
	 */
	for (size_t i = 0; i < count - 1; i++) {
		for (size_t j = 0; j < count - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

template <typename T> 
void SortingMachine<T>::insertSort(T array[], const size_t count) {
	/*
	 * We take elements, starting with one on index 1.
	 * For each chosen element on index i (key), we compare it with element with 
	 * index i - 1. If they're not in order, we swap them, take i - 1 vs i - 2 etc.
	 * Once we encounter two elements in correct order, we choose new key   
	 */
	for (int i = 1; i < count; i++) {
		T key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > key) {
			swap(&array[j], &array[j + 1]);
			--j;
		}
		array[j + 1] = key;
	}
}

template <typename T> 
void SortingMachine<T>::quickSort(T array[], size_t low, const size_t high) {
	/*
	 * Recursive algorithm.
	 * While index 'low' is lower than 'high', we take element on index 'high' as pivot.
	 * We take i = low and search in array for elements lower than pivot. We swap such elements with
	 * one on index i and increment i. After checking whole array, we swap pivot with element on current i
	 * index and call quickSort for elements on the left of pivot. Then we assign low as i + 1 and repeat. 
	 * Calling itself recursively once instead of two times saves memory
 	 */
	while (low < high) {

		T pivot = array[high];
		size_t i = low;

		for (size_t j = low; j < high; j++) {
			if (array[j] < pivot) {
				swap(&array[i], &array[j]);
				i++;
			}
		}
		swap(&array[i], &array[high]);

		if (i > 0) {
			quickSort(array, low, i - 1);
		}

		low = i + 1;
	}
}

template <typename T> 
inline void SortingMachine<T>::quickSort(T array[], const size_t count) {
	quickSort(array, 0, count - 1);
}

template <typename T> 
inline void SortingMachine<T>::mergeSort(T array[], const size_t count) {
	mergeSort(array, 0, count - 1);
}

template <typename T> 
void SortingMachine<T>::mergeSort(T array[], const size_t low, const size_t high) {
	/*
	 * Recursive algorithm
	 * While 'low' index is smaller than 'high', we calculate middle and call mergeSort
	 * for left and right halves of array. After that, we merge these, already sorted subarrays
	 */
	if (low < high) {
		size_t middle = (low + high) / 2;
		mergeSort(array, low, middle);
		mergeSort(array, middle + 1, high);

		merge(array, low, middle, high);
	} 
}

template <typename T>
void SortingMachine<T>::merge(T array[], const size_t low, const size_t middle, const size_t high) {
	// We create two arrays representing left and right half of main array
	const size_t leftCount = middle - low + 1;
	const size_t rightCount = high - middle;

	T* left = new T[leftCount];
	T* right = new T[rightCount];

	for (size_t i = 0; i < leftCount; i++) {
		left[i] = array[low + i];
	}
	for (size_t i = 0; i < rightCount; i++) {
		right[i] = array[middle + 1 + i];
	}

	// We assign values from subarrays to correct positions in main array
	size_t i = 0;
	size_t j = 0;
	size_t k = low; 
	while (i < leftCount && j < rightCount) {
		if (left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		}
		else {
			array[k] = right[j];
			j++;
		}
		k++;
	}

	// We copy remaining elements
	while (i < leftCount) {
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < rightCount) {
		array[k] = right[j];
		j++;
		k++;
	}

	delete[] left;
	delete[] right;
}

template<typename T>
void SortingMachine<T>::swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif

