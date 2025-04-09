#ifndef MATRIX_INPUT_WINDOW_H
#define MATRIX_INPUT_WINDOW_H

#include "matrix/matrix.hpp"
#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>

class matrix_input_window final : public QDialog {
  Q_OBJECT
  QTableWidget *table;
  QLabel *loading;

  matrix *m;
  bool is_closed;

public:
  matrix_input_window(const std::string &title, const msize_t &size, std::function<void(matrix *m)> &&cb, QWidget *parent = nullptr);
  ~matrix_input_window() override = default;

  void closeEvent(QCloseEvent *event) override;

private:
  void randomize() const;
};

#endif //MATRIX_INPUT_WINDOW_H
