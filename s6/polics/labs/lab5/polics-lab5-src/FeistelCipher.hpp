#ifndef POLICS_LAB3_SRC_FEISTELCIPHER_HPP
#define POLICS_LAB3_SRC_FEISTELCIPHER_HPP

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>

class FeistelCipher: public QMainWindow {
  Q_OBJECT

  QSpinBox *rounds;
  QSpinBox *key;
  QLineEdit *decrypted;
  QLineEdit *encrypted;

public:
  FeistelCipher(QWidget *parent = nullptr);
  ~FeistelCipher() override;

private slots:
  void encrypt();
  void decrypt();
  void copy();
  void paste();

private:
  int getRoundKey(int initial, int round);
  void crypt(int32_t *left, int32_t *right, int32_t rounds, int32_t key, bool reverse);
};


#endif //POLICS_LAB3_SRC_FEISTELCIPHER_HPP
