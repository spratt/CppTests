#include <iostream>

using namespace std;

class NamedObject {
public:
  NamedObject(string n) {
    name = n;
  }
protected:
  string name;
};

class A : public NamedObject {
public:
  A(string n) : NamedObject(n) {
    cout << "A: " << name << endl;
  }
  ~A() {
    cout << "~A: " << name << endl;
  }
};

class B : public NamedObject {
public:
  B(string n) : NamedObject(n) {
    cout << "B: " << name << endl;
  }
  ~B() {
    cout <<"~B: " << name << endl;
  }
};

class C : public NamedObject {
public:
  C(string n) : a(n), b(n), NamedObject(n) {
    cout << "C: " << name << endl;
  }
  ~C() {
    cout << "~C: " << name << endl;
  }
  A a;
  B b;
};

C c("global");

int main(int argc, char** argv) {
  C c("local");
  return 0;
}
