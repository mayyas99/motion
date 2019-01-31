/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/WPILib.h>
#include <frc/Joystick.h>

class OI {
	
private:
	frc::Joystick *stick_;

public:
	OI(const int joystickPort);
	~OI();

	frc::Joystick* GetJoystick();

	frc::JoystickButton *button1 = new frc::JoystickButton{stick_, 1};
	frc::JoystickButton *button2 = new frc::JoystickButton{stick_, 2};
	// frc::JoystickButton *button2 = new frc::JoystickButton{stick_, 2};
};
