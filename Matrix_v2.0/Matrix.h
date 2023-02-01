#pragma once
#include <iostream>

class Matrix
{
private:
	int size;
	int** arr;

	const Matrix& getBiggestMatrixByPairweisÑomparison(const Matrix& obj);

public:

	Matrix();

	Matrix(int size);

	Matrix(int size, int** tmp_arr);

	Matrix(const Matrix& obj);

	Matrix(Matrix&& obj);

	int getSize() const;

	Matrix& operator=(const Matrix& obj);

	Matrix& operator=(Matrix&& obj);

	// '+'
	Matrix operator+(const int element);

	Matrix& operator+=(const int element);

	Matrix operator+(const Matrix& matrix);

	Matrix& operator+=(const Matrix& matrix);
	//-----------

	// '-'
	Matrix operator-(const int element);

	Matrix& operator-=(const int element);

	Matrix operator-(const Matrix& matrix);

	Matrix& operator-=(const Matrix& matrix);
	//-----------
	
	// '*'
	Matrix operator*(const int element);

	Matrix& operator*=(const int element);

	Matrix operator*(const Matrix& matrix);

	Matrix& operator*=(const Matrix& matrix);
	//-----------

	// '/'

	Matrix operator/(const int element);

	Matrix& operator/=(const int element);

	Matrix operator/(const Matrix& matrix);

	Matrix& operator/=(const Matrix& matrix);
	//-----------

	Matrix& operator++();

	Matrix operator++(int);

	Matrix& operator--();

	Matrix operator--(int);

	bool operator==(const int element);

	bool operator!=(const int element);

	bool operator>(const int element);

	bool operator>=(const int element);

	bool operator<(const int element);

	bool operator<=(const int element);

	bool operator==(const Matrix& matrix);

	bool operator!=(const Matrix& matrix);

	bool operator>(const Matrix& matrix);

	bool operator>=(const Matrix& matrix);

	bool operator<(const Matrix& matrix);

	bool operator<=(const Matrix& matrix);

	friend std::istream& operator>> (std::istream& out, const Matrix& matrix);

	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);

	int*& operator[](const int id);

	int*& operator[](const int id) const;

	int& operator()(int row, int col);

	const int& operator()(int row, int col) const;

	operator int();

	~Matrix();

};

