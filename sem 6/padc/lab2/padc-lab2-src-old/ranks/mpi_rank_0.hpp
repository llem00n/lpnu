#ifndef MPIRANK0_H
#define MPIRANK0_H

#include <cstdint>
#include <QApplication>

#include "matrix/matrix.hpp"
#include "ranks/mpi_rank_base.hpp"
#include "ui/main_window.h"

class mpi_rank_0 final : public mpi_rank_base {
  enum class MatrixID {
    A,                             // INPUT
    b1,                            // INPUT
    A1,                            // INPUT
    c1,                            // INPUT
    A2,                            // INPUT
    B2,                            // INPUT
    C2,                            // Cij = 17 / (2i + j)
    b,                             // bi = 17 / i^2
    y1,                            // y1 = A * b
    y2,                            // y2 = A1 * (17b1 + c1)
    Y3,                            // A2 * (B2 + C2)
    b1_17,                         // 17b1
    b1_17_c1,                      // 17b1 + c1
    B2_C2,                         // B2 + C2
    Y3_S,                          // Y3^2
    Y3_Q,                          // Y3^3
    y2_t,                          // (y2 transposed)
    y1_t,                          // (y1 transposed)
    y1_y2_t,                       // y1 * (y2 transposed)
    y2_t_y1,                       // (y2 transposed) * y1
    y2_t_y1_Y3,                    // (y2 transposed) * y1 * Y3
    Y3_y2,                         // Y3 * y2
    Y3_y2_y1_t,                    // Y3 * y2 * (y1 transposed)
    Y3_Q_y2_t_y1_Y3,               // Y3^3 + (y2 transposed) * y1 * Y3
    Y3_Q_y2_t_y1_Y3_Y3_y2_y1_t,    // Y3^3 + (y2 transposed) * y1 * Y3 + Y3 * y2 * (y1 transposed)
    Length
  };

  QApplication app;
  main_window *win;
  uint32_t n;
  std::map<MatrixID, matrix> matricies;
  std::map<MatrixID, std::string> matrix_names;

public:
  mpi_rank_0(int argc, char **argv);
  ~mpi_rank_0() override = default;

  void run() override;

private:
  void set_n(const uint32_t &n);
  void set_matricies(MatrixID matrix_id);
  void on_init_complete();
};


#endif //MPIRANK0_H
