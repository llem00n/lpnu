#include "matrix/matrix.hpp"
#include <cstring>
#include <utility>

using namespace mtx;

std::shared_ptr<matrix> matrix::create(uint32_t rows, uint32_t cols, item_type_t *data) {
  const auto mem = malloc(sizeof(matrix) + rows * cols * sizeof(item_type_t));
  auto m = std::shared_ptr<matrix>(new (mem) matrix(rows, cols));
  if (data) {
    std::memcpy(m->_data, data, rows * cols * sizeof(item_type_t));
  }

  return std::move(m);
}

matrix::matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols) {
  _data = reinterpret_cast<item_type_t *>(this + 1);
  std::memset(_data, 0, rows * cols * sizeof(item_type_t));
}

std::shared_ptr<matrix> matrix::clone() const {
  auto m = create(rows, cols);
  std::memcpy(m->_data, _data, rows * cols * sizeof(item_type_t));
  return std::move(m);
}

std::shared_ptr<matrix> matrix::add(const std::shared_ptr<matrix> &m) const {
  auto res = create(rows, cols);
  for (uint32_t i = 0; i < rows * cols; ++i) {
    res->_data[i] = _data[i] + m->_data[i];
  }
  return std::move(res);
}

std::shared_ptr<matrix> matrix::sub(const std::shared_ptr<matrix> &m) const {
  auto res = create(rows, cols);
  for (uint32_t i = 0; i < rows * cols; ++i) {
    res->_data[i] = _data[i] - m->_data[i];
  }
  return std::move(res);
}

std::shared_ptr<matrix> matrix::mul(const std::shared_ptr<matrix> &m) const {
  auto res = create(rows, m->cols);

  for (uint32_t i = 0; i < rows; ++i) {
    for (uint32_t j = 0; j < m->cols; ++j) {
      for (uint32_t k = 0; k < cols; ++k) {
        res->_data[i * m->cols + j] += _data[i * cols + k] * m->_data[k * m->cols + j];
      }
    }
  }
  return std::move(res);
}

std::shared_ptr<matrix> matrix::mul(const item_type_t &scalar) const {
  auto res = create(rows, cols);
  for (uint32_t i = 0; i < rows * cols; ++i) {
    res->_data[i] = _data[i] * scalar;
  }
  return std::move(res);
}

std::shared_ptr<matrix> matrix::transpose() const {
  auto res = create(cols, rows);
  for (uint32_t i = 0; i < rows; ++i) {
    for (uint32_t j = 0; j < cols; ++j) {
      res->_data[j * rows + i] = _data[i * cols + j];
    }
  }
  return std::move(res);
}

matrix::item_type_t &matrix::operator()(uint32_t row, uint32_t col) {
  return _data[row * cols + col];
}

msize_t matrix::size() const {
  return {rows, cols};
}

matrix::item_type_t *matrix::data() const {
  return _data;
}

uint32_t matrix::calc_data_bytes(uint32_t rows, uint32_t cols) {
  return rows * cols * sizeof(item_type_t);
}

std::string matrix::to_string(uint32_t indentation) const {
  std::string res(indentation, ' ');
  for (uint32_t i = 0; i < rows; ++i) {
    for (uint32_t j = 0; j < cols; ++j) {
      res += std::to_string(_data[i * cols + j]) + " ";
    }
    if (i < rows - 1) res += "\n" + std::string(indentation, ' ');
  }
  return res;
}
