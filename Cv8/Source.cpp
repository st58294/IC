#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> m{ 3, 3 };
    int field[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    m.setFrom(field);

    Matrix<int> mt = m.transpose();
    Matrix<int> mmt = m.multiply(mt);
    Matrix<double> mmt_d = mmt.retype<double>();
    Matrix<double> n_d{ 3, 3 };
    double field_one_d[] = { 4.5, 5, 0, 2, -0.5, 7, 1.5, 9, 6 };
    n_d.setFrom(field_one_d);
    Matrix<double> mmtn_d = mmt_d.multiply(n_d);
    Matrix<int> r = mmtn_d.retype<int>();
    Matrix<int> t{ 3, 3 };
    int tfield[] = { 85, 225, 236, 292, 819, 866, 499, 1413, 1496 };
    t.setFrom(tfield);
    std::cout << "r==t ? " << (r.isEqual(t) ? "true" : "false") << std::endl;
    return 0;
}