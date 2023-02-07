#include "main.h"
using namespace arms;

void closeRoller () {
    // IntakeMotor.move(127);
}

void farRoller () {
    // IntakeMotor.move(127);
}

/**
 * Intended to be run with two discs facing towards low-goal, touching robot as preloads
 */
void tieBreaker() {
    // chassis::move(-24);
    // pros::delay(1000);
    // chassis::move(24);
    IntakeMotor.move(-127);
}

/*Four rollers and expansion*/
void skills() {
    // First two rollers?
    chassis::move(1, {REVERSE, ASYNC});
    RollerMotor.move(127);
    chassis::move(1);
    RollerMotor.move(0); 
    chassis::move(24);
    chassis::turn(90, RELATIVE);
    chassis::move(25, ASYNC);
    RollerMotor.move(127);
    chassis::move(1);
    RollerMotor.move(0);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    if (arms::selector::auton == 1) {
        closeRoller();
    } else if (arms::selector::auton == 2) {
        farRoller();
    } else if (arms::selector::auton == 3) {
        tieBreaker();
    } else if (arms::selector::auton == 0) {
        skills();
    }
}