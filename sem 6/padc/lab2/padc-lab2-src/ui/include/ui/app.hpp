#ifndef APP_HPP
#define APP_HPP

#include "ctx/ctx.hpp"
#include "ui/main_window.hpp"
#include <QApplication>

namespace ui {
class ui_qt_app {
  QApplication *app;
  main_window *window;
  ctx::ctx &ctx;
  std::function<void()> init_cb;
  std::function<void()> close_cb;

public:
  ui_qt_app(int argc, char *argv[], ctx::ctx &ctx);
  ~ui_qt_app();

  void input();
  void on_init_complete(std::function<void()> &&cb);
  void show_result(const std::shared_ptr<mtx::matrix> &result);
  void on_close(std::function<void()> &&cb);

private:
  void set_n(uint32_t n);
  void set_matricies(ctx::matrix_id id);
  void init_complete();
};
} // namespace ui

#endif // APP_HPP