// Level: 3
// Brute Force
// 1. Adjust the numbers according the three digits' order until no
// adjustment happens.
// 2. For example, (a, b, c) if now the order is dceba then we adjust
// it to dceba->dbcea->dabce
// 3. Anyway, I didn't prove why this procedure will stop, it just
// works!
// Another way to solve this is to use 'Topological sorting'
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int a[3];
int c = 0;
void helper();

int main() {
  int n;
  vector<int> all;
  
  while (cin >> n) {
    int i = 3;

    while (n != 0) {
      int m = n % 10;
      n /= 10;
      a[--i] = m;
    }
    for (int i = 0; i < 3; ++i) {
      all.push_back(a[i]);
    }
  }
  int tc;
  do {
    tc = c;
    for (int i = 0; i < all.size();) {
      a[0] = all[i++];
      a[1] = all[i++];
      a[2] = all[i++];
      helper();
    }
  } while (c != tc);
  for (auto i : v)
    cout << i;
  cout << endl;
  return 0;
}

void helper() {
  bool exist1, exist2, exist3;

  auto it1 = find(v.begin(), v.end(), a[0]);
  exist1 = !(it1 == v.end());
  auto it2 = find(v.begin(), v.end(), a[1]);
  exist2 = !(it2 == v.end());
  auto it3 = find(v.begin(), v.end(), a[2]);
  exist3 = !(it3 == v.end());
  
  if (!exist1)
    v.push_back(a[0]);
  if (!exist2)
    v.push_back(a[1]);
  if (!exist3)
    v.push_back(a[2]);

  if (exist2 && exist3 && it2 > it3) {
    v.erase(it2);
    it3 = find(v.begin(), v.end(), a[2]);
    v.insert(it3, a[1]);

    it1 = find(v.begin(), v.end(), a[0]);
    it2 = find(v.begin(), v.end(), a[1]);
    it3 = find(v.begin(), v.end(), a[2]);
    ++c;
  }
  if (exist1 && exist2 && it1 > it2) {
    v.erase(it1);
    it2 = find(v.begin(), v.end(), a[1]);
    v.insert(it2, a[0]);
    it1 = find(v.begin(), v.end(), a[0]);
    it2 = find(v.begin(), v.end(), a[1]);
    it3 = find(v.begin(), v.end(), a[2]);
    ++c;
  }
}
