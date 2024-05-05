#ifndef PREMUTATIONCIPHER_H
#define PREMUTATIONCIPHER_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>


class PermutationCipher final : public QMainWindow {
  Q_OBJECT

public:
  explicit PermutationCipher(QWidget *parent = nullptr);

  ~PermutationCipher() override = default;

private slots:
  void onEncryptClicked();

private:
  QLineEdit *keyInput;
  QLineEdit *messageInput;
  QTableWidget *table;
  QLineEdit *messageOutput;

  QList<QString> keyStringValues;
  QList<int> key;
  QString message;
  QStringList splitMessage;

private:
  [[nodiscard]] QVector<int> getKeyValues();
  [[nodiscard]] QStringList splitMessageIntoColumns();
  void updateTable() const;
  void writeOutput() const;
};


#endif //PREMUTATIONCIPHER_H
