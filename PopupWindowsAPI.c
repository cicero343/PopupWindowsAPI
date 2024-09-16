#include <windows.h>
#include <stdio.h>

// IDs for buttons
#define ID_SYSINFO 1001
#define ID_CMD 1007
#define ID_TASKMANAGER 1008
#define ID_LUSRMGMT 1009
#define ID_DEVMGMT 1010
#define ID_REGEDIT 1011

// Function prototypes
void ShowSystemInfo(HWND hwnd);
void LaunchUtility(HWND hwnd, LPCSTR app);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case ID_SYSINFO:
                    ShowSystemInfo(hwnd);
                    return 0;
                case ID_CMD:
                    LaunchUtility(hwnd, "cmd.exe");
                    return 0;
                case ID_TASKMANAGER:
                    LaunchUtility(hwnd, "taskmgr.exe");
                    return 0;
                case ID_LUSRMGMT:
                    LaunchUtility(hwnd, "lusrmgr.msc");
                    return 0;
                case ID_DEVMGMT:
                    LaunchUtility(hwnd, "devmgmt.msc");
                    return 0;
                case ID_REGEDIT:
                    LaunchUtility(hwnd, "regedit.exe");
                    return 0;
                case IDCLOSE:
                    DestroyWindow(hwnd);
                    return 0;
            }
            break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "System Info Popup";
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "System Info Popup", WS_OVERLAPPEDWINDOW,
        100, 100, 400, 300, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) return 0;

    CreateWindowEx(0, "BUTTON", "System Information", WS_CHILD | WS_VISIBLE, 20, 30, 150, 30, hwnd, (HMENU)ID_SYSINFO, hInstance, NULL);
    CreateWindowEx(0, "BUTTON", "Open CMD", WS_CHILD | WS_VISIBLE, 20, 70, 150, 30, hwnd, (HMENU)ID_CMD, hInstance, NULL);
    CreateWindowEx(0, "BUTTON", "Task Manager", WS_CHILD | WS_VISIBLE, 20, 110, 150, 30, hwnd, (HMENU)ID_TASKMANAGER, hInstance, NULL);
    CreateWindowEx(0, "BUTTON", "Local Users & Groups", WS_CHILD | WS_VISIBLE, 200, 30, 150, 30, hwnd, (HMENU)ID_LUSRMGMT, hInstance, NULL);
    CreateWindowEx(0, "BUTTON", "Device Manager", WS_CHILD | WS_VISIBLE, 200, 70, 150, 30, hwnd, (HMENU)ID_DEVMGMT, hInstance, NULL);
    CreateWindowEx(0, "BUTTON", "Registry Editor", WS_CHILD | WS_VISIBLE, 200, 110, 150, 30, hwnd, (HMENU)ID_REGEDIT, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// 1. Show all system information in a single popup
void ShowSystemInfo(HWND hwnd) {
    char buffer[256];
    DWORD size = 256;
    GetComputerName(buffer, &size);

    OSVERSIONINFO osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);

    ULARGE_INTEGER freeBytesAvailable, totalBytes, freeBytes;
    GetDiskFreeSpaceEx("C:\\", &freeBytesAvailable, &totalBytes, &freeBytes);

    DWORD uptime = GetTickCount64() / 1000;

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    SYSTEMTIME time;
    GetLocalTime(&time);

    char info[1024];
    sprintf(info, "Computer Name: %s\n"
                  "Windows Version: %d.%d (Build %d)\n\n"
                  "Free Disk Space on C: %llu MB\n"
                  "System Uptime: %lu seconds\n\n"
                  "Current Date & Time: %02d/%02d/%04d %02d:%02d:%02d\n\n"
                  "Total Physical Memory: %llu MB\n"
                  "Available Physical Memory: %llu MB",
            buffer, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber,
            freeBytesAvailable.QuadPart / (1024 * 1024),
            uptime,
            time.wDay, time.wMonth, time.wYear, time.wHour, time.wMinute, time.wSecond,
            statex.ullTotalPhys / (1024 * 1024), statex.ullAvailPhys / (1024 * 1024));

    MessageBox(hwnd, info, "System Information", MB_OK);
}

// 2. Launch system utilities
void LaunchUtility(HWND hwnd, LPCSTR app) {
    ShellExecute(NULL, "open", app, NULL, NULL, SW_SHOWNORMAL);
}
