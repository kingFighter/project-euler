// Level: 5
// Brute Force
// 1. Generate permutation
// 2. Check that
// Note: the type of number should hold its value! 
// Once again, I did't get it until that I wasted much time.

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

string str = "0123456789";
const int N = 9;
void genNumbers(int, vector<string> &);

int main() {
  vector<string> v;
  genNumbers(0, v);

  int num[7] = {2, 3, 5, 7, 11, 13, 17};
  unsigned  long long sum = 0ULL;

  for (auto str : v) {
    bool find = true;
    for (int i = 0; i < 7; ++i) {
      string t = str.substr(i + 1, 3);
      long n = atol(t.c_str());
      if (n % num[i] != 0) {
        find = false;
        break;
      }
    }
    if (find) {
      long number = atol(str.c_str());
      sum += number;
      cout << number << endl;
    }
  }
  cout << sum << endl;
}

void genNumbers(int m, vector<string> &v) {
  if (N == m) {
    if (str[0] != '0')
      v.push_back(str);
  } else {
    for (int i = m; i <= N; ++i) {
      char t = str[i];
      str[i] = str[m];
      str[m] = t;
      genNumbers(m + 1, v);

      str[m] = str[i];
      str[i] = t;
    }
  }
}
