#ifndef POWERED_ARM_H
#define POWERED_ARM_H

#include "saa3053_Arm_Robot.h"

class Powered_Arm : public virtual Arm_Robot
{
public:
		Powered_Arm(int mn, string n, int bl, int l, int wl, int ml) :Arm_Robot{ mn,n,bl,l,wl }, motor_limit{ ml }, Robot{mn,n,bl}
		{
				position.first = 0;
				position.second = 0;
				battery_level = bl;
				is_holding = false;
				motor_on = false;
				type = "Powered_Arm";
		};
		bool move(int x, int y);
		bool pick_up(int weight);
		bool drop();

protected:
		int motor_limit;
		bool motor_on;
		void power_on();
		void power_off();
};

#endif