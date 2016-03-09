/*
  Egyptian Multiplication
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

/*
  helper functions
*/
bool odd(int n) { return n & 0x1; }

int half(int n) { return n >> 1; }

/*
  1a = a
  (n + 1)a = na + a
*/
int multiply0(int n, int a) {
  if (n == 1) return a;
  return multiply0(n - 1, a) + a;
}

int multiply1(int n, int a) {
  if (n == 1) return a;
  int result = multiply1(half(n), a + a);
  if (odd(n)) result = result + a;
  return result;
}

int multiply_by_15(int a) {
  int b = (a + a) + a;
  int c = b + b;
  return (c + c) + b;
}

int main(int argc, char* argv[]) {
  if (argc < 3) return -1;
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  cout << "Input: " << a << ", " << b << endl;
  cout << a << " * " << b << " = " << multiply0(a,b) << endl;
  cout << a << " * " << b << " = " << multiply1(a,b) << endl;

  cout << "Multiply a by 15"<< endl;
  cout << a << " * 15 = " << multiply_by_15(a) << endl;


  return 0;
}
