#include "saa3053_Extendable_Arm.h"
#include "saa3053_Mobile_Robot.h"
#include "saa3053_Powered_Arm.h"
#include "saa3053_Super_Arm.h"
#include "saa3053_Mobile_Arm.h"
#include <vector>



int main() 
{
		

		Mobile_Arm mrRobot373(1005, "The Mobile Arm", 100, 10, 30, 15, 55);
cout << "test" <<  endl;
		mrRobot373.move(3, 3, 5, 5);
		mrRobot373.move(1,3, 19, 15);
		mrRobot373.move(1, 3, 10, 5);

		cout << endl << endl;


		Super_Arm mrRobot10(1005, "The Super Arm", 100, 10, 30, 30, 55);
		mrRobot10.move(3, 3);
		mrRobot10.pick_up(10);
		mrRobot10.move(5, 5);
		mrRobot10.drop();

		cout << endl << endl;

		Super_Arm mrRobot11(1006, "The Super Arm", 100, 10, 30, 30, 55);
		mrRobot11.move(3, 3);
		mrRobot11.pick_up(10);
		mrRobot11.move(15, 15);
		mrRobot11.drop();

		cout << endl << endl;

		Super_Arm mrRobot12(1007, "The Super Arm", 100, 10, 30, 30, 55);
		mrRobot12.move(3, 3);
		mrRobot12.pick_up(40);
		mrRobot12.move(5, 5);
		mrRobot12.drop();

		cout << endl << endl;

		Super_Arm mrRobot13(1008, "The Super Arm", 100, 10, 30, 30, 55);
		mrRobot13.move(3, 3);
		mrRobot13.pick_up(40);
		mrRobot13.move(15, 15);
		mrRobot13.drop();


		cout << endl << endl;

		
		return 0;
}
