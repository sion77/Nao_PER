using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace NAO_PER.Joystick
{
    public partial class JoystickConfiguration : Form
    {
        JoystickProperty JoystickProperty { get; set; }
        public InfoJoystick InfoJoystick { get; set; }
        public Action<JoystickAction> GetJoystickActionOnApply { get; set; }

        public JoystickConfiguration(JoystickAction joystickAction)
        {
            InitializeComponent();

            Button_Cancel.Click += (object sender, EventArgs e) =>Close();
            Button_Appliquer.Click += (object sender, EventArgs e) => { GetJoystickActionOnApply(JoystickProperty.ToJoystickAction()); Close(); };

            JoystickHandler.SuspendRobotMovement();
            InfoJoystick = JoystickHandler.GetGoystickInformation();

            JoystickProperty = new JoystickProperty(joystickAction);
            PropertyGrid_Joystick.SelectedObject = JoystickProperty;
            PropertyGrid_Joystick.PropertyValueChanged += (object s, PropertyValueChangedEventArgs e)=>
            {
                if ((Axes)e.ChangedItem.Value == Axes.Automatique)
                {
                    int axeId = JoystickHandler.GetLastAxesMoved();
                    Axes selectedAxe = (Axes)Enum.GetValues(typeof(Axes)).GetValue(axeId);
                    JoystickProperty.SetProperty(e.ChangedItem.Label, selectedAxe);
                }
                else if ((int)((Axes)e.ChangedItem.Value) > InfoJoystick.nbAxes)
                {
                    MessageBox.Show(Joystick.Resource.JoystickAxeNotFound + " " + (int)((Axes)e.ChangedItem.Value));
                    JoystickProperty.SetProperty(e.ChangedItem.Label, Axes.Axe0);
                }
            };
        }

        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);
            JoystickHandler.ResumeRobotMovement();
        }
    }

    enum Axes {Axe0, Axe1, Axe2, Axe3, Axe4, Axe5, Axe6, Axe7, Axe8, Axe9,Automatique };

    internal class JoystickProperty
    {
        public JoystickProperty(JoystickAction joystickAction)
        {

            MoveLeftAndRightAxe = (Axes)Enum.GetValues(typeof(Axes)).GetValue(joystickAction.idAxe_MoveLeftRight);
            MoveToWardAndBackWardAxe = (Axes)Enum.GetValues(typeof(Axes)).GetValue(joystickAction.idAxe_MoveTowardBackWard);
            TurnAxe = (Axes)Enum.GetValues(typeof(Axes)).GetValue(joystickAction.idAxe_Turn);
        }
        public JoystickProperty()
        {

        }



        [CategoryAttribute("Mouvements")]
        public Axes MoveToWardAndBackWardAxe { get; set; }
        [CategoryAttribute("Mouvements")]
        public Axes MoveLeftAndRightAxe { get; set; }
        [CategoryAttribute("Mouvements")]
        public Axes TurnAxe { get; set; }


        public void SetProperty(string propertyName, Axes value)
        {
            switch (propertyName)
            {
                case "MoveToWardAndBackWardAxe":
                    MoveToWardAndBackWardAxe = value;
                    break;
                case "MoveLeftAndRightAxe":
                    MoveLeftAndRightAxe = value;
                    break;
                case "TurnAxe":
                    TurnAxe = value;
                    break;
            }
        }

        public JoystickAction ToJoystickAction()
        {
            JoystickAction joystickAction;
            joystickAction.idAxe_MoveLeftRight = (int)MoveLeftAndRightAxe;
            joystickAction.idAxe_MoveTowardBackWard = (int)MoveToWardAndBackWardAxe;
            joystickAction.idAxe_Turn = (int)TurnAxe;
            return joystickAction;
        }
    }
}
