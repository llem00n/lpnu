#include "CaesarCipherWindow.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QClipboard>

const QString CaesarCipherWindow::ukrainianUpperAlphabet = QString("АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ");
const QString CaesarCipherWindow::ukrainianLowerAlphabet = QString("абвгґдеєжзиіїйклмнопрстуфхцчшщьюя");

CaesarCipherWindow::CaesarCipherWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle(tr("Шифр Цезаря"));

  stepValueLabel = new QLabel(tr("Крок шифрування:"));
  stepValueInput = new QSpinBox();
  stepValueInput->setRange(1, 25);
  stepValueInput->setValue(17);
  stepValueInput->setDisabled(true);

  inputTextLabel = new QLabel(tr("Вхідний текст:"));
  inputField = new QPlainTextEdit();
  inputField->setFixedHeight(100);

  outputTextLabel = new QLabel(tr("Вихідний текст:"));
  outputField = new QPlainTextEdit();
  outputField->setReadOnly(true);
  outputField->setFixedHeight(100);

  runButton = new QPushButton(tr("Зашифрувати"));
  connect(runButton, &QPushButton::clicked, this, &CaesarCipherWindow::handleRunButtonClicked);

  copyToClipboardButton = new QPushButton(tr("Копіювати"));
  connect(copyToClipboardButton, &QPushButton::clicked, this, &CaesarCipherWindow::handleCopyToClipboardButtonClicked);

  pasteFromClipboardButton = new QPushButton(tr("Вставити"));
  connect(pasteFromClipboardButton, &QPushButton::clicked, this,
          &CaesarCipherWindow::handlePasteFromClipboardButtonClicked);

  auto *stepLayout = new QHBoxLayout();
  stepLayout->addWidget(stepValueLabel);
  stepLayout->addWidget(stepValueInput);

  line1 = new QFrame();
  line1->setFrameShape(QFrame::HLine);
  line1->setFrameShadow(QFrame::Sunken);

  line2 = new QFrame();
  line2->setFrameShape(QFrame::HLine);
  line2->setFrameShadow(QFrame::Sunken);

  auto *mainLayout = new QVBoxLayout();
  mainLayout->addLayout(stepLayout);
  mainLayout->addWidget(inputTextLabel);
  mainLayout->addWidget(inputField);
  mainLayout->addWidget(pasteFromClipboardButton);
  mainLayout->addWidget(line1);
  mainLayout->addWidget(outputTextLabel);
  mainLayout->addWidget(outputField);
  mainLayout->addWidget(copyToClipboardButton);
  mainLayout->addWidget(line2);

  auto *buttonLayout = new QHBoxLayout();
  buttonLayout->addWidget(runButton);

  mainLayout->addLayout(buttonLayout);


  auto *centralWidget = new QWidget();
  centralWidget->setLayout(mainLayout);
  setCentralWidget(centralWidget);
}

void CaesarCipherWindow::handleRunButtonClicked() const {
  const QString text = inputField->toPlainText();
  const int step = stepValueInput->value();

  QString encryptedText;
  for (const QChar &currentChar : text) {
    encryptedText += encryptLetter(currentChar, step);
  }

  outputField->setPlainText(encryptedText);
}

void CaesarCipherWindow::handleCopyToClipboardButtonClicked() const {
  QString encryptedText = outputField->toPlainText();
  QClipboard *clipboard = QApplication::clipboard();
  clipboard->setText(encryptedText);
}

void CaesarCipherWindow::handlePasteFromClipboardButtonClicked() const {
  const QClipboard *clipboard = QApplication::clipboard();
  const QString clipboardText = clipboard->text();
  inputField->setPlainText(clipboardText);
}

bool CaesarCipherWindow::isUkrainianUpperLetter(const QChar &letter) {
  return ukrainianUpperAlphabet.contains(letter);
}

bool CaesarCipherWindow::isUkrainianLowerLetter(const QChar &letter) {
  return ukrainianLowerAlphabet.contains(letter);
}

QChar CaesarCipherWindow::encryptLetter(const QChar &letter, const int step) {
  QChar newLetterValue = letter;

  if (isUkrainianUpperLetter(letter)) {
    newLetterValue = ukrainianUpperAlphabet[(ukrainianUpperAlphabet.indexOf(letter) + step) % ukrainianUpperAlphabet.size()];
  } else if (isUkrainianLowerLetter(letter)) {
    newLetterValue = ukrainianLowerAlphabet[(ukrainianLowerAlphabet.indexOf(letter) + step) % ukrainianLowerAlphabet.size()];
  }

  return newLetterValue;
}