// Brute Force
#include <iostream>
#include <set>

using namespace std;

bool check(int);

int main() {
  int i = 10;
  while (!check(i)) {
    i++;
  }
  cout << i << endl;
  return 0;
}

bool check(int n) {
  int t = n;
  set<int> s;
  while (t > 0) {
    s.insert(t % 10);
    t /= 10;
  }
  int i;
  for (i = 2; i <= 6; ++i) {
    set<int> ss;
    t = i * n;
    while (t > 0) {
      ss.insert(t % 10);
      t /= 10;
    }
    if (s != ss)
      break;
  }
  if (7 == i)
    return true;
  else
    return false;
}
