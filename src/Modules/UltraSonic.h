
#ifndef ULTRASONIC_DRIVER_H
#define ULTRASONIC_DRIVER_H

class UltraSonicDriver {
public:
	UltraSonicDriver() : m_trigPin(0), m_echoPin(0) {};

	void Setup(int trig, int echo);

	void Trig(int delay = 10 /* in microseconds */);
	int Echo(int timeout = 1 /* in microseconds*/);

	float Distance(int delay = 10, int timetout = 1);

private:
	int m_trigPin;
	int m_echoPin;
};

#endif