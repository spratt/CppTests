#include <iostream>

using namespace std;

#define COUNT_OF( arr) (sizeof(arr)/sizeof(0[arr]))

#define COUNT_OF2(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

// constant pointer to constant variable
int size(int const * const a) {
  return COUNT_OF2(a);
}

// constant pointer
int foo(int * const a) {
  return ++(a[0]);
}

// pointer to constant data
int print(int const * a, int asize) {
  if(asize < 1) return 0;
  for(int i = 0; i < asize; ++i)
    cout << *(a++) << " ";
  cout << endl;
  return *(a-1);
}

int main(int argc, char** argv) {
  int s[] = {55, 32, 99, 22};
  int asize = COUNT_OF(s);
  int a[asize];
  for(int i = 0; i < asize; ++i)
    a[i] = s[i];
  cout << size(s) << endl;
  cout << size(a) << endl;
  cout << foo(a) << endl;
  cout << print(a,asize) << endl;
  cout << print(s,asize) << endl;
  // ======================================================================
  int const * const constPtrToConst = s;
  int       * const constPtr        = a;
  int const *       ptrToConst      = s;
  // ======================================================================
  cout << "Constant pointer to constant datum: " << *constPtrToConst << endl;
  cout << "Constant pointer to mutable datum:  " << ++(*constPtr) << endl;
  cout << "Mutable pointer to constant data:   " << *(++ptrToConst) << endl;
  return 0;
}
