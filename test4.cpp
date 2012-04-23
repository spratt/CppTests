#include <iostream>

using namespace std;

template<class T>
class TwoDimensionalArray {
public:
  TwoDimensionalArray(int r, int c) :
    rows(r), cols(c) {
    a = new T*[rows];
    for(int row = 0; row < rows; ++row)
      a[row] = new T[cols];
  }

  T get(int row, int col) {
    return a[row][col];
  }

  void set(int row, int col, T datum) {
    a[row][col] = datum;
  }

  int getRows() { return rows; }
  int getCols() { return cols; }

private:
  T** a;
  int rows, cols;
};

template<class T>
ostream& operator<<(ostream& out, TwoDimensionalArray<T> tda) {
  for(int row = 0; row < tda.getRows(); ++row) {
    out << tda.get(row,0);
    for(int col = 1; col < tda.getCols(); ++col)
      out << " " << tda.get(row,col);
    out << endl;
  }
  return out;
}

int main(int argc, char** argv) {
  TwoDimensionalArray<int> tda(2,2);
  tda.set(0,0,1);
  tda.set(0,1,2);
  tda.set(1,0,3);
  tda.set(1,1,4);
  cout << "TDA:" << endl << tda;
  return 0;
}
