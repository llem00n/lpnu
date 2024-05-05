#include <QApplication>

#include "CaesarDecipher.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CaesarDecipher window;
  window.show();
  return QApplication::exec();
}
