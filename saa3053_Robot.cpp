#include "saa3053_Robot.h"

string Robot::get_name()
{
		return name;
}
//bool Robot::move(int x, int y)
//{
//		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
//		if (distance < battery_level)
//		{
//				cout << "I, " << name << ", am moving to cord: " << x << ", " << y << endl;
//				battery_level -= distance;
//				position.first = x;
//				position.second = y;
//				return true;
//		}
//		else 
//		{
//				cout << name << " does not have enough battery to complete the task" << endl;
//				return false;
//		}
//}
void Robot::charge() 
{
		battery_level = battery_life;
		cout << name << " is fully charged" << endl;
		position.first = 0;
		position.second = 0;
}
double Robot::get_battery_percentage()
{
		double percentage = battery_level / double(battery_life) * 100;
		cout << name << " has " << percentage << "%  battery remaining" << endl;
		return percentage;
}

string Robot::get_type() 
{
		return type;
}


