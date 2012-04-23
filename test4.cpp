#include <iostream>
#include <iomanip>

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

  T get(int row, int col) const {
    return a[row][col];
  }

  void set(int row, int col, T datum) {
    a[row][col] = datum;
  }

  int getRows() const { return rows; }
  int getCols() const { return cols; }

private:
  T** a;
  int rows, cols;
};

template<class T>
ostream& operator<<(ostream& out, const TwoDimensionalArray<T>& tda) {
  for(int row = 0; row < tda.getRows(); ++row) {
    out << setw(2) << tda.get(row,0);
    for(int col = 1; col < tda.getCols(); ++col)
      out << " " << setw(2) << tda.get(row,col);
    out << endl;
  }
  return out;
}

int main(int argc, char** argv) {
  int rows = 5, cols = 5;
  TwoDimensionalArray<int> tda(rows,cols);
  {
    int i = 0;
    for(int row = 0; row < rows; ++row)
      for(int col = 0; col < cols; ++col)
	tda.set(row,col,++i);
  }
  cout << "TDA:" << endl << tda;
  return 0;
}
