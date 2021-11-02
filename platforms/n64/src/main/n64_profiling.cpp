#include <ultra64.h>
#include <profiling.h>

static struct {
    u32 cpuTime;
    u32 rspTime;
    u32 rdpClockTime;
    u32 rdpCmdTime;
    u32 rdpPipeTime;
    u32 rdpTmemTime;
} ProfilerData;

void profileStartMainLoop()
{
    bzero(&ProfilerData, sizeof(ProfilerData));
    ProfilerData.cpuTime = osGetTime();
    IO_WRITE(DPC_STATUS_REG, DPC_CLR_CLOCK_CTR | DPC_CLR_CMD_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_TMEM_CTR);
}

void profileBeforeGfxMainLoop()
{
    ProfilerData.cpuTime = osGetTime() - ProfilerData.cpuTime;
}

void profileEndMainLoop()
{
    ProfilerData.rdpClockTime = IO_READ(DPC_CLOCK_REG);
    ProfilerData.rdpCmdTime = IO_READ(DPC_BUFBUSY_REG);
    ProfilerData.rdpPipeTime = IO_READ(DPC_PIPEBUSY_REG);
    ProfilerData.rdpTmemTime = IO_READ(DPC_TMEM_REG);

    // // debug_printf("CPU:  %8u RSP:  %8u CLK:  %8u\nCMD:  %8u PIPE: %8u TMEM: %8u\n",
    //     ProfilerData.cpuTime, ProfilerData.rspTime, ProfilerData.rdpClockTime, ProfilerData.rdpCmdTime,
    //     ProfilerData.rdpPipeTime, ProfilerData.rdpTmemTime);
}
