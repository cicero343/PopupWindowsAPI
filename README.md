# PopupWindowsAPI

# Overview

PopupWindowsAPI is a simple C program that demonstrates the use of the Windows API to create a graphical user interface (GUI) application. The program displays a window with several buttons that allow users to view system information, disk space, uptime, network information, date and time, and memory stats. It also includes buttons to open system utilities such as Command Prompt and Task Manager.

![image](https://github.com/user-attachments/assets/6e4dcbcf-8859-4b39-bfa1-34aaaf1bd378)

# Features

- **System Information:** Displays the computer name, Windows version, available free space on the C: drive, system uptime in seconds, the current date and time, and displays total and available physical memory.
- **Open CMD:** Opens Command Prompt.
- **Task Manager:** Opens Task Manager.
- **Local Users & Groups:** Opens lusrmgr.msc (Local Users and Groups).
- **Device Manager:** Opens Device Manager.
- **Registry Editor:** Opens Registry Editor.

# Installation

You can install and compile the program using one of the following methods:

<h3> Option 1: Automated Build Script (build.bat) </h3>

This method uses Chocolatey to install GCC if not already installed.

    Download or clone the repository to your local machine.
    Run the build.bat file located in the project directory. The script will:
        Check if GCC is installed; if not, it will install it via Chocolatey.
        Compile the PopupWindowsAPI.c file and generate the PopupWindowsAPI.exe executable.

To run the program, simply double-click on the generated PopupWindowsAPI.exe.

<h3> Option 2: Visual Studio Code (with tasks.json) </h3>

    Make sure gcc is installed on your system.
    Open the project in Visual Studio Code.
    Use the built-in task runner by navigating to Terminal > Run Build Task. This will compile the code using the provided tasks.json.
    After the build, run PopupWindowsAPI.exe to execute the program.

<h3> Option 3:** Manual GCC Installation and Compilation </h3>

If you'd rather manually install and compile the program:

Install GCC:

For Windows, you can install GCC via MinGW, MSYS2, or another GCC distribution.

Ensure that gcc is added to your system's PATH.

Compile and Run:

Navigate to the directory containing the source code.

Run the following command to compile the program:

```cmd
gcc -o PopupWindowsAPI.exe PopupWindowsAPI.c
```

    This will generate an executable named PopupWindowsAPI.exe.
    To run the program, execute the following in Command Prompt:

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

# License

This project is licensed under the MIT License - see the LICENSE file for details.
