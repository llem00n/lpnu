#include <QApplication>

#include "CaesarCipherWindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CaesarCipherWindow window;
  window.show();
  return QApplication::exec();
}
