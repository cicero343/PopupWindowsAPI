# PopupWindowsAPI

# Overview

PopupWindowsAPI is a simple C program that demonstrates the use of the Windows API to create a graphical user interface (GUI) application. The program displays a window with several buttons that allow users to view system information, disk space, uptime, network information, date and time, and memory stats. It also includes buttons to open system utilities such as Command Prompt and Task Manager.

# Features

- **System Information:** Displays the computer name, Windows version, available free space on the C: drive, system uptime in seconds, the current date and time, and displays total and available physical memory.
- **Open CMD:** Opens Command Prompt.
- **Task Manager:** Opens Task Manager.
- **Local Users & Groups:** Opens lusrmgr.msc (Local Users and Groups).
- **Device Manager:** Opens Device Manager.
- **Registry Editor:** Opens Registry Editor.

# Prerequisites

- **GCC Compiler:** Ensure you have GCC installed and available in your system's PATH. For Windows, you can use MinGW or a similar GCC distribution.

# Compilation and Execution

To compile the program, open Command Prompt and navigate to the directory containing the source code. Run the following command:

```cmd
gcc -o PopupWindowsAPI.exe PopupWindowsAPI.c
```

This will generate an executable named PopupWindowsAPI.exe. You can then run the program by executing:

```cmd
PopupWindowsAPI.exe
```

# Usage

    System Info: Click the "System Info" button to view system information.
    Open CMD: Click the "Open CMD" to open Command Prompt.
    Task Manager: Click the "Task Manager" button to open Task Manager.
    Local Users_Groups: Click the button to open lusrmgr.msc.
    Device Manager: Click the button to open Device Manager.
    Registry Editor: Click the button to open Registry Editor.
    
# Notes

    Ensure the GCC compiler path is correctly set in your system environment variables for the compilation to work smoothly.

# License

This project is licensed under the MIT License - see the LICENSE file for details.
