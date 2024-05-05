#include "ranks/mpi_rank_0.hpp"

#include <iostream>
#include <QApplication>

#include "ui/main_window.h"
#include "ui/matrix_input_window.h"

mpi_rank_0::mpi_rank_0(int argc, char **argv): app(argc, argv), win(nullptr), n(0) {
  matrix_names = {
    {MatrixID::A, "Matrix A"},
    {MatrixID::b, "Matrix b"},
    {MatrixID::A1, "Matrix A1"},
    {MatrixID::b1, "Matrix b1"},
    {MatrixID::c1, "Matrix c1"},
    {MatrixID::A2, "Matrix A2"},
    {MatrixID::B2, "Matrix B2"},
    {MatrixID::C2, "Matrix C2"},
    {MatrixID::y1, "Matrix y1"},
    {MatrixID::y2, "Matrix y2"},
    {MatrixID::Y3, "Matrix Y3"}
  };
}

void mpi_rank_0::run() {
  win = new class main_window([this](const uint32_t n) {
    set_n(n);

    set_matricies(MatrixID::A);
  });
  win->show();

  QApplication::exec();
}

void mpi_rank_0::set_n(const uint32_t &n) {
  this->n = n;

  // matricies[MatrixID::A].set_size(n, n);
  // matricies[MatrixID::b].set_size(n, 1);
  // matricies[MatrixID::A1].set_size(n, n);
  // matricies[MatrixID::b1].set_size(n, 1);
  // matricies[MatrixID::c1].set_size(n, 1);
  // matricies[MatrixID::A2].set_size(n, n);
  // matricies[MatrixID::B2].set_size(n, n);
  // matricies[MatrixID::C2].set_size(n, n);
}

void mpi_rank_0::set_matricies(MatrixID matrix_id) {
  // if (matrix_id == MatrixID::C2) {
  //   on_init_complete();
  //   return;
  // }
  //
  // matrix_input_window matrix_input(matrix_names[matrix_id], matricies[matrix_id].get_size(), [this, matrix_id, &matrix_input](const matrix &m) {
  //   matricies[matrix_id] = m;
  //   matrix_input.close();
  //
  //   set_matricies(static_cast<MatrixID>(static_cast<int>(matrix_id) + 1));
  // }, win);
  //
  // matrix_input.exec();
  // matrix_input.show();
}

void mpi_rank_0::on_init_complete() {
  std::cout << "Init complete" << std::endl;
}