#include <iostream>

using namespace std;

void towerOfHanoi(int n, char src, char dst, char temp)
{
  if (n == 1)
  {
    cout << "Move disc " << n << " from " << src << " to " << dst << endl;
  }
  else
  {
    towerOfHanoi(n - 1, src, temp, dst);
    cout << "Move disc " << n << " from " << src << " to " << dst << endl;
    towerOfHanoi(n - 1, temp, dst, src);
  }
}

int main()
{
  int n;
  cout << "Enter the number of discs: ";
  cin >> n;
  towerOfHanoi(n, 'A', 'C', 'B');
  return 0;
}