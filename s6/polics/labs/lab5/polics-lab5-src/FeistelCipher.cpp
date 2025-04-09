#include "FeistelCipher.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIntValidator>
#include <QThread>

FeistelCipher::FeistelCipher(QWidget *parent) : QMainWindow(parent) {
  auto centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  auto *layout = new QVBoxLayout(centralWidget);

  auto encryptButton = new QPushButton("Зашифрувати", this);
  auto decryptButton = new QPushButton("Розшифрувати", this);
  connect(encryptButton, &QPushButton::clicked, this, &FeistelCipher::encrypt);
  connect(decryptButton, &QPushButton::clicked, this, &FeistelCipher::decrypt);

  auto topBarLayout = new QHBoxLayout();
  auto title = new QLabel("Шифр Фейстеля", this);
  title->setFont(QFont("Noto Sans", 12, QFont::Bold));
  topBarLayout->addWidget(title);

  auto buttonsLayout = new QHBoxLayout();
  buttonsLayout->addWidget(encryptButton);
  buttonsLayout->addWidget(decryptButton);
  buttonsLayout->setAlignment(Qt::AlignRight);
  topBarLayout->addLayout(buttonsLayout);

  auto cipherConfigLayout = new QHBoxLayout();
  auto roundsConfigLayout = new QVBoxLayout();
  auto roundsLabel = new QLabel("Кількість раундів", this);
  roundsConfigLayout->addWidget(roundsLabel);
  rounds = new QSpinBox(this);
  rounds->setMaximum(100);
  roundsConfigLayout->addWidget(rounds);
  cipherConfigLayout->addLayout(roundsConfigLayout);

  auto keyConfigLayout = new QVBoxLayout();
  auto keyLabel = new QLabel("Початковий ключ", this);
  keyConfigLayout->addWidget(keyLabel);
  key = new QSpinBox(this);
  keyConfigLayout->addWidget(key);
  cipherConfigLayout->addLayout(keyConfigLayout);

  auto line = new QFrame(this);
  line->setFrameShape(QFrame::HLine);
  line->setFrameShadow(QFrame::Sunken);

  auto inputLayout = new QVBoxLayout();
  inputLayout->setAlignment(Qt::AlignTop);
  auto inputLabel = new QLabel("Розшифроване повідомлення", this);
  inputLayout->addWidget(inputLabel);
  decrypted = new QLineEdit(this);
  inputLayout->addWidget(decrypted);
  auto pasteButton = new QPushButton("Вставити", this);
  connect(pasteButton, &QPushButton::clicked, this, &FeistelCipher::paste);
  inputLayout->addWidget(pasteButton);

  auto outputLayout = new QVBoxLayout();
  outputLayout->setAlignment(Qt::AlignTop);
  auto outputLabel = new QLabel("Зашифроване повідомлення", this);
  outputLayout->addWidget(outputLabel);
  encrypted = new QLineEdit(this);
  outputLayout->addWidget(encrypted);
  auto copyButton = new QPushButton("Скопіювати", this);
  connect(copyButton, &QPushButton::clicked, this, &FeistelCipher::copy);
  outputLayout->addWidget(copyButton);

  layout->setAlignment(Qt::AlignTop);
  layout->addLayout(topBarLayout);
  layout->addLayout(cipherConfigLayout);
  layout->addWidget(line);
  layout->addLayout(inputLayout);
  layout->addLayout(outputLayout);
}

FeistelCipher::~FeistelCipher() = default;

void FeistelCipher::encrypt() {
  auto constexpr chunk_size = 8;
  auto bytes_str = decrypted->text().split(" ");
  QByteArray bytes;
  std::transform(bytes_str.begin(), bytes_str.end(), std::back_inserter(bytes), [](const QString &byte) {
    return static_cast<char>(byte.toInt(nullptr, 16));
  });
  auto chunks_len = static_cast<int>(std::ceil(static_cast<double>(bytes_str.size()) / chunk_size));
  auto chunks = new int64_t[chunks_len] {};
  memcpy(chunks, bytes.data(), bytes.size());

  for (int i = 0; i < chunks_len; i++) {
    auto left = reinterpret_cast<int32_t *>(&chunks[i]) + 1;
    auto right = reinterpret_cast<int32_t *>(&chunks[i]);
    crypt(left, right, rounds->value(), key->value(), false);
  }

  QByteArray new_bytes(reinterpret_cast<char *>(chunks), chunk_size * chunks_len);
  auto new_bytes_str = new_bytes.toHex(' ').toUpper();
  encrypted->setText(new_bytes_str);
}

void FeistelCipher::decrypt() {
  auto constexpr chunk_size = 8;
  auto bytes_str = encrypted->text().split(" ");
  QByteArray bytes;
  std::transform(bytes_str.begin(), bytes_str.end(), std::back_inserter(bytes), [](const QString &byte) {
    return static_cast<char>(byte.toInt(nullptr, 16));
  });
  auto chunks_len = static_cast<int>(std::ceil(static_cast<double>(bytes_str.size()) / chunk_size));
  auto chunks = new int64_t[chunks_len] {};
  memcpy(chunks, bytes.data(), bytes.size());

  for (int i = 0; i < chunks_len; i++) {
    auto left = reinterpret_cast<int32_t *>(&chunks[i]) + 1;
    auto right = reinterpret_cast<int32_t *>(&chunks[i]);
    crypt(left, right, rounds->value(), key->value(), true);
  }

  QByteArray new_bytes(reinterpret_cast<char *>(chunks), chunk_size * chunks_len);
  auto new_bytes_str = new_bytes.toHex(' ').toUpper();
  decrypted->setText(new_bytes_str);
}

void FeistelCipher::copy() {
  encrypted->selectAll();
  encrypted->copy();
}

void FeistelCipher::paste() {
  decrypted->clear();
  decrypted->paste();
}

int FeistelCipher::getRoundKey(int initial, int round) {
  return initial + round;
}

void FeistelCipher::crypt(int32_t *left, int32_t *right, int32_t rounds, int32_t key, bool reverse) {
  for (int32_t i = 0; i < rounds; i++) {
    auto roundKey = getRoundKey(key, reverse ? rounds - i : i);
    auto temp = *right ^ (*left ^ roundKey);
    *right = *left;
    *left = temp;
  }
}