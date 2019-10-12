#include <iostream>
#include <stdlib.h> 
#include <time.h>   
 
 
using std::cout;
using std::cin;
 
 
void free_array(int** arr, const int n, const int m) /// Function for stripping memory
{
	for (int i = 0; i<n; i++) 
		delete[]arr[i];
	delete[]arr;
	arr = 0; /// Indicated that the memory area is now free
} 


int** init_array(int** arr, const int n, const int m) /// Function to allocate memory
{
	if (arr)
		free_array(arr, n, m);    /// If previously memory was allocated, clean it
 
	arr = new int*[n];
	for (int i = 0; i<n; i++) 
		arr[i] = new int[m];
	return arr;
} 
 

void fill_array(int** arr, const int n, const int m) /// Function to fill an array with random elements
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++) 
		{
			arr[i][j] = rand() % 100;
		}
	}
} 


void print_array(int** arr, const int n, const int m)  /// Function to display the array on the screen
{
	cout << "array " << n << ',' << m << ":\n";
	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<m; j++) 
		{
			cout << arr[i][j];
			cout.width(5); /// Set the minimum width of the output field
		}   cout << '\n';
	}
	cout << "\n\n";
} 
 
  
void worked_with_array(int** arr, const int n, const int m) /// Added a function that combines the same sequence of calls
{
	arr = init_array(arr, n, m); /// Allocated memory, assign it to the pointer							
	fill_array(arr, n, m); /// Called the function and filled the array with values								
	print_array(arr, n, m);	/// Called the function and output the array values to the screen                                
	free_array(arr, n, m);	/// Called the function and destroyed the array						
}
 
 
int main(int argc, char** argv)
{
	srand(unsigned(time(NULL))); /// Generated a random number using the time function 
	int** my_array = 0;
 
	int row = 9;
	int col = 20;
 
	worked_with_array(my_array, row, col);
 
	row = 3, col = 4;
	worked_with_array(my_array, row, col);
 
	row = 7, col = 14;	
	worked_with_array(my_array, row, col);
 
	cin.get();
 
}
