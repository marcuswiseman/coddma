#include <cstdint>
#include <stdio.h>
#include <leechcore.h>
#include <vmmdll.h>
#include "Vectors.h"
#include <exception>

class MemoryUtility {
	VMM_HANDLE vmm;
    VMMDLL_SCATTER_HANDLE scatterHandle;

public:

	bool connectToDma();

	VMMDLL_PROCESS_INFORMATION getProcessInfo(LPSTR processName);
	QWORD getProcessModule(DWORD mainProcessPid, LPSTR moduleName);
	DWORD getProcessPid(LPSTR processName);
    void readMemory(DWORD mainProcessPid, QWORD address, void* buff);

    VMMDLL_SCATTER_HANDLE scatterStart(DWORD mainProcessPid);
    bool scatterExecute();
    bool scatterRead(QWORD address, void* buff);
    void scatterClear();

	void close();
};

/*
    @info Connect to the DMA device
*/
bool MemoryUtility::connectToDma()
{
    LPSTR args[] = { (LPSTR)"", (LPSTR)"-device", (LPSTR)"fpga" };

    this->vmm = VMMDLL_Initialize(3, args);

    if (!this->vmm) {
        return false;
    }

    return true;
}

/*
    @info Close vmm
*/
void MemoryUtility::close()
{
    if (this->vmm) {
        VMMDLL_Close(this->vmm);
    }
}

/*
    @info Start scatter address search
*/
VMMDLL_SCATTER_HANDLE MemoryUtility::scatterStart(DWORD mainProcessPid) 
{
   this->scatterHandle = VMMDLL_Scatter_Initialize(this->vmm, mainProcessPid, VMMDLL_FLAG_NOCACHE);
   return this->scatterHandle;
}

/*
    @info Execute scatter search
*/
bool MemoryUtility::scatterExecute() 
{
    bool result = VMMDLL_Scatter_Execute(this->scatterHandle);
    this->scatterClear();
    return result;
}

/*
    @info Clear scatter data
*/
void MemoryUtility::scatterClear() 
{
    VMMDLL_Scatter_Clear(this->scatterHandle, 0, VMMDLL_FLAG_NOCACHE);
}

/*
    @info Queue a read to the scatter object
*/
bool MemoryUtility::scatterRead(QWORD address, void* buff) 
{
    DWORD cRead;

    return VMMDLL_Scatter_PrepareEx(this->scatterHandle, address, sizeof(buff), (PBYTE)buff, &cRead);
}

/*
    @info Get process module base address
*/
QWORD MemoryUtility::getProcessModule(DWORD mainProcessPid, LPSTR moduleName) 
{
    QWORD result = VMMDLL_ProcessGetModuleBaseU(this->vmm, mainProcessPid, moduleName);

    if (!result) {
        return false;
    }

    printf("Module Base Address: %llu\n", result);

    return result;
}

/*
    @Info Get process pid
*/
DWORD MemoryUtility::getProcessPid(LPSTR processName) 
{
    DWORD mainProcessPid;
    BOOL result = VMMDLL_PidGetFromName(this->vmm, processName, &mainProcessPid);

    if (!result) {
        return 0;
    }

    return mainProcessPid;
}

/*
    @info Read memory from process
*/
void MemoryUtility::readMemory(DWORD mainProcessPid, QWORD address, void* buff)
{
    DWORD cRead;

    try {
        VMMDLL_MemReadEx(this->vmm, mainProcessPid, address, (PBYTE)buff, sizeof(buff), &cRead, VMMDLL_FLAG_NOCACHE);
    }
    catch (std::exception e) {
        // do nothing
    }
}

/*
    @info Get process info
*/
VMMDLL_PROCESS_INFORMATION MemoryUtility::getProcessInfo(LPSTR processName)
{
    VMMDLL_PROCESS_INFORMATION mainProcessInfo;

    try {
        DWORD mainProcessPid = this->getProcessPid(processName);

        printf("PID FOUND: %lu\n", mainProcessPid);

        SIZE_T cbProcessInformation = sizeof(VMMDLL_PROCESS_INFORMATION);
        ZeroMemory(&mainProcessInfo, sizeof(VMMDLL_PROCESS_INFORMATION));
        mainProcessInfo.magic = VMMDLL_PROCESS_INFORMATION_MAGIC;
        mainProcessInfo.wVersion = VMMDLL_PROCESS_INFORMATION_VERSION;

        bool processResult = VMMDLL_ProcessGetInformation(vmm, mainProcessPid, &mainProcessInfo, &cbProcessInformation);

        if (processResult) {
            printf("SUCCESS: Process %s found!\n", processName);
            printf("Name = %s\n", mainProcessInfo.szName);
            printf("PageDirectoryBase = 0x%016llx\n", mainProcessInfo.paDTB);
            printf("PageDirectoryBaseUser = 0x%016llx\n", mainProcessInfo.paDTB_UserOpt);
            printf("ProcessState = 0x%08x\n", mainProcessInfo.dwState);
            printf("PID = 0x%08x\n", mainProcessInfo.dwPID);
            printf("ParentPID = 0x%08x\n", mainProcessInfo.dwPPID);
            printf("PEB = %llu\n", mainProcessInfo.win.vaPEB);
        }
        else {
            printf("FAILED: To find process %s!", processName);
        }
    }
    catch (std::exception e) {
        printf("FAILED: To load process %s\n", processName);
    }

    return mainProcessInfo;
}


