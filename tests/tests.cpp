#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "MyDev.h"


TEST(TestCase, MyDev8)
{
    // BaseBus *myBus = new MyBus();
    // BaseDev *myDev8 = new MyDev8(myBus);

    shared_basebus_ptr myBus = std::make_shared<MyBus>();
    shared_basedev_ptr myDev8 = std::make_shared<MyDev8>(myBus);


    uint8 addr8 =10;
    EXPECT_EQ(myDev8->read(addr8), 0x88);
}

TEST(TestCase, MyDev16)
{
    shared_basebus_ptr myBus = std::make_shared<MyBus>();
    shared_basedev_ptr myDev16 = std::make_shared<MyDev16>(myBus);

    uint16 addr16 = 0;
    EXPECT_EQ(myDev16->read(addr16), 0x8888);

}

TEST(TestCase, MyDev32)
{
    shared_basebus_ptr myBus = std::make_shared<MyBus>();
    shared_basedev_ptr myDev32 = std::make_shared<MyDev32>(myBus);

    uint32 addr32=32;
    EXPECT_EQ(myDev32->read(addr32), 0x32323232);
}