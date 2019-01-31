/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include <iostream>

OI::OI(const int joystickPort) {
  // Process operator interface input here.
  stick_ = new frc::Joystick(joystickPort);



    if(stick_ == nullptr) {
        std::cout << "Failed allocating stick!" << std::endl;
    }
}


OI::~OI(){
  if(stick_ != nullptr) {
    delete stick_;
  }
}

frc::Joystick* OI::GetJoystick() {
  return stick_;
}
