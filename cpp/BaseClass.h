#pragma once
#include "gtypes.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// const std::string logName = "devLog";
// static std::shared_ptr<spdlog::logger> shareLogger = spdlog::stdout_color_mt(logName);

#define devInfo(...) spdlog::info(__VA_ARGS__)

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

class BaseDev
{
    public:
        BaseDev(BaseBus* devBus):devBus(devBus){}
        ~BaseDev(){}

        virtual uint8 read(uint8 addr){return 0xde;}
        virtual uint16 read(uint16 addr){return 0xdead;}
        virtual uint32 read(uint32 addr){return 0xdeaddead;}

        //  void write(uint8 addr, uint8 value){devBus->write8(addr,value);}
        //  void write(uint16 addr, uint16 value){devBus->write16(addr,value);}
        //  void write(uint32 addr, uint32 value){devBus->write32(addr,value);}
    private:
        BaseBus* devBus;
};