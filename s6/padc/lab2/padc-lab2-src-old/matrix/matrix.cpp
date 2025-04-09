#include "matrix.hpp"
#include <random>

void matrix::create(void *mem, const uint32_t &rows, const uint32_t &cols) {
  new(mem) matrix(rows, cols);
}

matrix::matrix(const uint32_t &rows, const uint32_t &cols) : rows(rows), cols(cols) {
  data = static_cast<item_type_t *>(static_cast<void *>(this + 1));
}

size_t matrix::calc_size(const uint32_t &rows, const uint32_t &cols) {
  return sizeof(matrix) + sizeof(item_type_t) * rows * cols;
}

void matrix::add(const matrix *lhs, const matrix *rhs, const matrix *result) {
  for (uint32_t i = 0; i < lhs->rows * lhs->cols; i++) {
    result->data[i] = lhs->data[i] + rhs->data[i];
  }
}

void matrix::sub(const matrix *lhs, const matrix *rhs, const matrix *result) {
  for (uint32_t i = 0; i < lhs->rows * lhs->cols; i++) {
    result->data[i] = lhs->data[i] - rhs->data[i];
  }
}

void matrix::mul(const matrix *lhs, const matrix *rhs, const matrix *result) {
  for (uint32_t i = 0; i < lhs->rows; i++) {
    for (uint32_t j = 0; j < rhs->cols; j++) {
      result->data[i * result->cols + j] = 0;
      for (uint32_t k = 0; k < lhs->cols; k++) {
        result->data[i * result->cols + j] += lhs->data[i * lhs->cols + k] * rhs->data[k * rhs->cols + j];
      }
    }
  }
}

void matrix::mul(const matrix *lhs, const double *scalar, const matrix *result) {
  for (uint32_t i = 0; i < lhs->rows * lhs->cols; i++) {
    result->data[i] = lhs->data[i] * *scalar;
  }
}

void matrix::transpose(const matrix *m, const matrix *result) {
  for (uint32_t i = 0; i < m->rows; i++) {
    for (uint32_t j = 0; j < m->cols; j++) {
      result->data[j * result->cols + i] = m->data[i * m->cols + j];
    }
  }
}

matrix::item_type_t &matrix::operator()(const uint32_t &row, const uint32_t &col) const {
  return data[row * cols + col];
}
