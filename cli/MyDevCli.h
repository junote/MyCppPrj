#pragma once

#include <string>
#include "BaseDevCli.h"

using namespace cli;
using namespace std;

class MyDev8Cli:public Base8DevCli
{
    public:
        MyDev8Cli(shared_basedev_ptr dev, std::string devName):Base8DevCli(dev,devName){}
            
        ~MyDev8Cli()=default;
    private:
        shared_basedev_ptr dev;
        std::string devName;

};
class MyDev32Cli:public Base32DevCli
{
    public:
        MyDev32Cli(shared_basedev_ptr dev, std::string devName):Base32DevCli(dev,devName){}
            
        ~MyDev32Cli()=default;
    private:
        shared_basedev_ptr dev;
        std::string devName;

};

class MyDev16Cli:public Base16DevCli
{
    public:
        MyDev16Cli(shared_basedev_ptr dev, std::string devName):Base16DevCli(dev,devName){}
            
        ~MyDev16Cli()=default;
    private:
        shared_basedev_ptr dev;
        std::string devName;

};
