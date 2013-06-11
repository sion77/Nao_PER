using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading.Tasks;
using NAO_PER.Joystick;

namespace NAO_PER
{
    enum Mod {clavier,mouse,wiimote };

    public partial class MainWindow : Form
    {
        private Mod _mod = Mod.mouse;
        public JoystickConfiguration JoystickConfiguration { get; set; }
        public JoystickAction JoystickAction {get;set; }

        private int _nao_x;
        private int _nao_y;
        private int _nao_a;

        public MainWindow()
        {
            InitializeComponent();
            EnableUI(false);

            TextBox_IP.KeyDown += (object sender, KeyEventArgs e) =>{if (e.KeyCode == Keys.Enter)ConnectEvent(sender, e);};

            Button_Connect.Click += ConnectEvent;
            Button_StandUp.Click += PostureEvent;
            Button_SitDown.Click += PostureEvent;
            Button_Dance.Click += PostureEvent;
            Button_Wave.Click += PostureEvent;
            Button_Wipe.Click += PostureEvent;
            Button_LyingBelly.Click += PostureEvent;
            Button_LyingBack.Click += PostureEvent;
            Button_Crouch.Click += PostureEvent;
            Button_ServiceBumperEvent.Click += ServiceEvent;
            Button_ServiceNaoMarkDetection.Click += ServiceEvent;


            Picture_MoveToward.MouseDown +=EventImageButtonClick;
            Picture_TurnLeft.MouseDown += EventImageButtonClick;
            Picture_TurnRight.MouseDown += EventImageButtonClick;
            Picture_MoveBack.MouseDown += EventImageButtonClick;
            Picture_MoveLeft.MouseDown += EventImageButtonClick;
            Picture_MoveRight.MouseDown += EventImageButtonClick;


            Picture_MoveToward.MouseUp += EventImageButtonLeave;
            Picture_MoveToward.MouseLeave += EventImageButtonLeave;

            Picture_TurnLeft.MouseUp += EventImageButtonLeave;
            Picture_TurnLeft.MouseLeave += EventImageButtonLeave;

            Picture_TurnRight.MouseUp += EventImageButtonLeave;
            Picture_TurnRight.MouseLeave += EventImageButtonLeave;

            Picture_MoveBack.MouseUp += EventImageButtonLeave;
            Picture_MoveBack.MouseLeave += EventImageButtonLeave;

            Picture_MoveLeft.MouseUp += EventImageButtonLeave;
            Picture_MoveLeft.MouseLeave += EventImageButtonLeave;

            Picture_MoveRight.MouseUp += EventImageButtonLeave;
            Picture_MoveRight.MouseLeave += EventImageButtonLeave;

            SetClavierAndWiiMoteControl();
                
        }


        protected override void OnClosed(EventArgs e)
        {
            NaoHandler.Disconnect();
            base.OnClosed(e);
        }

        private void SetClavierAndWiiMoteControl()
        {
            Picture_JoystickProperties.Click += (object sender, EventArgs e) =>
            {
                if (_mod != Mod.wiimote)
                    return;
                if (JoystickConfiguration == null)
                {
                    Picture_JoystickProperties.BorderStyle = BorderStyle.Fixed3D;
                    JoystickConfiguration = new JoystickConfiguration(JoystickAction);
                    JoystickConfiguration.GetJoystickActionOnApply = ja => JoystickHandler.SetJoyStickAction(JoystickAction = ja);
                    JoystickConfiguration.ShowDialog(this);
                    JoystickConfiguration.Dispose();
                    JoystickConfiguration = null;
                    Picture_JoystickProperties.BorderStyle = BorderStyle.None;
                }
            };


            Picture_Clavier.Click +=(object sender,EventArgs e )=>
            {
                if (_mod == Mod.clavier)
                    _mod = Mod.mouse;
                else
                {
                    _mod = Mod.clavier;
                    JoystickHandler.DisableJoystick();
                }
                SetPictureButtonStyle();
            };

            Picture_WiiMote.Click += (object sender, EventArgs e) =>
            {
                if (_mod == Mod.wiimote)
                {
                    _mod = Mod.mouse;
                    JoystickHandler.DisableJoystick();
                }
                else
                {
                    _mod = Mod.wiimote;
                    new Task(() => 
                    {
                        unsafe
                        {
                            JoystickAction joystickAction = JoystickAction;
                            if (JoystickHandler.EnableJoystickControl(&joystickAction) == 0)
                            {
                                _mod = Mod.mouse;
                                Invoke(new MethodInvoker(() => SetPictureButtonStyle()));
                                MessageBox.Show(Resources.JoystickNotFountMessage);
                            }
                        }
                    }).Start();
                }
                SetPictureButtonStyle();
            };

            this.KeyPreview = true;
            this.KeyDown += (object sender, KeyEventArgs e) =>
            {
                if (_mod != Mod.clavier)
                    return;
                switch (e.KeyCode)
                {
                    case Keys.Z:
                        _nao_x = 1;
                        break;
                    case Keys.S:
                        _nao_x = -1;
                        break;
                    case Keys.Q:
                        _nao_y = 1;
                        break;
                    case Keys.D:
                        _nao_y = -1;
                        break;
                    case Keys.A:
                        _nao_a = 1;
                        break;
                    case Keys.E:
                        _nao_a = -1;
                        break;
                }
                NaoHandler.MoveToWard(_nao_x, _nao_y, _nao_a);
            };
            this.KeyUp += (object sender, KeyEventArgs e) =>
            {
                switch (e.KeyCode)
                {
                    case Keys.Z:
                        _nao_x = 0;
                        break;
                    case Keys.S:
                        _nao_x = 0;
                        break;
                    case Keys.Q:
                        _nao_y = 0;
                        break;
                    case Keys.D:
                        _nao_y = 0;
                        break;
                    case Keys.A:
                        _nao_a = 0;
                        break;
                    case Keys.E:
                        _nao_a = 0;
                        break;
                }
                NaoHandler.MoveToWard(_nao_x, _nao_y, _nao_a);
            };

        }

        private void SetPictureButtonStyle()
        {
            Picture_WiiMote.BorderStyle = BorderStyle.None;
            Picture_Clavier.BorderStyle = BorderStyle.None;
            Picture_JoystickProperties.Visible = false;
            switch (_mod)
            {
                case Mod.clavier:
                    Picture_Clavier.BorderStyle = BorderStyle.Fixed3D;
                    break;
                case Mod.wiimote:
                    Picture_JoystickProperties.Visible = true;
                    Picture_WiiMote.BorderStyle = BorderStyle.Fixed3D;
                    break;
            }
        }


        private void EventImageButtonClick(object sender,EventArgs e)
        {
            if (_mod != Mod.mouse)
                return;
            ((PictureBox)sender).BorderStyle = BorderStyle.Fixed3D;
            
            if (sender == Picture_MoveToward)
                NaoHandler.MoveToWard(1.0f, 0f, 0f);
            if (sender == Picture_TurnLeft)
                NaoHandler.MoveToWard(0f, 0f, 1.0f);
            if (sender == Picture_TurnRight)
                NaoHandler.MoveToWard(0f, 0f, -1.0f);
            if (sender == Picture_MoveBack)
                NaoHandler.MoveToWard(-1.0f, 0f, 0f);
            if (sender == Picture_MoveLeft)
                NaoHandler.MoveToWard(0f, 1f, 0f);
            if (sender == Picture_MoveRight)
                NaoHandler.MoveToWard(0f, -1f, 0f);
        }

        private void EventImageButtonLeave(object sender, EventArgs e)
        {
            PictureBox picture = sender as PictureBox;
            if (picture.BorderStyle == BorderStyle.Fixed3D)
            {
                picture.BorderStyle = BorderStyle.None;
                NaoHandler.StopMove();
            }
        }



        private void ConnectEvent(object sender, EventArgs e)
        {
            unsafe
            {
                if (NaoHandler.IsConnected() == 1)
                    DisconnectUI();
                else
                {


                    if (NaoHandler.TryToConnect(CsharpToCppTypeConverter.ToSbytePointer(TextBox_IP.Text)) == 1)
                    {
                        EnableUI(true);
                        Button_Connect.Text = Resources.Disconect;
                        TextBox_IP.Enabled = false;
                        Task task = new Task(delegate
                            {
                                if (NaoHandler.ShowVideoWindow() == 0)
                                    Invoke(new MethodInvoker(() => DisconnectUI()));
                            });
                        task.Start();
                    }
                    else
                    {

                    }
                }
            }
        }

        private void ServiceEvent(object sender, EventArgs e)
        {
            if (sender == Button_ServiceBumperEvent)
            {
                new Task(() => NaoHandler.EnableBumperDetection()).Start();
                new Task(() =>
                {
                    while (true)
                    {
                        if (NaoHandler.IsBumperPressed() == 1)
                            Invoke(new MethodInvoker(() => Label_BumperState.Text = "Obstacle!"));

                        else if (Label_BumperState.Text != string.Empty)
                            Invoke(new MethodInvoker(() => Label_BumperState.Text = string.Empty));
                        System.Threading.Thread.Sleep(50);
                    }
                }).Start();
            }
            else if(sender == this.Button_ServiceNaoMarkDetection)
            {
                new Task(() => NaoHandler.EnableNaoMarkServiceDetection()).Start();
                Button_FindMark.Visible = true;
                TextBox_NaoMarkId.Visible = true;
                Button_FindMark.Click +=(object sender2, EventArgs e2) => 
                {
                    if (string.IsNullOrEmpty(TextBox_NaoMarkId.Text))
                        return;
                    int markId = -1;
                    try
                    {
                        markId = System.Convert.ToInt32(TextBox_NaoMarkId.Text);
                    }
                    catch
                    {
                        TextBox_NaoMarkId.Text = null;
                        return;
                    }
                    if (markId != -1)
                    {
                        NaoHandler.SetMarkToFind(markId);
                        Label_SearchingMark.Visible = true;
                        new Task(() => 
                        {
                            while(true)
                            {
                                if (NaoHandler.IsMarkFounded() == 1)
                                    break;
                                System.Threading.Thread.Sleep(100);
                            }
                            Invoke(new MethodInvoker(() => Label_SearchingMark.Visible = false));
                        }).Start();
                    }

                };
            }
        }


        private void PostureEvent(object sender, EventArgs e)
        {
            unsafe
            {
                string item = string.Empty;
                if (sender == Button_StandUp)
                {
                    ListBox_ActionList.Items.Add(item = Resources.StandInit);
                    new Task(() =>
                    {
                        NaoHandler.SetPosture(CsharpToCppTypeConverter.ToSbytePointer("StandInit"));
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_SitDown)
                {
                    ListBox_ActionList.Items.Add(item = Resources.Sit);
                    new Task(() =>
                    {
                        NaoHandler.SetPosture(CsharpToCppTypeConverter.ToSbytePointer("Sit"));
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_LyingBelly)
                {
                    ListBox_ActionList.Items.Add(item = Resources.LyingBelly);
                    new Task(() =>
                    {
                        NaoHandler.SetPosture(CsharpToCppTypeConverter.ToSbytePointer("LyingBelly"));
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_LyingBack)
                {
                    ListBox_ActionList.Items.Add(item = Resources.LyingBack);
                    new Task(() =>
                    {
                        NaoHandler.SetPosture(CsharpToCppTypeConverter.ToSbytePointer("LyingBack"));
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_Crouch)
                {
                    ListBox_ActionList.Items.Add(item = Resources.Crouch);
                    new Task(() => 
                    {
                        NaoHandler.SetPosture(CsharpToCppTypeConverter.ToSbytePointer("Crouch"));
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_Dance)
                {
                    ListBox_ActionList.Items.Add(item = Resources.TaiChiDance);
                    new Task(() =>
                    {
                        NaoHandler.Annimation_TaiChiDance();
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_Wave)
                {
                    ListBox_ActionList.Items.Add(item = Resources.WaveHand);
                    new Task(() =>
                    {
                        NaoHandler.Annimation_WaveHand();
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                if (sender == Button_Wipe)
                {
                    ListBox_ActionList.Items.Add(item = Resources.Wipe);
                    new Task(() =>
                    {
                        NaoHandler.Annimation_Wipe();
                        Invoke(new MethodInvoker(() => ListBox_ActionList.Items.Remove(item)));
                    }).Start();
                }
                
            }
        }

        private void DisconnectUI()
        {
            NaoHandler.HideVideoWindow();
            EnableUI(false);
            Button_Connect.Text = Resources.Connect;
            TextBox_IP.Enabled = true;
            NaoHandler.Disconnect();
        }


        private void EnableUI(bool value)
        {
            GroupBox_BaseAction.Enabled = value;
            GroupBox_AdvancedAction.Enabled = value;
            GroupBox_ManualControl.Enabled = value;
            GroupBox_State.Enabled = value;
            GroupBox_Scripte.Enabled = value;
            CheckBox_Mod.Enabled = value;
        }
    }
}
