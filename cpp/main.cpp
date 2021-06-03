#include <iostream>
#include <memory>
#include "MyDev.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"

int main(int argc, char const *argv[])
{
    
    // auto shareLogger = spdlog::stdout_color_mt(logName);
    // shareLogger->info("hello,spdlog");

    // BaseBus* myBus = new MyBus();
    shared_basebus_ptr myBus = std::make_shared<MyBus>();
    // BaseDev* myDev16 = new MyDev16(myBus);
    shared_basedev_ptr myDev8 = std::make_shared<MyDev8>(myBus);
    shared_basedev_ptr myDev16 = std::make_shared<MyDev16>(myBus);
    shared_basedev_ptr myDev32 = std::make_shared<MyDev32>(myBus);

    uint8 addr8 = 0;
    devInfo("{:#x}",myBus->read8(addr8));

    myDev8->read(addr8);

    uint16 addr16 = 0;
    myDev16->read(addr16);

    uint32 addr32 = 0;
    devInfo("{:#x}",myBus->read32(addr32));

    myDev32->read(addr32);
    // BaseDev* myDev32 = new MyDev32(myBus);
    // uint32 addr32 = 0;
    // myDev32->read(addr32);
    


    return 0;
}
