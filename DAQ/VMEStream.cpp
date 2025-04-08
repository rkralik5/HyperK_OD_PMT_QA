/**
 * @file VMEStream.cpp
 * @brief Streams data from a VME module using CAENVMELib.
 *
 * This program initializes the VME interface, reads data from a specified
 * VME module, and streams the data to the console.
 * This is a DEMO program and should be modified for actual use.
 */

#include <iostream>
#include <CAENVMEtypes.h>
#include <CAENVMElib.h>

int main() {
    CVBoardTypes VMEBoard = cvV1718; 
    short Link = 0;                  // Link number
    short Device = 0;                // Device number
    int32_t Handle;                  // Handle for the VME interface
    CVErrorCodes ret;                // Error code

    // Initialize the VME interface
    ret = CAENVME_Init(VMEBoard, Link, Device, &Handle);
    if (ret != cvSuccess) {
        std::cerr << "Error initializing VME interface: " << CAENVME_DecodeError(ret) << std::endl;
        return 1;
    }

    std::cout << "VME interface initialized successfully." << std::endl;

    // Address of the VME module to read from (example address)
    uint32_t address = 0x00010000;
    // Buffer to store the data read from the VME module
    uint32_t data;
    // Number of bytes to read (example: 4 bytes for a 32-bit word)
    CVDataWidth dataWidth = cvD32;

    while (true) {
        // Read data from the VME module
        ret = CAENVME_ReadCycle(Handle, address, &data, cvA32_U_DATA, dataWidth);
        if (ret != cvSuccess) {
            std::cerr << "Error reading data from VME module: " << CAENVME_DecodeError(ret) << std::endl;
            break;
        }

        // Stream the data to the console
        std::cout << "Data read from VME module: 0x" << std::hex << data << std::dec << std::endl;

        // Optional: sleep or wait for a specific time before the next read
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Close the VME interface
    ret = CAENVME_End(Handle);
    if (ret != cvSuccess) {
        std::cerr << "Error closing VME interface: " << CAENVME_DecodeError(ret) << std::endl;
        return 1;
    }

    std::cout << "VME interface closed successfully." << std::endl;

    return 0;
}
