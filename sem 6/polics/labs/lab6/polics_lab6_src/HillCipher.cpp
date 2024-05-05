#include "HillCipher.hpp"
#include "matrix.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QClipboard>
#include <QApplication>
#include <QStatusBar>

HillCipher::HillCipher(QWidget *parent) {
  auto mainWidget = new QWidget(parent);
  auto layout = new QVBoxLayout(mainWidget);
  setCentralWidget(mainWidget);
  setMinimumWidth(300);
  setWindowTitle("Шифр Хілла");

  auto title = new QLabel("Шифр Хілла");
  title->setFont(QFont("Noto Sans", 16, QFont::Bold));
  title->setAlignment(Qt::AlignLeft);
  layout->addWidget(title);

  auto line1 = new QFrame();
  line1->setFrameShape(QFrame::HLine);
  line1->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line1);

  auto settingsLayout = new QVBoxLayout();

  auto settingsTitle = new QLabel("Налаштування");
  settingsTitle->setFont(QFont("Noto Sans", 10, QFont::Bold));
  settingsTitle->setAlignment(Qt::AlignLeft);
  settingsLayout->addWidget(settingsTitle);

  auto keyLayout = new QHBoxLayout();
  auto keyLabel = new QLabel("Ключ");
  keyLayout->addWidget(keyLabel);
  keyLayout->addStretch();
  auto keyValue = new QLabel(KEY);
  keyLayout->addWidget(keyValue);
  settingsLayout->addLayout(keyLayout);

  auto sizeLayout = new QHBoxLayout();
  auto sizeLabel = new QLabel("Розмір блоку");
  sizeLayout->addWidget(sizeLabel);
  sizeLayout->addStretch();
  auto sizeValue = new QLabel(QString::number(SIZE));
  sizeLayout->addWidget(sizeValue);
  settingsLayout->addLayout(sizeLayout);

  auto maskLayout = new QHBoxLayout();
  auto maskLabel = new QLabel("Алгоритм маскування");
  maskLayout->addWidget(maskLabel);
  maskLayout->addStretch();
  auto maskValue = new QLabel(MASKING_ALGORITHM);
  maskLayout->addWidget(maskValue);
  settingsLayout->addLayout(maskLayout);

  layout->addLayout(settingsLayout);

  auto line2 = new QFrame();
  line2->setFrameShape(QFrame::HLine);
  line2->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line2);

  auto inputLayout = new QVBoxLayout();

  auto inputTitle = new QLabel("Відкритий текст");
  inputTitle->setFont(QFont("Noto Sans", 10, QFont::Bold));
  inputTitle->setAlignment(Qt::AlignLeft);

  inputText = new QTextEdit();
  inputLayout->addWidget(inputTitle);
  inputLayout->addWidget(inputText);

  auto inputButtons = new QHBoxLayout();
  auto copyInputButton = new QPushButton("Копіювати");
  auto clearInputButton = new QPushButton("Очистити");
  auto pasteInputButton = new QPushButton("Вставити");
  inputButtons->addWidget(copyInputButton);
  inputButtons->addWidget(clearInputButton);
  inputButtons->addWidget(pasteInputButton);
  inputLayout->addLayout(inputButtons);
  layout->addLayout(inputLayout);

  auto line3 = new QFrame();
  line3->setFrameShape(QFrame::HLine);
  line3->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line3);

  auto outputLayout = new QVBoxLayout();
  auto outputTitle = new QLabel("Шифрований текст");
  outputTitle->setFont(QFont("Noto Sans", 10, QFont::Bold));
  outputTitle->setAlignment(Qt::AlignLeft);

  outputText = new QTextEdit();
  outputLayout->addWidget(outputTitle);
  outputLayout->addWidget(outputText);

  auto outputButtons = new QHBoxLayout();
  auto copyOutputButton = new QPushButton("Копіювати");
  auto clearOutputButton = new QPushButton("Очистити");
  auto pasteOutputButton = new QPushButton("Вставити");

  outputButtons->addWidget(copyOutputButton);
  outputButtons->addWidget(clearOutputButton);
  outputButtons->addWidget(pasteOutputButton);
  outputLayout->addLayout(outputButtons);
  layout->addLayout(outputLayout);

  auto line4 = new QFrame();
  line4->setFrameShape(QFrame::HLine);
  line4->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line4);

  auto buttonsLayout = new QHBoxLayout();
  auto encryptButton = new QPushButton("Зашифрувати");
  auto decryptButton = new QPushButton("Розшифрувати");
  buttonsLayout->addWidget(encryptButton);
  buttonsLayout->addWidget(decryptButton);
  layout->addLayout(buttonsLayout);

  auto statusBar = new QStatusBar();
  setStatusBar(statusBar);
  statusBar->showMessage("Готовий до роботи");

  connect(encryptButton, &QPushButton::clicked, this, &HillCipher::encrypt);
  connect(decryptButton, &QPushButton::clicked, this, &HillCipher::decrypt);

  connect(copyInputButton, &QPushButton::clicked, this, [&]() {
    QApplication::clipboard()->setText(inputText->toPlainText());
  });

  connect(clearInputButton, &QPushButton::clicked, this, [&]() {
    inputText->clear();
  });

  connect(pasteInputButton, &QPushButton::clicked, this, [&]() {
    inputText->setText(QApplication::clipboard()->text());
  });

  connect(copyOutputButton, &QPushButton::clicked, this, [&]() {
    QApplication::clipboard()->setText(outputText->toPlainText());
  });

  connect(clearOutputButton, &QPushButton::clicked, this, [&]() {
    outputText->clear();
  });

  connect(pasteOutputButton, &QPushButton::clicked, this, [&]() {
    outputText->setText(QApplication::clipboard()->text());
  });

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      keyMatrix[i][j] = ALPHABET.indexOf(KEY[i * SIZE + j]);
    }
  }
}

void HillCipher::encrypt() {
  auto text = inputText->toPlainText().toLower();
  auto maskedText = insertMask(text);
  QString res;
  for (int i = 0; i < maskedText.size(); i += SIZE) {
    int block[SIZE], result[SIZE];
    for (int j = 0; j < SIZE; j++) {
      block[j] = ALPHABET.indexOf(maskedText[i + j]);
    }

    for (int j = 0; j < SIZE; j++) {
      result[j] = 0;
      for (int k = 0; k < SIZE; k++) {
        result[j] += keyMatrix[j][k] * block[k];
      }
      result[j] %= ALPHABET_SIZE;
    }

    for (int j = 0; j < SIZE; j++) {
      res += ALPHABET[result[j]];
    }
  }
}

void HillCipher::decrypt() {
  auto text = outputText->toPlainText().toLower();
  QString res;
}

QString HillCipher::insertMask(const QString &text) {
  QString result;

  for (const auto &c : text) {
    result += QString("XX") + c;
  }

  return result;
}

QString HillCipher::removeMask(const QString &text) {
  QString result;

  for (int i = 0; i < text.size(); i += 3) {
    result += text[i + 2];
  }

  return result;
}