#include "mpi_rank_base.hpp"

#include <mpi.h>

mpi_rank_base::mpi_rank_base(): rank(0), size(0) {
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
}
