#include<iostream>

using std::cout;
using std::endl;

int main()
{
  const int x = 21;
  const int y = 21;
  long long  int matrix[x][y];

  for(int i = 0; i < x; i++)
    matrix[i][y - 1] = 1;
  for(int j = 0; j < y; j++)
    matrix[x - 1][j] = 1;

  for (int i = x - 2; i >= 0; i--)
    for (int j = y - 2; j >= 0; j--)
      matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];

  cout << matrix[0][0];
  cout << endl;
}


