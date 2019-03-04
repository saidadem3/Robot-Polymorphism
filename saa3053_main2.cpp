#include "saa3053_Extendable_Arm.h"
#include "saa3053_Mobile_Robot.h"
#include "saa3053_Powered_Arm.h"
#include "saa3053_Super_Arm.h"
#include "saa3053_Mobile_Arm.h"
#include <vector>



int main() 
{

		vector<Robot*> mrRobot59;
		mrRobot59.push_back(new Arm_Robot(1001, "The Arm Robot", 100, 10, 30));
		mrRobot59.push_back(new Mobile_Robot(1004, "The Mobile Robot", 100));
		mrRobot59.push_back(new Extendable_Arm(1002, "The Extendable Arm", 100, 10, 30, 15));
		mrRobot59.push_back(new Powered_Arm(1003, "The Powered Arm", 100, 10, 30, 55));
		mrRobot59.push_back(new Super_Arm(1005, "The Super Arm", 100, 10, 30, 30, 55));
		mrRobot59.push_back(new Mobile_Arm(1006, "The Mobile Arm", 100, 10, 30, 15, 55));

		
		for (Robot* cool : mrRobot59)
		{
				if (cool->get_type() == "Arm_Robot")
				{
						Arm_Robot *army = dynamic_cast<Arm_Robot*>(cool);
						army->move(1, 2);
						army->pick_up(20);
						army->move(2, 2);
						army->drop();
						army->move(15, 15);
						army->pick_up(40);
				}

				else if (cool->get_type() == "Extendable_Arm")
				{
						Extendable_Arm *ext = dynamic_cast<Extendable_Arm*>(cool);
						ext->move(1, 2);
						ext->pick_up(20);
						ext->move(2, 2);
						ext->drop();
						ext->move(30, 30);
						ext->pick_up(40);
						ext->move(9, 9);
						ext->pick_up(40);
				}

				else if (cool->get_type() == "Powered_Arm")
				{
						Powered_Arm *powa = dynamic_cast<Powered_Arm*>(cool);
						powa->move(1, 2);
						powa->pick_up(20);
						powa->move(2, 2);
						powa->drop();
						powa->move(30, 30);
						powa->move(5, 5);
						powa->pick_up(40);
						powa->move(3, 3);
						powa->drop();
				}

				else if (cool->get_type() == "Mobile_Robot")
				{
						Mobile_Robot *mob = dynamic_cast<Mobile_Robot*>(cool);
						mob->move(1, 2, 3);
				}

				else if (cool->get_type() == "Super_Arm")
				{
						Super_Arm *supa = dynamic_cast<Super_Arm*>(cool);
						supa->move(1, 2);
						supa->pick_up(20);
						supa->move(2, 2);
						supa->drop();
						supa->move(15, 15);
						supa->charge();
						supa->move(5, 5);
						supa->pick_up(40);
						supa->move(3, 3);
						supa->drop();
				}

				else if (cool->get_type() == "Mobile_Arm")
				{
						Mobile_Arm *moby = dynamic_cast<Mobile_Arm*>(cool);
						moby->move(1, 2, 3, 4);
						moby->pick_up(10);
						moby->move(3, 2, 1, 1);
						moby->drop();
				}
				else
						cool->move(2, 2);
		}
		return 0;
}
