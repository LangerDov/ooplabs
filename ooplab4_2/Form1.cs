namespace ooplab4_2
{
    public partial class Form1 : Form
    {
        private class Model
        {
            private int a;
            private int b;
            private int c;

            public Model(int a, int b, int c)
            {
                this.a = a;
                this.b = b;
                this.c = c;
            }

            public void SetA(int a)
            {
                if (a > 100)
                    a = 100;
                
                if (a < b)
                    this.a = a;
            }
            public int GetA()
            {
                return a;
            }
            public void SetB(int b)
            {
                if (b > 100)
                    b = 100;
                if (b > c)
                {
                    return;
                }
                else if (b < a)
                {
                    return;
                }

                this.b = b;
            }

            public int GetB()
            {
                return b;
            }
            public void SetC(int c)
            {
                if (c > 100)
                    c = 100;
                
                if (c < b)
                {
                    return;
                }
                this.c = c;

            }
            public int GetC()
            {
                return c;
            }
        }

        Model model;

        void UpdateValues()
        {
            tb_A.Text = model.GetA().ToString();
            tb_B.Text = model.GetB().ToString();
            tb_C.Text = model.GetC().ToString();

            nUP_A.Value = model.GetA();
            nUP_B.Value = model.GetB();
            nUP_C.Value = model.GetC();

            trb_A.Value = model.GetA();
            trb_B.Value = model.GetB();
            trb_C.Value = model.GetC();
        }
        public Form1()
        {
            model = new Model(30, 60, 70);
            InitializeComponent();
            UpdateValues();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (((TextBox)sender).Name == "tb_A")
            {
                model.SetA(int.Parse(tb_A.Text));
            }
            else if (((TextBox)sender).Name == "tb_B")
            {
                model.SetB(int.Parse(tb_B.Text));
            }
            else if (((TextBox)sender).Name == "tb_C")
            {
                model.SetC(int.Parse(tb_C.Text));
            }
            UpdateValues();
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }

        }

        private void nUP_A_ValueChanged(object sender, EventArgs e)
        {
            if (((NumericUpDown)sender).Name == "nUP_A")
            {
                model.SetA(((int)nUP_A.Value));
            }
            else if (((NumericUpDown)sender).Name == "nUP_B")
            {
                model.SetB(((int)nUP_B.Value));
            }
            else if (((NumericUpDown)sender).Name == "nUP_C")
            {
                model.SetC(((int)nUP_C.Value));
            }
            UpdateValues();
        }

        private void trb_B_ValueChanged(object sender, EventArgs e)
        {
            if (((TrackBar)sender).Name == "trb_A")
            {
                model.SetA(((int)trb_A.Value));
            }
            else if (((TrackBar)sender).Name == "trb_B")
            {
                model.SetB(((int)trb_B.Value));
            }
            else if (((TrackBar)sender).Name == "trb_C")
            {
                model.SetC(((int)trb_C.Value));
            }
            UpdateValues();
        }
    }
}