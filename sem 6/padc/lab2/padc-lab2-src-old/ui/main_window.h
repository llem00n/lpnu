#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLineEdit>

class main_window final : public QMainWindow {
  Q_OBJECT
  QLineEdit *n_input;

public:
  explicit main_window(std::function<void(uint32_t)> &&n_setter, QWidget *parent = nullptr);
  ~main_window() override;
};

#endif //MAIN_WINDOW_H
