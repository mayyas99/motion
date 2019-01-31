#include "subsystems/DriveTrain.h"
// #include <unistd.h>
// #include <frc/Joystick.h>

DriveTrain::DriveTrain():
frc::Subsystem("DriveTrain"),
mFrontLeftController(kFrontLeftMotor),
mRearLeftController(kRearLeftMotor),
mFrontRightController(kFrontRightMotor),
mRearRightController(kRearRightMotor) {


/* Factory default hardware to prevent unexpected behavior */
  mFrontLeftController.ConfigFactoryDefault();
  mRearLeftController.ConfigFactoryDefault();
  mFrontRightController.ConfigFactoryDefault();
  mRearRightController.ConfigFactoryDefault();


/* Configure Sensor Source for Pirmary PID */
  mFrontLeftController.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
  mRearLeftController.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
  mFrontRightController.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);
  mRearRightController.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx, kTimeoutMs);


	/**
	 * Configure Talon SRX Output and Sesnor direction accordingly
	 * Invert Motor to have green LEDs when driving Talon Forward / Requesting Postiive Output
	 * Phase sensor to have positive increment when driving Talon Forward (Green LED)
	 */
	mFrontLeftController.SetInverted(true);
	mRearLeftController.SetInverted(true);
	mFrontRightController.SetInverted(false);
	mRearRightController.SetInverted(false);

	mFrontLeftController.SetSensorPhase(true);
	mRearLeftController.SetSensorPhase(true);
	mFrontRightController.SetSensorPhase(true);
	mRearRightController.SetSensorPhase(true);

/* Set relevant frame periods to be at least as fast as periodic rate */
	mFrontLeftController.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeoutMs); // we didnt understand this 
	mFrontLeftController.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeoutMs);

	mRearLeftController.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeoutMs); 
	mRearLeftController.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeoutMs);

	mFrontRightController.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeoutMs);  
	mFrontRightController.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeoutMs);

	mRearRightController.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, kTimeoutMs);  
	mRearRightController.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, kTimeoutMs);


/* Set the peak and nominal outputs */
	mFrontLeftController.ConfigNominalOutputForward(0, kTimeoutMs);
	mFrontLeftController.ConfigNominalOutputReverse(0, kTimeoutMs);
	mFrontLeftController.ConfigPeakOutputForward(1, kTimeoutMs);
	mFrontLeftController.ConfigPeakOutputReverse(-1, kTimeoutMs);

	mRearLeftController.ConfigNominalOutputForward(0, kTimeoutMs);
	mRearLeftController.ConfigNominalOutputReverse(0, kTimeoutMs);
	mRearLeftController.ConfigPeakOutputForward(1, kTimeoutMs);
	mRearLeftController.ConfigPeakOutputReverse(-1, kTimeoutMs);

	mFrontRightController.ConfigNominalOutputForward(0, kTimeoutMs);
	mFrontRightController.ConfigNominalOutputReverse(0, kTimeoutMs);
	mFrontRightController.ConfigPeakOutputForward(1, kTimeoutMs);
	mFrontRightController.ConfigPeakOutputReverse(-1, kTimeoutMs);

	mRearRightController.ConfigNominalOutputForward(0, kTimeoutMs);
	mRearRightController.ConfigNominalOutputReverse(0, kTimeoutMs);
	mRearRightController.ConfigPeakOutputForward(1, kTimeoutMs);
	mRearRightController.ConfigPeakOutputReverse(-1, kTimeoutMs);


/* Set Motion Magic gains in slot0 - see documentation */
	mFrontLeftController.SelectProfileSlot(kSlotIdx, kPIDLoopIdx);
	mFrontLeftController.Config_kF(kSlotIdx, kF, kTimeoutMs);
	mFrontLeftController.Config_kP(kSlotIdx, kP, kTimeoutMs);
	mFrontLeftController.Config_kI(kSlotIdx, kI, kTimeoutMs);
	mFrontLeftController.Config_kD(kSlotIdx, kD, kTimeoutMs);

	mRearLeftController.SelectProfileSlot(kSlotIdx, kPIDLoopIdx);
	mRearLeftController.Config_kF(kSlotIdx, kF, kTimeoutMs);
	mRearLeftController.Config_kP(kSlotIdx, kP, kTimeoutMs);
	mRearLeftController.Config_kI(kSlotIdx, kI, kTimeoutMs);
	mRearLeftController.Config_kD(kSlotIdx, kD, kTimeoutMs);

	mFrontRightController.SelectProfileSlot(kSlotIdx, kPIDLoopIdx);
	mFrontRightController.Config_kF(kSlotIdx, kF, kTimeoutMs);
	mFrontRightController.Config_kP(kSlotIdx, kP, kTimeoutMs);
	mFrontRightController.Config_kI(kSlotIdx, kI, kTimeoutMs);
	mFrontRightController.Config_kD(kSlotIdx, kD, kTimeoutMs);

	mRearRightController.SelectProfileSlot(kSlotIdx, kPIDLoopIdx);
	mRearRightController.Config_kF(kSlotIdx, kF, kTimeoutMs);
	mRearRightController.Config_kP(kSlotIdx, kP, kTimeoutMs);
	mRearRightController.Config_kI(kSlotIdx, kI, kTimeoutMs);
	mRearRightController.Config_kD(kSlotIdx, kD, kTimeoutMs);


/* Set acceleration and vcruise velocity - see documentation */
	mFrontLeftController.ConfigMotionCruiseVelocity(3500, kTimeoutMs);
	mFrontLeftController.ConfigMotionAcceleration(3500, kTimeoutMs);

	mRearLeftController.ConfigMotionCruiseVelocity(3500, kTimeoutMs);
	mRearLeftController.ConfigMotionAcceleration(3500, kTimeoutMs);

	mFrontRightController.ConfigMotionCruiseVelocity(3500, kTimeoutMs);
	mFrontRightController.ConfigMotionAcceleration(3500, kTimeoutMs);

	mRearRightController.ConfigMotionCruiseVelocity(3500, kTimeoutMs);
	mRearRightController.ConfigMotionAcceleration(3500, kTimeoutMs);


	/* Zero the sensor */
	mFrontLeftController.SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);

	mRearLeftController.SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);

	mFrontRightController.SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);

	mRearRightController.SetSelectedSensorPosition(0, kPIDLoopIdx, kTimeoutMs);


// mFrontLeftController.SetInverted(true);
// mRearLeftController.SetInverted(true);
// mFrontRightController.SetInverted(false);
// mRearRightController.SetInverted(false);

// mFrontLeftController.SetSensorPhase(true);
// mRearLeftController.SetSensorPhase(true);
// mFrontRightController.SetSensorPhase(true);
// mRearRightController.SetSensorPhase(true);

// mFrontLeftController.SetInverted(true);
// mRearLeftController.SetInverted(true);
// mFrontRightController.SetInverted(false);
// mRearRightController.SetInverted(false);

// mFrontLeftController.SetSensorPhase(true);
// mRearLeftController.SetSensorPhase(true);
// mFrontRightController.SetSensorPhase(true);
// mRearRightController.SetSensorPhase(true);
}


void DriveTrain::InitDefaultCommand() {
// Set the default command for a subsystem here.
// SetDefaultCommand(new MySpecialCommand());
//   SetDefaultCommand()
}

DriveTrain::~DriveTrain() {

}

void DriveTrain::DRCDrive(double move,double rotate) {
	// mDrive.ArcadeDrive(move, rotate, true);
	mFrontLeftController.Set(ControlMode::PercentOutput, move);
	mRearLeftController.Set(ControlMode::PercentOutput, move);
	mFrontRightController.Set(ControlMode::PercentOutput, move);
	mRearRightController.Set(ControlMode::PercentOutput, move);
}

void DriveTrain::MotionMagicDrive(double target) {

  mFrontLeftController.Set(ControlMode::MotionMagic, target);
  mRearLeftController.Set(ControlMode::MotionMagic, target);
  mFrontRightController.Set(ControlMode::MotionMagic, target);
  mRearRightController.Set(ControlMode::MotionMagic, target);
	

	// if (++_loops >= 20) {
	// 	_loops = 0;
	// 	std::cout << "ClosedLoopError: " << mFrontLeftController.GetClosedLoopError(kPIDLoopIdx) << std::endl;
	// 	std::cout << "Sensor Position: " << mFrontLeftController.GetSelectedSensorPosition(kPIDLoopIdx) << std::endl;
	// 	std::cout << "ClosedLoopTarget: " << mFrontLeftController.GetClosedLoopTarget(kPIDLoopIdx) << std::endl;
	// }

	// usleep(10);
}

bool DriveTrain::isMotionMagicDriveFinished() {
	return 	abs(mFrontLeftController.GetClosedLoopTarget(kPIDLoopIdx) - mFrontLeftController.GetSelectedSensorPosition(kPIDLoopIdx)) < 15;
}

void DriveTrain::feedTalons() {
	// mFrontLeftController.Feed();
	// mRearLeftController.Feed();
	// mFrontRightController.Feed();
	// mRearRightController.Feed();
	mDrive.Feed();
}

double DriveTrain::CmToEncoderUnit(double cm)
{
	// return cm / (radiusCm * pi) * 4096 * 2;
}

double DriveTrain::InToEncoderUnit(double in)
{
	// return in / (radiusIn * pi) * 4096 * 2;
}

double DriveTrain::ConvertToEncoderUnits(double Target , Units unit)
{
	switch (unit)
	{
		case cm :
			return Target / (radiusCm * pi) * 4096 * 2;
			break;
		case In :
		    return Target / (radiusIn * pi) * 4096 * 2; 
			break;
	}
}

// void DriveTrain::SRXOutput()
// {
//   // mRearLeftController.set(ControlMode.PercentOutput, xSpeed);
//   // mRearRightController.Set(ControlMode.PercentOutput, xSpeed);

//   // mRearLeftController.GetFaults(_faults);
//   // mFrontRightController.GetFaults(_faults);

//   // std::cout << "Sensor Vel:" << mFrontRightController.GetSelectedSensorVelocity() << std::endl;
//   // std::cout << "Sensor Pos:" << mFrontRightController.GetSelectedSensorPosition() << std::endl;
//   // std::cout << "Out %" << mFrontRightController.GetMotorOutputPercent() << std::endl;
//   // // std::cout << "Sensor Vel:" << mRearRightController.GetSelectedSensorVelocity() << std::endl;
//   // // std::cout << "Sensor Pos:" << mRearRightController.GetSelectedSensorPosition() << std::endl;
//   // // std::cout << "Out %" << mRearRightController.GetMotorOutputPercent() << std::endl;
//   // std::cout << "Out Of Phase:" << _faults.SensorOutOfPhase << std::endl;
//   // std::cout << mFrontLeftController.GetSelectedSensorVelocity() << std::endl;
 
//   // int absolutePosition = mRearRightController.GetSelectedSensorPosition(0);
//   // int absolutePositionFFF = mRearRightController.GetSelectedSensorPosition(0) & 0xFFF;

//   // std::cout << "GetSelectedSensorPosition:" << absolutePosition << std::endl;
//   // std::cout << "GetSelectedSensorPosition & 0xFFF:" << absolutePositionFFF << std::endl;
// }
