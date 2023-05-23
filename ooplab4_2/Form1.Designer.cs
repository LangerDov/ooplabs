namespace ooplab4_2
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tb_C = new TextBox();
            tb_B = new TextBox();
            tb_A = new TextBox();
            nUP_B = new NumericUpDown();
            nUP_C = new NumericUpDown();
            nUP_A = new NumericUpDown();
            trb_A = new TrackBar();
            trb_B = new TrackBar();
            trb_C = new TrackBar();
            label1 = new Label();
            ((System.ComponentModel.ISupportInitialize)nUP_B).BeginInit();
            ((System.ComponentModel.ISupportInitialize)nUP_C).BeginInit();
            ((System.ComponentModel.ISupportInitialize)nUP_A).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trb_A).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trb_B).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trb_C).BeginInit();
            SuspendLayout();
            // 
            // tb_C
            // 
            tb_C.Location = new Point(620, 212);
            tb_C.Name = "tb_C";
            tb_C.Size = new Size(150, 27);
            tb_C.TabIndex = 8;
            tb_C.TextChanged += textBox3_TextChanged;
            tb_C.KeyPress += textBox3_KeyPress;
            // 
            // tb_B
            // 
            tb_B.Location = new Point(339, 212);
            tb_B.Name = "tb_B";
            tb_B.Size = new Size(150, 27);
            tb_B.TabIndex = 9;
            tb_B.TextChanged += textBox3_TextChanged;
            tb_B.KeyPress += textBox3_KeyPress;
            // 
            // tb_A
            // 
            tb_A.Location = new Point(57, 212);
            tb_A.Name = "tb_A";
            tb_A.Size = new Size(150, 27);
            tb_A.TabIndex = 10;
            tb_A.TextChanged += textBox3_TextChanged;
            tb_A.KeyPress += textBox3_KeyPress;
            // 
            // nUP_B
            // 
            nUP_B.Location = new Point(339, 267);
            nUP_B.Name = "nUP_B";
            nUP_B.Size = new Size(150, 27);
            nUP_B.TabIndex = 11;
            nUP_B.ValueChanged += nUP_A_ValueChanged;
            // 
            // nUP_C
            // 
            nUP_C.Location = new Point(620, 267);
            nUP_C.Name = "nUP_C";
            nUP_C.Size = new Size(150, 27);
            nUP_C.TabIndex = 12;
            nUP_C.ValueChanged += nUP_A_ValueChanged;
            // 
            // nUP_A
            // 
            nUP_A.Location = new Point(57, 267);
            nUP_A.Name = "nUP_A";
            nUP_A.Size = new Size(150, 27);
            nUP_A.TabIndex = 13;
            nUP_A.ValueChanged += nUP_A_ValueChanged;
            // 
            // trb_A
            // 
            trb_A.Location = new Point(57, 323);
            trb_A.Maximum = 100;
            trb_A.Name = "trb_A";
            trb_A.Size = new Size(150, 56);
            trb_A.TabIndex = 14;
            trb_A.ValueChanged += trb_B_ValueChanged;
            // 
            // trb_B
            // 
            trb_B.Location = new Point(338, 323);
            trb_B.Maximum = 100;
            trb_B.Name = "trb_B";
            trb_B.Size = new Size(151, 56);
            trb_B.TabIndex = 15;
            trb_B.ValueChanged += trb_B_ValueChanged;
            // 
            // trb_C
            // 
            trb_C.Location = new Point(619, 323);
            trb_C.Maximum = 100;
            trb_C.Name = "trb_C";
            trb_C.Size = new Size(151, 56);
            trb_C.TabIndex = 16;
            trb_C.ValueChanged += trb_B_ValueChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 70F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(43, 26);
            label1.Name = "label1";
            label1.Size = new Size(727, 155);
            label1.TabIndex = 17;
            label1.Text = "A <= B <= C";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 380);
            Controls.Add(label1);
            Controls.Add(trb_C);
            Controls.Add(trb_B);
            Controls.Add(trb_A);
            Controls.Add(nUP_A);
            Controls.Add(nUP_C);
            Controls.Add(nUP_B);
            Controls.Add(tb_A);
            Controls.Add(tb_B);
            Controls.Add(tb_C);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)nUP_B).EndInit();
            ((System.ComponentModel.ISupportInitialize)nUP_C).EndInit();
            ((System.ComponentModel.ISupportInitialize)nUP_A).EndInit();
            ((System.ComponentModel.ISupportInitialize)trb_A).EndInit();
            ((System.ComponentModel.ISupportInitialize)trb_B).EndInit();
            ((System.ComponentModel.ISupportInitialize)trb_C).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox tb_C;
        private TextBox tb_B;
        private TextBox tb_A;
        private NumericUpDown nUP_B;
        private NumericUpDown nUP_C;
        private NumericUpDown nUP_A;
        private TrackBar trb_A;
        private TrackBar trb_B;
        private TrackBar trb_C;
        private Label label1;
    }
}