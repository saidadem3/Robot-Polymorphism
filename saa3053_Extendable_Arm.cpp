#include "saa3053_Extendable_Arm.h"

bool Extendable_Arm::move(int x, int y)
{
		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
		int armdistance = ceil(sqrt(pow(x - 0, 2) + pow(y - 0, 2)));
		int battery_change = 0;
		if (armdistance > length)
		{
				if (armdistance < (extend_length + length))
				{
						extend();
				}
				else
				{
						cout << name << " is unable to reach" << endl;
						return false;
				}
		}
		else
		{
						retract();
		}
		if (is_holding == true)
		{
				if (is_extended == true)
				{
						battery_change = (distance * 3);
				}
				battery_change = (distance * 2);
		}
		else if (is_extended == true)
		{
				if (is_holding == true)
				{
						int battery_change = battery_level - (distance * 3);
				}
				battery_change = (distance * 2);
		}
		else if ((is_extended == false) && (is_holding == false))
		{
				battery_change = distance;
		}
		if (battery_change < battery_level)
		{
						cout << name << " moved to cord: " << x << ", " << y << endl;
						battery_level -= battery_change;
						position.first = x;
						position.second = y;
						return true;
		}
		else
		{
				cout << name << " does not have enough battery to complete task" << endl;
				return false;
		}
}

bool Extendable_Arm::extend()
{
		if (is_extended == true)
		{
				cout << name << "'s arm is already extended" << endl;
				return false;
		}
		else 
		{
				battery_level--;
				cout << name << " extended it's arm" << endl;
				is_extended = true;
				return true;
		}
}

bool Extendable_Arm::retract()
{
		if (is_extended == true)
		{
				is_extended = false;
				battery_level--;
				cout << name << " retracted it's arm" << endl;
				return true;
		}
		return false;
}
