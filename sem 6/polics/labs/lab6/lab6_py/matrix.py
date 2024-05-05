import numpy as np

def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1

def mod_inv_matrix(matrix, modulus):
    det = int(round(np.linalg.det(matrix)))
    det_inv = mod_inverse(det, modulus)
    adjoint_matrix = np.zeros_like(matrix)
    for i in range(matrix.shape[0]):
        for j in range(matrix.shape[1]):
            minor = np.delete(np.delete(matrix, i, axis=0), j, axis=1)
            adjoint_matrix[j, i] = ((-1) ** (i + j)) * int(round(np.linalg.det(minor)))
    inv_matrix = (det_inv * adjoint_matrix) % modulus
    return inv_matrix