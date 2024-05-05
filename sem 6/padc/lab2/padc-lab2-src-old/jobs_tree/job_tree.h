#ifndef JOB_TREE_H
#define JOB_TREE_H

#include <functional>

#include "matrix/matrix.hpp"

class job_tree {
public:
  using job_func_t = std::function<matrix *(const matrix *, const matrix *)>;

  job_tree(const job_func_t &job_func);
  job_tree(const job_tree &child);
  job_tree(job_tree &&child) noexcept;
  job_tree(const job_tree &child1, const job_tree &child2);
  job_tree(job_tree &&child1, job_tree &&child2) noexcept;

  ~job_tree();
};


#endif //JOB_TREE_H
