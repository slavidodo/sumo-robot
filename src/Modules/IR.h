
#ifndef IR_DRIVER_H
#define IR_DRIVER_H

class IRDriver
{
public:
	IRDriver() : m_analogPin(0) {}

	void Setup(int analogPin) {
		m_analogPin = analogPin;

		pinMode(m_analogPin, INPUT);
	}

	int Value() {
		return analogRead(m_analogPin);
	}

private:
	int m_analogPin;
	int m_senstivity;
};

#endif