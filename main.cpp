#include <iostream>
#include <vector>

// Interfaces
#include "Interfaces/LoRa.h"
#include "Interfaces/Serial.h"

// Example lora data in the format it is received
uint8_t loraRaw[] = { 'a', 0, 0x00, 5, 10 };

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
    //serialTask();

    return 0;
}


/**
 * Demo lora task
 */
void loRaTask()
{
    // Create interface
    Interfaces::LoRa lora;

    // Convert data to string
    std::string data((char *)loraRaw, sizeof(loraRaw) + 1);

    // Get command contract
    auto contract = lora.handle(data);

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
    // Create interface
    Interfaces::Serial serial;

    // Get command contract
    auto state = serial.handle(seriaData);
}