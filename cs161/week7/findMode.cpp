/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 22nd, 2017
** Description: That takes as parameters an array of int and the size 
** of the array, and returns a vector containing the mode(s).
*********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(int data[], int arraySize)
{
    int temp,left,right;

    for(int i=0;i < arraySize;i++){
        for(int j = 0;j < arraySize - 1; j++){
            
            left = data[j];
            right = data[j+1];
            if(left > right){
                temp = left;
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    return *data;
}

/*************************
** name: printArray
** Description: prints an array to the terminal
**************************/
void printArray(int array[],int arraySize)
{
    for(int i=0;i< arraySize;i++){
        cout << array[i] << endl;
    }
    cout << endl;
}

/*************************
** name: numCount
** Description: finds how many times the mode appears in an array
**************************/
int numCount(int data[],int arraySize)
{
    int mostFrequent = 0;
    int tempFrequent = 0;
    int numHolder = data[0];
    
    bubbleSort(data,arraySize);
    for(int i = 0;i < arraySize;i++){
        if(numHolder == data[i]){
            tempFrequent++;
        }
        else{
            numHolder = data[i];
            tempFrequent = 1;
        }
        if(tempFrequent > mostFrequent){
            mostFrequent = tempFrequent;
        }
    }
    return mostFrequent;
    
}

/*************************
** name: printVector
** Description: prints the contents of a vector
**************************/
void printVector(vector<int> myVector)
{
    int length = myVector.size();
    for(int i = 0; i < length;i++){
        cout << myVector[i] << endl;
    }
}

/*************************
** name: findMode
** Description: finds all the modes with the same frequency in an array
**************************/
vector<int> findMode(int data[],int arraySize)
{
    vector<int> modeVector;
    int tempFrequency = 0;
    int frequency = numCount(data,arraySize);
    int numHolder = data[0];

    bubbleSort(data,arraySize);

    for(int i = 0;i < arraySize;i++){
        if(numHolder == data[i]){
            tempFrequency++;
        }
        else{
            numHolder = data[i];
            tempFrequency = 1;
        }
        if(tempFrequency == frequency){
            tempFrequency = 1;
            modeVector.push_back(numHolder);
        }
    }
    return modeVector;
}

/*
int main()
{
    int dataSet1[3] = {10,5,6};
    int dataSet2[10] = {3,15,11,200,0,200,20,21};
    int dataSet3[3] = {2,5,5};
    int dataSet4[6] = {1,1,1,100,100,100};
    int dataSet5[3] = {32,49,95};
    int dataSet6[4] = {-1,-6,-1,5};

    cout << "Vector1" << endl;
    vector<int> Vector1 = findMode(dataSet1,3);
    printVector(Vector1);
    cout << endl;

    cout << "Vector2" << endl;
    vector<int> Vector2 = findMode(dataSet2,10);
    printVector(Vector2);
    cout << endl;

    cout << "Vector3" << endl;
    vector<int> Vector3 = findMode(dataSet3,3);
    printVector(Vector3);
    cout << endl;

    cout << "Vector4" << endl;
    vector<int> Vector4 = findMode(dataSet4,6);
    printVector(Vector4);
    cout << endl;

    cout << "Vector5" << endl;
    vector<int> Vector5 = findMode(dataSet5,3);
    printVector(Vector5);
    cout << endl;

    cout << "Vector6" << endl;
    vector<int> Vector6 = findMode(dataSet6,4);
    printVector(Vector6);
    cout << endl;
}
*/