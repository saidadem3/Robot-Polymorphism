#ifndef SUPER_ARM_H
#define SUPER_ARM_H

#include "saa3053_Extendable_Arm.h"
#include "saa3053_Powered_Arm.h"


class Super_Arm : public virtual Extendable_Arm, public virtual Powered_Arm
{
public: 
		Super_Arm(int mn, string n, int bl, int l, int wl, int el, int ml) : Extendable_Arm { mn, n, bl, l, wl, el }, Powered_Arm{ mn,n,bl,l,wl,ml }, Robot{mn,n,bl}, Arm_Robot{mn,n,bl,l,wl}
		{
				position.first = 0;
				position.second = 0;
				is_holding = false;
				battery_level = bl;
				is_extended = false;
				motor_on = false;
				type = "Super_Arm";
		}
		bool move(int x, int y);
};

#endif
