#include<stdlib.h>
#include<string.h>
#include<stdio.h>

FILE *fp,*fileInfo;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n2 = r - m;
	int n1 = m - l + 1;
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


void mergeSort(int arr[], int l, int r)
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
		fprintf(fileInfo,"%d ", A[i]);
	}

	fprintf(fileInfo,"\n");
}

int main()
{

	int arr[1000] = {0};
	int arr_size =0;
	int data;

	char file1[20];

	strcpy(file1,"data.txt");

	fp = fopen(file1,"r+");

	if (fp == NULL)
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
strcpy(file2,"merge.out");

fileInfo = fopen(file2,"w");

if (fileInfo == NULL)
{
	perror("Unable to create file");
	return -1;
}

  
fprintf(fileInfo,"Given array is \n");
printArray(arr, arr_size);

mergeSort(arr+1, 0, arr[0]-1);

fprintf(fileInfo,"\nSorted array Using MERGE SORT is \n");
printArray(arr, arr_size);

fclose(fileInfo);

fileInfo=NULL;
fp=NULL;

return 0;

}