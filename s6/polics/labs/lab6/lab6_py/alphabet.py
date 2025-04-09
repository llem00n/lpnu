def Ord(char: str) -> int:
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ '
    return alphabet.index(char.upper())

def Chr(num: int) -> str:
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ '
    return alphabet[num]