#ifndef BMPSTEGANOGRAPHY_H
#define BMPSTEGANOGRAPHY_H

#include <QMainWindow>
#include <QFile>
#include <QPushButton>
#include <QTextEdit>

class BMPSteganography final: public QMainWindow {
  Q_OBJECT

  enum class WorkMode {
    Encrypt,
    Decrypt
  } mode;

  QFile *inputFile;
  QFile *outputFile;

  QPushButton *inputFileButton;
  QPushButton *outputFileButton;
  QTextEdit *message;

public:
  explicit BMPSteganography(QWidget *parent = nullptr);
  ~BMPSteganography() override = default;

private slots:
  void modeChanged(int mode);
  void action() const;

private:
  void encrypt() const;
  void decrypt() const;
};



#endif //BMPSTEGANOGRAPHY_H
