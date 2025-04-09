#include "mt_main/mpi_app.hpp"
#include "mt_main/ranks.hpp"
#include "ui/app.hpp"
#include <mpi.h>
#include "ctx/ctx.hpp"
#include "solver/solver.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

std::unique_ptr<mpi_app> mpi_app::instance = nullptr;

mpi_app::mpi_app(int argc, char **argv) : argc(argc), argv(argv) {}

mpi_app &mpi_app::create(int argc, char **argv) {
  if (instance == nullptr) {
    instance = std::move(std::unique_ptr<mpi_app>(new mpi_app(argc, argv)));
  }

  return *instance;
}

mpi_app::~mpi_app() {
  MPI_Finalize();
}

void mpi_app::execute_current() {
  switch (get_rank()) {
    case ranks::MAIN:
      return rank_main();
    case ranks::R1:
      return rank_1();
    case ranks::R2:
      return rank_2();
    case ranks::R3:
      return rank_3();
    default:
      break;
  }
}

void mpi_app::rank_main() {
  ctx::ctx ctx;
  ui::ui_qt_app app(argc, argv, ctx);
  app.on_init_complete([&ctx, &app]() {
    sv::solver solver(ctx);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    for (int i = static_cast<int>(ranks::R1); i < static_cast<int>(ranks::LENGTH); i++) {
      MPI_Send(&ctx.n, 1, MPI_UINT32_T, i, static_cast<int>(tags::N), MPI_COMM_WORLD);
    }

    // Send _data to rank 1
    MPI_Send(ctx.matrices[ctx::matrix_id::A].get()->data(), ctx.n * ctx.n,
             MPI_DOUBLE, static_cast<int>(ranks::R1), static_cast<int>(tags::A), MPI_COMM_WORLD);

    // Send _data to rank 2
    MPI_Send(ctx.matrices[ctx::matrix_id::A2].get()->data(), ctx.n * ctx.n,
             MPI_DOUBLE, static_cast<int>(ranks::R2), static_cast<int>(tags::A2), MPI_COMM_WORLD);
    MPI_Send(ctx.matrices[ctx::matrix_id::B2].get()->data(), ctx.n * ctx.n,
             MPI_DOUBLE, static_cast<int>(ranks::R2), static_cast<int>(tags::B2), MPI_COMM_WORLD);

    solver.y2();

    auto buffer = new mtx::matrix::item_type_t[ctx.n * ctx.n];
    MPI_Recv(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::R1),
             static_cast<int>(tags::y1), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    ctx.matrices[ctx::matrix_id::y1] = mtx::matrix::create(ctx.n, 1, buffer);

    MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE,
             static_cast<int>(ranks::R2), static_cast<int>(tags::Y3), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    ctx.matrices[ctx::matrix_id::Y3] = mtx::matrix::create(ctx.n, ctx.n, buffer);



    MPI_Bcast(ctx.matrices[ctx::matrix_id::y1].get()->data(), ctx.n * 1,
              MPI_DOUBLE, static_cast<int>(ranks::MAIN), MPI_COMM_WORLD);
    MPI_Bcast(ctx.matrices[ctx::matrix_id::y2].get()->data(), ctx.n * 1,
              MPI_DOUBLE, static_cast<int>(ranks::MAIN), MPI_COMM_WORLD);
    MPI_Bcast(ctx.matrices[ctx::matrix_id::Y3].get()->data(), ctx.n * ctx.n,
              MPI_DOUBLE, static_cast<int>(ranks::MAIN), MPI_COMM_WORLD);

    solver.X4();
    MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::R1),
             static_cast<int>(tags::X1), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    ctx.matrices[ctx::matrix_id::X1] = mtx::matrix::create(ctx.n, ctx.n, buffer);
    MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::R2),
             static_cast<int>(tags::X2), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    ctx.matrices[ctx::matrix_id::X2] = mtx::matrix::create(ctx.n, ctx.n, buffer);
    MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::R3),
             static_cast<int>(tags::X3), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    ctx.matrices[ctx::matrix_id::X3] = mtx::matrix::create(ctx.n, ctx.n, buffer);

    solver.X();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "Time taken: " << duration << "ns\n";

    std::ofstream out("output.txt");
    out << "y1\n" << ctx.matrices[ctx::matrix_id::y1]->to_string(2) << std::endl;
    out << "\ny2\n" << ctx.matrices[ctx::matrix_id::y2]->to_string(2) << std::endl;
    out << "\nY3\n" << ctx.matrices[ctx::matrix_id::Y3]->to_string(2) << std::endl;

    out << "\nX1\n" << ctx.matrices[ctx::matrix_id::X1]->to_string(2) << std::endl;
    out << "\nX2\n" << ctx.matrices[ctx::matrix_id::X2]->to_string(2) << std::endl;
    out << "\nX3\n" << ctx.matrices[ctx::matrix_id::X3]->to_string(2) << std::endl;
    out << "\nX4\n" << ctx.matrices[ctx::matrix_id::X4]->to_string(2) << std::endl;

    out << "\nX\n" << ctx.matrices[ctx::matrix_id::X]->to_string(2) << std::endl;
    out.close();

    app.show_result(ctx.matrices[ctx::matrix_id::X]);
  });
  app.on_close([]() {
    for (int i = static_cast<int>(ranks::R1); i < static_cast<int>(ranks::LENGTH); i++) {
      MPI_Send(nullptr, 0, MPI_INT, i, static_cast<int>(tags::EXIT), MPI_COMM_WORLD);
    }
  });
  app.input();
}

void mpi_app::rank_1() {
  // Receive N
  ctx::ctx ctx;
  sv::solver solver(ctx);
  MPI_Recv(&ctx.n, 1, MPI_UINT32_T, static_cast<int>(ranks::MAIN), static_cast<int>(tags::N), MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);

  // Calculate y1
  const auto buffer = new mtx::matrix::item_type_t[ctx.n * ctx.n];

  MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE,
           static_cast<int>(ranks::MAIN), static_cast<int>(tags::A), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  ctx.matrices[ctx::matrix_id::A] = mtx::matrix::create(ctx.n, ctx.n, buffer);

  solver.y1();

  MPI_Send(ctx.matrices[ctx::matrix_id::y1].get()->data(), ctx.n * 1, MPI_DOUBLE,
           static_cast<int>(ranks::MAIN), static_cast<int>(tags::y1), MPI_COMM_WORLD);

  // Calculate X1
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::y2] = mtx::matrix::create(ctx.n, 1, buffer);
  MPI_Bcast(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::Y3] = mtx::matrix::create(ctx.n, ctx.n, buffer);
  delete[] buffer;

  solver.X1();
  MPI_Send(ctx.matrices[ctx::matrix_id::X1].get()->data(), ctx.n * ctx.n,
           MPI_DOUBLE, static_cast<int>(ranks::MAIN), static_cast<int>(tags::X1), MPI_COMM_WORLD);
}

void mpi_app::rank_2() {
  // Receive N
  ctx::ctx ctx;
  sv::solver solver(ctx);
  MPI_Recv(&ctx.n, 1, MPI_UINT32_T, static_cast<int>(ranks::MAIN), static_cast<int>(tags::N), MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);

  // Calculate Y3
  const auto buffer = new mtx::matrix::item_type_t[ctx.n * ctx.n];
  MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE,
           static_cast<int>(ranks::MAIN), static_cast<int>(tags::A2), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  ctx.matrices[ctx::matrix_id::A2] = mtx::matrix::create(ctx.n, ctx.n, buffer);

  MPI_Recv(buffer, ctx.n * ctx.n, MPI_DOUBLE,
           static_cast<int>(ranks::MAIN), static_cast<int>(tags::B2), MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  ctx.matrices[ctx::matrix_id::B2] = mtx::matrix::create(ctx.n, ctx.n, buffer);

  solver.Y3();

  MPI_Send(ctx.matrices[ctx::matrix_id::Y3].get()->data(), ctx.n * ctx.n,
           MPI_DOUBLE, static_cast<int>(ranks::MAIN), static_cast<int>(tags::Y3), MPI_COMM_WORLD);

  // Calculate X2
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::y1] = mtx::matrix::create(ctx.n, 1, buffer);
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::y2] = mtx::matrix::create(ctx.n, 1, buffer);
  MPI_Bcast(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  delete[] buffer;

  solver.X2();
  MPI_Send(ctx.matrices[ctx::matrix_id::X2].get()->data(), ctx.n * ctx.n,
           MPI_DOUBLE, static_cast<int>(ranks::MAIN), static_cast<int>(tags::X2), MPI_COMM_WORLD);
}

void mpi_app::rank_3() {
  // Receive N
  ctx::ctx ctx;
  sv::solver solver(ctx);
  MPI_Recv(&ctx.n, 1, MPI_UINT32_T, static_cast<int>(ranks::MAIN), static_cast<int>(tags::N), MPI_COMM_WORLD,
           MPI_STATUS_IGNORE);

  // Calculate X3
  const auto buffer = new mtx::matrix::item_type_t[ctx.n * ctx.n];
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::y1] = mtx::matrix::create(ctx.n, 1, buffer);
  MPI_Bcast(buffer, ctx.n * 1, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  ctx.matrices[ctx::matrix_id::y2] = mtx::matrix::create(ctx.n, 1, buffer);
  MPI_Bcast(buffer, ctx.n * ctx.n, MPI_DOUBLE, static_cast<int>(ranks::MAIN),
            MPI_COMM_WORLD);
  delete[] buffer;

  solver.X3();
  MPI_Send(ctx.matrices[ctx::matrix_id::X3].get()->data(), ctx.n * ctx.n,
           MPI_DOUBLE, static_cast<int>(ranks::MAIN), static_cast<int>(tags::X3), MPI_COMM_WORLD);
}

ranks mpi_app::get_rank() {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  return static_cast<ranks>(rank);
}

int mpi_app::get_size() {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  return size;
}