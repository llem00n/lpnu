#include "main_window.h"

#include <QIntValidator>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

main_window::main_window(std::function<void(uint32_t)> &&n_setter, QWidget *parent) : QMainWindow(parent) {
  const auto main_widget = new QWidget(this);
  setCentralWidget(main_widget);

  const auto layout = new QVBoxLayout(main_widget);
  main_widget->setLayout(layout);

  const auto n_label = new QLabel("N", main_widget);
  n_label->setFont(QFont("Noto Sans", 14, QFont::Bold));
  layout->addWidget(n_label);

  n_input = new QLineEdit(main_widget);
  n_input->setValidator(new QIntValidator(0, INT32_MAX, n_input));
  layout->addWidget(n_input);

  const auto ok_button = new QPushButton("OK", main_widget);
  layout->addWidget(ok_button);
  connect(ok_button, &QPushButton::clicked, [this, n_setter = std::move(n_setter)]() {
    if (n_input->text().isEmpty() || n_input->text().toInt() == 0) {
      return;
    }

    hide();
    n_setter(n_input->text().toUInt());
  });
}

main_window::~main_window() {
  delete n_input;
}
