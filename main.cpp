#include <iostream>
#include <vector>
#include <cstdint>

// Communications
#include "Communications/LoRa.h"
#include "Communications/Serial.h"

// Commands
#include "Commands/Directory.h"

// Example lora data in the format it is received
uint8_t loraRaw[] = { 'a', 0x31, 0x00, 100, 200 };

// Example serial data in the format it is received in
std::string seriaData = "REL=1";

// Tasks
void loRaTask();
void serialTask();


/**
 * Main event loop
 */
int main()
{
    // Welcome message
    std::cout << "Command Architecture Demo" << std::endl;

    loRaTask();
    serialTask();

    return 0;
}


/**
 * Demo lora task
 */
void loRaTask()
{
    // Directory for commands
    Commands::Directory directory;

    // Create interface
    Communications::LoRa lora;

    // Convert raw lora data to string
    std::string data((char *)loraRaw, sizeof(loraRaw) + 1);

    // Get command contract
    auto contract = lora.handle(data);

    // Execute command in contract
    directory.call(contract);

    // Demo
    if(contract.status && contract.validLength)
    {
        std::cout << "Sent: " << data << std::endl <<
                     "Command: " << std::any_cast < char >(contract.params[0]) <<
                     " Param 1: " << std::any_cast < uint32_t >(contract.params[1]) << std::endl;
    }
    else
    {
        std::cout << "Invalid data" << std::endl;
    }
}


/**
 * Demo serial task
 */
void serialTask()
{
    /*// Create interface
    Communications::Serial serial;

    // Get command contract
    auto contract = serial.handle(seriaData);

    // Demo
    if(contract.status && contract.validLength)
    {
        std::cout << "Sent: " << seriaData << std::endl <<
                     "Command: " << std::any_cast < std::string >(contract.params[0]) <<
                     " Param 1: " << std::any_cast < int >(contract.params[1]) << std::endl;
    }
    else
    {
        std::cout << "Invalid data" << std::endl;
    }*/
}