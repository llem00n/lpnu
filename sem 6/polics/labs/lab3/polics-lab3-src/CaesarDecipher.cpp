#include "CaesarDecipher.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

QString CaesarDecipher::ukrainianAlphabetLC = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
QString CaesarDecipher::ukrainianAlphabetUC = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

CaesarDecipher::CaesarDecipher(QWidget *parent) : QMainWindow(parent) {
  const auto mainWidget = new QWidget(this);
  setCentralWidget(mainWidget);

  const auto layout = new QVBoxLayout(mainWidget);
  mainWidget->setLayout(layout);

  const auto inputLabel = new QLabel("Зашифроване повідомлення", mainWidget);
  layout->addWidget(inputLabel);
  input = new QTextEdit(mainWidget);
  layout->addWidget(input);

  const auto line1 = new QFrame(mainWidget);
  line1->setFrameShape(QFrame::HLine);
  line1->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line1);

  const auto outputLabel = new QLabel("Розшифроване повідомлення", mainWidget);
  layout->addWidget(outputLabel);
  output = new QTextEdit(mainWidget);
  output->setReadOnly(true);
  layout->addWidget(output);

  const auto line2 = new QFrame(mainWidget);
  line2->setFrameShape(QFrame::HLine);
  line2->setFrameShadow(QFrame::Sunken);
  layout->addWidget(line2);

  const auto buttonsLayout = new QHBoxLayout();
  buttonsLayout->setAlignment(Qt::AlignRight);
  layout->addLayout(buttonsLayout);

  const auto decipherButton = new QPushButton("Розшифрувати", mainWidget);
  buttonsLayout->addWidget(decipherButton);
  connect(decipherButton, &QPushButton::clicked, this, &CaesarDecipher::decipher);

  setWindowTitle("Дешифртаор Цезаря");
}

void CaesarDecipher::decipher() const {
  const auto message = input->toPlainText();
  const auto frequencies = getFrequencies(message);
  const auto mostFrequentLetter = std::max_element(frequencies.begin(), frequencies.end(),
                                                   [](const auto &lhs, const auto &rhs) -> bool {
                                                     return lhs < rhs;
                                                   });
  const QString ukrainianAlphabet = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
  constexpr auto mostFrequentLetterInUkrainian = QChar(u'о');
  const auto shift = ukrainianAlphabet.indexOf(mostFrequentLetter.key()) - ukrainianAlphabet.indexOf(
                       mostFrequentLetterInUkrainian) - 1;
  QString result;
  for (const auto &ch: message) {
    if (isUkrainianLetter(ch)) {
      const auto shifted = ukrainianAlphabet.indexOf(toUkrainianLowercase(ch)) + shift;
      QChar newLetter;
      if (shifted < 0) {
        newLetter = QChar(ukrainianAlphabet[ukrainianAlphabet.size() + shifted]);
      } else {
        newLetter = QChar(ukrainianAlphabet[shifted % ukrainianAlphabet.size()]);
      }

      result += isUkrainianUppercaseLetter(ch) ? toUkrainianUppercase(newLetter) : newLetter;
    } else {
      result += ch;
    }
  }
  output->setText(result);
}

bool CaesarDecipher::isUkrainianLowercaseLetter(const QChar &letter) {
  return ukrainianAlphabetLC.contains(letter);
}

bool CaesarDecipher::isUkrainianUppercaseLetter(const QChar &letter) {
  return ukrainianAlphabetUC.contains(letter);
}

bool CaesarDecipher::isUkrainianLetter(const QChar &letter) {
  return isUkrainianLowercaseLetter(letter) || isUkrainianUppercaseLetter(letter);
}

QChar CaesarDecipher::toUkrainianLowercase(const QChar &letter) {
  if (isUkrainianUppercaseLetter(letter)) {
    return QChar(letter.unicode() - u'А' + u'а');
  }
  return letter;
}

QChar CaesarDecipher::toUkrainianUppercase(const QChar &letter) {
  if (isUkrainianLowercaseLetter(letter)) {
    return QChar(letter.unicode() - u'а' + u'А');
  }
  return letter;
}

QMap<QChar, uint16_t> CaesarDecipher::getFrequencies(const QString &message) {
  QMap<QChar, uint16_t> frequencies;
  for (const auto &ch: message) {
    if (isUkrainianLetter(ch)) {
      frequencies[toUkrainianLowercase(ch)]++;
    }
  }
  return frequencies;
}
