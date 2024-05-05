from numpy import matrix, linalg
from random import randint
from alphabet import Ord, Chr
from matrix import mod_inv_matrix

def hill_cipher_encrypt(plain_text: str, key: matrix) -> str:
    text = []
    for i in plain_text.upper():
        text.append(randint(0, 26))
        text.append(randint(0, 26))
        text.append(Ord(i))

    while len(text) % 3 != 0:
        text.append(randint(0, 26))

    cipher_text = ''
    for i in range(0, len(text), 3):
        row = matrix([[text[i], text[i + 1], text[i + 2]]])
        mult = row * key
        for x in range(3):
            cipher_text += Chr(mult.item(0, x) % 27)

    return cipher_text

def hill_cipher_decrypt(cipher_text: str, key: matrix) -> str:
    text = [Ord(i) for i in cipher_text.upper()]
    decoded_text = ''
    for i in range(0, len(text), 3):
        row = matrix([[text[i], text[i + 1], text[i + 2]]])
        inv = mod_inv_matrix(key, 27)
        mult = row * inv
        for x in range(3):
            decoded_text += Chr(int(mult.item(0, x)) % 27)

    plain_text = ''
    for i in range(0, len(decoded_text), 3):
        plain_text += decoded_text[i + 2]
    return plain_text