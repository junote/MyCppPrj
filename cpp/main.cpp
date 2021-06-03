#include <iostream>
#include "MyDev.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"

int main(int argc, char const *argv[])
{
    
    // auto shareLogger = spdlog::stdout_color_mt(logName);
    // shareLogger->info("hello,spdlog");

    BaseBus* myBus = new MyBus();
    BaseDev* myDev16 = new MyDev16(myBus);

    uint16 addr = 0;
    myDev16->read(addr);

    BaseDev* myDev32 = new MyDev32(myBus);
    uint32 addr32 = 0;
    myDev32->read(addr32);
    


    return 0;
}
