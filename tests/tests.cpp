#include <gtest/gtest.h>
#include "iostream"
#include "MyDev.h"


TEST(TestCase, MyDev8)
{
    BaseBus *myBus = new MyBus();
    BaseDev *myDev8 = new MyDev8(myBus);

    uint8 addr8 =10;
    EXPECT_EQ(myDev8->read(addr8), 0x88);
}

TEST(TestCase, MyDev16)
{
    BaseBus *myBus = new MyBus();
    BaseDev *myDev16 = new MyDev16(myBus);

    uint16 addr16 = 0;
    EXPECT_EQ(myDev16->read(addr16), 0x8888);

}

TEST(TestCase, MyDev32)
{
    BaseBus *myBus = new MyBus();
    BaseDev *myDev32 = new MyDev32(myBus);

    uint32 addr32=32;
    EXPECT_EQ(myDev32->read(addr32), 0x32323232);
}