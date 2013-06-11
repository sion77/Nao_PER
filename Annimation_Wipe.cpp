#include "stdafx.h"
#include "SERVICES_UNMANAGED.h"

void Annimation_Wipe()
{
	/*
	// Choregraphe bezier export in c++.
	// Add #include <alproxies/almotionproxy.h> at the beginning of this file.
	std::vector<std::string> names;
	AL::ALValue times, keys;
	names.reserve(14);
	times.arraySetSize(14);
	keys.arraySetSize(14);

	names.push_back("HeadPitch");
	times[0].arraySetSize(6);
	keys[0].arraySetSize(6);

	times[0][0] = 0.960000;
	keys[0][0] = AL::ALValue::array(-0.0261199, AL::ALValue::array(3, -0.320000, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[0][1] = 1.68000;
	keys[0][1] = AL::ALValue::array(0.427944, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[0][2] = 3.28000;
	keys[0][2] = AL::ALValue::array(0.308291, AL::ALValue::array(3, -0.533333, 0.0739191), AL::ALValue::array(3, 0.226667, -0.0314156));
	times[0][3] = 3.96000;
	keys[0][3] = AL::ALValue::array(0.111940, AL::ALValue::array(3, -0.226667, 0.0588857), AL::ALValue::array(3, 0.186667, -0.0484941));
	times[0][4] = 4.52000;
	keys[0][4] = AL::ALValue::array(-0.0138480, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[0][5] = 5.08000;
	keys[0][5] = AL::ALValue::array(0.0613180, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("HeadYaw");
	times[1].arraySetSize(6);
	keys[1].arraySetSize(6);

	times[1][0] = 0.960000;
	keys[1][0] = AL::ALValue::array(-0.234743, AL::ALValue::array(3, -0.320000, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[1][1] = 1.68000;
	keys[1][1] = AL::ALValue::array(-0.622845, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[1][2] = 3.28000;
	keys[1][2] = AL::ALValue::array(-0.113558, AL::ALValue::array(3, -0.533333, -0.144250), AL::ALValue::array(3, 0.226667, 0.0613061));
	times[1][3] = 3.96000;
	keys[1][3] = AL::ALValue::array(-0.00617796, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[1][4] = 4.52000;
	keys[1][4] = AL::ALValue::array(-0.0276540, AL::ALValue::array(3, -0.186667, 0.00511335), AL::ALValue::array(3, 0.186667, -0.00511335));
	times[1][5] = 5.08000;
	keys[1][5] = AL::ALValue::array(-0.0368580, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LElbowRoll");
	times[2].arraySetSize(6);
	keys[2].arraySetSize(6);

	times[2][0] = 0.800000;
	keys[2][0] = AL::ALValue::array(-0.866668, AL::ALValue::array(3, -0.266667, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[2][1] = 1.52000;
	keys[2][1] = AL::ALValue::array(-0.868202, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[2][2] = 3.12000;
	keys[2][2] = AL::ALValue::array(-0.822183, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[2][3] = 3.80000;
	keys[2][3] = AL::ALValue::array(-0.992455, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[2][4] = 4.36000;
	keys[2][4] = AL::ALValue::array(-0.966378, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[2][5] = 4.92000;
	keys[2][5] = AL::ALValue::array(-0.990923, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LElbowYaw");
	times[3].arraySetSize(6);
	keys[3].arraySetSize(6);

	times[3][0] = 0.800000;
	keys[3][0] = AL::ALValue::array(-0.957257, AL::ALValue::array(3, -0.266667, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[3][1] = 1.52000;
	keys[3][1] = AL::ALValue::array(-0.823801, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[3][2] = 3.12000;
	keys[3][2] = AL::ALValue::array(-1.00788, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[3][3] = 3.80000;
	keys[3][3] = AL::ALValue::array(-0.925044, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[3][4] = 4.36000;
	keys[3][4] = AL::ALValue::array(-1.24412, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[3][5] = 4.92000;
	keys[3][5] = AL::ALValue::array(-0.960325, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LHand");
	times[4].arraySetSize(4);
	keys[4].arraySetSize(4);

	times[4][0] = 1.52000;
	keys[4][0] = AL::ALValue::array(0.00230429, AL::ALValue::array(3, -0.506667, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[4][1] = 3.12000;
	keys[4][1] = AL::ALValue::array(0.00230429, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[4][2] = 3.80000;
	keys[4][2] = AL::ALValue::array(0.00230429, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.373333, 0.000000));
	times[4][3] = 4.92000;
	keys[4][3] = AL::ALValue::array(0.00230429, AL::ALValue::array(3, -0.373333, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LShoulderPitch");
	times[5].arraySetSize(6);
	keys[5].arraySetSize(6);

	times[5][0] = 0.800000;
	keys[5][0] = AL::ALValue::array(0.863599, AL::ALValue::array(3, -0.266667, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[5][1] = 1.52000;
	keys[5][1] = AL::ALValue::array(0.858999, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[5][2] = 3.12000;
	keys[5][2] = AL::ALValue::array(0.888144, AL::ALValue::array(3, -0.533333, -0.0165061), AL::ALValue::array(3, 0.226667, 0.00701510));
	times[5][3] = 3.80000;
	keys[5][3] = AL::ALValue::array(0.929562, AL::ALValue::array(3, -0.226667, -0.0235543), AL::ALValue::array(3, 0.186667, 0.0193977));
	times[5][4] = 4.36000;
	keys[5][4] = AL::ALValue::array(1.01700, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[5][5] = 4.92000;
	keys[5][5] = AL::ALValue::array(0.977116, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LShoulderRoll");
	times[6].arraySetSize(6);
	keys[6].arraySetSize(6);

	times[6][0] = 0.800000;
	keys[6][0] = AL::ALValue::array(0.286815, AL::ALValue::array(3, -0.266667, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[6][1] = 1.52000;
	keys[6][1] = AL::ALValue::array(0.230059, AL::ALValue::array(3, -0.240000, 0.00872785), AL::ALValue::array(3, 0.533333, -0.0193952));
	times[6][2] = 3.12000;
	keys[6][2] = AL::ALValue::array(0.202446, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[6][3] = 3.80000;
	keys[6][3] = AL::ALValue::array(0.406468, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[6][4] = 4.36000;
	keys[6][4] = AL::ALValue::array(0.360449, AL::ALValue::array(3, -0.186667, 0.0145729), AL::ALValue::array(3, 0.186667, -0.0145729));
	times[6][5] = 4.92000;
	keys[6][5] = AL::ALValue::array(0.319030, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("LWristYaw");
	times[7].arraySetSize(4);
	keys[7].arraySetSize(4);

	times[7][0] = 1.52000;
	keys[7][0] = AL::ALValue::array(0.386526, AL::ALValue::array(3, -0.506667, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[7][1] = 3.12000;
	keys[7][1] = AL::ALValue::array(0.386526, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[7][2] = 3.80000;
	keys[7][2] = AL::ALValue::array(0.386526, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.373333, 0.000000));
	times[7][3] = 4.92000;
	keys[7][3] = AL::ALValue::array(0.386526, AL::ALValue::array(3, -0.373333, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RElbowRoll");
	times[8].arraySetSize(6);
	keys[8].arraySetSize(6);

	times[8][0] = 0.640000;
	keys[8][0] = AL::ALValue::array(1.28093, AL::ALValue::array(3, -0.213333, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[8][1] = 1.36000;
	keys[8][1] = AL::ALValue::array(1.39752, AL::ALValue::array(3, -0.240000, -0.0301510), AL::ALValue::array(3, 0.533333, 0.0670022));
	times[8][2] = 2.96000;
	keys[8][2] = AL::ALValue::array(1.57239, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[8][3] = 3.64000;
	keys[8][3] = AL::ALValue::array(1.24105, AL::ALValue::array(3, -0.226667, 0.0186267), AL::ALValue::array(3, 0.186667, -0.0153397));
	times[8][4] = 4.20000;
	keys[8][4] = AL::ALValue::array(1.22571, AL::ALValue::array(3, -0.186667, 0.0153397), AL::ALValue::array(3, 0.186667, -0.0153397));
	times[8][5] = 4.76000;
	keys[8][5] = AL::ALValue::array(0.840674, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RElbowYaw");
	times[9].arraySetSize(6);
	keys[9].arraySetSize(6);

	times[9][0] = 0.640000;
	keys[9][0] = AL::ALValue::array(-0.128898, AL::ALValue::array(3, -0.213333, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[9][1] = 1.36000;
	keys[9][1] = AL::ALValue::array(-0.285367, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[9][2] = 2.96000;
	keys[9][2] = AL::ALValue::array(-0.156510, AL::ALValue::array(3, -0.533333, -0.128857), AL::ALValue::array(3, 0.226667, 0.0547641));
	times[9][3] = 3.64000;
	keys[9][3] = AL::ALValue::array(0.754686, AL::ALValue::array(3, -0.226667, -0.242834), AL::ALValue::array(3, 0.186667, 0.199981));
	times[9][4] = 4.20000;
	keys[9][4] = AL::ALValue::array(1.17193, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[9][5] = 4.76000;
	keys[9][5] = AL::ALValue::array(0.677985, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RHand");
	times[10].arraySetSize(4);
	keys[10].arraySetSize(4);

	times[10][0] = 1.36000;
	keys[10][0] = AL::ALValue::array(0.00290721, AL::ALValue::array(3, -0.453333, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[10][1] = 2.96000;
	keys[10][1] = AL::ALValue::array(0.00290088, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[10][2] = 3.64000;
	keys[10][2] = AL::ALValue::array(0.00290721, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.373333, 0.000000));
	times[10][3] = 4.76000;
	keys[10][3] = AL::ALValue::array(0.00290088, AL::ALValue::array(3, -0.373333, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RShoulderPitch");
	times[11].arraySetSize(6);
	keys[11].arraySetSize(6);

	times[11][0] = 0.640000;
	keys[11][0] = AL::ALValue::array(0.0767419, AL::ALValue::array(3, -0.213333, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[11][1] = 1.36000;
	keys[11][1] = AL::ALValue::array(-0.595150, AL::ALValue::array(3, -0.240000, 0.0975941), AL::ALValue::array(3, 0.533333, -0.216876));
	times[11][2] = 2.96000;
	keys[11][2] = AL::ALValue::array(-0.866668, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[11][3] = 3.64000;
	keys[11][3] = AL::ALValue::array(-0.613558, AL::ALValue::array(3, -0.226667, -0.253109), AL::ALValue::array(3, 0.186667, 0.208443));
	times[11][4] = 4.20000;
	keys[11][4] = AL::ALValue::array(0.584497, AL::ALValue::array(3, -0.186667, -0.249275), AL::ALValue::array(3, 0.186667, 0.249275));
	times[11][5] = 4.76000;
	keys[11][5] = AL::ALValue::array(0.882091, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RShoulderRoll");
	times[12].arraySetSize(6);
	keys[12].arraySetSize(6);

	times[12][0] = 0.640000;
	keys[12][0] = AL::ALValue::array(-0.0199840, AL::ALValue::array(3, -0.213333, -0.000000), AL::ALValue::array(3, 0.240000, 0.000000));
	times[12][1] = 1.36000;
	keys[12][1] = AL::ALValue::array(-0.0199840, AL::ALValue::array(3, -0.240000, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[12][2] = 2.96000;
	keys[12][2] = AL::ALValue::array(-0.615176, AL::ALValue::array(3, -0.533333, 0.190180), AL::ALValue::array(3, 0.226667, -0.0808265));
	times[12][3] = 3.64000;
	keys[12][3] = AL::ALValue::array(-0.833004, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.186667, 0.000000));
	times[12][4] = 4.20000;
	keys[12][4] = AL::ALValue::array(-0.224006, AL::ALValue::array(3, -0.186667, -0.00920487), AL::ALValue::array(3, 0.186667, 0.00920487));
	times[12][5] = 4.76000;
	keys[12][5] = AL::ALValue::array(-0.214801, AL::ALValue::array(3, -0.186667, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	names.push_back("RWristYaw");
	times[13].arraySetSize(4);
	keys[13].arraySetSize(4);

	times[13][0] = 1.36000;
	keys[13][0] = AL::ALValue::array(-0.0583340, AL::ALValue::array(3, -0.453333, -0.000000), AL::ALValue::array(3, 0.533333, 0.000000));
	times[13][1] = 2.96000;
	keys[13][1] = AL::ALValue::array(-0.0521979, AL::ALValue::array(3, -0.533333, -0.000000), AL::ALValue::array(3, 0.226667, 0.000000));
	times[13][2] = 3.64000;
	keys[13][2] = AL::ALValue::array(-0.0675380, AL::ALValue::array(3, -0.226667, -0.000000), AL::ALValue::array(3, 0.373333, 0.000000));
	times[13][3] = 4.76000;
	keys[13][3] = AL::ALValue::array(-0.0383920, AL::ALValue::array(3, -0.373333, -0.000000), AL::ALValue::array(3, 0.000000, 0.000000));

	try
	{
		AL::ALMotionProxy motion(*_robotIp, 9559);
		motion.angleInterpolationBezier(names, times, keys);
	}
	catch(const std::exception&)
	{

	}*/
}