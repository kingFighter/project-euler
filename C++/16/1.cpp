/*****************************************************************
 Project Euler - Problem 16

 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

 What is the sum of the digits of the number 21000?
******************************************************************/

#include <iostream>
#include <string>

using namespace std;

int C2I(char); //char to int converter
char I2C(int); //int to char converter
string X2(string); //Multiplies a given integer (represented as by a string) by two,
                   //the maximum size of operand is theoretically infinite!
int main()
{
    string two = "2";

    for (int i = 0; i < 999; i++)
        two = X2(two);

    int sum = 0;

    for (int i = 0; i < (int)two.length(); i++)
        sum += (int)two[i] - 48;

    cout << "Answer = " << sum << endl;
    return 0;
}

int C2I(char c)
{
    return int(c) - 48;
}
char I2C(int n)
{
    return char(n) + 48;
}
string X2(string number)
{
    string answer = "";
    int digit, result, carry = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        digit = C2I(number[i]);
        result = (digit * 2) + carry;

        if (result >= 10)
        {
            carry = result / 10;
            result = result % 10;
        }
        else
            carry = 0;
        answer = I2C(result) + answer;
    }
    if (carry != 0)
        answer = I2C(carry) + answer;
    return answer;
}
