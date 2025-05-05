#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimension mismatch.";
    }
};

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c, const T& initial = T())
        : rows(r), cols(c), data(r, vector<T>(c, initial)) {}

    size_t rowCount() const { return rows; }
    size_t colCount() const { return cols; }

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix index out of bounds");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols)
            throw out_of_range("Matrix index out of bounds");
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.at(i, j) = this->at(i, j) + other.at(i, j);
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& el : row)
                cout << el << " ";
            cout << "\n";
        }
    }
};
