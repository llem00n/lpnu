using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //string[] alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string alphabet = "";
        string text = "";
        string dechip = "";
        CaesarCipher caesar;
        Dictionary<char, double> anl = new Dictionary<char, double>();
        StringBuilder sb = new StringBuilder();
        readonly Dictionary<char, double> commonEng = new Dictionary<char, double>()
        
        {
            {'A', 8.167}, {'B', 1.492}, {'C', 2.782}, {'D', 4.253}, {'E', 12.702}, {'F', 2.228}, {'G', 2.015},
            {'H', 6.094}, {'I', 6.966}, {'J', 0.153}, {'K', 0.772}, {'L', 4.025},  {'M', 2.406}, {'N', 6.749},
            {'O', 7.507}, {'P', 1.929}, {'Q', 0.095}, {'R', 5.987}, {'S', 6.327},  {'T', 9.056}, {'U', 2.758},
            {'V', 0.978}, {'W', 2.360}, {'X', 0.150}, {'Y', 1.974}, {'Z', 0.074},
        };
        List<int> lst = new List<int>();
        public Dictionary<int, int> differ = new Dictionary<int, int>();
        
        private void button_Decrypt_Click(object sender, EventArgs e)
        {
            if (textBox_input.Text == "")
                MessageBox.Show("ВВедіть повідомлення", "Попередження");
            else
            {
                try
                {
                    sb.Clear();
                    differ.Clear();
                    alphabet = alph;
                    string res = "";
                    text = textBox_input.Text;
                    textBox_output.Text = "";
                    caesar = new CaesarCipher();
                    int[] key = { 0, 0 };
                    for (int i = 0; i < 26; i++)
                    {
                        res = caesar.Decrypt(text, i);
                        lst.Clear();
                        foreach (var let in alphabet)
                        {
                            double prc = (double)(100 * res.ToUpper().Count(s => s == let)) / (double)(res.ToUpper().Count(s => alphabet.Any(p => p == s)));
                            if (!anl.ContainsKey(let))
                                anl.Add(let, prc);
                            double df = Math.Pow(commonEng[let] - prc, 2);
                            //int difference = (int)(100 * (commonEng[let] - prc) / commonEng[let]);
                            int difference = (int)df;
                            lst.Add(difference);
                        }
                        int total = 0;
                        foreach (int dif in lst)
                        {
                            total += dif;
                        }
                        total /= 26;
                        //if(!differ.ContainsKey(i))
                        differ.Add(i, total);

                        sb.AppendFormat("\n--------------------------------------------------------------------------------------------------------\n");
                        sb.AppendLine();
                        sb.AppendFormat("\nIteration: {0}\n", i);
                        sb.AppendLine();
                        sb.AppendFormat("\nDispersion is: {0}\n", differ[i]);
                        sb.AppendLine();
                        sb.AppendFormat("\nText is: ");
                        sb.AppendLine();
                        sb.AppendFormat("{0}", res);
                        sb.AppendLine();

                        sb.AppendFormat("\n--------------------------------------------------------------------------------------------------------\n");
                        sb.AppendLine();

                    }

                    key = GetKey();
                    sb.AppendLine(String.Format("Key of code: {0}", key[0]));
                    dechip = caesar.Decrypt(text, key[0]);
                    sb.AppendFormat("\nDispersion is: {0}\n", key[1]);
                    sb.AppendLine();
                    sb.AppendFormat("\nText is: ");
                    sb.AppendLine();
                    sb.AppendFormat("{0}", dechip);
                    sb.AppendLine();

                    //sb.AppendLine(dechip);

                    Set();
                    textBox_output.Text = sb.ToString();
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Помилка розшифрування: {ex.ToString()}");
                }
            }
        }

        public int[] GetKey()
        {
            int[] res = { 0, 0};
            int key = -1, value = 0;
            foreach (var ite in differ)
            {
                if (key == -1)
                {
                    key = ite.Key;
                    value = ite.Value;
                }

                else if (value > ite.Value)
                {
                    key = ite.Key;
                    value = ite.Value;
                }
            }
            res[0] = key;
            res[1] = value;
            return res;
        }
        public void Set()
        {
            //datagridview settings
            dataGridView1.ColumnCount = 4;
            dataGridView1.Columns[0].HeaderText = "Symbol";
            dataGridView1.Columns[1].HeaderText = "Count";
            dataGridView1.Columns[2].HeaderText = "Percent";
            dataGridView1.Columns[3].HeaderText = "Common percent";
            dataGridView1.Columns[0].Width = 40;
            dataGridView1.Columns[1].Width = 50;
            dataGridView1.Columns[2].Width = 60;
            dataGridView1.Columns[3].Width = 50;
            dataGridView1.DataSource = null;
            dataGridView1.Rows.Clear();
            int count = 0;

            foreach (var let in alphabet)
            {
                double prc = (double)(100 * dechip.ToUpper().Count(s => s == let)) / (double)(dechip.ToUpper().Count(s => alphabet.Any(p => p == s)));
                
                if (!anl.ContainsKey(let))
                    anl.Add(let, prc);
                dataGridView1.Rows.Add();
                dataGridView1.Rows[count].Cells[0].Value = let;
                dataGridView1.Rows[count].Cells[1].Value = dechip.ToUpper().Count(s => s == let);
                dataGridView1.Rows[count].Cells[2].Value = string.Format("{0:f3}%", prc);
                dataGridView1.Rows[count].Cells[3].Value = string.Format("{0:f3}%", commonEng.ElementAt(count).Value);
                count++;
            }
        }



     
    }
}
