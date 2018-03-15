#ifndef ARM_ROBOT_H
#define ARM_ROBOT_H
#include "saa3053_Robot.h"
class Arm_Robot : public Robot
{
public:
		Arm_Robot(int mn, string n, int bl, int l, int wl) : Robot{mn,n,bl}, length{ l }, weight_limit{ wl } 
		{
				position.first = 0;
				position.second = 0;
				battery_level = bl;
				is_holding = false;
		};
		bool move(int x, int y);
		bool pick_up(int weight);
		bool drop();

protected:
		int length;
		int weight_limit;
		bool is_holding;

};

#endif