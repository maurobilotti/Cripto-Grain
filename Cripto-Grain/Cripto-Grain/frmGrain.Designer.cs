namespace Cripto_Grain
{
    partial class frmGrain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnAbrirImg = new System.Windows.Forms.Button();
            this.picImg = new System.Windows.Forms.PictureBox();
            this.btnCifrar = new System.Windows.Forms.Button();
            this.btnDescrifrar = new System.Windows.Forms.Button();
            this.fileDialog = new System.Windows.Forms.OpenFileDialog();
            this.txtPath = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.picImg)).BeginInit();
            this.SuspendLayout();
            // 
            // btnAbrirImg
            // 
            this.btnAbrirImg.Location = new System.Drawing.Point(13, 13);
            this.btnAbrirImg.Name = "btnAbrirImg";
            this.btnAbrirImg.Size = new System.Drawing.Size(75, 23);
            this.btnAbrirImg.TabIndex = 0;
            this.btnAbrirImg.Text = "Abrir Imagen";
            this.btnAbrirImg.UseVisualStyleBackColor = true;
            this.btnAbrirImg.Click += new System.EventHandler(this.btnAbrirImg_Click);
            // 
            // picImg
            // 
            this.picImg.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.picImg.BackColor = System.Drawing.SystemColors.ControlDark;
            this.picImg.Location = new System.Drawing.Point(12, 71);
            this.picImg.Name = "picImg";
            this.picImg.Size = new System.Drawing.Size(807, 437);
            this.picImg.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picImg.TabIndex = 1;
            this.picImg.TabStop = false;
            // 
            // btnCifrar
            // 
            this.btnCifrar.Location = new System.Drawing.Point(94, 13);
            this.btnCifrar.Name = "btnCifrar";
            this.btnCifrar.Size = new System.Drawing.Size(75, 23);
            this.btnCifrar.TabIndex = 2;
            this.btnCifrar.Text = "Cifrar";
            this.btnCifrar.UseVisualStyleBackColor = true;
            this.btnCifrar.Click += new System.EventHandler(this.btnCifrar_Click);
            // 
            // btnDescrifrar
            // 
            this.btnDescrifrar.Location = new System.Drawing.Point(175, 13);
            this.btnDescrifrar.Name = "btnDescrifrar";
            this.btnDescrifrar.Size = new System.Drawing.Size(75, 23);
            this.btnDescrifrar.TabIndex = 3;
            this.btnDescrifrar.Text = "Descifrar";
            this.btnDescrifrar.UseVisualStyleBackColor = true;
            this.btnDescrifrar.Click += new System.EventHandler(this.btnDescrifrar_Click);
            // 
            // fileDialog
            // 
            this.fileDialog.FileName = "file";
            // 
            // txtPath
            // 
            this.txtPath.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.txtPath.Location = new System.Drawing.Point(13, 45);
            this.txtPath.Name = "txtPath";
            this.txtPath.Size = new System.Drawing.Size(489, 20);
            this.txtPath.TabIndex = 4;
            // 
            // frmGrain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(832, 520);
            this.Controls.Add(this.txtPath);
            this.Controls.Add(this.btnDescrifrar);
            this.Controls.Add(this.btnCifrar);
            this.Controls.Add(this.picImg);
            this.Controls.Add(this.btnAbrirImg);
            this.Name = "frmGrain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Grain Stream Cipher";
            this.Load += new System.EventHandler(this.frmGrain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picImg)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAbrirImg;
        private System.Windows.Forms.PictureBox picImg;
        private System.Windows.Forms.Button btnCifrar;
        private System.Windows.Forms.Button btnDescrifrar;
        private System.Windows.Forms.OpenFileDialog fileDialog;
        private System.Windows.Forms.TextBox txtPath;
    }
}

