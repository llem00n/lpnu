#include "ui/matrix_input_window.hpp"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <random>

using namespace ui;

matrix_input_window::matrix_input_window(const std::string &title, mtx::matrix &matrix, std::function<void()> &&cb, QWidget *parent): QDialog(parent), is_closed(false), m(matrix) {
  resize(600, 400);

  setWindowTitle(title.c_str());

  const auto layout = new QVBoxLayout(this);
  setLayout(layout);

  const auto toolbar = new QHBoxLayout();
  layout->addLayout(toolbar);

  const auto title_widget = new QLabel(title.c_str(), this);
  title_widget->setFont(QFont("Noto Sans", 14, QFont::Bold));
  toolbar->addWidget(title_widget);

  const auto buttons = new QHBoxLayout();
  buttons->setAlignment(Qt::AlignRight);
  toolbar->addLayout(buttons);

  loading = new QLabel("Loading...", this);
  loading->hide();
  buttons->addWidget(loading);

  const auto randomize_button = new QPushButton("Randomize", this);
  randomize_button->setMaximumWidth(90);
  buttons->addWidget(randomize_button);
  connect(randomize_button, &QPushButton::clicked, [this]() {
    randomize();
  });

  const auto ok_button = new QPushButton("OK", this);
  ok_button->setMaximumWidth(90);
  buttons->addWidget(ok_button);

  table = new QTableWidget(static_cast<int>(m.size().rows), static_cast<int>(m.size().cols), this);
  for (int i = 0; i < table->columnCount(); i++) {
    table->setColumnWidth(i, 40);
  }
  layout->addWidget(table);

  connect(ok_button, &QPushButton::clicked, [this, cb = std::move(cb)]() {
    hide();

    for (int i = 0; i < table->rowCount(); i++) {
      for (int j = 0; j < table->columnCount(); j++) {
        const auto item = table->item(i, j);
        if (item == nullptr) {
          m(i, j) = 0;
          continue;
        }

        m(i, j) = item->text().toDouble();
      }
    }

    is_closed = true;
    delete table;

    cb();
  });

  connect(randomize_button, &QPushButton::clicked, [this]() {
    randomize();
  });
}

void matrix_input_window::randomize() const {
  loading->show();
  QApplication::processEvents();

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<mtx::matrix::item_type_t> dis(-100, 100);

  for (int i = 0; i < table->rowCount(); i++) {
    for (int j = 0; j < table->columnCount(); j++) {
      const double value = round(dis(gen) * 100) / 100;
      table->setItem(i, j, new QTableWidgetItem(QString::number(value)));
    }
  }

  loading->hide();
}

void matrix_input_window::closeEvent(QCloseEvent *event) {
  QDialog::closeEvent(event);
  if (is_closed) return;

  QApplication::quit();
}