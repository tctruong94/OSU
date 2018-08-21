#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <time.h>

void merge(int *arr, int l, int m, int r)
{

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
  
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1+ j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int *arr, int l, int r) 
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;

	for (i=0; i < size; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
}



void insertionSort(int *arr, int n) 
{
	int i, j,key;

	for(i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}

}

/*******************************
function: generateRandomArray
description: generate an array with random numbers betwen 0 - 10,000
*******************************/
void generateRandomArray(int *arr, int size) 
{
	for(int i=0; i<size; i++)
	{
		arr[i] = rand() % 10000;
	}
}


int main()
{
  
	int rows = 7;

	int **arr = (int **) malloc(rows * sizeof(int *));
  
	//array of the sizes of the different arrays
	int array_size[7] = {1000, 2000, 5000, 10000, 12000, 15000, 20000};

	//array of size 1000, 2000, 5000, 10000, 120000, 15000, 20000
	arr[0] = (int *) malloc(1000 * sizeof(int));
	arr[1] = (int *) malloc(2000 * sizeof(int));
	arr[2] = (int *) malloc(5000 * sizeof(int));
	arr[3] = (int *) malloc(10000 * sizeof(int));
	arr[4] = (int *) malloc(12000 * sizeof(int));
	arr[5] = (int *) malloc(15000 * sizeof(int));
	arr[6] = (int *) malloc(20000 * sizeof(int));
  
	double timeMergeSort[7];				//to hold running time
	double timeInsertionSort[7];			//to hold running time
  

	for(int i=0; i<7; i++)
	{
		generateRandomArray(arr[i], array_size[i]);			//fill array with random numbers
	}
 
	for(int i=0; i<7; i++)				//get mergesort running time
	{
	clock_t t;
	t = clock();
  
	mergeSort(arr[i], 0, array_size[i]-1);
  
	t = clock() - t;					//end time - start time
  
	timeMergeSort[i] = ((double)t)/CLOCKS_PER_SEC;

	}
  

	for(int i=0; i<7; i++)				//get insertionsort running time
	{
  		clock_t t;
  		t = clock();
  
		insertionSort(arr[i], array_size[i]);
  
		t = clock() - t;						//end time - start time
  
		timeInsertionSort[i] = ((double)t)/CLOCKS_PER_SEC;

	}
  
	printf("\nRunning times of Merge Sort : \n");

	for(int i=0;i<7; i++)
	{
		printf("%f ", timeMergeSort[i]);
	}
  
	printf("\nRunning times of Insertion Sort : \n");

	for(int i=0;i<7; i++)
	{
		printf("%f ", timeInsertionSort[i]);
	}
  
double mergeSortTotalTime, insertionSortTotalTime;
  
	for(int i=0;i<7; i++)
	{
		mergeSortTotalTime += timeMergeSort[i];
	}
  
	for(int i=0;i<7; i++)
	{
		insertionSortTotalTime += timeInsertionSort[i];
  	}

	printf("\nAvg Running time of Merge Sort = \%f seconds", mergeSortTotalTime/7);

	printf("\nAvg Running time of Insertion Sort = %f seconds", insertionSortTotalTime/7);
  
return 0;

}