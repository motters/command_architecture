#include <iostream>
#include <vector>

// Interfaces
#include "Interfaces/LoRa.h"
#include "Interfaces/Serial.h"

// Example lora data in the format it is received
std::vector<uint8_t> loRaData = { 'b', 0, 0x00, 0x00, 0x10 };

// Example serial data in the format it is received in
std::vector<char> seriaData = {'R', 'E', 'L', '=', '1'};

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

    // Event loop
    while(true)
    {
        loRaTask();
        serialTask();
    }

    return 0;
}


/**
 * Demo lora task
 */
void loRaTask()
{
    Interfaces::LoRa lora;

    bool state = lora.handle(loRaData);
}


/**
 * Demo serial task
 */
void serialTask()
{
    Interfaces::Serial serial;

    bool state = serial.handle(seriaData);
}