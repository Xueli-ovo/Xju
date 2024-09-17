#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#elif __APPLE__
#include <sys/sysctl.h>
#include <mach/mach.h>
#endif

void printCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "Current Date and Time: ";
    std::cout << ltm->tm_year + 1900 << "/" << ltm->tm_mon + 1 << "/" << ltm->tm_mday << " ";
    std::cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
}

void printOSInfoAndUptime() {
    #ifdef _WIN32
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);

    std::cout << "Operating System: Windows" << std::endl;

    std::ifstream uptimeFile("/proc/uptime");
    if (uptimeFile.is_open()) {
        double uptime;
        uptimeFile >> uptime;
        uptimeFile.close();
        int days = uptime / (60 * 60 * 24);
        int hours = (int)(uptime / 3600) % 24;
        int minutes = (int)(uptime / 60) % 60;
        int seconds = (int)uptime % 60;

        std::cout << "Uptime: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
    }
    #elif __linux__
    struct utsname unameData;
    if(uname(&unameData) == 0) {
        std::cout << "Operating System: " << unameData.sysname << " " << unameData.release << std::endl;
    }

    struct sysinfo sys_info;
    if(sysinfo(&sys_info) == 0) {
        int days = sys_info.uptime / (60 * 60 * 24);
        int hours = (int)(sys_info.uptime / 3600) % 24;
        int minutes = (int)(sys_info.uptime / 60) % 60;
        int seconds = (int)sys_info.uptime % 60;

        std::cout << "Uptime: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
    }
    #elif __APPLE__
    size_t size;
    int mib[2] = {CTL_KERN, KERN_OSRELEASE};
    sysctl(mib, 2, NULL, &size, NULL, 0);

    char* release = new char[size];
    sysctl(mib, 2, release, &size, NULL, 0);

    std::cout << "Operating System: macOS " << release << std::endl;

    mib[0] = CTL_KERN;
    mib[1] = KERN_BOOTTIME;
    struct timeval boottime;
    size = sizeof(boottime);
    sysctl(mib, 2, &boottime, &size, NULL, 0);

    time_t now = time(0);
    double uptime = difftime(now, boottime.tv_sec);

    int days = uptime / (60 * 60 * 24);
    int hours = (int)(uptime / 3600) % 24;
    int minutes = (int)(uptime / 60) % 60;
    int seconds = (int)uptime % 60;

    std::cout << "Uptime: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
    #endif
}

int main() {
    printCurrentDateTime();
    printOSInfoAndUptime();

    return 0;
}