#include "PremutationCipher.h"

#include <QStatusBar>
#include <QPushButton>

PermutationCipher::PermutationCipher(QWidget *parent) : QMainWindow(parent) {
  const auto mainLayout = new QVBoxLayout;
  const auto centralWidget = new QWidget;
  centralWidget->setLayout(mainLayout);
  setCentralWidget(centralWidget);
  setWindowTitle("Шифр перестановки");
  resize(600, 300);

  const auto inputLayout = new QHBoxLayout;
  inputLayout->setAlignment(Qt::AlignBottom);

  const auto inputMessagelayout = new QVBoxLayout;
  const auto inputTitle = new QLabel("Повідомлення");
  messageInput = new QLineEdit;
  messageInput->setPlaceholderText("Повідомлення");
  inputMessagelayout->addWidget(inputTitle);
  inputMessagelayout->addWidget(messageInput);
  inputLayout->addLayout(inputMessagelayout);

  const auto keyLayout = new QVBoxLayout;
  const auto keyTitle = new QLabel("Ключ");
  keyInput = new QLineEdit;
  keyInput->setPlaceholderText("1 2 3 4 5");
  keyInput->setFixedWidth(150);
  keyLayout->addWidget(keyTitle);
  keyLayout->addWidget(keyInput);
  inputLayout->addLayout(keyLayout);

  const auto encryptButtonLayout = new QVBoxLayout;
  const auto encyptButtonTitleDummy = new QLabel;
  const auto encryptButton = new QPushButton("Зашифрувати");
  connect(encryptButton, &QPushButton::clicked, this, &PermutationCipher::onEncryptClicked);
  encryptButtonLayout->addWidget(encyptButtonTitleDummy);
  encryptButtonLayout->addWidget(encryptButton);
  inputLayout->addLayout(encryptButtonLayout);

  mainLayout->addLayout(inputLayout);

  table = new QTableWidget;
  mainLayout->addWidget(table);

  const auto messageOutputLayout = new QVBoxLayout;
  const auto messageOutputTitle = new QLabel("Зашифроване повідомлення");
  messageOutput = new QLineEdit;
  messageOutput->setReadOnly(true);
  messageOutput->setPlaceholderText("Зашифроване повідомлення");
  messageOutputLayout->addWidget(messageOutputTitle);
  messageOutputLayout->addWidget(messageOutput);
  mainLayout->addLayout(messageOutputLayout);

  mainLayout->setAlignment(Qt::AlignTop);

  const auto statusBar = new QStatusBar;
  setStatusBar(statusBar);
}

void PermutationCipher::onEncryptClicked() {
  key = getKeyValues();
  if (key.isEmpty()) {
    return;
  }

  message = messageInput->text();
  if (message.isEmpty()) {
    statusBar()->showMessage("Повідомлення не може бути порожнім");
    return;
  }

  splitMessage = PermutationCipher::splitMessageIntoColumns();
  updateTable();
  writeOutput();
}

QVector<int> PermutationCipher::getKeyValues() {
  statusBar()->clearMessage();

  keyStringValues = this->keyInput->text().split(" ").toVector();
  QVector<int> keyValues;
  std::transform(keyStringValues.begin(), keyStringValues.end(), std::back_inserter(keyValues),
                 [](const QString &value) {
                   return value.toInt();
                 });
  auto keyValuesSorted = keyValues;
  std::sort(keyValuesSorted.begin(), keyValuesSorted.end());

  if (keyValuesSorted.first() != 1) {
    statusBar()->showMessage("Ключ повинен починатися з 1");
    return {};
  }
  for (int i = 1; i < keyValuesSorted.size(); ++i) {
    if (keyValuesSorted[i] != keyValuesSorted[i - 1] + 1) {
      statusBar()->showMessage("Ключ повинен бути послідовним");
      return {};
    }
  }

  return keyValues;
}

QStringList PermutationCipher::splitMessageIntoColumns() {
  QStringList columnStrings(key.size());
  for (int i = 0; i < message.length(); ++i) {
    columnStrings[i % key.size()] += message[i];
  }

  return columnStrings;
}

void PermutationCipher::updateTable() const {
  table->clear();
  table->setColumnCount(static_cast<int>(key.size()));
  table->setRowCount(static_cast<int>(std::max_element(splitMessage.begin(), splitMessage.end(), [](const QString &a, const QString &b) {
    return a.size() < b.size();
  })->size()));
  table->setHorizontalHeaderLabels(keyStringValues);
  for (int i = 0; i < splitMessage.size(); ++i) {
    table->setColumnWidth(i, 10);
    for (int j = 0; j < splitMessage[i].size(); ++j) {
      table->setItem(j, i, new QTableWidgetItem(QString(splitMessage[i][j])));
    }
  }
}

void PermutationCipher::writeOutput() const {
  QString output;
  for (const auto &keyValue: key) {
    output += splitMessage[keyValue - 1];
  }

  messageOutput->setText(output);
}
