#include "saa3053_Extendable_Arm.h"
#include "saa3053_Powered_Arm.h"

class Super_Arm : public Arm_Robot, public Extendable_Arm, public Powered_Arm
{
public: Super_Arm(int mn, string n, int bl, int l, int wl, int el, int ml) : Arm_Robot{ mn,n,bl,l,wl }, Extendable_Arm{ el }, Powered_Arm{ml}
{

}
				bool move(int x, int y);
};