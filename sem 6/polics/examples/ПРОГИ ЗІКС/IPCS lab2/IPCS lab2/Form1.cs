using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab2
{
    public partial class Form1 : Form
    {
        string key= null;
        string input = null;
       
        //DataTable table = new DataTable();
        public Form1()
        {
            InitializeComponent();
                       
        }

        private void button_Encrypt_Click(object sender, EventArgs e)
        {
            
            try
            {
                if (String.IsNullOrEmpty(textBox_input.Text))
                {
                    MessageBox.Show("Введіть повідомлення");
                }
                else if (String.IsNullOrEmpty(textBox_key.Text))
                {
                    MessageBox.Show("Введіть повідомлення");
                }
                else
                {
                    string output = null;
                    key = textBox_key.Text;
                    input = (textBox_input.Text.Length % key.Length == 0) ? 
                        textBox_input.Text :
                        textBox_input.Text.PadRight(textBox_input.Text.Length - (textBox_input.Text.Length % key.Length) + key.Length ,' ');

                    int common = input.Length;
                    int colum = key.Length;
                    int rows = (int)Math.Ceiling((double)input.Length / colum);

                    dataGridView1.Rows.Clear();
                    dataGridView2.Rows.Clear();

                    dataGridView1.RowCount = rows;
                    dataGridView2.RowCount = rows;
                    dataGridView1.ColumnCount = colum;
                    dataGridView2.ColumnCount = colum;

                    char[,] startArr = new char[rows, colum];
                    char[,] endArr = new char[rows, colum];

                    int row1, colum1, i;
                    int[] key_get = GetKey(key);

                    for (i = 0; i < common; i++)
                    {
                        row1 = i / colum ;
                        colum1 = i % colum;
                        startArr[row1,colum1] = input[i];
                        dataGridView1.Columns[colum1].Width = 30;
                        dataGridView1.Columns[colum1].HeaderText = (colum1 + 1).ToString(); 
                        dataGridView1.Rows[row1].Cells[colum1].Value = input[i];
                    }

                    for (i = 0; i < common; i++)
                    {
                        row1 = i / colum;
                        colum1 = i % colum;
                        endArr[row1, colum1] = startArr[row1,key_get[colum1]];
                        dataGridView2.Columns[colum1].Width = 30;
                        dataGridView2.Columns[colum1].HeaderText = (key_get[colum1]+1).ToString();
                        dataGridView2.Rows[row1].Cells[colum1].Value = startArr[row1, key_get[colum1]];
                    }
                    for (i = 0; i < common; i++)
                    {
                        row1 = i / rows;
                        colum1 = i % rows;
                        output += endArr[colum1, row1];
                    }

                    textBox_output.Text = output;
                }
            }
            catch
            {
                MessageBox.Show("Помилка шифрування");
            }

        }
        private static int[] GetKey(string key)
        {
            int[] arr = new int[key.Length];
            for (int i = 0; i < key.Length; i++)
            {
                arr[i] = Int32.Parse(key[i].ToString())-1;
            }
            return arr;

        }

        private void button__Decrypt_Click(object sender, EventArgs e)
        {
            try
            {
                string output = null;
                if (String.IsNullOrEmpty(textBox_input.Text))
                {
                    MessageBox.Show("Введіть повідомлення");
                }
                else if (String.IsNullOrEmpty(textBox_key.Text))
                {
                    MessageBox.Show("Введіть повідомлення");
                }
                else
                {
                    
                    key = textBox_key.Text;
                    input = textBox_input.Text;

                    int common = input.Length;
                    int colum = key.Length;
                    int rows = (int)Math.Ceiling((double)input.Length / colum);

                    dataGridView1.Rows.Clear();
                    dataGridView2.Rows.Clear();
                    dataGridView1.RowCount = rows;
                    dataGridView2.RowCount = rows;
                    dataGridView1.ColumnCount = colum;
                    dataGridView2.ColumnCount = colum;

                    char[,] startArr = new char[rows, colum];
                    char[,] endArr = new char[rows, colum];

                    int row1, colum1, i;
                    int[] key_get = GetKey(key);
                    //Array.Sort(key_get);

                    for (i = 0; i < common; i++)
                    {
                        row1 = i % rows;
                        colum1 = i / rows;
                        startArr[row1, colum1] = input[i];
                        dataGridView1.Columns[colum1].Width = 30;
                        dataGridView1.Columns[colum1].HeaderText = (key_get[colum1] + 1).ToString();
                        dataGridView1.Rows[row1].Cells[colum1].Value = input[i];
                    }

                    for (i = 0; i < common; i++)
                    {
                        row1 = i / colum;
                        colum1 = i % colum;
                        
                        endArr[row1, colum1] = startArr[row1, key_get[colum1]];
                        dataGridView2.Columns[colum1].Width = 30;
                        dataGridView2.Columns[colum1].HeaderText = (colum1 + 1).ToString();
                        dataGridView2.Rows[row1].Cells[colum1].Value = startArr[row1, key_get[colum1]];
                    }
                    for (i = 0; i < common; i++)
                    {
                        row1 = i / colum;
                        colum1 = i % colum;
                        output += endArr[row1, colum1];
                    }

                    textBox_output.Text = output;
                }
            }
            catch
            {
                MessageBox.Show("Помилка шифрування");
            }
        }
    }

}
