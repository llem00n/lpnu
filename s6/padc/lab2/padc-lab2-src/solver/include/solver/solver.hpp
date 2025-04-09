#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "ctx/ctx.hpp"
#include "matrix/matrix.hpp"

namespace sv {
class solver {
  ctx::ctx &ctx;

public:
  explicit solver(ctx::ctx &ctx);

  std::shared_ptr<mtx::matrix> y1();
  std::shared_ptr<mtx::matrix> y2();
  std::shared_ptr<mtx::matrix> Y3();
  std::shared_ptr<mtx::matrix> X1();
  std::shared_ptr<mtx::matrix> X2();
  std::shared_ptr<mtx::matrix> X3();
  std::shared_ptr<mtx::matrix> X4();
  std::shared_ptr<mtx::matrix> X();

private:
  [[nodiscard]] std::shared_ptr<mtx::matrix> b() const;
  [[nodiscard]] std::shared_ptr<mtx::matrix> C2() const;
};
} // namespace sv

#endif // SOLVER_HPP