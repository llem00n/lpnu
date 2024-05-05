#ifndef PADC_LAB2_MPI_APP_HPP
#define PADC_LAB2_MPI_APP_HPP

#include "mt_main/ranks.hpp"
#include <memory>
#include <mpi.h>

class mpi_app {
  int argc;
  char **argv;
  static std::unique_ptr<mpi_app> instance;

  mpi_app(int argc, char *argv[]);

public:
  static mpi_app &create(int argc, char *argv[]);

  mpi_app(const mpi_app &) = delete;
  mpi_app &operator=(const mpi_app &) = delete;
  mpi_app(mpi_app &&) = delete;
  mpi_app &operator=(mpi_app &&) = delete;
  ~mpi_app();

  void execute_current();

  void rank_main();
  void rank_1();
  void rank_2();
  void rank_3();

  static ranks get_rank();
  static int get_size();
};

#endif //PADC_LAB2_MPI_APP_HPP
