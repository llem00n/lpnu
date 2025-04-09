#include "solver/solver.hpp"
#include <cmath>
#include <iostream>

using namespace sv;

solver::solver(ctx::ctx &ctx) : ctx(ctx) {}

std::shared_ptr<mtx::matrix> solver::b() const {
  const auto b = mtx::matrix::create(ctx.n, 1);
  for (uint32_t i = 0; i < ctx.n; ++i) {
    (*b)(i, 0) = 17 / pow(i + 1, 2);
  }
  return b;
}

std::shared_ptr<mtx::matrix> solver::y1() {
  return ctx.matrices[ctx::matrix_id::y1] = ctx.matrices[ctx::matrix_id::A]->mul(b());
}

std::shared_ptr<mtx::matrix> solver::y2() {
  return ctx.matrices[ctx::matrix_id::y2] = ctx.matrices[ctx::matrix_id::y2] = ctx.matrices[ctx::matrix_id::A1]->mul(
      ctx.matrices[ctx::matrix_id::b1]->mul(17)->add(
          ctx.matrices[ctx::matrix_id::c1]));
}

std::shared_ptr<mtx::matrix> solver::C2() const {
  const auto C2 = mtx::matrix::create(ctx.n, ctx.n);
  for (uint32_t i = 0; i < ctx.n; ++i) {
    for (uint32_t j = 0; j < ctx.n; ++j) {
      (*C2)(i, j) = 17.0 / (2 * (i + 1) + (j + 1));
    }
  }
  return C2;
}

std::shared_ptr<mtx::matrix> solver::Y3() {
  return ctx.matrices[ctx::matrix_id::Y3] = ctx.matrices[ctx::matrix_id::A2]->mul(
      ctx.matrices[ctx::matrix_id::B2]->add(C2()));
}

std::shared_ptr<mtx::matrix> solver::X1() {
  return ctx.matrices[ctx::matrix_id::X1] = ctx.matrices[ctx::matrix_id::Y3]->mul(ctx.matrices[ctx::matrix_id::Y3])->mul(ctx.matrices[ctx::matrix_id::Y3]);
}

std::shared_ptr<mtx::matrix> solver::X2() {
  return ctx.matrices[ctx::matrix_id::X2] = ctx.matrices[ctx::matrix_id::y2]->transpose()->mul(ctx.matrices[ctx::matrix_id::y1])->mul(ctx.matrices[ctx::matrix_id::Y3]);
}

std::shared_ptr<mtx::matrix> solver::X3() {
  return ctx.matrices[ctx::matrix_id::X3] = ctx.matrices[ctx::matrix_id::y1]->mul(ctx.matrices[ctx::matrix_id::y2]->transpose());
}

std::shared_ptr<mtx::matrix> solver::X4() {
  return ctx.matrices[ctx::matrix_id::X4] = ctx.matrices[ctx::matrix_id::Y3]->mul(ctx.matrices[ctx::matrix_id::y2])->mul(ctx.matrices[ctx::matrix_id::y1]->transpose());
}

std::shared_ptr<mtx::matrix> solver::X() {
  return ctx.matrices[ctx::matrix_id::X] = ctx.matrices[ctx::matrix_id::X1]->add(ctx.matrices[ctx::matrix_id::X2])->add(ctx.matrices[ctx::matrix_id::X3])->add(ctx.matrices[ctx::matrix_id::X4]);
}