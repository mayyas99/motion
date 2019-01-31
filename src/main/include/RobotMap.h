/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/WPILib.h>
// #include <math.h>
// #include <string>
#include <iostream>


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

constexpr int  kFrontRightMotor = 0;
constexpr int  kFrontLeftMotor  = 1;
constexpr int  kRearRightMotor  = 2;
constexpr int  kRearLeftMotor   = 3;

constexpr int kSlotIdx = 0;
constexpr int kPIDLoopIdx = 0;
constexpr int kTimeoutMs = 15;
constexpr double kP =0.6;
constexpr double kI = 0.004;
constexpr double kD = 5.75;
constexpr double kF = 0.1705;
constexpr int kIzone = 50;
constexpr double kPeakOutput = 0.0;
constexpr double pi = 3.14159265358979323846;
constexpr double radiusCm = 15.24;
constexpr double radiusIn = 6;
enum Units { cm , In};



// double Rtargets;
// double targetPos = 12000;
// constexpr double vfrghj = 15.24;
// enum fruit {apple , banana  };
// constexpr int kDoubleSolenoidForward = 7;
// constexpr int kDoubleSolenoidReverse = 6;
