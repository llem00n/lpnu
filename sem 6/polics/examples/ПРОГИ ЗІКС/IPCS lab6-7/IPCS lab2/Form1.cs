using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Labs.Hill;

namespace IPCS_lab2
{
    public partial class Form1 : Form
    {


        //DataTable table = new DataTable();
        public Form1()
        {
            InitializeComponent();

        }
        private const int rank = 3;
        readonly SecurityAlgorithm security = new Hill(new[] { Hill.SymbolType.Mask, Hill.SymbolType.Character, Hill.SymbolType.Character }, rank);
        private void DoJob67(Func<string, string, string> job)
        {
            try
            {
                if (string.IsNullOrEmpty(textBox_key.Text.Trim()))
                {
                    MessageBox.Show("Введіть ключ!");
                    return;
                }
                if (textBox_key.Text.Length != 9)
                {
                    MessageBox.Show("Введіть ключ");
                    return;
                }
                if (dOpenFile.ShowDialog() == DialogResult.OK)
                {
                    if (dSaveFile.ShowDialog() == DialogResult.OK)
                    {
                        string key = textBox_key.Text;
                        string input = File.ReadAllText(dOpenFile.FileName);
                        if (string.IsNullOrEmpty(input))
                        {
                            MessageBox.Show("Немає що шифрувати!");
                            return;
                        }
                        textBox_input.Text = input;
                        string output = job(input, key);
                        File.WriteAllText(dSaveFile.FileName, output);
                        textBox_output.Text = output;
                    }
                    MessageBox.Show("Виконано!");
                }
            }
            catch (ArgumentException ar)
            {
                MessageBox.Show(ar.Message);
            }
            catch
            {
                MessageBox.Show("Не вдалось зашифрувати/розшифрувати повідомлення!");
            }
        }
        private void button_Encrypt_Click(object sender, EventArgs e)
        {
            DoJob67(security.Encrypt);
        }

        private void button__Decrypt_Click(object sender, EventArgs e)
        {
            DoJob67(security.Decrypt);
        }
    }
}


