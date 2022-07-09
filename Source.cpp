//Fahad Waheed (20I-0651)

#include <iostream>

using namespace std;

int count = 0;

void display(int arr[], int size);

int merge(int Array[], int low, int mid, int high)
{
	//mid + 1 will be passed in the variable mid when the function is called
	int* result = new int[high - low + 1]; // allocate temporary array
	int array1_index = low, array2_index = mid;
	int i = 0; //index for result array
	int count = 0;

	while (array1_index < mid && array2_index <= high)
	{
		if (Array[array1_index] <= Array[array2_index])
		{
			result[i++] = Array[array1_index++]; //post increment
		}
		else
		{
			result[i++] = Array[array2_index++]; //post increment
			count += mid - array1_index;
		}
	}

	while (array2_index <= high) // copy remaining elements from array 2
	{
		result[i++] = Array[array2_index++];
	}
	while (array1_index < mid)// copy remaining elements from array 1
	{
		result[i++] = Array[array1_index++];
	}
	// copying elements from temporary array to "Array"
	for (i = 0; i < high - low + 1; i++) //high-low +1 = array size
	{
		if (Array[low + i] != result[i])
		
		Array[low + i] = result[i];
	}
	delete[] result; // de-allocate memory
	return count;
}



void mergeSort(int arr[], int first, int last)
{
	if (first < last) //List size is greater than 1
	{
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid); //Split for first half
		mergeSort(arr, mid + 1, last);//Split for second half
		::count += merge(arr, first, mid + 1, last);
		display(arr, last - first + 1);
		cout << "count: " << ::count << endl;
	}
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i];
		else
			cout << arr[i] << ", ";
	}
	cout << endl;
}

int main()
{
	int arr[5] = { 5,4,3,2,1 };

	display(arr, 5);

	mergeSort(arr, 0, 4);

	display(arr, 5); 

	cout << "Total Overtakes: " << ::count << endl;
}