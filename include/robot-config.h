#pragma once
#include "main.h"

#pragma region Ports
#define LEFT_DRIVE_A_PORT 2
#define LEFT_DRIVE_B_PORT -4
#define RIGHT_DRIVE_A_PORT -20
#define RIGHT_DRIVE_B_PORT 21

#define CATAPULT_A_PORT 1
#define CATAPULT_B_PORT 10

#define INTAKE_PORT 11
#define ROLLER_PORT 6
#pragma endregion

extern pros::Controller controller;
extern pros::ADIDigitalIn limitSwitch;
extern pros::ADIDigitalOut pneumatics;

// Drivetrain
extern pros::Motor LeftDriveMotorA;
extern pros::Motor LeftDriveMotorB;
extern pros::Motor_Group LeftDriveMotors;
extern pros::Motor RightDriveMotorA;
extern pros::Motor RightDriveMotorB;
extern pros::Motor_Group RightDriveMotors;

// Catapult
extern pros::Motor CatapultMotorA;
extern pros::Motor CatapultMotorB;
extern pros::Motor_Group CatapultMotors;

extern pros::Motor IntakeMotor;
extern pros::Motor RollerMotor;