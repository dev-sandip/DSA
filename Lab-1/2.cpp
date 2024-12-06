// fibonacci formula with constant time complexity

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n = 50;
  double phi = (1 + sqrt(5)) / 2;
  unsigned long long fibonacci = round(pow(phi, n) / sqrt(5));

  cout << "Fibonacci(" << n << ") using formula: " << fibonacci << endl;

  return 0;
}
