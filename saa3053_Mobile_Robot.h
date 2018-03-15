#ifndef MOBILE_ROBOT_H
#define MOBILE_ROBOT_H


#include "saa3053_Arm_Robot.h"

class Mobile_Robot : public Robot
{
public:
		Mobile_Robot(int mn, string n, int bl) : Robot{ mn, n, bl } 
		{
				position.first = 0;
				position.second = 0;
				battery_level = bl;
				set_speed_level(1);
		};
		bool move(int x, int y);
		bool move(int x, int y, int speed);
		
protected:
		int speed_level;
		void set_speed_level(int speed);
};

#endif // !MOBILE_ROBOT_H
