using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cripto_Grain
{
    public partial class frmGrain : Form
    {
        public frmGrain()
        {
            InitializeComponent();
            fileDialog.Filter = "BMP Files (*.bmp)|*.bmp";
        }

        private void btnAbrirImg_Click(object sender, EventArgs e)
        {
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                Image image = Image.FromFile(fileDialog.FileName);
                picImg.Image = image;
                
            }
        }

        private void btnCifrar_Click(object sender, EventArgs e)
        {

        }

        private void btnDescrifrar_Click(object sender, EventArgs e)
        {

        }

        private void frmGrain_Load(object sender, EventArgs e)
        {

        }      
    }
}
