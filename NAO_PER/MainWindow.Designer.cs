namespace NAO_PER
{
    partial class MainWindow
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainWindow));
            this.GroupBox_Connexion = new System.Windows.Forms.GroupBox();
            this.Button_Connect = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.TextBox_IP = new System.Windows.Forms.TextBox();
            this.GroupBox_BaseAction = new System.Windows.Forms.GroupBox();
            this.Button_Crouch = new System.Windows.Forms.Button();
            this.Button_LyingBack = new System.Windows.Forms.Button();
            this.Button_LyingBelly = new System.Windows.Forms.Button();
            this.Button_SitDown = new System.Windows.Forms.Button();
            this.Button_StandUp = new System.Windows.Forms.Button();
            this.Button_PlayMusique = new System.Windows.Forms.Button();
            this.Button_Dance = new System.Windows.Forms.Button();
            this.Button_Wave = new System.Windows.Forms.Button();
            this.Button_Wipe = new System.Windows.Forms.Button();
            this.GroupBox_AdvancedAction = new System.Windows.Forms.GroupBox();
            this.GroupBox_ManualControl = new System.Windows.Forms.GroupBox();
            this.Picture_JoystickProperties = new System.Windows.Forms.PictureBox();
            this.Picture_WiiMote = new System.Windows.Forms.PictureBox();
            this.Picture_Clavier = new System.Windows.Forms.PictureBox();
            this.Picture_MoveLeft = new System.Windows.Forms.PictureBox();
            this.Picture_MoveRight = new System.Windows.Forms.PictureBox();
            this.Picture_MoveBack = new System.Windows.Forms.PictureBox();
            this.Picture_MoveToward = new System.Windows.Forms.PictureBox();
            this.Picture_TurnRight = new System.Windows.Forms.PictureBox();
            this.Picture_TurnLeft = new System.Windows.Forms.PictureBox();
            this.GroupBox_State = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.ListBox_ActionList = new System.Windows.Forms.ListBox();
            this.GroupBox_Scripte = new System.Windows.Forms.GroupBox();
            this.Label_BumperState = new System.Windows.Forms.Label();
            this.Button_ServiceBumperEvent = new System.Windows.Forms.Button();
            this.CheckBox_Mod = new System.Windows.Forms.CheckBox();
            this.Button_ServiceNaoMarkDetection = new System.Windows.Forms.Button();
            this.TextBox_NaoMarkId = new System.Windows.Forms.TextBox();
            this.Button_FindMark = new System.Windows.Forms.Button();
            this.Label_SearchingMark = new System.Windows.Forms.Label();
            this.GroupBox_Connexion.SuspendLayout();
            this.GroupBox_BaseAction.SuspendLayout();
            this.GroupBox_AdvancedAction.SuspendLayout();
            this.GroupBox_ManualControl.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_JoystickProperties)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_WiiMote)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_Clavier)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveRight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveBack)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveToward)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_TurnRight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_TurnLeft)).BeginInit();
            this.GroupBox_State.SuspendLayout();
            this.GroupBox_Scripte.SuspendLayout();
            this.SuspendLayout();
            // 
            // GroupBox_Connexion
            // 
            this.GroupBox_Connexion.Controls.Add(this.Button_Connect);
            this.GroupBox_Connexion.Controls.Add(this.label1);
            this.GroupBox_Connexion.Controls.Add(this.TextBox_IP);
            this.GroupBox_Connexion.Location = new System.Drawing.Point(12, 12);
            this.GroupBox_Connexion.Name = "GroupBox_Connexion";
            this.GroupBox_Connexion.Size = new System.Drawing.Size(760, 60);
            this.GroupBox_Connexion.TabIndex = 0;
            this.GroupBox_Connexion.TabStop = false;
            this.GroupBox_Connexion.Text = "Connexion";
            // 
            // Button_Connect
            // 
            this.Button_Connect.Location = new System.Drawing.Point(307, 19);
            this.Button_Connect.Name = "Button_Connect";
            this.Button_Connect.Size = new System.Drawing.Size(78, 20);
            this.Button_Connect.TabIndex = 2;
            this.Button_Connect.Text = "Connexion";
            this.Button_Connect.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(100, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Adresse IP du robot";
            // 
            // TextBox_IP
            // 
            this.TextBox_IP.Location = new System.Drawing.Point(112, 19);
            this.TextBox_IP.Name = "TextBox_IP";
            this.TextBox_IP.Size = new System.Drawing.Size(189, 20);
            this.TextBox_IP.TabIndex = 0;
            // 
            // GroupBox_BaseAction
            // 
            this.GroupBox_BaseAction.Controls.Add(this.Button_Crouch);
            this.GroupBox_BaseAction.Controls.Add(this.Button_LyingBack);
            this.GroupBox_BaseAction.Controls.Add(this.Button_LyingBelly);
            this.GroupBox_BaseAction.Controls.Add(this.Button_SitDown);
            this.GroupBox_BaseAction.Controls.Add(this.Button_StandUp);
            this.GroupBox_BaseAction.Location = new System.Drawing.Point(12, 79);
            this.GroupBox_BaseAction.Name = "GroupBox_BaseAction";
            this.GroupBox_BaseAction.Size = new System.Drawing.Size(226, 244);
            this.GroupBox_BaseAction.TabIndex = 1;
            this.GroupBox_BaseAction.TabStop = false;
            this.GroupBox_BaseAction.Text = "Actions de base";
            // 
            // Button_Crouch
            // 
            this.Button_Crouch.Location = new System.Drawing.Point(75, 77);
            this.Button_Crouch.Name = "Button_Crouch";
            this.Button_Crouch.Size = new System.Drawing.Size(97, 23);
            this.Button_Crouch.TabIndex = 9;
            this.Button_Crouch.Text = "Accroupie";
            this.Button_Crouch.UseVisualStyleBackColor = true;
            // 
            // Button_LyingBack
            // 
            this.Button_LyingBack.Location = new System.Drawing.Point(75, 106);
            this.Button_LyingBack.Name = "Button_LyingBack";
            this.Button_LyingBack.Size = new System.Drawing.Size(97, 23);
            this.Button_LyingBack.TabIndex = 8;
            this.Button_LyingBack.Text = "Allongé - dos";
            this.Button_LyingBack.UseVisualStyleBackColor = true;
            // 
            // Button_LyingBelly
            // 
            this.Button_LyingBelly.Location = new System.Drawing.Point(75, 135);
            this.Button_LyingBelly.Name = "Button_LyingBelly";
            this.Button_LyingBelly.Size = new System.Drawing.Size(97, 23);
            this.Button_LyingBelly.TabIndex = 7;
            this.Button_LyingBelly.Text = "Allongé - ventre";
            this.Button_LyingBelly.UseVisualStyleBackColor = true;
            // 
            // Button_SitDown
            // 
            this.Button_SitDown.Location = new System.Drawing.Point(75, 48);
            this.Button_SitDown.Name = "Button_SitDown";
            this.Button_SitDown.Size = new System.Drawing.Size(97, 23);
            this.Button_SitDown.TabIndex = 1;
            this.Button_SitDown.Text = "Assis";
            this.Button_SitDown.UseVisualStyleBackColor = true;
            // 
            // Button_StandUp
            // 
            this.Button_StandUp.Location = new System.Drawing.Point(75, 19);
            this.Button_StandUp.Name = "Button_StandUp";
            this.Button_StandUp.Size = new System.Drawing.Size(97, 23);
            this.Button_StandUp.TabIndex = 0;
            this.Button_StandUp.Text = "Lever";
            this.Button_StandUp.UseVisualStyleBackColor = true;
            // 
            // Button_PlayMusique
            // 
            this.Button_PlayMusique.Location = new System.Drawing.Point(75, 106);
            this.Button_PlayMusique.Name = "Button_PlayMusique";
            this.Button_PlayMusique.Size = new System.Drawing.Size(97, 23);
            this.Button_PlayMusique.TabIndex = 6;
            this.Button_PlayMusique.Text = "Musique";
            this.Button_PlayMusique.UseVisualStyleBackColor = true;
            // 
            // Button_Dance
            // 
            this.Button_Dance.Location = new System.Drawing.Point(75, 19);
            this.Button_Dance.Name = "Button_Dance";
            this.Button_Dance.Size = new System.Drawing.Size(97, 23);
            this.Button_Dance.TabIndex = 5;
            this.Button_Dance.Text = "Danser";
            this.Button_Dance.UseVisualStyleBackColor = true;
            // 
            // Button_Wave
            // 
            this.Button_Wave.Location = new System.Drawing.Point(75, 48);
            this.Button_Wave.Name = "Button_Wave";
            this.Button_Wave.Size = new System.Drawing.Size(97, 23);
            this.Button_Wave.TabIndex = 4;
            this.Button_Wave.Text = "Saluer";
            this.Button_Wave.UseVisualStyleBackColor = true;
            // 
            // Button_Wipe
            // 
            this.Button_Wipe.Location = new System.Drawing.Point(75, 77);
            this.Button_Wipe.Name = "Button_Wipe";
            this.Button_Wipe.Size = new System.Drawing.Size(97, 23);
            this.Button_Wipe.TabIndex = 3;
            this.Button_Wipe.Text = "Pleurer";
            this.Button_Wipe.UseVisualStyleBackColor = true;
            // 
            // GroupBox_AdvancedAction
            // 
            this.GroupBox_AdvancedAction.Controls.Add(this.Button_Dance);
            this.GroupBox_AdvancedAction.Controls.Add(this.Button_PlayMusique);
            this.GroupBox_AdvancedAction.Controls.Add(this.Button_Wave);
            this.GroupBox_AdvancedAction.Controls.Add(this.Button_Wipe);
            this.GroupBox_AdvancedAction.Location = new System.Drawing.Point(244, 79);
            this.GroupBox_AdvancedAction.Name = "GroupBox_AdvancedAction";
            this.GroupBox_AdvancedAction.Size = new System.Drawing.Size(241, 244);
            this.GroupBox_AdvancedAction.TabIndex = 2;
            this.GroupBox_AdvancedAction.TabStop = false;
            this.GroupBox_AdvancedAction.Text = "Actions avancées";
            // 
            // GroupBox_ManualControl
            // 
            this.GroupBox_ManualControl.Controls.Add(this.Picture_JoystickProperties);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_WiiMote);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_Clavier);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_MoveLeft);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_MoveRight);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_MoveBack);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_MoveToward);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_TurnRight);
            this.GroupBox_ManualControl.Controls.Add(this.Picture_TurnLeft);
            this.GroupBox_ManualControl.Location = new System.Drawing.Point(492, 79);
            this.GroupBox_ManualControl.Name = "GroupBox_ManualControl";
            this.GroupBox_ManualControl.Size = new System.Drawing.Size(280, 244);
            this.GroupBox_ManualControl.TabIndex = 3;
            this.GroupBox_ManualControl.TabStop = false;
            this.GroupBox_ManualControl.Text = "Contrôle manuel du robot";
            // 
            // Picture_JoystickProperties
            // 
            this.Picture_JoystickProperties.BackgroundImage = global::NAO_PER.Properties.Resources.config_icn;
            this.Picture_JoystickProperties.Location = new System.Drawing.Point(237, 202);
            this.Picture_JoystickProperties.Name = "Picture_JoystickProperties";
            this.Picture_JoystickProperties.Size = new System.Drawing.Size(33, 33);
            this.Picture_JoystickProperties.TabIndex = 11;
            this.Picture_JoystickProperties.TabStop = false;
            this.Picture_JoystickProperties.Visible = false;
            // 
            // Picture_WiiMote
            // 
            this.Picture_WiiMote.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Picture_WiiMote.BackgroundImage")));
            this.Picture_WiiMote.Location = new System.Drawing.Point(131, 135);
            this.Picture_WiiMote.Name = "Picture_WiiMote";
            this.Picture_WiiMote.Size = new System.Drawing.Size(100, 100);
            this.Picture_WiiMote.TabIndex = 10;
            this.Picture_WiiMote.TabStop = false;
            // 
            // Picture_Clavier
            // 
            this.Picture_Clavier.BackgroundImage = global::NAO_PER.Resources.clavier;
            this.Picture_Clavier.Location = new System.Drawing.Point(25, 135);
            this.Picture_Clavier.Name = "Picture_Clavier";
            this.Picture_Clavier.Size = new System.Drawing.Size(100, 100);
            this.Picture_Clavier.TabIndex = 9;
            this.Picture_Clavier.TabStop = false;
            // 
            // Picture_MoveLeft
            // 
            this.Picture_MoveLeft.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("Picture_MoveLeft.BackgroundImage")));
            this.Picture_MoveLeft.Location = new System.Drawing.Point(58, 79);
            this.Picture_MoveLeft.Name = "Picture_MoveLeft";
            this.Picture_MoveLeft.Size = new System.Drawing.Size(50, 50);
            this.Picture_MoveLeft.TabIndex = 8;
            this.Picture_MoveLeft.TabStop = false;
            // 
            // Picture_MoveRight
            // 
            this.Picture_MoveRight.BackgroundImage = global::NAO_PER.Resources.arrow_moveright;
            this.Picture_MoveRight.Location = new System.Drawing.Point(191, 79);
            this.Picture_MoveRight.Name = "Picture_MoveRight";
            this.Picture_MoveRight.Size = new System.Drawing.Size(50, 50);
            this.Picture_MoveRight.TabIndex = 7;
            this.Picture_MoveRight.TabStop = false;
            // 
            // Picture_MoveBack
            // 
            this.Picture_MoveBack.BackgroundImage = global::NAO_PER.Resources.arrow_moveback;
            this.Picture_MoveBack.Location = new System.Drawing.Point(124, 79);
            this.Picture_MoveBack.Name = "Picture_MoveBack";
            this.Picture_MoveBack.Size = new System.Drawing.Size(50, 50);
            this.Picture_MoveBack.TabIndex = 6;
            this.Picture_MoveBack.TabStop = false;
            // 
            // Picture_MoveToward
            // 
            this.Picture_MoveToward.BackgroundImage = global::NAO_PER.Properties.Resources.arrow_toward;
            this.Picture_MoveToward.Location = new System.Drawing.Point(124, 19);
            this.Picture_MoveToward.Name = "Picture_MoveToward";
            this.Picture_MoveToward.Size = new System.Drawing.Size(50, 50);
            this.Picture_MoveToward.TabIndex = 4;
            this.Picture_MoveToward.TabStop = false;
            // 
            // Picture_TurnRight
            // 
            this.Picture_TurnRight.BackgroundImage = global::NAO_PER.Properties.Resources.arrow_turnright;
            this.Picture_TurnRight.Location = new System.Drawing.Point(191, 19);
            this.Picture_TurnRight.Name = "Picture_TurnRight";
            this.Picture_TurnRight.Size = new System.Drawing.Size(50, 50);
            this.Picture_TurnRight.TabIndex = 2;
            this.Picture_TurnRight.TabStop = false;
            // 
            // Picture_TurnLeft
            // 
            this.Picture_TurnLeft.BackgroundImage = global::NAO_PER.Properties.Resources.arrow_turnleft;
            this.Picture_TurnLeft.Location = new System.Drawing.Point(58, 19);
            this.Picture_TurnLeft.Name = "Picture_TurnLeft";
            this.Picture_TurnLeft.Size = new System.Drawing.Size(50, 50);
            this.Picture_TurnLeft.TabIndex = 1;
            this.Picture_TurnLeft.TabStop = false;
            // 
            // GroupBox_State
            // 
            this.GroupBox_State.Controls.Add(this.label2);
            this.GroupBox_State.Controls.Add(this.ListBox_ActionList);
            this.GroupBox_State.Location = new System.Drawing.Point(12, 329);
            this.GroupBox_State.Name = "GroupBox_State";
            this.GroupBox_State.Size = new System.Drawing.Size(473, 220);
            this.GroupBox_State.TabIndex = 4;
            this.GroupBox_State.TabStop = false;
            this.GroupBox_State.Text = "Etat du robot";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(194, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Liste des actions en attente d\'exécution";
            // 
            // ListBox_ActionList
            // 
            this.ListBox_ActionList.FormattingEnabled = true;
            this.ListBox_ActionList.Location = new System.Drawing.Point(6, 41);
            this.ListBox_ActionList.Name = "ListBox_ActionList";
            this.ListBox_ActionList.Size = new System.Drawing.Size(129, 173);
            this.ListBox_ActionList.TabIndex = 7;
            // 
            // GroupBox_Scripte
            // 
            this.GroupBox_Scripte.Controls.Add(this.Label_SearchingMark);
            this.GroupBox_Scripte.Controls.Add(this.Button_FindMark);
            this.GroupBox_Scripte.Controls.Add(this.TextBox_NaoMarkId);
            this.GroupBox_Scripte.Controls.Add(this.Button_ServiceNaoMarkDetection);
            this.GroupBox_Scripte.Controls.Add(this.Label_BumperState);
            this.GroupBox_Scripte.Controls.Add(this.Button_ServiceBumperEvent);
            this.GroupBox_Scripte.Location = new System.Drawing.Point(492, 358);
            this.GroupBox_Scripte.Name = "GroupBox_Scripte";
            this.GroupBox_Scripte.Size = new System.Drawing.Size(280, 191);
            this.GroupBox_Scripte.TabIndex = 5;
            this.GroupBox_Scripte.TabStop = false;
            this.GroupBox_Scripte.Text = "Liste des modes";
            // 
            // Label_BumperState
            // 
            this.Label_BumperState.AutoSize = true;
            this.Label_BumperState.Location = new System.Drawing.Point(156, 25);
            this.Label_BumperState.Name = "Label_BumperState";
            this.Label_BumperState.Size = new System.Drawing.Size(0, 13);
            this.Label_BumperState.TabIndex = 1;
            // 
            // Button_ServiceBumperEvent
            // 
            this.Button_ServiceBumperEvent.Location = new System.Drawing.Point(25, 20);
            this.Button_ServiceBumperEvent.Name = "Button_ServiceBumperEvent";
            this.Button_ServiceBumperEvent.Size = new System.Drawing.Size(125, 23);
            this.Button_ServiceBumperEvent.TabIndex = 0;
            this.Button_ServiceBumperEvent.Text = "Détection d\'obstacle";
            this.Button_ServiceBumperEvent.UseVisualStyleBackColor = true;
            // 
            // CheckBox_Mod
            // 
            this.CheckBox_Mod.AutoSize = true;
            this.CheckBox_Mod.Location = new System.Drawing.Point(492, 335);
            this.CheckBox_Mod.Name = "CheckBox_Mod";
            this.CheckBox_Mod.Size = new System.Drawing.Size(200, 17);
            this.CheckBox_Mod.TabIndex = 6;
            this.CheckBox_Mod.Text = "Utiliser le robot en mode automatique";
            this.CheckBox_Mod.UseVisualStyleBackColor = true;
            // 
            // Button_ServiceNaoMarkDetection
            // 
            this.Button_ServiceNaoMarkDetection.Location = new System.Drawing.Point(25, 50);
            this.Button_ServiceNaoMarkDetection.Name = "Button_ServiceNaoMarkDetection";
            this.Button_ServiceNaoMarkDetection.Size = new System.Drawing.Size(125, 23);
            this.Button_ServiceNaoMarkDetection.TabIndex = 2;
            this.Button_ServiceNaoMarkDetection.Text = "Détection de NaoMark";
            this.Button_ServiceNaoMarkDetection.UseVisualStyleBackColor = true;
            // 
            // TextBox_NaoMarkId
            // 
            this.TextBox_NaoMarkId.Location = new System.Drawing.Point(159, 52);
            this.TextBox_NaoMarkId.Name = "TextBox_NaoMarkId";
            this.TextBox_NaoMarkId.Size = new System.Drawing.Size(41, 20);
            this.TextBox_NaoMarkId.TabIndex = 3;
            this.TextBox_NaoMarkId.Visible = false;
            // 
            // Button_FindMark
            // 
            this.Button_FindMark.Location = new System.Drawing.Point(206, 50);
            this.Button_FindMark.Name = "Button_FindMark";
            this.Button_FindMark.Size = new System.Drawing.Size(68, 23);
            this.Button_FindMark.TabIndex = 4;
            this.Button_FindMark.Text = "Chercher";
            this.Button_FindMark.UseVisualStyleBackColor = true;
            this.Button_FindMark.Visible = false;
            // 
            // Label_SearchingMark
            // 
            this.Label_SearchingMark.AutoSize = true;
            this.Label_SearchingMark.Location = new System.Drawing.Point(25, 80);
            this.Label_SearchingMark.Name = "Label_SearchingMark";
            this.Label_SearchingMark.Size = new System.Drawing.Size(154, 13);
            this.Label_SearchingMark.TabIndex = 5;
            this.Label_SearchingMark.Text = "Recherche de mark en cours...";
            this.Label_SearchingMark.Visible = false;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(784, 562);
            this.Controls.Add(this.CheckBox_Mod);
            this.Controls.Add(this.GroupBox_Scripte);
            this.Controls.Add(this.GroupBox_State);
            this.Controls.Add(this.GroupBox_ManualControl);
            this.Controls.Add(this.GroupBox_AdvancedAction);
            this.Controls.Add(this.GroupBox_BaseAction);
            this.Controls.Add(this.GroupBox_Connexion);
            this.MaximumSize = new System.Drawing.Size(800, 600);
            this.MinimumSize = new System.Drawing.Size(800, 600);
            this.Name = "MainWindow";
            this.Text = "Interface de contrôle";
            this.GroupBox_Connexion.ResumeLayout(false);
            this.GroupBox_Connexion.PerformLayout();
            this.GroupBox_BaseAction.ResumeLayout(false);
            this.GroupBox_AdvancedAction.ResumeLayout(false);
            this.GroupBox_ManualControl.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.Picture_JoystickProperties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_WiiMote)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_Clavier)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveRight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveBack)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_MoveToward)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_TurnRight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Picture_TurnLeft)).EndInit();
            this.GroupBox_State.ResumeLayout(false);
            this.GroupBox_State.PerformLayout();
            this.GroupBox_Scripte.ResumeLayout(false);
            this.GroupBox_Scripte.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox GroupBox_Connexion;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox TextBox_IP;
        private System.Windows.Forms.Button Button_Connect;
        private System.Windows.Forms.GroupBox GroupBox_BaseAction;
        private System.Windows.Forms.Button Button_PlayMusique;
        private System.Windows.Forms.Button Button_Dance;
        private System.Windows.Forms.Button Button_Wave;
        private System.Windows.Forms.Button Button_Wipe;
        private System.Windows.Forms.Button Button_SitDown;
        private System.Windows.Forms.Button Button_StandUp;
        private System.Windows.Forms.GroupBox GroupBox_AdvancedAction;
        private System.Windows.Forms.GroupBox GroupBox_ManualControl;
        private System.Windows.Forms.GroupBox GroupBox_State;
        private System.Windows.Forms.GroupBox GroupBox_Scripte;
        private System.Windows.Forms.CheckBox CheckBox_Mod;
        private System.Windows.Forms.Button Button_LyingBack;
        private System.Windows.Forms.Button Button_LyingBelly;
        private System.Windows.Forms.Button Button_Crouch;
        private System.Windows.Forms.PictureBox Picture_TurnRight;
        private System.Windows.Forms.PictureBox Picture_TurnLeft;
        private System.Windows.Forms.PictureBox Picture_MoveToward;
        private System.Windows.Forms.PictureBox Picture_MoveRight;
        private System.Windows.Forms.PictureBox Picture_MoveBack;
        private System.Windows.Forms.PictureBox Picture_MoveLeft;
        private System.Windows.Forms.PictureBox Picture_Clavier;
        private System.Windows.Forms.PictureBox Picture_WiiMote;
        private System.Windows.Forms.ListBox ListBox_ActionList;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Button_ServiceBumperEvent;
        private System.Windows.Forms.Label Label_BumperState;
        private System.Windows.Forms.PictureBox Picture_JoystickProperties;
        private System.Windows.Forms.Button Button_FindMark;
        private System.Windows.Forms.TextBox TextBox_NaoMarkId;
        private System.Windows.Forms.Button Button_ServiceNaoMarkDetection;
        private System.Windows.Forms.Label Label_SearchingMark;
    }
}

