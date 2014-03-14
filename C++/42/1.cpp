#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isTriangle(const string &);

int main() {
  string str;
  getline(cin, str);
  int pos = 0;
  int count = 0;
  while((pos = str.find_first_of(",")) != string::npos) {
    if (isTriangle(str.substr(1, pos - 2)))
        count++;
    str = str.substr(pos + 1);
  }
    cout << count << endl;
  return 0;

}

bool isTriangle(const string & str) {
  int sum = 0;
  for (int i = 0; i < str.size(); i++) {
    sum += str[i] - 'A' + 1;
  }
  sum *= 2;
  int n = sqrt(sum);
  if (n * (n + 1) == sum)
    return true;
  else
    return false;
}
