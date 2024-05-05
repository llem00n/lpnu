using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IPCS_lab1
{
        public class RoundButton : Button
        {
            protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
            {
                var graphicsPath = new GraphicsPath();
           
                graphicsPath.AddRectangle(ClientRectangle);
            
                this.Region = new Region(graphicsPath);
                base.OnPaint(e);
            }
        }
}
