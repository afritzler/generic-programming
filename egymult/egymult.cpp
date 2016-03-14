/*
  Egyptian Multiplication
*/
#include <iostream>
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

/*
  Multiply accumulate funtion
*/
int mult_acc0(int r, int n, int a) {
  if (n == 1) return r + a;
  if (odd(n)) {
    return mult_acc0(r + a, half(n), a + a);
  } else {
    return mult_acc0(r, half(n), a + a);
  }
}

int mult_acc1(int r, int n, int a) {
  if (n == 1) return r + a;
  if (odd(n)) return r = r + a;
  return mult_acc1(r, half(n), a + a);
}

int mult_acc2(int r, int n, int a) {
  if (odd(n)) {
    r = r + a;
    if (n == 1) return r;
  }
  return mult_acc2(r, half(n), a + a);
}

int mult_acc3(int r, int n, int a) {
  if (odd(n)) {
    r = r + a;
    if (n == 1) return r;
  }
  n = half(n);
  a = a + a;
  return mult_acc3(r, n, a);
}

int mult_acc4(int r, int n, int a) {
  while (true) {
    if (odd(n)) {
      r = r + a;
      if (n == 1) return r;
    }
    n = half(n);
    a = a + a;
  }
}

int multiply2(int n, int a) {
  if (n == 1) return a;
  return mult_acc4(a, n - 1, a);
}

int multiply3(int n, int a) {
  while(!odd(n)) {
    a = a + a;
    n = half(n);
  }
  if (n == 1) return a;
  return mult_acc4(a, n - 1, a);
}

int multiply4(int n, int a) {
  while(!odd(n)) {
    a = a + a;
    n = half(n);
  }
  if (n == 1) return a;
  // even(n-1) -> n-1 != 1
  return mult_acc4(a, half(n - 1), a + a);
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

  cout << "Multiply accumulate"<< endl;
  cout << a << " * " << b << " = " << multiply2(a,b) << endl;
  cout << a << " * " << b << " = " << multiply3(a,b) << endl;
  cout << a << " * " << b << " = " << multiply4(a,b) << endl;

  return 0;
}
