#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "matrix/msize_t.hpp"
#include <cstdint>
#include <cstddef>
#include <memory>
#include <string>

namespace mtx {
  class matrix {
  public:
    using item_type_t = double;

  private:
    uint32_t rows;
    uint32_t cols;
    item_type_t *_data;

  public:
    matrix() = delete;

    static std::shared_ptr<matrix> create(uint32_t rows, uint32_t cols, item_type_t *data = nullptr);
    [[nodiscard]] std::shared_ptr<matrix> clone() const;

    [[nodiscard]] std::shared_ptr<matrix> add(const std::shared_ptr<matrix> &m) const;
    [[nodiscard]] std::shared_ptr<matrix> sub(const std::shared_ptr<matrix> &m) const;
    [[nodiscard]] std::shared_ptr<matrix> mul(const std::shared_ptr<matrix> &m) const;
    [[nodiscard]] std::shared_ptr<matrix> mul(const item_type_t &scalar) const;
    [[nodiscard]] std::shared_ptr<matrix> transpose() const;
    matrix::item_type_t &operator()(uint32_t row, uint32_t col);

    [[nodiscard]] msize_t size() const;
    item_type_t *data() const;

    [[nodiscard]] std::string to_string(uint32_t indentation = 0) const;

    static uint32_t calc_data_bytes(uint32_t rows, uint32_t cols);
  private:
    matrix(uint32_t rows, uint32_t cols);
  };
} // namespace mtx

#endif //MATRIX_HPP
