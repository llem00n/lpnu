﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab1
{
    class CaesarCipher
    {
        string alfabet = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
        string retVal = "";

        private string CodeEncode(string text, int k)
        {
            try
            {
      
                //додаємо до алфавіту малі літери
                var fullAlfabet = alfabet + alfabet.ToLower();
                var letterQty = fullAlfabet.Length;
                
                for (int i = 0; i < text.Length; i++)
                {
                    var c = text[i];
                    var index = fullAlfabet.IndexOf(c);
                    if (index < 0)
                    {
                        //якщо літеру не знайдено, додаємо її незмінною
                        retVal += c.ToString();
                    }
                    else
                    {
                        int codeIndex = (100*letterQty + index + k) % letterQty;
                        retVal += fullAlfabet[codeIndex];
                    }
                }

                
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: {ex.Message}", "Попередження");
            }
            return retVal;
        }

        //шифрування тексту
        public string Encrypt(string plainMessage, int key)
            => CodeEncode(plainMessage, key);

        //дешифрування тексту
        public string Decrypt(string encryptedMessage, int key)
            => CodeEncode(encryptedMessage, -key);
        public void SetAlpha(bool check)
        {
            string ukr = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
            string eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            alfabet = check == true ? ukr : eng;
        }
      
    }
}
