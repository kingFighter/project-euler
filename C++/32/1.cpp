// Brute Force
#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> product;
  int i,j;
  int num;
  
  // 1 digit * 4 digit = 4 digit
  // 2 digit * 3 digit = 4 digit
  for (i = 2; i <= 99; ++i) {
    set<int> s;
    j = (i > 9) ? 123 : 1234;

    for (; j< 10000 / i + 1; j++) {
      s.clear();
      num = 0;
      int t = j;
      while (t > 0) {
        s.insert(t % 10);
        t /= 10;
        num++;
      }
      t = j * i;
      while (t > 0) {
        s.insert(t % 10);
        t /= 10;
        num++;
      }
      
      t = i;
      while (t > 0) {
        s.insert(t % 10);
        t /= 10;
        num++;
      }

      if (s.size() == 9 && s.count(0) == 0 && num == 9)
        product.insert(i * j);
    }
    
  }
  
  int sum = 0;
  for (auto it : product)
    sum += it;
    
  cout << sum << endl;
  return 0;
}
