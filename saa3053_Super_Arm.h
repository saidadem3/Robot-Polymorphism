#include "saa3053_Extendable_Arm.h"
#include "saa3053_Powered_Arm.h"

class Super_Arm : public Extendable_Arm, public Powered_Arm
{
public: Super_Arm(int mn, string n, int bl, int l, int wl, int el, int ml) : Extendable_Arm{ mn,n,bl,l,wl,el}, Powered_Arm{ mn,n,bl,l,wl,ml}
{

}


				bool move(int x, int y);
};