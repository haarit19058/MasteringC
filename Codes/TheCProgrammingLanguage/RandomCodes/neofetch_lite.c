#include <stdio.h>
#include <Windows.h>

// Function to get CPU information
void getCPUInfo() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    printf("Processor Architecture: ");
    switch (sysInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("x64\n");
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            printf("ARM\n");
            break;
        case PROCESSOR_ARCHITECTURE_IA64:
            printf("Itanium-based\n");
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86\n");
            break;
        default:
            printf("Unknown\n");
    }
    printf("Number of Processors: %u\n", sysInfo.dwNumberOfProcessors);
}

// Function to get memory information
void getMemoryInfo() {
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    GlobalMemoryStatusEx(&memStatus);
    printf("Total Physical Memory: %.2f GB\n", (double)memStatus.ullTotalPhys / (1024 * 1024 * 1024));
    printf("Available Physical Memory: %.2f GB\n", (double)memStatus.ullAvailPhys / (1024 * 1024 * 1024));
}

int main() {
    printf("System Information:\n");
    printf("-------------------\n");
    getCPUInfo();
    printf("\n");
    getMemoryInfo();
    return 0;
}
