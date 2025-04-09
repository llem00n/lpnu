#include "ui/app.hpp"
#include "ui/matrix_input_window.hpp"
#include "ui/matrix_output_window.hpp"

using namespace ui;

ui_qt_app::ui_qt_app(int argc, char *argv[], ctx::ctx &ctx) : ctx(ctx) {
  app = new QApplication(argc, argv);
  init_cb = [] {};
}

ui_qt_app::~ui_qt_app() { delete app; }

void ui_qt_app::input() {
  window = new main_window([this](const uint32_t &n) {
    set_n(n);

    set_matricies(ctx::matrix_id::A);
  });
  window->show();

  app->exec();
}

void ui_qt_app::set_n(uint32_t n) {
  ctx.n = n;

  ctx.matrices[ctx::matrix_id::A] = mtx::matrix::create(ctx.n, ctx.n);
  ctx.matrices[ctx::matrix_id::A1] = mtx::matrix::create(ctx.n, ctx.n);
  ctx.matrices[ctx::matrix_id::b1] = mtx::matrix::create(ctx.n, 1);
  ctx.matrices[ctx::matrix_id::c1] = mtx::matrix::create(ctx.n, 1);
  ctx.matrices[ctx::matrix_id::A2] = mtx::matrix::create(ctx.n, ctx.n);
  ctx.matrices[ctx::matrix_id::B2] = mtx::matrix::create(ctx.n, ctx.n);
}

void ui_qt_app::set_matricies(ctx::matrix_id id) {
  if (id == ctx::matrix_id::b) {
    init_complete();
    return;
  }

  matrix_input_window input_window(
      ctx.matrix_names[id], *ctx.matrices[id], [this, id]() {
        set_matricies(static_cast<ctx::matrix_id>(static_cast<int>(id) + 1));
      });
  input_window.exec();
  input_window.show();
}

void ui_qt_app::init_complete() { init_cb(); }

void ui_qt_app::on_init_complete(std::function<void()> &&cb) { init_cb = cb; }

void ui_qt_app::show_result(const std::shared_ptr<mtx::matrix> &result) {
  matrix_output_window output_window("Result", *result);
  output_window.exec();
  output_window.show();
}

void ui_qt_app::on_close(std::function<void()> &&cb) {
  close_cb = cb;
  QObject::connect(app, &QApplication::aboutToQuit, [this]() { close_cb(); });
}