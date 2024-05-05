#include "ctx/ctx.hpp"

ctx::ctx::ctx() : n(0) {
  matrix_names = {{matrix_id::A, "Matrix A"},   {matrix_id::A1, "Matrix A1"},
                  {matrix_id::b1, "Matrix b1"}, {matrix_id::c1, "Matrix c1"},
                  {matrix_id::A2, "Matrix A2"}, {matrix_id::B2, "Matrix B2"},
                  {matrix_id::y1, "Matrix y1"}, {matrix_id::y2, "Matrix y2"},
                  {matrix_id::Y3, "Matrix Y3"}};
}