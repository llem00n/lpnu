#include <QApplication>

#include "PremutationCipher.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  PermutationCipher window;
  window.show();
  return QApplication::exec();
}
