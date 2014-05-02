// Level: 5
// Brute Force Big Number multiply

#include <iostream>

using namespace std;

void numToArr(int , int *);
int sumNumMulNum(int *, int);

int main() {
  int result[200] = {0};

  int sum = 0;
  for (int i = 1; i < 100; ++i) {
    numToArr(i, result);
    for (int j = 2 - 1; j < 100 - 1; ++j) {
      int t = sumNumMulNum(result, i);
      if (sum < t)
        sum = t;
    }
  }
  cout << sum << endl;
  return 0;
}

void numToArr(int n, int *arr) {
  int i = 0;
  while (n != 0) {
    arr[++i] = n % 10;
    n /= 10;
  }
  arr[0] = i;
}

int sumNumMulNum(int *result, int num) {
  int sizeRe = result[0];
  int t = 0;
  int j;
  for (j = 1; j <= sizeRe; ++j) {
    t += num * result[j];
    result[j] = t % 10;
    t /= 10;
  }
  while (t > 0) {
    result[++sizeRe] = t % 10;
    t /= 10;
  }
  result[0] = sizeRe;

  int sum = 0;
  for  (int i = 1; i <= sizeRe; ++i)
    sum += result[i];
  return sum;
}
