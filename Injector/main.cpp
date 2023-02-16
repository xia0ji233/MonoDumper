#include<windows.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<TlHelp32.h>

void InjectModule(DWORD ProcessId, const char* szPath)
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
    printf("进程句柄:%p\n", hProcess);
    LPVOID lpAddress = VirtualAllocEx(hProcess, NULL, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    SIZE_T dwWriteLength = 0;
    WriteProcessMemory(hProcess, lpAddress, szPath, strlen(szPath), &dwWriteLength);
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, lpAddress, NULL, NULL);
    WaitForSingleObject(hThread, -1);
    VirtualFreeEx(hProcess, lpAddress, 0, MEM_RELEASE);
    CloseHandle(hProcess);
    CloseHandle(hThread);
}

DWORD FindProcess() {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32;
    pe32 = { sizeof(pe32) };
    BOOL ret = Process32First(hSnap, &pe32);
    while (ret)
    {
        //wprintf(L"%s\n", pe32.szExeFile);
        if (!wcsncmp(pe32.szExeFile, L"Granny.exe", 11)) {
            printf("Find Granny.exe Process %d\n", pe32.th32ProcessID);
            return pe32.th32ProcessID;
        }
        ret = Process32Next(hSnap, &pe32);
    }
    return 0;
}
int main() {
    DWORD ProcessId = FindProcess();
    while (!ProcessId) {
        printf("未找到Granny程序，等待两秒中再试\n");
        Sleep(2000);
        ProcessId = FindProcess();
    }
    printf("开始注入进程...\n");
    InjectModule(ProcessId, "C:\\Users\\xia0ji233\\source\\repos\\Game3\\x64\\Debug\\GrannyConsole.dll");
    printf("注入完毕\n");

}