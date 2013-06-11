struct JoystickAction
{
	int idAxe_MoveTowardBackWard;
	int idAxe_MoveLeftRight;
	int idAxe_Turn;
};



struct InfoJoystick
{
	int nbButton;
	int nbAxes;
};

struct AxeValue
{
	float x;
	float y;
	float z;
};