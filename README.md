# PopupWindowsAPI

# Overview

PopupWindowsAPI is a simple C program that demonstrates the use of the Windows API to create a graphical user interface (GUI) application. The program displays a window with several buttons that allow users to view system information, disk space, uptime, network information, date and time, and memory stats. It also includes buttons to open system utilities such as Command Prompt and Task Manager.

# Features

    System Information: Displays the computer name and Windows version.
    Disk Space: Shows the available free space on the C: drive.
    Uptime: Displays the system uptime in seconds.
    Network Info: Placeholder for future network information (currently not implemented).
    Date & Time: Shows the current date and time.
    Memory Stats: Displays total and available physical memory.
    Open CMD: Launches Command Prompt.
    Task Manager: Opens Task Manager.
    User Management: Buttons to open lusrmgr.msc (Local Users and Groups), Device Manager, and Registry Editor.

# Prerequisites

    GCC Compiler: Ensure you have GCC installed and available in your system's PATH. For Windows, you can use MinGW or a similar GCC distribution.

# Compilation and Execution

To compile the program, open Command Prompt and navigate to the directory containing the source code. Run the following command:

sh

gcc -o PopupWindowsAPI.exe PopupWindowsAPI.c

This will generate an executable named PopupWindowsAPI.exe. You can then run the program by executing:

sh

PopupWindowsAPI.exe

# Usage

    System Info: Click the "System Info" button to view system information.
    Disk Space: Click the "Disk Space" button to view available disk space.
    Uptime: Click the "Uptime" button to view system uptime.
    Network Info: Click the "Network Info" button to display network information (currently a placeholder).
    Date & Time: Click the "Date & Time" button to view the current date and time.
    Memory Stats: Click the "Memory Stats" button to view memory statistics.
    Open CMD: Click the "Open CMD" button to launch Command Prompt.
    Task Manager: Click the "Task Manager" button to open Task Manager.
    User Management: Click the buttons for lusrmgr.msc, Device Manager, and Registry Editor to access these system utilities.

# Notes

    The Network Info button currently displays a placeholder message as the feature is not yet implemented.
    Ensure the GCC compiler path is correctly set in your system environment variables for the compilation to work smoothly.

# License

This project is licensed under the MIT License - see the LICENSE file for details.
