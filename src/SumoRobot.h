
#ifndef SUMO_ROBOT_H
#define SUMO_ROBOT_H

#include "Modules/MotorDriver.h"
#include "Modules/UltraSonic.h"
#include "Modules/IR.h"

class SumoRobot {
public:

	MotorDriver& GetRMotor() { return m_rMotor; }
	MotorDriver& GetLMotor() { return m_lMotor; }

	UltraSonicDriver& GetUltraSonic() { return m_ultraSonic; }

	IRDriver& GetFrontIR() { return m_frontIR; }
	IRDriver& GetBackIR() { return m_backIR; }

private:
	UltraSonicDriver m_ultraSonic;

	IRDriver m_frontIR;
	IRDriver m_backIR;

	MotorDriver m_rMotor;
	MotorDriver m_lMotor;
};

#endif