#include "tid_log.h"

int main() 
{
    TIDLog log("logs","COMMON_A");
    TIDLog log2("logs2", "COMMON_B");

    for (int i = 0; i < 100; i++)
    {
        LOGINFO(log) << "In log-1 " << i << ", i * i = " << i * i;
        LOGINFO(log2) << "In log-2 " << i << ", i + i = " << i + i;
    }
    return 0;
}