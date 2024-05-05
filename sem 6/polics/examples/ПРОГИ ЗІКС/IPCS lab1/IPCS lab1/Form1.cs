using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.SizableToolWindow;
            Region = System.Drawing.Region.FromHrgn(CreateRoundRectRgn(0, 0, Width, Height, 20, 20));
        }
        [DllImport("Gdi32.dll", EntryPoint = "CreateRoundRectRgn")]
        private static extern IntPtr CreateRoundRectRgn
        (
            int nLeftRect,     // x-coordinate of upper-left corner
            int nTopRect,      // y-coordinate of upper-left corner
            int nRightRect,    // x-coordinate of lower-right corner
            int nBottomRect,   // y-coordinate of lower-right corner
            int nWidthEllipse, // width of ellipse
            int nHeightEllipse // height of ellipse
        );

        int key;
        string mess;
        bool check = true;
        private void roundButton1_Click(object sender, EventArgs e)
        {
            mess = textBox2.Text;
            var c = new CaesarCipher();
            try
            {

                if (int.TryParse(textBox1.Text, out key))
                {
                    if (textBox2.Text != string.Empty)
                    {
                        check = rb_Ukr.Checked == true ? true : false;
                        c.SetAlpha(check);
                        textBox3.Text = c.Encrypt(mess, key);
                    }
                    else MessageBox.Show("Введіть повідомлення", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

                }
                else MessageBox.Show("Введіть крок", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            catch(Exception ex)
            {
                MessageBox.Show($"Помилка: {ex.Message}");
            }

        }
        private void roundButton2_Click(object sender, EventArgs e)
        {
            mess = textBox2.Text;
            var c = new CaesarCipher();
            try
            {
                
                if (int.TryParse(textBox1.Text, out key))
                {
                    if (textBox2.Text != string.Empty)
                    {
                        
                        check = rb_Ukr.Checked == true ? true : false;
                        c.SetAlpha(check);
                        textBox3.Text =  c.Decrypt(mess, key);
                    }
                    else MessageBox.Show("Введіть повідомлення", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

                }
                else MessageBox.Show("Введіть крок", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: {ex.Message}");
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(textBox1.Text, "[^0-9]"))
            {
                MessageBox.Show("Введіть тільки цифри", "Попередження");
                
                textBox1.Text = textBox1.Text.Remove(textBox1.Text.Length - 1);
            }
        }



       
    }
}
