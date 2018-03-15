#include "saa3053_Mobile_Robot.h"

bool Mobile_Robot::move(int x, int y)
{
		int distance = ceil(sqrt(pow(x - position.first, 2) + pow(y - position.second, 2)));
		int battery_change = 0;
		if (speed_level == 1)
				battery_change = distance;
		else if (speed_level == 2)
				battery_change = (distance * 2);
		else
				battery_change = (distance * 3);

		if (battery_change < battery_level)
		{
				cout << name << " moved to cord: " << x << ", " << y << " at speed level " << speed_level << endl;
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

bool Mobile_Robot::move(int x, int y, int speed)
{
		speed_level = speed;
		int distance = sqrt(pow(x - position.first, 2) + pow(y - position.second, 2));
		int battery_change = 0;
		if (speed_level == 1)
				battery_change = distance;
		else if (speed_level == 2)
				battery_change = (distance * 2);
		else
				battery_change = (distance * 3);

		if (battery_change < battery_level)
		{
				cout << name << " moved to cord: " << x << ", " << y << " at speed level " << speed_level << endl;
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

void Mobile_Robot::set_speed_level(int speed)
{
		speed_level = speed;
		cout << name << " speed set to " << speed << endl;
}
