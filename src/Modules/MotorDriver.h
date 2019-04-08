
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MotorDriver {
public:
	MotorDriver() : m_enablePin(0), m_in1Pin(0), m_in2Pin(0) {};

	void Setup(int enable, int in1, int in2);

	void TurnOn(int speed = 255) { SignalEnable(speed); }
	void TurnOff() { SignalEnable(0); }

	void Forward();
	void Backwards();
	void Brakes();

protected:
	void SignalEnable(int speed);

private:
	int m_enablePin;
	int m_in1Pin;
	int m_in2Pin;
};

#endif