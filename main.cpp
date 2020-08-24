#include "tid_log.h"

TIDLog tidLog;
TIDLog tidLog2;

int main() 
{
    tidLog.init("TIDLog1", "COMMON_A");
    tidLog2.init("TIDLog2", "COMMON_B");

    for (int i = 0; i < 100; i++)
    {
        TIDLOG_INFO(tidLog) << "In log-1 " << i << ", i * i = " << i * i;
        TIDLOG_DEBUG(tidLog2) << "In log-2 " << i << ", i + i = " << i + i;
    }

    return 0;
}