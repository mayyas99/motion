#pragma once
#include "RobotMap.h"
#include <frc/commands/Command.h>
#include <string>


class DriveWithMotionMagic : public frc::Command {
public:
	DriveWithMotionMagic(double TargetI , Units unit);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	
	bool start_mp = true;
};