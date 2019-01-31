#pragma once

#include <frc/commands/Command.h>

class DriveWithJoystick : public frc::Command {
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	bool start_mp = true;
};