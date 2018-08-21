#include<iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

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

int main()
{
    int n,i=0;
    clock_t tStart = clock();

    cout << "Input the number of terms for Fibonacci Series: ";
    cin >> n;
    cout << "\nFibonacci Series time: ";

    while(i<n)
    {
    //cout<<" "<<fibonacci(i);
    i++;
    }
    cout << double( clock() - tStart ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    return 0;
}