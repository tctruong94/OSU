#include <ctime>
#include<iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int fibonacci(int n);

int main()
{
    int n,
        i=0,
        t1 = 0,
        t2 = 1,
        nextTerm = 0;

    clock_t tStart = clock();
  
    cout << "\n----Recursive vs Iterative Time----" << endl << endl;
    cout << "Description: Measure and compare the running time of recursive and iterative" << endl;
    cout << "             implementations of Fibonacci Numbers Calculation" << endl;

    cout << "\nEnter the number: ";
    cin >> n;

    cout << "\nFibonacci time(iterative): ";

    for (int i = 1; i <= n; ++i)
    {
        if(i == 1)
        {
            continue;
        }

        if(i == 2)
        {
            continue;
        }

    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  
    }

    cout << double( clock() - tStart ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    cout << "\nFibonacci time(recursive): ";

    while(i<n)
    {
        i++;
    }
    
    cout << double( clock() - tStart ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    return 0;
}


int fibonacci(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
    return(fibonacci(n-1)+fibonacci(n-2));
    }
}
