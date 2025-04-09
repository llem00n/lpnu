#ifndef CTX_HPP
#define CTX_HPP

#include "matrix/matrix.hpp"
#include <cstdint>
#include <map>
#include <memory>
#include <string>

namespace ctx {
enum class matrix_id {
  A,
  b1,
  A1,
  c1,
  A2,
  B2,
  b,
  C2,
  y1,
  y2,
  Y3,
  X1,
  X2,
  X3,
  X4,
  X,
};

struct ctx {
  uint32_t n;
  std::map<matrix_id, std::shared_ptr<mtx::matrix>> matrices;
  std::map<matrix_id, std::string> matrix_names;

  ctx();
};
} // namespace ctx

#endif // CTX_HPP