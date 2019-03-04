CXX= g++
CXX_FLAGS = -std=c++11
DEPS = saa3053_Robot.h saa3053_Arm_Robot.h saa3053_Mobile_Arm.h saa3053_Super_Arm.h saa3053_Mobile_Robot.h saa3053_Extendable_Arm.h saa3053_Powered_Arm.h
OBJ = saa3053_Robot.o saa3053_Arm_Robot.o saa3053_Mobile_Arm.o saa3053_Super_Arm.o saa3053_Mobile_Robot.o saa3053_Extendable_Arm.o saa3053_Powered_Arm.o

%.o : %.cpp $(DEPS)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

main: $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $(OBJ) saa3053_main1.cpp
main2: $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $(OBJ) saa3053_main2.cpp
clean:
	rm *.o main main2
