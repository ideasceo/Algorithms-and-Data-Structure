
/*

One possible improvement for Bubble Sort would be to add a flag variable and a test that
determines if an exchange was made during the current iteration. If no exchange was made,
then the list is sorted and so the algorithm can stop early. Modify the Bubble Sort
implementation to add this flag and test. Compare the modified implementation on a range of
inputs to determine if it does or does not improve performance in practice.

*/

#include <iostream>
#include <chrono>
using namespace std;

//functions prototype
void swap(int *, int *); // swap two values
void bubbleSort(int arr[], int);
void bubbleSortModified(int arr[], int);
void displayValues(int arr[], int);

int main()
{
	//record start time
	auto start = std::chrono::high_resolution_clock::now();
	int array1[] = { 64, 34, 25, 32, 52, 21, 28, 56, 100, 120, 95 };
	int n = sizeof(array1) / sizeof(array1[0]);
	
	bubbleSort(array1, n);
	cout << "\nSorted array without flag variable: \n\n";
	displayValues(array1, n);
	// Record end time
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;

	cout << "\nThe execution time of bubble sort without flag is:   "<< elapsed.count() << endl;

	start = std::chrono::high_resolution_clock::now();
	int array2[] = { 64, 34, 25, 32, 52, 21, 28, 56, 100, 120, 95 };
	n = sizeof(array2) / sizeof(array2[0]);
	cout << "\n\nSorted array with flag variable: \n\n";
	bubbleSortModified(array2, n);
	displayValues(array2, n);
	// Record end time
	finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsd = finish - start;

	cout << "\nThe execution time of bubble sort with flag is:   " << elapsd.count() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}

//implementation of function 'swap'
void swap(int *a, int *b) // swap two values
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//implementation of function 'bubble sort'
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{    
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//implementation of function 'bubble sort with flag'
void bubbleSortModified(int arr[], int n)
{
	bool flag = false; //flag variable
	for (int i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place    
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
		{
			break; // no current ilteration made
		}
		else
			flag = false; // check for ilteration again
	}
}

//implementation of function 'displayValues'
void displayValues(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
		
	cout << endl;
}