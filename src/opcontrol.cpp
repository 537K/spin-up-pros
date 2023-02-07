#include "main.h"

#pragma region Constants

#define CATA_SPEED 127
#define INTAKE_SPEED 127
#define ROLLER_SPEED 127

#pragma endregion Constants

#pragma region Controls

#define CATA_FORWARD DIGITAL_R1
#define CATA_REVERSE DIGITAL_R2
#define INTAKE_FORWARD DIGITAL_L1
#define INTAKE_REVERSE DIGITAL_L2
#define ROLLER_FORWARD DIGITAL_X
#define ROLLER_REVERSE DIGITAL_B
#define EXPANSION_RELEASE DIGITAL_RIGHT

#pragma endregion Controls

bool cataMotorsStopped = true;

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol () {
    int intakePower = 0;
    int rollerPower = 0;
    while (true) {
        #pragma region Drivetrain
        int drivetrainLeftSpeed = controller.get_analog(ANALOG_LEFT_Y) + controller.get_analog(ANALOG_RIGHT_X);
        int drivetrainRightSpeed = controller.get_analog(ANALOG_LEFT_Y) - controller.get_analog(ANALOG_RIGHT_X);

        // check for deadband
        if (drivetrainLeftSpeed < 5 && drivetrainLeftSpeed > -5)
            drivetrainLeftSpeed = 0;
        if (drivetrainRightSpeed < 5 && drivetrainRightSpeed > -5)
            drivetrainRightSpeed = 0;

        LeftDriveMotors.move(drivetrainLeftSpeed);
        RightDriveMotors.move(drivetrainRightSpeed);
        #pragma endregion Drivetrain

        #pragma region Catapult
        if (controller.get_digital(CATA_FORWARD)) {
            CatapultMotors.move(CATA_SPEED);
            cataMotorsStopped = false;
        } else if (controller.get_digital(CATA_REVERSE)) {
            CatapultMotors.move(-(CATA_SPEED));
            cataMotorsStopped = false;
        } else if (!cataMotorsStopped) {
            CatapultMotors.move(0);
            cataMotorsStopped = true;
        }
        #pragma endregion Catpult
        
        #pragma region Rollers
        
        if (controller.get_digital_new_press(INTAKE_FORWARD)) {
            if (intakePower == 0 || intakePower == -INTAKE_SPEED) {
                intakePower = INTAKE_SPEED;
            } else {
                intakePower = 0;
            }
        } else if (controller.get_digital_new_press(INTAKE_REVERSE)) {
            if (intakePower == 0 || intakePower == INTAKE_SPEED) {
                intakePower = -INTAKE_SPEED;
            } else {
                intakePower = 0;
            }
        }
        IntakeMotor.move(intakePower);

        if (controller.get_digital_new_press(ROLLER_FORWARD)) {
            if (rollerPower == 0 || intakePower == -ROLLER_SPEED) {
                rollerPower = ROLLER_SPEED;
            } else {
                rollerPower = 0;
            }
        } else if (controller.get_digital_new_press(ROLLER_REVERSE)) {
            if (rollerPower == 0 || rollerPower == ROLLER_SPEED) {
                rollerPower = -ROLLER_SPEED;
            } else {
                rollerPower = 0;
            }
        }
        RollerMotor.move(rollerPower);

        /*if button is pressed:
            new press:
                motor running?:
                    stop
                else:
                    run
            old press:
                motor running?:
                    run
                else:
                    stop
        */
        

        #pragma endregion Rollers

        if (controller.get_digital(EXPANSION_RELEASE)) { pneumatics.set_value(1); }

        pros::delay(2);
    }
}