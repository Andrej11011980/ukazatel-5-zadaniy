/*Написать функцию, получающую указатель
на статический массив и его размер.Функция распределяет
положительные, отрицательные и нулевые элементы в отдельных динамических
массивы.*/
#include <iostream>
using namespace std;
template <class T>
void showArr(T* arr, int size);

template <class T>
void NewFinishElement(T*& arr, int& size);

int* negative_numbers(int* arr, int size);

int* null_numbers(int* arr, int size);

int* positive_numbers(int* arr, int size);





template <class T>
void showArr(T* arr, int size)  //   функция показа динамического массива на экран консоли
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",   ";
	cout << "\n";
}

template <class T>
void NewFinishElement(T*& arr, int& size)  //   функция добавления элемента в конец массива
{
	T* arr1 = new int[size + 1];

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

int* negative_numbers(int* arr, int size, int& element_newArr)      // создаем массив с отрицательными элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] < 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}


int* null_numbers(int* arr, int size, int& element_newArr)      // создаем массив с нуливыми элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}

int* positive_numbers(int* arr, int size, int& element_newArr)      // создаем массив с положительными элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] > 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}

int main()
{
	system("chcp 1251 > 0");

	const int size = 7;
	int Arr[size]{ 20 , 5, 4 , 30 ,27 , 3, 4 };  // исходный массив

	cout << "Исходный массив : \n";
	showArr(Arr, size);

	int size1 = 0;
	int* Arr1 = negative_numbers(Arr, size, size1); // создаем массив с отрицательными элементами

	cout << "\nМассив с отрицательными элементами : \n";
	showArr(Arr1, size1);

	int size2 = 0;
	int* Arr2 = null_numbers(Arr, size, size2);  // создаем массив с нуливыми элементами

	cout << "\nМассив с нулевыми элементами : \n";
	showArr(Arr2, size2);

	int size3 = 0;
	int* Arr3 = positive_numbers(Arr, size, size3);  // создаем массив с положительными элементами

	cout << "\nМассив с положительными элементами : \n";
	showArr(Arr3, size3);
}
