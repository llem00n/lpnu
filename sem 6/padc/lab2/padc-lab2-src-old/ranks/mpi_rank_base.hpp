#ifndef RANK_H
#define RANK_H

class mpi_rank_base {
protected:
  int rank;
  int size;

public:
  mpi_rank_base();
  virtual ~mpi_rank_base() = default;

  virtual void run() = 0;
};

#endif //RANK_H
