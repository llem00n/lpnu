#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QPlainTextEdit>
#include <QFrame>
#include <QPushButton>

class CaesarCipherWindow final : public QMainWindow {
  Q_OBJECT

public:
  explicit CaesarCipherWindow(QWidget *parent = nullptr);

private slots:
  void handleRunButtonClicked() const;
  void handleCopyToClipboardButtonClicked() const;
  void handlePasteFromClipboardButtonClicked() const;

private:
  static bool isUkrainianUpperLetter(const QChar &letter);
  static bool isUkrainianLowerLetter(const QChar &letter);
  [[nodiscard]] static QChar encryptLetter(const QChar &letter, int step);

  static const QString ukrainianUpperAlphabet;
  static const QString ukrainianLowerAlphabet;

  QLabel *stepValueLabel;
  QSpinBox *stepValueInput;
  QLabel *inputTextLabel;
  QPlainTextEdit *inputField;
  QLabel *outputTextLabel;
  QPlainTextEdit *outputField;
  QPushButton *runButton;
  QPushButton *copyToClipboardButton;
  QPushButton *pasteFromClipboardButton;
  QFrame *line1;
  QFrame *line2;
};


#endif //WINDOW_H
