#include "ui/matrix_output_window.hpp"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <random>

using namespace ui;

matrix_output_window::matrix_output_window(const std::string &title, mtx::matrix &matrix, QWidget *parent): QDialog(parent), is_closed(false), m(matrix) {
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

  const auto ok_button = new QPushButton("OK", this);
  ok_button->setMaximumWidth(90);
  buttons->addWidget(ok_button);

  table = new QTableWidget(static_cast<int>(m.size().rows), static_cast<int>(m.size().cols), this);
  for (int i = 0; i < table->columnCount(); i++) {
    table->setColumnWidth(i, 40);
  }
  layout->addWidget(table);

  connect(ok_button, &QPushButton::clicked, [this]() {
    close();
  });

    for (uint32_t i = 0; i < m.size().rows; i++) {
        for (uint32_t j = 0; j < m.size().cols; j++) {
        table->setItem(i, j, new QTableWidgetItem(QString::number(m(i, j))));
        }
    }
}

void matrix_output_window::closeEvent(QCloseEvent *event) {
  QDialog::closeEvent(event);
  if (is_closed) return;

  QApplication::quit();
}