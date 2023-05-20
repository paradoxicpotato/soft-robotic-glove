#include "ADS1X15.h"
#include <AFMotor.h>
#include <PID_v1.h>

// Set motor terminals
AF_DCMotor motor1(2); // Pressurise
AF_DCMotor motor2(1); // Vacuum

//ADS Addressing
ADS1115 ADS(0x48); // ADS1
ADS1115 ADS2(0x49); // ADS2
 
// Solenoid valve port assignment
int SolValve1 = 30;
int SolValve2 = 31;
int SolValve3 = 32;
int SolValve4 = 33;
int SolValve5 = 34;
int SolValve6 = 35;
int SolValve7 = 36;
int SolValve8 = 37;

// PID variable declarations

double Pressure0;
double Pressure1;
double Pressure2;
double Pressure3;
double Pressure4;

double PWM0;
double PWM1;
double PWM2;
double PWM3;
double PWM4;

double Kp = 10;
double Ki = 0.001;
double Kd = 0;

double Setpoint0 = 80;
double Setpoint1 = 80;
double Setpoint2 = 80;
double Setpoint3 = 80;
double Setpoint4 = 80;

// PID Loop declarations
PID pid0(&Pressure0, &PWM0, &Setpoint0, Kp, Ki, Kd, DIRECT);
PID pid1(&Pressure1, &PWM1, &Setpoint1, Kp, Ki, Kd, DIRECT);
PID pid2(&Pressure2, &PWM2, &Setpoint2, Kp, Ki, Kd, DIRECT);
PID pid3(&Pressure3, &PWM3, &Setpoint3, Kp, Ki, Kd, DIRECT);
PID pid4(&Pressure4, &PWM4, &Setpoint4, Kp, Ki, Kd, DIRECT);

int mode = 2;
int press_state = 1; // 1 Pressurise 0 Depressurise
unsigned long previousMillis = 0;

void setup() 
{
  Serial.begin(115200);

  // Start ADS
  ADS.begin();
  ADS2.begin();

  //Set initial speed of the motor & stop
	motor1.setSpeed(255);
	motor1.run(RELEASE);
	//motor2.setSpeed(255);
	//motor2.run(RELEASE);

  // Set solenoid pin modes
  pinMode(SolValve1, OUTPUT);
  pinMode(SolValve2, OUTPUT);
  pinMode(SolValve3, OUTPUT);
  pinMode(SolValve4, OUTPUT);
  pinMode(SolValve5, OUTPUT);
  pinMode(SolValve6, OUTPUT);
  pinMode(SolValve7, OUTPUT);
  pinMode(SolValve8, OUTPUT);

  //Turn PID on
  pid0.SetMode(AUTOMATIC);
  pid1.SetMode(AUTOMATIC);
  pid2.SetMode(AUTOMATIC);
  pid3.SetMode(AUTOMATIC);
  pid4.SetMode(AUTOMATIC);

  // Set Limits
  pid0.SetOutputLimits(200, 255);
  pid1.SetOutputLimits(200, 255);
  pid2.SetOutputLimits(200, 255);
  pid3.SetOutputLimits(200, 255);
  pid4.SetOutputLimits(200, 255);
}
 
void loop() {
    
  // Compute PID values
  pid0.Compute();
  pid1.Compute();
  pid2.Compute();
  pid3.Compute();
  pid4.Compute();

  //mode_select();
  read_pressure();
  motor_control();

}
