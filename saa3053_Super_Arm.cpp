#include "saa3053_Super_Arm.h"

bool Super_Arm::move(int x, int y)
{
		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
		int armdistance = ceil(sqrt(pow(x - 0, 2) + pow(y - 0, 2)));
		int battery_change = 0;
		if (motor_on == true)
		{
				if(is_extended == true)
				{
						if (is_holding == true) 
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
								battery_change = (distance * 5);
						}
						else
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
								battery_change = (distance * 4);
						}
				}
				else 
				{	
						if (is_holding == true)
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
								battery_change = (distance * 3);
						}
						else
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
								battery_change = (distance * 2);
						}
				}
		}
		else
		{
				if(is_extended == false)
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
				if (armdistance < length)
				{
						cout << name << "is unable to reach" << endl;
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