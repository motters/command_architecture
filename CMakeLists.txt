cmake_minimum_required(VERSION 3.14)
project(command_architecture)

set(CMAKE_CXX_STANDARD 17)


add_executable(command_architecture main.cpp Commands/Methods/Method.h Commands/Methods/Radio.h Validators/Range.h Validators/Contains.h Validators/Length.h Guards/NotSealed.h Communications/Serial.h Communications/LoRa.h Guards/Guard.h Communications/Communication.h Validators/Validator.h Commands/Contract.h Commands/Directory.h Commands/CommandList.h Tools/GetAny.h Storage.h Guards/GuardsInit.h)

# Disable C++ exceptions.
option(USE_CXX_EXCEPTIONS "Disable C++ exception support" OFF)
target_compile_options(command_architecture PUBLIC -fno-exceptions)
