// Dynamic Programming
#include <iostream>

using namespace std;

int main() {
  int target = 200;
  int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200};
  int *ways = new int[target+1];
  ways[0] = 1;
 
  for (int i = 0; i < 8; i++) {
    for (int j = coins[i]; j <= target; j++) {
      ways[j] += ways[j - coins[i]];
    }
  }
  cout << ways[200] << endl;
}
