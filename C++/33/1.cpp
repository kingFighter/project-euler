// Brute Force
#include <iostream>

using namespace std;

int getMaxCommonDivisor(int, int);
int getDenominator(int, int);

int main() {
  int a[2], b[2];
  int i, j;
  double v;
  int fraction[8];
  int count = 0;

  cout << "The four fraction: \n";
  for (i = 10; i < 100; ++i) {
    a[0] = i / 10;
    a[1] = i % 10;
    for (j = i + 1; j < 100; ++j) {
      b[0] = j / 10;
      b[1] = j % 10;

      if (a[1] != b[0])         // from analysis, this condition must
        continue;               // be true
        

      v = static_cast<double>(i) / j;
      for (int k1 = 0; k1 < 2; ++k1) {
        for (int k2 = 0; k2 < 2; ++k2) {
          if (a[k1] == b[k2] && static_cast<double>(a[1 - k1]) / b[1 - k2] == v)  {
            fraction[count++] = i;
            fraction[count++] = j;
            cout << i << " / " << j << endl;
          }
        }
      }
    }
  }

  int numerator = 1, denominator = 1;
  for (i = 0; i < 8 ; i += 2) 
    numerator *= fraction[i];

  for (i = 1; i < 8; i += 2)
    denominator *= fraction[i];
  
  
  cout << "Product: " << numerator << " / " << denominator << " = "
       << getDenominator(numerator, denominator) << endl;
  return 0;
}

int getMaxCommonDivisor(int numerator, int denominator) {
  int temp = denominator % numerator;
  if (0 == temp)
    return numerator;
  else 
    return getMaxCommonDivisor(temp, numerator);

}
int getDenominator(int numerator, int denominator) {
  return denominator / getMaxCommonDivisor(numerator, denominator);
}
