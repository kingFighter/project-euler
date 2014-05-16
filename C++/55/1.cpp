// Level: 5
// Brute Force
// Check as the problem describes.
// I really really hate C++ don't have a standard Big Number
// Library!!!!! 

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const vector< int >& n) {
  auto size = n.size();
  for (int i = 0; i < size / 2; ++i) {
    if (n[i] != n[size - i - 1])
      return false;
  }
  return true;
}

void reverseAdd(const vector<int>& n, vector<int>& r) {
  r.clear();
  int c = 0;
  auto size = n.size();
  for (int i = 0; i < size; ++i) {
    div_t d = div(n[i] + n[size - i - 1] + c, 10);
    r.push_back(d.rem);
    c = d.quot;
  }
  if (c != 0)
    r.push_back(c);
}

bool isLychrel(int n) {
  vector< int > a, r;
  while (n != 0) {
    r.push_back( n % 10 );
    n /= 10;
  }

  bool palindrome = false;
  int count = 0;
  while (count <= 50 && !palindrome) {
    a = r;
    reverseAdd(a, r);
    palindrome = isPalindrome(r);
    ++count;
  }

  return !palindrome;
}

int main() {
  int count = 0;
  const int LIMIT = 10000;
  for (int n = 1; n < LIMIT; ++n) {
    if (isLychrel(n))
      ++count;
  }
  cout << "Count = " << count << endl;
  return 0;
}
