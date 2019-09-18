cmake_minimum_required(VERSION 3.14)
project(command_architecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(command_architecture main.cpp Commands/Command.h Commands/Calibration.h Commands/CreditControl.h Commands/Relay.h Validators/Range.h Validators/Contains.h Validators/Length.h Guards/IsSealed.h Guards/IsLocked.h Guards/HasCredit.h Interfaces/Serial.h Interfaces/LoRa.h Guards/Guard.h Interfaces/Interface.h Validators/Validator.h)