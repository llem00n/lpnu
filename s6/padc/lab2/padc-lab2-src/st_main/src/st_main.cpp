#include "ctx/ctx.hpp"
#include "ui/app.hpp"
#include "solver/solver.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char *argv[]) {
  ctx::ctx ctx;
  ui::ui_qt_app app(argc, argv, ctx);
  app.on_init_complete([&ctx, &app]() {
    sv::solver solver(ctx);

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    solver.y1();
    solver.y2();
    solver.Y3();

    solver.X1();
    solver.X2();
    solver.X3();
    solver.X4();

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
  app.input();
}