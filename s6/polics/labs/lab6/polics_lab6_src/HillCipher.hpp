#ifndef POLICS_LAB6_SRC_HILLCIPHER_HPP
#define POLICS_LAB6_SRC_HILLCIPHER_HPP

#include <QObject>
#include <QMainWindow>
#include <QTextEdit>
#include <QString>

class HillCipher : public QMainWindow {
  Q_OBJECT

private:
  const QString KEY = "porubaimikho";
  static const int SIZE = 3;
  const QString ALPHABET = "abcdefghijklmnopqrstuvwxyz ,.!?1234567890";
  const int ALPHABET_SIZE = ALPHABET.size();
  const QString MASKING_ALGORITHM = "{ mi; mi; vi }";

  int keyMatrix[SIZE][SIZE];

public:
  explicit HillCipher(QWidget *parent = nullptr);
  ~HillCipher() = default;

private:
  QTextEdit *inputText;
  QTextEdit *outputText;

  QString insertMask(const QString &text);
  QString removeMask(const QString &text);

private slots:
  void encrypt();
  void decrypt();
};


#endif //POLICS_LAB6_SRC_HILLCIPHER_HPP
