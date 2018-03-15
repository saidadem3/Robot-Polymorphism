#include "saa3053_Extendable_Arm.h"
#include "saa3053_Mobile_Robot.h"
#include "saa3053_Powered_Arm.h"



int main() 
{
		Robot *mrRobot = new Arm_Robot(1337, "yousef", 100, 10, 30);
		int x = 0, y = 0;
		cout << "Let's begin" << endl;
		while (mrRobot->move(x,y)) {
				x += 1;
				y += 1;
		}
		mrRobot->charge();
		x = 2;
		y = 2;
		while (mrRobot->move(x, y)) {
				x += 1;
				y += 1;
		}

		cout << endl << endl;

		Mobile_Robot mrRobot2(1004, "The Mobile_Robot", 100);
		mrRobot2.move(3, 3);
		mrRobot2.move(5, 5, 3);
		mrRobot2.move(3, 1, 2);
		mrRobot2.move(7, 7, 2);

		cout << endl << endl;

		Arm_Robot mrRobot3(1001, "The Arm Robot", 100,10,30);
		mrRobot3.move(3, 3);
		mrRobot3.pick_up(10);
		mrRobot3.move(5, 5);
		mrRobot3.drop();
		mrRobot3.pick_up(50);
		mrRobot3.move(15, 15);

		cout << endl << endl;

		Extendable_Arm mrRobot4(1002, "The Extendable Arm", 100, 10, 30, 15);
		mrRobot4.move(3, 3);
		mrRobot4.pick_up(10);
		mrRobot4.move(5, 5);
		mrRobot4.drop();
		mrRobot4.move(15, 15);
		mrRobot4.pick_up(10);
		mrRobot4.move(16, 16);
		mrRobot4.drop();
		mrRobot4.move(5, 5);
		mrRobot4.pick_up(9);
		mrRobot4.move(15, 15);
		mrRobot4.drop();
		mrRobot4.move(25, 25);


		cout << endl << endl;

		Robot *mrRobot333 = new Extendable_Arm(1002, "The Extendable Arm", 100, 10, 30, 15);
	mrRobot333->move(3, 3);
	mrRobot333->pick_up(10);
	mrRobot333->move(5, 5);
	mrRobot333->drop();
	mrRobot333->move(15, 15);
	mrRobot333->pick_up(10);
	mrRobot333->move(16, 16);
	mrRobot333->drop();
	mrRobot333->move(5, 5);
	mrRobot333->pick_up(9);
	mrRobot333->move(15, 15);
	mrRobot333->drop();
	mrRobot333->move(25, 25);


		Powered_Arm mrRobot5(1003, "The Powered Arm", 100, 10, 30, 55);
		mrRobot5.move(3, 3);
		mrRobot5.pick_up(10);
		mrRobot5.pick_up(5);
		mrRobot5.move(5, 5);
		mrRobot5.drop();
		mrRobot5.move(1, 1);
		mrRobot5.pick_up(45);
		mrRobot5.move(2, 2);
		mrRobot5.drop();
		mrRobot5.move(6, 6);
		mrRobot5.pick_up(60);

		return 0;
}