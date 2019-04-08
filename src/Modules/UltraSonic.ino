
#include "Modules/UltraSonic.h"

void UltraSonicDriver::Setup(int trig, int echo)
{
	m_trigPin = trig;
	m_echoPin = echo;

	pinMode(m_trigPin, OUTPUT);
	pinMode(m_echoPin, INPUT);
}

void UltraSonicDriver::Trig(int delay/* = 10*/)
{
	digitalWrite(m_trigPin, HIGH);
	delayMicroseconds(delay);
	digitalWrite(m_trigPin, LOW);
}

int UltraSonicDriver::Echo(int timeout/* = 1*/)
{
	return pulseIn(m_echoPin, HIGH, timeout);
}

float UltraSonicDriver::Distance(int delay/* = 10*/, int timeout/* = 1*/)
{
	// trigger the wave
	Trig(delay);

	// the time for wave to travel the distance / 2 (back and forth)
	int time = Echo(timeout) / 2;

	// return distance in centimeters
	return 0.034f * time;
}