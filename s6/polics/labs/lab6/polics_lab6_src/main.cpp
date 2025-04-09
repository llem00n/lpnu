#include <iostream>
#include "HillCipher.hpp"
#include <QApplication>
#include "matrix.hpp"

int main(int argc, char **argv) {
  int test[3][3] = {
    {4, 3, 8},
    {6, 2, 5},
    {1, 5, 9}
  }, result[3][3];
  invert(test, result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }

  QApplication app(argc, argv);

  HillCipher hillCipher;
  hillCipher.show();

  return app.exec();

  return 0;
}
