#include <iostream>
#include <ctime>
using namespace std;

int main()
{
int n, t1 = 0, t2 = 1, nextTerm = 0;
clock_t tStart = clock();
  

cout << "Enter the number of terms: ";
cin >> n;

cout << "Fibonacci Series: ";

for (int i = 1; i <= n; ++i)
{
// Prints the first two terms.
if(i == 1)
{
// cout << " " << t1;
continue;
}
if(i == 2)
{
//cout << t2 << " ";
continue;
}
nextTerm = t1 + t2;
t1 = t2;
t2 = nextTerm;
  
//cout << nextTerm << " ";
}
int stop_s=clock();
cout<<"time";
cout << double( clock() - tStart ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

return 0;
}