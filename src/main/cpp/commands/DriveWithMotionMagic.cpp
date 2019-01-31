#include "commands/DriveWithMotionMagic.h"
#include "Robot.h"
#include "../../include/subsystems/DriveTrain.h"
#include "../../include/OI.h"


DriveWithMotionMagic::DriveWithMotionMagic(double Target , Units unit)
 {
	 *Robot::m_driveTrain.RTarget = Robot::m_driveTrain.ConvertToEncoderUnits(Target , unit);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::m_driveTrain);
}

//Called just before this Command runs the first time
void DriveWithMotionMagic::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveWithMotionMagic::Execute() {
	Robot::m_driveTrain.feedTalons();
	Robot::m_driveTrain.MotionMagicDrive(Robot::m_driveTrain.mTarget);
	// Robot::m_driveTrain.DRCDrive(0.4, 0.0);

	// Robot::m_driveTrain.SRXOutput();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithMotionMagic::IsFinished() {
	// return Robot::m_driveTrain.isMotionMagicDriveFinished();
	return false;
}

// Called once after isFinished returns true
void DriveWithMotionMagic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithMotionMagic::Interrupted() {
	std::cout << "Interrupteeeeeeeeeeeeeeeed" << std::endl;
	End();
}