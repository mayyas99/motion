#include "commands/DriveWithJoystick.h"
#include "Robot.h"
#include "../../include/subsystems/DriveTrain.h"
#include "../../include/OI.h"

DriveWithJoystick::DriveWithJoystick() {
	
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::m_driveTrain);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
//	SubsystemObjects::m_driveTrain.RobotDriveCartesian(SubsystemObjects::m_OI.GetJoystick());

	Robot::m_driveTrain.DRCDrive(-1 * Robot::m_oi.GetJoystick()->GetY(), Robot::m_oi.GetJoystick()->GetX());

	// if (Robot::m_oi.GetJoystick()->GetRawButton(1)) {
  //     Robot::m_driveTrain.mSolenoid.Set(frc::DoubleSolenoid::kForward);
  //   } else if (Robot::m_oi.GetJoystick()->GetRawButton(2)) {
  //     Robot::m_driveTrain.mSolenoid.Set(frc::DoubleSolenoid::kReverse);
  //   } else if (Robot::m_oi.GetJoystick()->GetRawButton(3)){
  //     Robot::m_driveTrain.mSolenoid.Set(frc::DoubleSolenoid::kOff);
  //   }
	// Robot::m_driveTrain.SRXOutput();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
	End();
}