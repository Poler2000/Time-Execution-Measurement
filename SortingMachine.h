#include <functional>
#ifndef SORTINGMACHINE_H
#define SORTINGMACHINE_H

template <typename T> class  SortingMachine {
	public:
		SortingMachine();
		~SortingMachine();
		static void bubbleSort(T array[], const int size);
		static void insertSort(T array[], const int size);
		static void quickSort(T array[], const int size);
		static void mergeSort(T array[], const int size);
		
	private:
		static void swap(T* a, T* b);
		static void merge(T array[], const int left, const int middle, const int right);
		static void mergeSort(T array[], const int left, const int right);
		static void quickSort(T array[], int low, const int &high);
};

template <typename T> 
SortingMachine<T>::SortingMachine() {
}

template <typename T> 
SortingMachine<T>::~SortingMachine() {
}

template <typename T> 
void SortingMachine<T>::bubbleSort(T array[], const int size) {
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}



template <typename T> 
void SortingMachine<T>::insertSort(T array[], const int size) {
	
	for (int i = 1; i < size; i++) {
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
void SortingMachine<T>::quickSort(T array[], int low, const int &high) {
	
	while (low < high) {

		int pivot = array[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (array[j] < pivot) {
				i++;
				swap(&array[i], &array[j]);
			}
		}
		swap(&array[i + 1], &array[high]);

		pivot = i + 1;

		quickSort(array, low, pivot - 1);

		low = pivot + 1;
		//quickSort(array, pivot + 1, high);
	}
}

template <typename T> 
void SortingMachine<T>::quickSort(T array[], const int size) {
	quickSort(array, 0, size - 1);
}



template <typename T> 
void SortingMachine<T>::mergeSort(T array[], const int size) {
	mergeSort(array, 0, size - 1);
}

template <typename T> 
void SortingMachine<T>::mergeSort(T array[], const int left, const int right) {
	if (left < right) {
		int middle = (right + left) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);

		merge(array, left, middle, right);
	} 
}

template <typename T>
void SortingMachine<T>::merge(T array[], const int l, const int m, const int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}


template<typename T>
void SortingMachine<T>::swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
#endif

