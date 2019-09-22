#include <iostream>
#include <vector>
#include <cstdint>

// Communications
#include "Communications/LoRa.h"
#include "Communications/Serial.h"

// Guards init
#include "Guards/GuardsInit.h"

// Settings
#include "Storage.h"

// Commands
#include "Commands/Directory.h"

// Example lora data in the format it is received
uint8_t loraRaw[] = { 'a', 0x31, 0x00, 100, 200, 5 };

// Example serial data in the format it is received in
std::string seriaData = "FREQ=822109384,5";

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
    std::cout << "=========================" << std::endl<< std::endl;

    // Setup the setting class
    Storage storage;

    // Setup guard classes so they have access to the settings class
    Guards::GuardsInit::init(storage);

    loRaTask();
    std::cout <<std::endl<<std::endl;
    serialTask();

    return 0;
}


/**
 * Demo lora task
 */
void loRaTask()
{

    // Create interface
    Communications::LoRa lora;

    // Convert raw lora data to string
    std::string data((char *)loraRaw, sizeof(loraRaw) + 1);

    // Get command contract
    auto contract = lora.handle(data);

    // Demo
    if(contract.validExecution())
    {
        std::cout << "LORA = ";
        std::cout << "Received: ";
        for(int i = 0; i <  data.size(); i++)
        {
            std::cout << unsigned((uint8_t)data.at(i)) << " ";
        }

        std::cout << "Sent: ";
        for(int i = 0; i < contract.communicationsOutput.size(); i++)
        {
            std::cout << unsigned((uint8_t)contract.communicationsOutput.at(i)) << " ";
        }
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
    Communications::Serial serial;

    // Get command contract
    auto contract = serial.handle(seriaData);

    // Demo
    if(contract.validExecution())
    {

        std::cout << "SERIAL = " << "Received: " << seriaData << " Sent: " << contract.communicationsOutput << std::endl;
    }
    else
    {
        std::cout << "Invalid data" << std::endl;
    }
}