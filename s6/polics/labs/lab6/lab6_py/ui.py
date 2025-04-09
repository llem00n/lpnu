import sys
from PyQt6.QtWidgets import (
    QApplication,
    QWidget,
    QLineEdit,
    QHBoxLayout,
    QVBoxLayout,
    QPushButton,
    QLabel,
    QTextEdit,
    QFrame,
    QMainWindow,
    QStatusBar,
)
from hill_cipher import hill_cipher_encrypt, hill_cipher_decrypt
from numpy import matrix
from alphabet import Ord


class HillCipherWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Hill Cipher")

        label = QLabel("Шифр Хілла")
        label.setStyleSheet("font-size: 20px;")

        key_input_layout = QHBoxLayout()
        key_input_label = QLabel("Ключ:")
        self.key_input = QLineEdit()
        self.key_input.setText("PORUBAIMH")
        self.key_input.setReadOnly(True)
        key_input_layout.addWidget(key_input_label)
        key_input_layout.addWidget(self.key_input)

        plain_text_input_layout = QVBoxLayout()
        plain_text_input_label = QLabel("Розшифроване повідомлення:")
        self.plain_text_input = QTextEdit()
        plain_text_input_layout.addWidget(plain_text_input_label)
        plain_text_input_layout.addWidget(self.plain_text_input)
        line1 = QFrame()
        line1.setFrameShape(QFrame.Shape.HLine)
        plain_text_input_layout.addWidget(line1)

        cipher_text_input_layout = QVBoxLayout()
        cipher_text_input_label = QLabel("Зашифроване повідомлення:")
        self.cipher_text_input = QTextEdit()
        cipher_text_input_layout.addWidget(cipher_text_input_label)
        cipher_text_input_layout.addWidget(self.cipher_text_input)
        line2 = QFrame()
        line2.setFrameShape(QFrame.Shape.HLine)
        cipher_text_input_layout.addWidget(line2)

        encrypt_button = QPushButton("Зашифрувати")
        encrypt_button.clicked.connect(self.encrypt)
        decrypt_button = QPushButton("Розшифрувати")
        decrypt_button.clicked.connect(self.decrypt)

        layout = QVBoxLayout()
        layout.addWidget(label)
        layout.addLayout(key_input_layout)
        layout.addLayout(plain_text_input_layout)
        layout.addLayout(cipher_text_input_layout)
        layout.addWidget(encrypt_button)
        layout.addWidget(decrypt_button)

        central_widget = QWidget()
        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)
        self.setStatusBar(QStatusBar(self))
        self.statusBar().showMessage("Готовий до роботи")

        self.show()


    def encrypt(self):
        key = self.get_key()
        plain_text = self.plain_text_input.toPlainText()
        cipher_text = hill_cipher_encrypt(plain_text, key)
        self.cipher_text_input.setText(cipher_text)

    def decrypt(self):
        key = self.get_key()
        cipher_text = self.cipher_text_input.toPlainText()
        plain_text = hill_cipher_decrypt(cipher_text, key)
        self.plain_text_input.setText(plain_text)

    def get_key(self) -> matrix:
        key_chars = list(self.key_input.text().upper())
        key_rows = []
        for i in range(3):
            chars_row = key_chars[i * 3 : (i + 1) * 3]
            key_rows.append([Ord(char) for char in chars_row])

        return matrix(key_rows)


class App:
    def __init__(self):
        self.app = QApplication(sys.argv)
        self.window = HillCipherWindow()

    def run(self):
        sys.exit(self.app.exec())
