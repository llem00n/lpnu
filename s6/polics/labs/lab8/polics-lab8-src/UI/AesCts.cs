using System.Security.Cryptography;

namespace UI;

public class AesCts
{
    private readonly byte[] _key;
    private readonly byte[] _iv;

    public AesCts(byte[] key, byte[] iv)
    {
        if (key.Length != 16)
            throw new ArgumentException("Ключ має бути довжиною 16 байт.", nameof(key));
        if (iv.Length != 16)
            throw new ArgumentException("IV має бути довжиною 16 байт.", nameof(iv));

        _key = key;
        _iv = iv;
    }

    public byte[] Encrypt(byte[] plaintext)
    {
        using var aesAlg = Aes.Create();
        aesAlg.Key = _key;
        aesAlg.IV = _iv;
        aesAlg.Mode = CipherMode.CBC;
        aesAlg.Padding = PaddingMode.None;
        
        while (plaintext.Length % 16 != 0)
            plaintext = plaintext.Concat(new byte[] { 0 }).ToArray();
        
        using var encryptor = aesAlg.CreateEncryptor();
        using var msEncrypt = new MemoryStream();
        using var csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write);
        csEncrypt.Write(plaintext, 0, plaintext.Length);
        csEncrypt.FlushFinalBlock();
        return msEncrypt.ToArray();
    }

    public byte[] Decrypt(byte[] ciphertext)
    {
        using var aesAlg = Aes.Create();
        aesAlg.Key = _key;
        aesAlg.IV = _iv;
        aesAlg.Mode = CipherMode.CBC;
        aesAlg.Padding = PaddingMode.None;
        
        while (ciphertext.Length % 16 != 0)
            ciphertext = ciphertext.Concat(new byte[] { 0 }).ToArray();
        
        using var decryptor = aesAlg.CreateDecryptor();
        using var msDecrypt = new MemoryStream();
        using var csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Write);
        csDecrypt.Write(ciphertext, 0, ciphertext.Length);
        csDecrypt.FlushFinalBlock();
        return msDecrypt.ToArray();
    }
}