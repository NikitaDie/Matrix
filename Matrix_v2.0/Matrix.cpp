#include "Matrix.h"
#include <cassert>

const Matrix& Matrix::getBiggestMatrixByPairweis�omparison(const Matrix& matrix) {	//can use only when sizes are equal
	
	int tmp_points{ 0 };

	for (int i{ 0 }; i < this->size; ++i) {
		for (int j{ 0 }; j < this->size; ++j) {
			if (this->arr[i][j] > matrix.arr[i][j]) ++tmp_points;
		}
	}

	if (tmp_points > this->size / 2) return *this;
	else if (tmp_points < this->size / 2) return matrix;
	else {
		for (int i{ 0 }; i < this->size; ++i) {
			for (int j{ 0 }; j < this->size; ++j) {
				if (this->arr[i][j] > matrix.arr[i][j]) return *this;
				else if (this->arr[i][j] < matrix.arr[i][j]) return matrix;
			}
		}
	}
}

Matrix::Matrix() :
	size{ 0 },
	arr{ nullptr }
{
}

Matrix::Matrix(int size) :
	size{ size },
	arr{ new int* [size] }
{
	for (int i{ 0 }; i < size; ++i) {
		arr[i] = new int[size];
	}
}


Matrix::Matrix(int size, int** tmp_arr) :
	size{ size },
	arr{ new int*[size] }
{
	for (int i{ 0 }; i < size; ++i) {
		arr[i] = new int[size] {};
		for (int j{ 0 }; j < size; ++j) {
			arr[i][j] = tmp_arr[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& obj) :
	size{ obj.size },
	arr{ new int*[obj.size] }
{
	for (int i{ 0 }; i < obj.size; ++i) {
		arr[i] = new int[obj.size];
		for (int j{ 0 }; j < obj.size; ++j) {
			arr[i][j] = obj.arr[i][j];
		}
	}
}

Matrix::Matrix(Matrix&& obj) :
	size{ obj.size },
	arr{ obj.arr }
{
	obj.arr = nullptr;
}
////

int Matrix::getSize() const
{
	return this->size;
}

////

Matrix& Matrix::operator=(const Matrix& obj)
{
	if (this == &obj)
		return *this;

	if (this->arr != nullptr) {

		for (int i{ 0 }; i < this->size; ++i) {
			delete[] this->arr[i];
		}

		delete[] this->arr;
	}


	this->size = obj.size;
	this->arr = new int*[obj.size];

	for (int i{ 0 }; i < this->size; ++i) {
		this->arr[i] = new int[obj.size];
		for (int j{ 0 }; j < this->size; ++j) {
			this->arr[i][j] = obj.arr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& obj)
{
	delete[] this->arr;

	this->size = obj.size;
	this->arr = obj.arr;

	obj.arr = nullptr;

	return *this;
}


//araphmetic operators

Matrix Matrix::operator+(const int element)
{
	Matrix tmp_matrix{ *(this) };
	for (int i = 0; i < tmp_matrix.size; ++i) {
		for (int j = 0; j < tmp_matrix.size; ++j) {
			tmp_matrix.arr[i][j] += element;
		}
	}
	return tmp_matrix;
}


Matrix& Matrix::operator+=(const int element)
{
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			this->arr[i][j] += element;
		}
	}
	return *this;
}


Matrix Matrix::operator+(const Matrix& matrix)
{
	Matrix tmp_matrix;

	if (this->size >= matrix.size) {
		tmp_matrix = *this;

			for (int i = 0; i < matrix.size; ++i) {
				for (int j = 0; j < matrix.size; ++j) {
					tmp_matrix.arr[i][j] += matrix.arr[i][j];
				}
			}
	}
	else {

		tmp_matrix = matrix;

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] += this->arr[i][j];
			}
		}

	}
	return tmp_matrix;
}

Matrix& Matrix::operator+=(const Matrix& matrix)
{

	if (this->size >= matrix.size) {

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				this->arr[i][j] += matrix.arr[i][j];
			}
		}
	}
	else {

		Matrix tmp_matrix{ matrix };

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] += this->arr[i][j];
			}
		}

		*this = tmp_matrix;

	}
	return *this;
}

Matrix Matrix::operator-(const int element)
{
	Matrix tmp_matrix{ *(this) };
	for (int i = 0; i < tmp_matrix.size; ++i) {
		for (int j = 0; j < tmp_matrix.size; ++j) {
			tmp_matrix.arr[i][j] -= element;
		}
	}
	return tmp_matrix;
}

Matrix& Matrix::operator-=(const int element)
{
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			this->arr[i][j] -= element;
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& matrix)
{
	Matrix tmp_matrix;

	if (this->size >= matrix.size) {
		tmp_matrix = *this;

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				tmp_matrix.arr[i][j] -= matrix.arr[i][j];
			}
		}
	}
	else {

		tmp_matrix = matrix;

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] -= this->arr[i][j];
			}
		}

	}
	return tmp_matrix;
}

Matrix& Matrix::operator-=(const Matrix& matrix)
{

	if (this->size >= matrix.size) {

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				this->arr[i][j] -= matrix.arr[i][j];
			}
		}
	}
	else {

		Matrix tmp_matrix{ matrix };

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] -= this->arr[i][j];
			}
		}

		*this = tmp_matrix;

	}
	return *this;
}

Matrix Matrix::operator*(const int element)
{
	Matrix tmp_matrix{ *(this) };
	for (int i = 0; i < tmp_matrix.size; ++i) {
		for (int j = 0; j < tmp_matrix.size; ++j) {
			tmp_matrix.arr[i][j] *= element;
		}
	}
	return tmp_matrix;
}

Matrix& Matrix::operator*=(const int element)
{
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			this->arr[i][j] *= element;
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& matrix)
{
	Matrix tmp_matrix;

	if (this->size >= matrix.size) {
		tmp_matrix = *this;

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				tmp_matrix.arr[i][j] *= matrix.arr[i][j];
			}
		}
	}
	else {

		tmp_matrix = matrix;

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] *= this->arr[i][j];
			}
		}

	}
	return tmp_matrix;
}

Matrix& Matrix::operator*=(const Matrix& matrix)
{

	if (this->size >= matrix.size) {

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				this->arr[i][j] *= matrix.arr[i][j];
			}
		}
	}
	else {

		Matrix tmp_matrix{ matrix };

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				tmp_matrix.arr[i][j] *= this->arr[i][j];
			}
		}

		*this = tmp_matrix;

	}
	return *this;
}

Matrix Matrix::operator/(const int element)
{
	Matrix tmp_matrix{ *(this) };
	for (int i = 0; i < tmp_matrix.size; ++i) {
		for (int j = 0; j < tmp_matrix.size; ++j) {
			tmp_matrix.arr[i][j] /= element;
		}
	}
	return tmp_matrix;
}

Matrix& Matrix::operator/=(const int element)
{
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			this->arr[i][j] /= element;
		}
	}
	return *this;
}

Matrix Matrix::operator/(const Matrix& matrix)
{
	Matrix tmp_matrix;

	if (this->size >= matrix.size) {
		tmp_matrix = *this;

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				if (matrix.arr[i][j] == 0) continue;
				tmp_matrix.arr[i][j] /= matrix.arr[i][j];
			}
		}
	}
	else {

		tmp_matrix = matrix;

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				if (matrix.arr[i][j] == 0) continue;
				tmp_matrix.arr[i][j] /= this->arr[i][j];
			}
		}

	}
	return tmp_matrix;
}

Matrix& Matrix::operator/=(const Matrix& matrix)
{

	if (this->size >= matrix.size) {

		for (int i = 0; i < matrix.size; ++i) {
			for (int j = 0; j < matrix.size; ++j) {
				if (matrix.arr[i][j] == 0) continue;
				this->arr[i][j] /= matrix.arr[i][j];
			}
		}
	}
	else {

		Matrix tmp_matrix{ matrix };

		for (int i = 0; i < this->size; ++i) {
			for (int j = 0; j < this->size; ++j) {
				if (matrix.arr[i][j] == 0) continue;
				tmp_matrix.arr[i][j] /= this->arr[i][j];
			}
		}

		*this = tmp_matrix;

	}
	return *this;
}

Matrix& Matrix::operator++() //prefix
{
	*(this) + 1;
	return *this;
}

Matrix Matrix::operator++(int) //postfix
{
	Matrix temp{ *this };
	++(*this);
	return temp;
}

Matrix& Matrix::operator--() //prefix
{
	*(this) - 1;
	return *this;
}

Matrix Matrix::operator--(int) //postfix
{
	Matrix temp{ *this };
	--(*this);
	return temp;
}

// bool operators

bool Matrix::operator==(const int element)
{
	return (int)*this == element;
}

bool Matrix::operator!=(const int element)
{
	return (int)*this != element;
}

bool Matrix::operator>(const int element)
{
	return (int)*this >= element;
}

bool Matrix::operator>=(const int element)
{
	return (int)*this >= element;
}

bool Matrix::operator<(const int element)
{
	return (int)*this < element;
}

bool Matrix::operator<=(const int element)
{
	return (int)*this <= element;
}

bool Matrix::operator==(const Matrix& matrix) 
{
	for (int i = 0; i < matrix.size; ++i) {
		for (int j = 0; j < matrix.size; ++j) {
			if (this->arr[i][j] != matrix.arr[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& matrix)
{
	for (int i = 0; i < matrix.size; ++i) {
		for (int j = 0; j < matrix.size; ++j) {
			if (this->arr[i][j] != matrix.arr[i][j]) {
				return true;
			}
		}
	}

	return false;
}

bool Matrix::operator>(const Matrix& matrix)
{
	if (this->size > matrix.size) return true;

	if (this->size < matrix.size) return false;

	if (this->size == matrix.size || *this != matrix) {
		if (&getBiggestMatrixByPairweis�omparison(matrix) == &matrix) return false;
	}

	return true;
}

bool Matrix::operator>=(const Matrix& matrix)
{
	if (*this > matrix or *this == matrix)
		return true;

	return false;
}

bool Matrix::operator<(const Matrix& matrix)
{
	if (this->size < matrix.size) return true;

	if (this->size > matrix.size) return false;

	if (this->size == matrix.size || *this != matrix) {
		if (&getBiggestMatrixByPairweis�omparison(matrix) == &matrix) return true;
	}

	return false;
}

bool Matrix::operator<=(const Matrix& matrix)
{
	if (*this < matrix or *this == matrix)
		return true;

	return false;
}

//bit operators
std::istream& operator>> (std::istream& in, const Matrix& matrix)
{

	for (int i = 0; i < matrix.size; ++i) {
		for (int j = 0; j < matrix.size; ++j) {
			in >> matrix.arr[i][j];
		}
	}

	return in;  //�������� �����?
}

std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
	if (matrix.arr == nullptr) {
		return out;
	}

	out << "\n";

	for (int i = 0; i < matrix.size; ++i) {
		for (int j = 0; j < matrix.size; ++j) {
			out << matrix.arr[i][j] << " ";
		}
		out << "\n";
	}

	return out;
}

//others

int*& Matrix::operator[](const int id)
{
	assert(id >= 0 && id < this->size);

	return this->arr[id];
}

int*& Matrix::operator[](const int id) const
{
	assert(id >= 0 && id < this->size);

	return this->arr[id];
}

int& Matrix::operator()(int row, int col)
{
	assert(row >= 0 && row < this->size);
	assert(col >= 0 && col < this->size);

	return this->arr[row][col];
}

const int& Matrix::operator()(int row, int col) const
{
	assert(row >= 0 && row < this->size);
	assert(col >= 0 && col < this->size);

	return this->arr[row][col];
}

Matrix::operator int()
{
	if (size == 0) return 0;

	int tmp_sum{ 0 };

	for (int i{ 0 }; i < this->size; ++i) {
		for (int j{ 0 }; j < this->size; ++j) {
			tmp_sum += this->arr[i][j];
		}
	}

	return tmp_sum; //?
}

Matrix::~Matrix()
{
	if (this->arr != nullptr) {
		for (int i{ 0 }; i < this->size; ++i) {
			delete[] this->arr[i];
		}

		delete[] this->arr;
	}
}

