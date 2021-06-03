#pragma once
#include <memory>
#include "gtypes.h"


class BaseBus
{
    public:
        BaseBus() = default;
        ~BaseBus() = default;
        virtual uint8 read8(uint8 addr){return 0xde;}
        virtual uint16 read16(uint16 addr){return 0xdead;}
        virtual uint32 read32(uint32 addr){return 0xdeaddead;}
        // virtual void write8(uint8 addr, uint8 value){}
        // virtual void write16(uint16 addr, uint16 value){}
        // virtual void write32(uint32 addr, uint32 value){}

    private:
};

using shared_basebus_ptr = std::shared_ptr<BaseBus>;

class BaseDev
{
    public:
        BaseDev(shared_basebus_ptr devBus):devBus(devBus){}
        ~BaseDev(){}

        virtual uint8 read(uint8 addr){return 0xde;}
        virtual uint16 read(uint16 addr){return 0xdead;}
        virtual uint32 read(uint32 addr){return 0xdeaddead;}

        //  void write(uint8 addr, uint8 value){devBus->write8(addr,value);}
        //  void write(uint16 addr, uint16 value){devBus->write16(addr,value);}
        //  void write(uint32 addr, uint32 value){devBus->write32(addr,value);}
    private:
        shared_basebus_ptr devBus;
};

using shared_basedev_ptr = std::shared_ptr<BaseDev>;