#ifndef CAESARDECIPHER_H
#define CAESARDECIPHER_H

#include <QMainWindow>
#include <QTextEdit>

class CaesarDecipher: public QMainWindow {
  Q_OBJECT

  QTextEdit *input;
  QTextEdit *output;

private slots:
  void decipher() const;

public:
  CaesarDecipher(QWidget *parent = nullptr);
  ~CaesarDecipher() override = default;

private:
  static bool isUkrainianLowercaseLetter(const QChar &letter);
  static bool isUkrainianUppercaseLetter(const QChar &letter);
  static bool isUkrainianLetter(const QChar &letter);
  static QChar toUkrainianLowercase(const QChar &letter);
  static QChar toUkrainianUppercase(const QChar &letter);
  static QMap<QChar, uint16_t> getFrequencies(const QString &message);

  static QString ukrainianAlphabetLC;
  static QString ukrainianAlphabetUC;
};



#endif //CAESARDECIPHER_H
