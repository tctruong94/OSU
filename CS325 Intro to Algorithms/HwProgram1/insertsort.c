#include <stdio.h>
#include<string.h>
#include <math.h>


FILE *fp,*fileInfo;

void insertionSort(int arr[], int n)
{
	int i, key, j;

	for (i = 1; i < n; i++)
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

void printArray(int arr[], int n)
{
	int i;

	for (i=0; i < n; i++)
	{
		fprintf(fileInfo,"%d ", arr[i]);
	}

	fprintf(fileInfo,"\n");
}

int main()
{
	int data;
	int arr[1000] = {0};
	int arr_size =0;
	char file1[20];

	strcpy(file1,"data.txt");

	fp = fopen(file1,"r+");

	if (fp == NULL) // if file not opened return error
	{
		perror("Unable to open file");
		return -1;
	}
	else
	{
		fscanf (fp, "%d", &data);   
		arr[arr_size]=data;
		arr_size++;

		while (!feof (fp))
		{  
			fscanf (fp, "%d", &data);  
			arr[arr_size]=data;
			arr_size++;   
		}
	}

	char file2[20];
	strcpy(file2,"insert.out");

	fileInfo = fopen(file2,"w");

	if (fileInfo == NULL) // if file not opened return error
	{
		perror("Unable to create file");
		return -1;
	}

	fprintf(fileInfo,"Array: \n");
	printArray(arr, arr_size);

	insertionSort(arr+1, arr[0]-1);

	fprintf(fileInfo,"\nSorted array(insert sort) \n");
	printArray(arr, arr_size);

	fclose(fileInfo);

	fileInfo=NULL;
	fp=NULL;

	return 0;
}