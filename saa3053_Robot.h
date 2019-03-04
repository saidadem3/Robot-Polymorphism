#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;


class Robot
{
public:
		Robot(int mn, string n, int bl) : model_number{ mn }, name{ n }, battery_level{ bl } 
		{
				position.first = 0;
				position.second = 0;
				battery_life = bl;
		};
		virtual bool move(int x, int y)=0;
		void charge();
		double get_battery_percentage();
		string get_name();
		string get_type();

protected:
		int model_number;
		string name;
		int battery_life;
		int battery_level;
		pair<int, int> position;
		string type;
};

#endif