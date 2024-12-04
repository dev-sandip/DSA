// fibonacci formula with constant time complexity

#include <iostream>
#include <cmath>
using namespace std;

unsigned long long fibonacciFormula(int n)
{
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

int main()
{
  int n = 50;
  cout << "Fibonacci(" << n << ") using formula: " << fibonacciFormula(n) << endl;
  return 0;
}