#ifndef MATRIX_INPUT_WINDOW_HPP
#define MATRIX_INPUT_WINDOW_HPP

#include "matrix/matrix.hpp"
#include "matrix/msize_t.hpp"
#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>

namespace ui {
  class matrix_input_window final : public QDialog {
    Q_OBJECT
    QTableWidget *table;
    QLabel *loading;

    mtx::matrix &m;
    bool is_closed;

  public:
    matrix_input_window(const std::string &title, mtx::matrix &matrix, std::function<void()> &&cb, QWidget *parent = nullptr);
    ~matrix_input_window() override = default;

    void closeEvent(QCloseEvent *event) override;

  private:
    void randomize() const;
  };
}

#endif //MATRIX_INPUT_WINDOW_HPP
