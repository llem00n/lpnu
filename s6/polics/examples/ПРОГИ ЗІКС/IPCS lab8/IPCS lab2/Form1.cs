using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Labs.Hill;

namespace IPCS_lab8
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

        }
        private const byte lenIV = 16;
        private static void AesCtrTransform(byte[] key, byte[] salt, Stream inputStream, Stream outputStream)
        {
            SymmetricAlgorithm aes =
                new AesManaged { Mode = CipherMode.ECB, Padding = PaddingMode.None };

            int blockSize = aes.BlockSize / 8;

            if (salt.Length != blockSize)
            {
                throw new ArgumentException(
                    string.Format(
                        "Salt size must be same as block size (actual: {0}, expected: {1})",
                        salt.Length, blockSize));
            }

            byte[] counter = (byte[])salt.Clone();

            Queue<byte> xorMask = new Queue<byte>();

            var zeroIv = new byte[blockSize];
            ICryptoTransform counterEncryptor = aes.CreateEncryptor(key, zeroIv);

            int b;
            while ((b = inputStream.ReadByte()) != -1)
            {
                if (xorMask.Count == 0)
                {
                    var counterModeBlock = new byte[blockSize];

                    counterEncryptor.TransformBlock(
                        counter, 0, counter.Length, counterModeBlock, 0);

                    for (var i2 = counter.Length - 1; i2 >= 0; i2--)
                    {
                        if (++counter[i2] != 0)
                        {
                            break;
                        }
                    }

                    foreach (var b2 in counterModeBlock)
                    {
                        xorMask.Enqueue(b2);
                    }
                }

                var mask = xorMask.Dequeue();
                outputStream.WriteByte((byte)(((byte)b) ^ mask));
            }
        }

        private void DoCipher()
        {

            try
            {
                if (string.IsNullOrEmpty(textBox_key.Text.Trim()))
                {
                    MessageBox.Show("Введіть ключ!");
                    return;
                }
                if (string.IsNullOrEmpty(textBox_input.Text.Trim()))
                {
                    MessageBox.Show("Введіть IV!");
                    return;
                }

                byte[] keyBytes = Encoding.UTF8.GetBytes(textBox_key.Text);

                int len = keyBytes.Length;
                if (len != 24)
                {
                    MessageBox.Show("Розмір ключа повинен 24 літери(192-bit) (" + len + ")");
                    return;
                }

                string salt = textBox_input.Text.Substring(0, Math.Min(textBox_input.Text.Length, lenIV));
                salt = salt.PadRight(16, salt[salt.Length - 1]);

                textBox_input.Enabled = false;
                textBox_input.Text = salt;
                textBox_input.Enabled = true;

                byte[] saltBytes = Encoding.UTF8.GetBytes(salt);

                if (dOpenFile.ShowDialog() == DialogResult.OK)
                {
                    using (FileStream fs = File.OpenRead(dOpenFile.FileName))
                    {
                        if (dSaveFile.ShowDialog() == DialogResult.OK)
                        {
                            using (FileStream fs2 = File.OpenWrite(dSaveFile.FileName))
                            {
                                AesCtrTransform(keyBytes, saltBytes, fs, fs2);
                            }
                        }
                    }
                    MessageBox.Show("Виконано!");
                }
            }
            catch
            {
                MessageBox.Show("Не вдалось зашифрувати/розшифрувати повідомлення!");
            }
        }
        private void button_Encrypt_Click(object sender, EventArgs e)
        {
            DoCipher();
        }

        private void button__Decrypt_Click(object sender, EventArgs e)
        {
            DoCipher();
        }
    }
}


