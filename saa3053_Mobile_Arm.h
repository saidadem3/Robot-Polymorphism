#include "saa3053_Mobile_Robot.h"
#include "saa3053_Super_Arm.h"

class Mobile_Arm : public Super_Arm, public Mobile_Robot
{
public:
		Mobile_Arm(int mn, string n, int bl, int l, int wl, int el, int ml) : Super_Arm(mn, n, bl, l, wl, el, ml), Mobile_Robot(mn, n, bl), Robot (mn, n, bl), Arm_Robot(mn,n,bl,l,wl), Powered_Arm(mn, n, bl, l, wl, ml), Extendable_Arm(mn, n, bl, l, wl, el)
		{			
				position.first = 0;
				position.second = 0;
				arm_position.first = 0;
				arm_position.second = 0;
				is_holding = false;
				battery_level = bl;
				is_extended = false;
				motor_on = false;
				type = "Mobile_Arm";
		};
		bool move(int x, int y);
		bool move(int x, int y, int speed);
		bool move_arm(int x, int y);
		bool move(int base_x, int base_y, int arm_x, int arm_y);
		bool move(int base_x, int base_y, int arm_x, int arm_y, int speed);

private:
		pair<int, int> arm_position;
};
