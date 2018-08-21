#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int sum(int arrayValue[], int counterVal);
int triangular(int n);
string reverse(string str);


int main()
{
    int choice;

    cout << endl << "Welcome to the recursive program! Please select an option: " << endl;
    do
    {
        cout << endl << "1) Reverses a string" << endl;
        cout << "2) Recursively calculate the sum of an array" << endl;
        cout << "3) Sum of all items that form a triangle with N rows" << endl;
        cout << "4) Exit" << endl;
        cout << "Choice: ";

        cin >> choice;
        while ((choice != 1)  && (choice != 2 && (choice != 3 && (choice !=4))))	
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Please enter valid choice: ";
		cin >> choice;
	}

    switch(choice)
    {
        case 1:
        {
            string str;
            cout << "Enter String" << endl;
            cin >> str;

            string rev_str = reverse(str);

            cout << rev_str << endl;

            break;
        }
        case 2:
        {
            int ArrSize;
            
            cout << "Enter Array Size: ";
            cin >> ArrSize;
            
            int *arrayVal = new int [ArrSize];

            cout << "Enter Array elements separated by space: ";
            
            for (int a = 0; a<ArrSize; a++)
            {
                cin>>*(arrayVal+a);
            }
            
            cout << endl << "Sum:" << sum(arrayVal,ArrSize) << endl;

            break;
        }
        case 3:
        {
            int rows;
            cout << "\nEnter the number of rows : ";
            cin >> rows;
            
            cout << "\nThe total number of items in triangle(or triangular number) for " << rows << " rows is : " <<triangular(rows) << endl;

            break;

        }
    }
    }
    while(choice != 4);


    return 0;
}



//FUNCTIONS


int sum(int arrayValue[], int counterVal)
{
     if (counterVal == 1)
     {
        return arrayValue[0];
     }
     else
     {
         return arrayValue[0] + sum(arrayValue+1,counterVal-1);
     }
}



int triangular(int n)
{
    return n * (n+1)/2;
}



string reverse(string str)
{
    
    string reverseString = "";
    
    if (str.length() <= 1)
    {
        return str;
    }

    string copy = str;
    int n = copy.length() - 1;

    string first = copy.substr(0, 1);

    copy = copy.substr(1, n);

    reverseString += reverse(copy);
    reverseString += first;

    return reverseString;
}