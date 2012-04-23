#include <iostream>

using namespace std;

class A {
public:
  A() {
    cout << "A" <<endl;
  }
  ~A() {
    cout << "~A" <<endl;
  }
};

class B {
public:
  B() {
    cout << "B" << endl;
  }
  ~B() {
    cout <<"~B" << endl;
  }
};

class C {
public:
  C() : a(), b() {
    cout << "C" << endl;
  }
  ~C() {
    cout << "~C" << endl;
  }
  B b;
  A a;
};

int main(int argc, char** argv) {
  C c;
  return 0;
}
