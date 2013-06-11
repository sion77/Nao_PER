namespace NAO_PER.Joystick
{
    partial class JoystickConfiguration
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
            this.PropertyGrid_Joystick = new System.Windows.Forms.PropertyGrid();
            this.Button_Appliquer = new System.Windows.Forms.Button();
            this.Button_Cancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // PropertyGrid_Joystick
            // 
            this.PropertyGrid_Joystick.Location = new System.Drawing.Point(0, 0);
            this.PropertyGrid_Joystick.Name = "PropertyGrid_Joystick";
            this.PropertyGrid_Joystick.Size = new System.Drawing.Size(235, 329);
            this.PropertyGrid_Joystick.TabIndex = 0;
            // 
            // Button_Appliquer
            // 
            this.Button_Appliquer.Location = new System.Drawing.Point(12, 334);
            this.Button_Appliquer.Name = "Button_Appliquer";
            this.Button_Appliquer.Size = new System.Drawing.Size(75, 23);
            this.Button_Appliquer.TabIndex = 1;
            this.Button_Appliquer.Text = "Appliquer";
            this.Button_Appliquer.UseVisualStyleBackColor = true;
            // 
            // Button_Cancel
            // 
            this.Button_Cancel.Location = new System.Drawing.Point(147, 334);
            this.Button_Cancel.Name = "Button_Cancel";
            this.Button_Cancel.Size = new System.Drawing.Size(75, 23);
            this.Button_Cancel.TabIndex = 2;
            this.Button_Cancel.Text = "Annuler";
            this.Button_Cancel.UseVisualStyleBackColor = true;
            // 
            // JoystickConfiguration
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(234, 361);
            this.Controls.Add(this.Button_Cancel);
            this.Controls.Add(this.Button_Appliquer);
            this.Controls.Add(this.PropertyGrid_Joystick);
            this.MaximumSize = new System.Drawing.Size(250, 400);
            this.MinimumSize = new System.Drawing.Size(250, 400);
            this.Name = "JoystickConfiguration";
            this.Text = "Configuration du joystick";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PropertyGrid PropertyGrid_Joystick;
        private System.Windows.Forms.Button Button_Appliquer;
        private System.Windows.Forms.Button Button_Cancel;
    }
}