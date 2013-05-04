using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Mozzerella
{
    static class Program
    {
        private static Mozzerella mozzerella;
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            GameCore.OpenWindow();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Idle += new EventHandler(Update);
            Application.Run(mozzerella = new Mozzerella());
        }

        public static void Update(object sender, EventArgs e)
        {
            GameCore.Update();
            mozzerella.Update();
        }
    }
}
