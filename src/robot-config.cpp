#include "main.h"

pros::Controller controller (CONTROLLER_MASTER);
pros::ADIDigitalIn limitSwitch ('B');
pros::ADIDigitalOut pneumatics ('A');

// Drivetrain
pros::Motor LeftDriveMotorA (LEFT_DRIVE_A_PORT);
pros::Motor LeftDriveMotorB (LEFT_DRIVE_B_PORT);
pros::Motor_Group LeftDriveMotors ({LeftDriveMotorA, LeftDriveMotorB});
pros::Motor RightDriveMotorA (RIGHT_DRIVE_A_PORT);
pros::Motor RightDriveMotorB (RIGHT_DRIVE_B_PORT);
pros::Motor_Group RightDriveMotors ({RightDriveMotorA, RightDriveMotorB});

// Catapult
pros::Motor CatapultMotorA (CATAPULT_A_PORT);
pros::Motor CatapultMotorB (CATAPULT_B_PORT);
pros::Motor_Group CatapultMotors ({CatapultMotorA, CatapultMotorB});

// Rollers
pros::Motor IntakeMotor (INTAKE_PORT);
pros::Motor RollerMotor (ROLLER_PORT);