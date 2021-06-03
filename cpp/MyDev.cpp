#include "MyDev.h"
#include <iostream>

uint8 MyBus::read8(uint8 addr)
{
     return 0x88;
}

uint16 MyBus::read16(uint16 addr)
{
     return 0x1616;
}

uint32 MyBus::read32(uint32 addr)
{
     return 0x32323232;
}

uint16 MyDev16::read(uint16 addr)
{
     devInfo("here is mydev16 read");
    return 0x8888;
}

uint32 MyDev32::read(uint32 addr)
{
     devInfo("here is mydev32 read");
     return myBus->read32(addr);
}