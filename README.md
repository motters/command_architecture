# Example Command Architecture

Project demonstrates a simple architecture for sharing commands between
different communication interfaces.

The architecture handles the following:
  * Data abstraction from different interface inputs and formats.
  * One repository of commands shared between multiple communication interfaces. 
  * Validation of data abstracted from communication interfaces.
  * Guarding commands so they are only runnable under certain conditions.
  * Responding to the communication interface with a result in the correct 
    interface format.
  
  
## Example

The example code shows example data received via LoRa and a serial interface.
Both communication interface requests are trying to execute the same command 
with the same parameters.

