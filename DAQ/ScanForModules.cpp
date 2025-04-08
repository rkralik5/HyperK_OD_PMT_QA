/**
 * @file ScanForModules.cpp
 * @brief Scans for VME modules in a VME crate using CAENVMELib.
 *
 * This program initializes the VME interface, scans for modules by reading
 * from each possible base address, and prints the addresses of found modules.
 */

#include <CAENVMELib.h>
#include <stdio.h>

int main() {
    CVBoardHandle handle;
    int32_t ret;
    uint32_t data;
    uint32_t baseAddress;

    // Initialize the VME crate
    ret = CAENVME_Init(cvV2718, 0, 0, &handle);
    if (ret != cvSuccess) {
        printf("Failed to initialize VME interface\n");
        return -1;
    }

    // Scan for modules
    for (baseAddress = 0x00000000; baseAddress <= 0xFFFF0000; baseAddress += 0x10000) {
        ret = CAENVME_ReadCycle(handle, baseAddress, &data, cvA32_U_DATA, cvD32);
        if (ret == cvSuccess) {
            printf("Module found at base address: 0x%08X\n", baseAddress);
        }
    }

    // Close the VME crate
    CAENVME_End(handle);

    return 0;
}