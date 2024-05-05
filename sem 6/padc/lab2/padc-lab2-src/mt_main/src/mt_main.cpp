#include "mt_main/ranks.hpp"
#include "mt_main/mpi_app.hpp"
#include <mpi.h>
#include <iostream>

int main(int argc, char *argv[]) {
  MPI_Init(&argc, &argv);
  auto &app = mpi_app::create(argc, argv);

  if (mpi_app::get_size() < static_cast<int>(ranks::LENGTH)) {
    if (mpi_app::get_rank() == ranks::MAIN) {
      std::cerr << "Need at least " << static_cast<int>(ranks::LENGTH) << " ranks" << std::endl;
    }

    return 1;
  }

  app.execute_current();
}