#include "saa3053_Mobile_Arm.h"

bool Mobile_Arm::move(int x, int y)
{
		return Mobile_Robot::move(x, y);
}

bool Mobile_Arm::move(int x, int y, int speed)
{
		return Mobile_Robot::move(x, y, speed);
}

bool Mobile_Arm::move_arm(int x, int y)
{
		return Super_Arm::move(x,y); 
}

bool Mobile_Arm::move(int base_x, int base_y, int arm_x, int arm_y)
{
		
int base_distance = sqrt(pow(base_x - position.first, 2) + pow(base_y - position.second, 2));
		int battery_change = 0;
		if (speed_level == 1)
				battery_change = base_distance;
		else if (speed_level == 2)
				battery_change = (base_distance * 2);
		else
				battery_change = (base_distance * 3);

		if (battery_change < battery_level)
		{
				cout << name << "'s base location moved to cord: " << base_x << ", " << base_y << " at speed level " << speed_level <<" and ";
				battery_level -= battery_change;
				position.first = base_x;
				position.second = base_y;
				//return true;
		}
		else
		{
				cout << name << " does not have enough battery to complete task" << endl;
				return false;
		}

		int distance = ceil(sqrt(pow(arm_x - arm_position.first, 2) + pow(arm_y - arm_position.second, 2)));
		int armdistance = ceil(sqrt(pow(arm_x - 0, 2) + pow(arm_y - 0, 2)));
		if (motor_on == true)
		{
				if (is_extended == true)
				{
						if (is_holding == true)
						{
								battery_change = (distance * 5);
						}
						else
						{
								battery_change = (distance * 4);
						}
				}
				else
				{
						if (is_holding == true)
						{
								battery_change = (distance * 3);
						}
						else
						{
								battery_change = (distance * 2);
						}
				}
		}
		else
		{
				if (is_extended == false)
				{
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
								cout << name << "'s arm moved to cord: " << arm_x << ", " << arm_y << endl;
								battery_level -= battery_change;
								position.first = arm_x;
								position.second = arm_y;
								return true;
						}
						else
						{
								cout << name << " does not have enough battery to complete task" << endl;
								return false;
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
		}
		if (battery_change < battery_level)
		{
				if (armdistance > length)
				{
						cout << name << "is unable to reach" << endl;
						return false;
				}
				else
				{
						cout << name << " moved to cord: " << arm_x << ", " << arm_y << endl;
						battery_level -= battery_change;
						position.first = arm_x;
						position.second = arm_y;
						return true;
				}
		}
		else
		{
				cout << name << " does not have enough battery to complete task" << endl;
				return false;
		}
}

bool Mobile_Arm::move(int base_x, int base_y, int arm_x, int arm_y, int speed)
{
		return false;
}
