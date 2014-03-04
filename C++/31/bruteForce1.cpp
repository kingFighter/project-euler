// Brute Force 
#include <iostream>

using namespace std;

int main() {
  int a[8] = {200, 100, 50, 20, 10, 5, 2, 1};
  int left[8] = {200};
  int ways = 0;
  for (int i1 = 0; i1 <= left[0] / a[0]; i1++) {
    left[1] = left[0] - i1 * a[0];
    for (int i2 = 0; i2 <= left[1] / a[1]; i2++) {
      left[2] = left[1] - i2 * a[1];
      for (int i3 = 0; i3 <= left[2] / a[2]; i3++) {
        left[3] = left[2] - i3 * a[2];
        for (int i4 = 0; i4 <= left[3] / a[3]; i4++) {
          left[4] = left[3] - i4 * a[3];
          for (int i5 = 0; i5 <= left[4] / a[4]; i5++) {
            left[5] = left[4] - i5 * a[4];
            for (int i6 = 0; i6 <= left[5] / a[5]; i6++) {
              left[6] = left[5] - i6 * a[5];
              for (int i7 = 0; i7 <= left[6] / a[6]; i7++) {
                left[7] = left[6] - i7 * a[6];
                if ((left[7] / a[7]) * a[7] == left[7]) 
                  ways++;
              }
            }
          }
        }
      }
    }
  }
  cout << ways << endl;
  return 0;
}
