#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>
#include <cstddef>

typedef struct range {
  int32_t start;
  int32_t end;
} range_t;

typedef struct msize {
  uint32_t rows;
  uint32_t cols;
} msize_t;

class matrix {
public:
  using item_type_t = double;

private:
  uint32_t rows;
  uint32_t cols;
  item_type_t *data;

public:
  matrix() = delete;

  static void create(void *mem, const uint32_t &rows, const uint32_t &cols);

  static void add(const matrix *lhs, const matrix *rhs, const matrix *result);
  static void sub(const matrix *lhs, const matrix *rhs, const matrix *result);
  static void mul(const matrix *lhs, const matrix *rhs, const matrix *result);
  static void mul(const matrix *lhs, const double *scalar, const matrix *result);
  static void transpose(const matrix *m, const matrix *result);

  static size_t calc_size(const uint32_t &rows, const uint32_t &cols);

  item_type_t &operator()(const uint32_t &row, const uint32_t &col) const;

private:
  matrix(const uint32_t &rows, const uint32_t &cols);
};

#endif //MATRIX_H
