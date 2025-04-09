#include "BMPSteganography.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFrame>
#include <QStatusBar>
#include <QFileDialog>

BMPSteganography::BMPSteganography(QWidget *parent) : QMainWindow(parent), inputFile(nullptr), outputFile(nullptr),
                                                      mode(WorkMode::Encrypt) {
  const auto mainWidget = new QWidget(this);
  setCentralWidget(mainWidget);
  const auto mainLayout = new QVBoxLayout(mainWidget);
  mainLayout->setAlignment(Qt::AlignTop);

  const auto modeSelectionLayout = new QHBoxLayout();
  const auto modeSelectionLabel = new QLabel("Режим");
  const auto modeSelection = new QComboBox();
  modeSelection->addItem("Шифрування", QVariant::fromValue(WorkMode::Encrypt));
  modeSelection->addItem("Дешифрування", QVariant::fromValue(WorkMode::Decrypt));
  connect(modeSelection, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BMPSteganography::modeChanged);
  modeSelectionLayout->addWidget(modeSelectionLabel);
  modeSelectionLayout->addWidget(modeSelection);
  modeSelectionLayout->setAlignment(Qt::AlignLeft);
  mainLayout->addLayout(modeSelectionLayout);

  const auto line1 = new QFrame();
  line1->setFrameShape(QFrame::HLine);
  line1->setFrameShadow(QFrame::Sunken);
  mainLayout->addWidget(line1);

  const auto fileSelectionLayout = new QHBoxLayout();

  const auto inputFileSelectionLayout = new QVBoxLayout();
  const auto inputFileLabel = new QLabel("Вхідний файл");
  inputFileButton = new QPushButton("Обрати файл");
  inputFileButton->setIcon(QIcon::fromTheme("viewimage"));
  connect(inputFileButton, &QPushButton::clicked, [this] {
    const auto fileName = QFileDialog::getOpenFileName(this, "Обрати файл", QDir::currentPath(), "BMP (*.bmp)");
    if (!fileName.isEmpty()) {
      inputFile = new QFile(fileName);
      inputFileButton->setText(fileName.split("/").last());
    }
  });
  inputFileSelectionLayout->addWidget(inputFileLabel);
  inputFileSelectionLayout->addWidget(inputFileButton);
  fileSelectionLayout->addLayout(inputFileSelectionLayout);

  const auto outputFileSelectionLayout = new QVBoxLayout();
  const auto outputFileLabel = new QLabel("Вихідний файл");
  outputFileButton = new QPushButton("Обрати файл");
  outputFileButton->setIcon(QIcon::fromTheme("viewimage"));
  connect(outputFileButton, &QPushButton::clicked, [this] {
    const auto fileName = QFileDialog::getSaveFileName(this, "Обрати файл", QDir::currentPath(), "BMP (*.bmp)");
    if (!fileName.isEmpty()) {
      outputFile = new QFile(fileName);
      outputFileButton->setText(fileName.split("/").last());
    }
  });
  outputFileSelectionLayout->addWidget(outputFileLabel);
  outputFileSelectionLayout->addWidget(outputFileButton);
  fileSelectionLayout->addLayout(outputFileSelectionLayout);

  mainLayout->addLayout(fileSelectionLayout);

  const auto line2 = new QFrame();
  line2->setFrameShape(QFrame::HLine);
  line2->setFrameShadow(QFrame::Sunken);
  mainLayout->addWidget(line2);

  const auto messageLayout = new QVBoxLayout();
  const auto messageLabel = new QLabel("Повідомлення");
  message = new QTextEdit();
  messageLayout->addWidget(messageLabel);
  messageLayout->addWidget(message);
  mainLayout->addLayout(messageLayout);

  const auto line3 = new QFrame();
  line3->setFrameShape(QFrame::HLine);
  line3->setFrameShadow(QFrame::Sunken);
  mainLayout->addWidget(line3);

  const auto actionButton = new QPushButton("Виконати");
  connect(actionButton, &QPushButton::clicked, this, &BMPSteganography::action);
  mainLayout->addWidget(actionButton);

  const auto statusBar = new QStatusBar(this);
  setStatusBar(statusBar);
}

void BMPSteganography::modeChanged(int mode) {
  if (inputFile) {
    if (inputFile->isOpen()) inputFile->close();
    delete inputFile;
    inputFile = nullptr;
  }

  if (outputFile) {
    if (outputFile->isOpen()) outputFile->close();
    delete outputFile;
    outputFile = nullptr;
  }

  inputFileButton->setText("Обрати файл");
  outputFileButton->setText("Обрати файл");
  message->clear();
  statusBar()->clearMessage();

  this->mode = static_cast<WorkMode>(mode);

  switch (this->mode) {
    case WorkMode::Encrypt:
      inputFileButton->setDisabled(false);
      outputFileButton->setDisabled(false);
      message->setReadOnly(false);
      break;
    case WorkMode::Decrypt:
      inputFileButton->setDisabled(false);
      outputFileButton->setDisabled(true);
      message->setReadOnly(true);
      break;
  }
}

void BMPSteganography::action() const {
  switch (mode) {
    case WorkMode::Encrypt:
      encrypt();
      break;
    case WorkMode::Decrypt:
      decrypt();
      break;
  }
}

void BMPSteganography::encrypt() const {
  if (!inputFile || !outputFile) {
    statusBar()->showMessage("Помилка: не вибрано вхідний або вихідний файл");
    return;
  }

  inputFile->open(QIODevice::ReadOnly);
  outputFile->open(QIODevice::WriteOnly);

  auto bmpBytes = inputFile->readAll();
  const auto messageBytes = message->toPlainText().toUtf8();
  const auto bmpSize = bmpBytes.size();
  const auto messageSize = messageBytes.size();

  if (bmpSize < messageSize * 8) {
    statusBar()->showMessage("Помилка: розмір повідомлення більший за розмір зображення");
    inputFile->close();
    outputFile->close();
    return;
  }

  for (int bi = 138, mi = 0; mi < messageSize; mi++, bi += 8) {
    bmpBytes[bi] = (bmpBytes[bi] & 0xFE) | ((messageBytes[mi] & 0x80) >> 7);
    bmpBytes[bi + 1] = (bmpBytes[bi + 1] & 0xFE) | ((messageBytes[mi] & 0x40) >> 6);
    bmpBytes[bi + 2] = (bmpBytes[bi + 2] & 0xFE) | ((messageBytes[mi] & 0x20) >> 5);
    bmpBytes[bi + 3] = (bmpBytes[bi + 3] & 0xFE) | ((messageBytes[mi] & 0x10) >> 4);
    bmpBytes[bi + 4] = (bmpBytes[bi + 4] & 0xFE) | ((messageBytes[mi] & 0x08) >> 3);
    bmpBytes[bi + 5] = (bmpBytes[bi + 5] & 0xFE) | ((messageBytes[mi] & 0x04) >> 2);
    bmpBytes[bi + 6] = (bmpBytes[bi + 6] & 0xFE) | ((messageBytes[mi] & 0x02) >> 1);
    bmpBytes[bi + 7] = (bmpBytes[bi + 7] & 0xFE) | (messageBytes[mi] & 0x01);
  }

  outputFile->write(bmpBytes);

  inputFile->close();
  outputFile->close();
}

void BMPSteganography::decrypt() const {
  if (!inputFile) {
    statusBar()->showMessage("Помилка: не вибрано вхідний файл");
    return;
  }

  inputFile->open(QIODevice::ReadOnly);
  const auto bmpBytes = inputFile->readAll();
  inputFile->close();
  QByteArray messageBytes;

  for (int i = 138; i < bmpBytes.size(); i += 8) {
    const char ch = (bmpBytes[i] & 0x01) << 7
      | (bmpBytes[i + 1] & 0x01) << 6
      | (bmpBytes[i + 2] & 0x01) << 5
      | (bmpBytes[i + 3] & 0x01) << 4
      | (bmpBytes[i + 4] & 0x01) << 3
      | (bmpBytes[i + 5] & 0x01) << 2
      | (bmpBytes[i + 6] & 0x01) << 1
      | (bmpBytes[i + 7] & 0x01);

    if (ch == 0) continue;

    messageBytes.append(ch);
  }

  const auto message = QString::fromUtf8(messageBytes);
  this->message->setText(message);
}
