#include <QApplication>

#include "BMPSteganography.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  BMPSteganography window;
  window.show();
  return QApplication::exec();
}
