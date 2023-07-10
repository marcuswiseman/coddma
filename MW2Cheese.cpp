#include <Windows.h>
#include "MemoryUtility.h"
#include "Decrypt.h"
#include <math.h>

MemoryUtility MemUtil;

DWORD                       PROCESS_PID;
QWORD                       PROCESS_PEB;
VMMDLL_PROCESS_INFORMATION  PROCESS_INFO;
QWORD                       MODULE_BASE_ADDRESS;

QWORD                       CLIENT_INFO;
QWORD                       CLIENT_INFO_BASE;

void run();

/*
    @info Our main application call
*/
int main()
{
    if (!MemUtil.connectToDma()) {
        printf("FAIL: DMA Failed to connect!\n");
        return 1;
    }

    printf("SUCCESS: DMA Connected!\n");

    PROCESS_INFO = MemUtil.getProcessInfo((LPSTR)"cod.exe");
    PROCESS_PID = PROCESS_INFO.dwPID;
    PROCESS_PEB = PROCESS_INFO.win.vaPEB;
    MODULE_BASE_ADDRESS = MemUtil.getProcessModule(PROCESS_PID, (LPSTR)"cod.exe");
    CLIENT_INFO_BASE = get_client_info_base(MODULE_BASE_ADDRESS, PROCESS_PEB);

    printf("Client Base: %llu\n", CLIENT_INFO_BASE);

    run();

    MemUtil.close();
    printf("Closing!\n");
}

/*
    @info Main process loop
*/
void run() {
    MemUtil.scatterStart(PROCESS_PID);

    QWORD localPlayerAddress;
    MemUtil.scatterRead(CLIENT_INFO_BASE + (offsets::local_index * offsets::player::size), &localPlayerAddress);
    MemUtil.scatterExecute();
    printf("PlayerAddr: %llu\n", localPlayerAddress);

    MemUtil.close();
}

