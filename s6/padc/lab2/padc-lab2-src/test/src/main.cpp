#include "ui/app.hpp"
#include "ctx/ctx.hpp"
#include "matrix/matrix.hpp"
#include <fstream>

template <typename T> class ptr {
  T *data;

public:
  ptr(std::initializer_list<T> list) : data(new T[list.size()]) {
    std::copy(list.begin(), list.end(), data);
  }
  ~ptr() { delete[] data; }

  T *get() { return data; }
};

int main(int argc, char *argv[]) {
  ctx::ctx ctx;
  ui::ui_qt_app app(argc, argv, ctx);

  using ptr_t = ptr<mtx::matrix::item_type_t>;
  using mid = ctx::matrix_id;
  auto &ms = ctx.matrices;

  ctx.n = 3;
  ms[mid::A] = mtx::matrix::create(ctx.n, ctx.n, ptr_t({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  }).get());

  ms[mid::A1] = mtx::matrix::create(ctx.n, ctx.n, ptr_t({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  }).get());

  ms[mid::b1] = mtx::matrix::create(ctx.n, 1, ptr_t({
    1,
    2,
    3
  }).get());

  ms[mid::c1] = mtx::matrix::create(ctx.n, 1, ptr_t({
    1,
    2,
    3
  }).get());

  ms[mid::A2] = mtx::matrix::create(ctx.n, ctx.n, ptr_t({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  }).get());

  ms[mid::B2] = mtx::matrix::create(ctx.n, ctx.n, ptr_t({
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
  }).get());

  ms[mid::b] = mtx::matrix::create(ctx.n, 1, ptr_t({
    17.0 / pow(1, 2),
    17.0 / pow(2, 2),
    17.0 / pow(3, 2)
  }).get());

  ms[mid::C2] = mtx::matrix::create(ctx.n, ctx.n, ptr_t({
    17.0 / (2 * 1 + 1), 17.0 / (2 * 1 + 2), 17.0 / (2 * 1 + 3),
    17.0 / (2 * 2 + 1), 17.0 / (2 * 2 + 2), 17.0 / (2 * 2 + 3),
    17.0 / (2 * 3 + 1), 17.0 / (2 * 3 + 2), 17.0 / (2 * 3 + 3)
  }).get());

  auto y1 = ms[mid::A]->mul(ms[mid::b]);
  auto y2 = ms[mid::A1]->mul(ms[mid::b1]->mul(17)->add(ms[mid::c1]));
  auto Y3 = ms[mid::A2]->mul(ms[mid::B2]->add(ms[mid::C2]));

  auto X1 = Y3->mul(Y3)->mul(Y3);
  auto X2 = y2->transpose()->mul(y1)->mul(Y3);
  auto X3 = y1->mul(y2->transpose());
  auto X4 = Y3->mul(y2)->mul(y1->transpose());

  auto X = X1->add(X2)->add(X3)->add(X4);

  std::ofstream out("output.txt");
  out << "y1\n" << y1->to_string(2) << std::endl;
  out << "\ny2\n" << y2->to_string(2) << std::endl;
  out << "\nY3\n" << Y3->to_string(2) << std::endl;
  out << "\nX1\n" << X1->to_string(2) << std::endl;
  out << "\nX2\n" << X2->to_string(2) << std::endl;
  out << "\nX3\n" << X3->to_string(2) << std::endl;
  out << "\nX4\n" << X4->to_string(2) << std::endl;
  out << "\nX\n" << X->to_string(2) << std::endl;
  out.close();

  app.show_result(X);
}