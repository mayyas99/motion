#pragma once

#include <frc/commands/Subsystem.h>
#include "RobotMap.h"
#include <iostream>
#include <frc/WPILib.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Victor.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/DoubleSolenoid.h>
#include <frc/MotorSafety.h>

class DriveTrain : public frc::Subsystem {
private:
	// frc::Victor mFrontLeftController;
	// frc::Victor mRearLeftController;
	// frc::Victor mFrontRightController;
	// frc::Victor mRearRightController;

	WPI_TalonSRX mFrontLeftController;
	WPI_TalonSRX mRearLeftController;
	WPI_TalonSRX mFrontRightController;
	WPI_TalonSRX mRearRightController;

	// TalonSRX mFrontLeftController;
	// TalonSRX mRearLeftController;
	// TalonSRX mFrontRightController;
	// TalonSRX mRearRightController;

 	frc::SpeedControllerGroup mLeftSide{mFrontLeftController, mRearLeftController};
 	frc::SpeedControllerGroup mRightSide{mFrontRightController, mRearRightController};

 	frc::DifferentialDrive mDrive{mLeftSide, mRightSide};

	Faults _faults;
	int _loops = 0;
	

public:
 	DriveTrain();
	~DriveTrain();

    void InitDefaultCommand() override;
	// void DRCDrive(double ySpeed,double xSpeed);
	void DRCDrive(double move,double rotate);
	void MotionMagicDrive(double target1);
	bool isMotionMagicDriveFinished();
	void feedTalons();
	double CmToEncoderUnit(double cm);
	double InToEncoderUnit(double in);
	double ConvertToEncoderUnits(double target , Units unit);
	double mTarget;
	double *RTarget = &mTarget;


// Fruit FRC = cm;
	// frc::DoubleSolenoid mSolenoid{6, 7};
	// void SRXOutput();
};