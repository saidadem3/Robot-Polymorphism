#include "saa3053_Arm_Robot.h"

bool Arm_Robot::move(int x, int y)
{
		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
		int armdistance = ceil(sqrt(pow(x - 0, 2) + pow(y - 0, 2)));
		int battery_change = 0;
		if (is_holding == true)
		{
				battery_change =  (distance*2);
		}
		else
		{
				battery_change =  distance;
		}
		if (battery_change < battery_level)
		{
				if (armdistance > length)
				{
						cout << name << " could not reach that far" << endl;
						return false;
				}
				else
				{
						cout << name <<" moved to cord: " << x << ", " << y << endl;
						battery_level -= battery_change;
						position.first = x;
						position.second = y;
						return true;
				}
		}
		else
		{
				cout << name <<" does not have enough battery to complete task" << endl;
				return false;
		}
}

bool Arm_Robot::pick_up(int weight)
{
		if (is_holding == true)
		{
				cout << name << " is already holding something" << endl;
				return false;
		}
		else
		{
				if (battery_level != 0)
				{
						if (weight > weight_limit)
						{
								cout << name << " could not pick up the item because it was too heavy" << endl;
								return false; 
						}
						else
						{
								cout << name << " picked up the item" << endl;
								battery_level--;
								is_holding = true;
								return true;
						}
				}
				else
				{
						cout << name << " does not have enough battery to complete the task" << endl;
						return false;
				}
		}
}

bool Arm_Robot::drop()
{
		if (battery_level != 0) 
				{

				if (is_holding == true)
				{
						is_holding = false;
						battery_level--;
						cout << name << " dropped the item" << endl;
						return true;
				}
				else
				{
						cout << name << " currently has nothing in hand" << endl;
						return false;
				}
		}
		else
		{
				cout << name << " does not have enough battery to complete the task" << endl;
				return false;
		}
}
