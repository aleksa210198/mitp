#include <iostream>
#include <stdlib.h> 
#include <time.h>   
 
 
using std::cout;
using std::cin;
 
 
void free_array(int** arr, const int N, const int M) /// delete memory
{
	for (int i = 0; i<N; i++) 
		delete[]arr[i];
	delete[]arr;
	arr = 0;         
} 


int** init_array(int** arr, const int N, const int M) /// init memory
{
	if (arr)
		free_array(arr, N, M);    
 
	arr = new int*[N];
	for (int i = 0; i<N; i++) 
		arr[i] = new int[M];
	return arr;
} 
 

void fill_array(int** arr, const int N, const int M) /// fill memory
{
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++) 
		{
			arr[i][j] = rand() % 100;
		}
	}
} 


void print_array(int** arr, const int N, const int M)  /// output to the screen
{
	cout << "array " << N << ',' << M << ":\n";
	for (int i = 0; i<N; i++) 
	{
		for (int j = 0; j<M; j++) 
		{
			cout << arr[i][j];
			cout.width(5);
		}   cout << '\n';
	}
	cout << "\n\n";
} 
 
  
void worked_with_array(int** arr, const int N, const int M) /// Added a function that combines the same sequence of calls
{
	arr = init_array(arr, N, M);							
	fill_array(arr, N, M);									
	print_array(arr, N, M);	                                
	free_array(arr, N, M);									
}
 
 
int main(int argc, char** argv)
{
	srand(unsigned(time(NULL)));    
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
