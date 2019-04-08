// author: slavi

#include "SumoRobot.h"
SumoRobot g_sumoRobot;

// motor pins
constexpr int pinMotorEnA = 5;
constexpr int pinMotorEnB = 6;

constexpr int pinMotorIn1 = 7;
constexpr int pinMotorIn2 = 8;
constexpr int pinMotorIn3 = 12;
constexpr int pinMotorIn4 = 13;

constexpr int pinUltraSonicTrig = 2;
constexpr int pinUltraSonicEcho = 3;

constexpr int pinIRFrontAnalog = A0;
constexpr int pinIRBackAnalog = A1;

// ultrasonic pins
// the setup function runs once when you press reset or power the board
void setup()
{
	auto& rMotor = g_sumoRobot.GetRMotor();
	auto& lMotor = g_sumoRobot.GetLMotor();

	auto& irFront = g_sumoRobot.GetFrontIR();
	auto& irBack = g_sumoRobot.GetBackIR();

	auto& ultraSonic = g_sumoRobot.GetUltraSonic();

	// setup pins
	rMotor.Setup(pinMotorEnB, pinMotorIn3, pinMotorIn4);
	lMotor.Setup(pinMotorEnA, pinMotorIn1, pinMotorIn2);

	//ultraSonic.Setup(pinUltraSonicTrig, pinUltraSonicEcho);

	irFront.Setup(pinIRFrontAnalog);
	irBack.Setup(pinIRBackAnalog);

	Serial.begin(9600); // 9600 bit/s

	pinMode(pinUltraSonicTrig, OUTPUT);
	pinMode(pinUltraSonicEcho, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	auto& rMotor = g_sumoRobot.GetRMotor();
	auto& lMotor = g_sumoRobot.GetLMotor();

	auto& irFront = g_sumoRobot.GetFrontIR();
	auto& irBack = g_sumoRobot.GetBackIR();

	auto& ultraSonic = g_sumoRobot.GetUltraSonic();

	///Serial.println(ultraSonic.Distance(10, 100));

	digitalWrite(pinUltraSonicTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinUltraSonicTrig, LOW);

	int time = pulseIn(pinUltraSonicEcho, HIGH);
	//Serial.println(time);

	Serial.println(irFront.DigitalValue());

	delay(1000);
}