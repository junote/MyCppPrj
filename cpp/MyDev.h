#pragma once

#include "BaseClass.h"

class MyBus:public BaseBus
{
    public:
        MyBus(){}
        ~MyBus(){}
        uint8 read8(uint8 addr);
        uint16 read16(uint16 addr);
        uint32 read32(uint32 addr);
};

class MyDev8:public BaseDev
{
public:
    MyDev8(BaseBus* myBus):myBus(myBus),BaseDev(myBus){}
    ~MyDev8(){}
    uint8 read(uint8 addr){return myBus->read8(addr);}

private:
    BaseBus* myBus;

};


class MyDev32:public BaseDev
{
public:
    MyDev32(BaseBus* myBus):myBus(myBus),BaseDev(myBus){}
    ~MyDev32(){}
    uint32 read(uint32 addr);

private:
    BaseBus* myBus;

};

class MyDev16:public BaseDev
{
public:
    MyDev16(BaseBus* myBus):myBus(myBus),BaseDev(myBus){}
    ~MyDev16(){}
    uint16 read(uint16 addr);
private:
    BaseBus* myBus;

};