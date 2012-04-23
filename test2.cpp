#include <iostream>

using namespace std;

class A {
  // declaring friends allows them to touch privates
  friend int operator+(int,A&);
  friend int doubleValue(const A&);
  
public:
  A(int value = 0) {
    _value = value;
  }
  
private:
  int _value;
};

// must be a const parameter to use implicit constructor
// when given doubleValue(9)
int doubleValue(const A& a) {
  return (2 * a._value);
}

int operator+(int x, A& a) {
  return x + a._value;
}

int operator+(A& a, int x) {
  // commutative, so defer to other operator
  return operator+(x,a);
}

/*
  // the following does not work, because at least one parameter
  // must be a class or enum
int operator+(int x, int y) {
  return (x - y);
}
*/

int main(int argc, char** argv) {
  A a(5);
  A b = 5;
  cout << (5+a) << endl;
  cout << (a + 5) << endl;
  cout << doubleValue(b) << endl;
  cout << doubleValue(9) << endl;
  return 0;
}
