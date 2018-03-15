#ifndef EXTENDABLE_ARM_H
#define EXTENDABLE_ARM_H

#include "saa3053_Arm_Robot.h"

class Extendable_Arm : public Arm_Robot 
{
public:
		Extendable_Arm(int mn, string n, int bl, int l, int wl, int el) : Arm_Robot{ mn,n,bl,l,wl }, extend_length{ el }
		{
				position.first = 0;
				position.second = 0;
				battery_level = bl;
				is_holding = false;
				is_extended = false;
		};
		bool move(int x, int y);
protected:
		int extend_length;
		bool is_extended;
		bool extend();
		bool retract();

};

#endif