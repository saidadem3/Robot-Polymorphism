#include "saa3053_Powered_Arm.h"

bool Powered_Arm::move(int x, int y)
{
		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
		int armdistance = ceil(sqrt(pow(x - 0, 2) + pow(y - 0, 2)));
		int battery_change = 0;
		if (motor_on == true)
		{
				if (is_holding == true)
				{
						battery_change = (distance * 4);
				}
				else
				{
						battery_change = (distance * 3);
				}
		}
		else
		{
				if (is_holding == true)
				{
						battery_change = (distance * 2);
				}
				else
				battery_change = distance;
		}
		if (battery_change < battery_level)
		{
				if (armdistance > length)
				{
						cout << name <<  "is unable to reach" << endl;
						return false;
				}
				else
				{
						cout << name << " moved to cord: " << x << ", " << y << endl;
						battery_level -= battery_change;
						position.first = x;
						position.second = y;
						return true;
				}
		}
		else
		{
				cout << name << " does not have enough battery to complete task" << endl;
				return false;
		}
}

bool Powered_Arm::pick_up(int weight)
{
		if (is_holding == true)
		{
				cout << "The " << name << " is already holding something" << endl;
				return false;
		}
		else
		{
				if (battery_level != 0)
				{
						if (weight > (weight_limit))
						{
								power_on();
								if (weight > motor_limit)
								{
										cout << name << " could not pick up the item because it was too heavy" << endl;
										return false;
								}
								else
								{
										cout << name << " picked the item up" << endl;
										battery_level--;
										is_holding = true;
										return true;
								}
						}
						else
						{
								cout << name << " picked the item up" << endl;
								battery_level--;
								is_holding = true;
								return true;
						}
				}
				else
				{
						cout << name << " does not have enough battery to complete task" << endl;
						return false;
				}
		}		
}

bool Powered_Arm::drop()
{
		if (battery_level != 0)
		{
				if (is_holding == true)
				{
						if (motor_on == true)
						{
								battery_level--;
								cout << name << " dropped the item" << endl;
								power_off();
								is_holding = false;
								return true;
						}
						
						else
						{
								is_holding = false;
								battery_level--;
								cout << name << " dropped the item" << endl;
								return true;
						}
				}
				else
				{
						cout << name << " currently has nothing in hand" << endl;
						return false;
				}
		}
		else
		{
				cout << name << " does not have enough battery to complete task" << endl;
				return false;
		}
}

void Powered_Arm::power_on()
{
		motor_on = true;
		cout << name << "'s motor is now on" << endl;
}

void Powered_Arm::power_off()
{
		motor_on = false;
		cout << name << "'s motor is now off" << endl;
}
