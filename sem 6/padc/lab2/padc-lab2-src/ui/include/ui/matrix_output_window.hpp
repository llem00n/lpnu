#ifndef MATRIX_OUTPUT_WINDOW_HPP
#define MATRIX_OUTPUT_WINDOW_HPP

#include "matrix/matrix.hpp"
#include "matrix/msize_t.hpp"
#include <QDialog>
#include <QLabel>
#include <QMainWindow>
#include <QTableWidget>

namespace ui {
  class matrix_output_window final : public QDialog {
    Q_OBJECT
    QTableWidget *table;

    mtx::matrix &m;
    bool is_closed;

  public:
    matrix_output_window(const std::string &title, mtx::matrix &matrix, QWidget *parent = nullptr);
    ~matrix_output_window() override = default;

    void closeEvent(QCloseEvent *event) override;
  };
}

#endif //MATRIX_OUTPUT_WINDOW_HPP