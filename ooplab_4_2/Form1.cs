using System.Security.Cryptography.X509Certificates;

namespace ooplab_4
{
    public partial class Form1 : Form
    {
        class CCircle
        {
            private class View
            {
                public Pen pen;
                public View()
                {
                    pen = new Pen(Color.Red);
                }

                public void Draw(PaintEventArgs ev, Rectangle area)
                {
                    ev.Graphics.DrawEllipse(pen, area);
                }

            }

            private class Model
            {
                public bool PointOnArea(Rectangle area, int x, int y)
                {
                    return false;
                }
            }

            private View view;

            private Rectangle area;

            private Model model;

            public CCircle(int x, int y)
            {
                view = new View();
                model = new Model();
                area.Height = 100;
                area.Width = 100;
                area.X = x;
                area.Y = y;
            }

            public void SetSize(int width, int height)
            {
                area.Height = height;
                area.Width = width;
            }

            public void SetPos(int x, int y)
            {
                area.X = x;
                area.Y = y;
            }

            public bool PointOnMe(Rectangle area, int x, int y)
            {
                return model.PointOnArea(area, x, y);
            }
            public void Draw(PaintEventArgs ev)
            {
                view.Draw(ev, area);
            }


        }

        List<CCircle> circles;
        public Form1()
        {
            InitializeComponent();
            circles = new List<CCircle>();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            for (int i = 0; i < circles.Count - 1; i++)
            {
                circles[i].Draw(e);
            }
        }

        private void Form1_Click(object sender, EventArgs e)
        {
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            CCircle circle = new CCircle(e.X, e.Y);
            circles.Add(circle);
        }
    }
}