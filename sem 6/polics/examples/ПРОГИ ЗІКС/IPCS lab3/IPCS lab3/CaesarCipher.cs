using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab3
{
    class CaesarCipher
    {
        string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string retVal = "";

        private string CodeEncode(string text, int k)
        {
            try
            {
                retVal = "";
                //додаємо до алфавіту малі літери
                var fullAlfabet =  alfabet + alfabet.ToLower();
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
                        int codeIndex = ( letterQty + index - k) % letterQty;
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
        public string Decrypt(string plainMessage, int key)
            => CodeEncode(plainMessage, key);


    }
}
