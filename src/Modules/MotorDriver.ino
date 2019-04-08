
#include "Modules/MotorDriver.h"

void MotorDriver::Setup(int enable, int in1, int in2)
{
	m_enablePin = enable;
	m_in1Pin = in1;
	m_in2Pin = in2;

	pinMode(m_enablePin, OUTPUT);
	pinMode(m_in1Pin, OUTPUT);
	pinMode(m_in2Pin, OUTPUT);
}

void MotorDriver::Forward()
{
	digitalWrite(m_in1Pin, LOW);
	digitalWrite(m_in2Pin, HIGH);
}

void MotorDriver::Backwards()
{
	digitalWrite(m_in1Pin, HIGH);
	digitalWrite(m_in2Pin, LOW);
}

void MotorDriver::Brakes()
{
	digitalWrite(m_in1Pin, LOW);
	digitalWrite(m_in2Pin, LOW);
}

void MotorDriver::SignalEnable(int speed)
{
	//Brakes();
	analogWrite(m_enablePin, speed);
}