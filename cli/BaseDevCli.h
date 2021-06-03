#pragma once


#include <memory>
#include <string>
#include <iostream>

#include "cli/cli.h"

#include "BaseClass.h"
#include "MyCli.h"

using namespace cli;
using namespace std;


class Base8DevCli
{
    public:
        Base8DevCli(shared_basedev_ptr dev, std::string devName):dev(dev),devName(devName){
            rootMenu->Insert(
                devName + ".read", {"regAddr", "len"},
                [&](std::ostream& out, uint8 regAddr, int len)
                {
                    readFuncLen(out,regAddr,len);
                },
                "read lens of regs" );
            rootMenu->Insert(
                devName + ".read", {"regAddr"},
                [&](std::ostream& out, uint8 regAddr)
                {
                    readFunc(out,regAddr);
                },
                "read lens of regs" );            
               
        }
        ~Base8DevCli(){}
        void readFuncLen(std::ostream& out, uint8 regAddr, int len){
                for(int i = 0; i < len; i++)
                    out << std::hex <<"[" <<(unsigned)(regAddr + i) << "]:" 
                        << (unsigned)(dev->read((uint8)(regAddr + i))) << "\n";
        }
        void readFunc(std::ostream& out, uint8 regAddr){
            out << std::hex <<"[" <<(unsigned)(regAddr) << "]:" 
                << (unsigned)(dev->read((uint8)(regAddr))) << "\n";
        }       
    private:
        shared_basedev_ptr dev;
        std::string devName;

};

class Base16DevCli
{
    public:
        Base16DevCli(shared_basedev_ptr dev, std::string devName):dev(dev),devName(devName){
            rootMenu->Insert(
                devName + ".read", {"regAddr", "len"},
                [&](std::ostream& out, uint16 regAddr, int len)
                {
                    readFuncLen(out,regAddr,len);
                },
                "read lens of regs" );
            rootMenu->Insert(
                devName + ".read", {"regAddr"},
                [&](std::ostream& out, uint16 regAddr)
                {
                    readFunc(out,regAddr);
                },
                "read lens of regs" );            
               
        }
        ~Base16DevCli(){}
        void readFuncLen(std::ostream& out, uint16 regAddr, int len){
                for(int i = 0; i < len; i++)
                    out << std::hex <<"[" <<(unsigned)(regAddr + i) << "]:" 
                        << (unsigned)(dev->read((uint16)(regAddr + i))) << "\n";
        }
        void readFunc(std::ostream& out, uint16 regAddr){
            out << std::hex <<"[" <<(unsigned)(regAddr) << "]:" 
                << (unsigned)(dev->read((uint16)(regAddr))) << "\n";
        }       
    private:
        shared_basedev_ptr dev;
        std::string devName;

};


class Base32DevCli
{
    public:
        Base32DevCli(shared_basedev_ptr dev, std::string devName):dev(dev),devName(devName){
            rootMenu->Insert(
                devName + ".read", {"regAddr", "len"},
                [&](std::ostream& out, uint32 regAddr, int len)
                {
                    readFuncLen(out,regAddr,len);
                },
                "read lens of regs" );
            rootMenu->Insert(
                devName + ".read", {"regAddr"},
                [&](std::ostream& out, uint32 regAddr)
                {
                    readFunc(out,regAddr);
                },
                "read lens of regs" );            
               
        }
        ~Base32DevCli(){}
        void readFuncLen(std::ostream& out, uint32 regAddr, int len){
                for(int i = 0; i < len; i++)
                    out << std::hex <<"[" <<(unsigned)(regAddr + i * 4) << "]:" 
                        << (unsigned)(dev->read((uint32)(regAddr + i * 4))) << "\n";
        }
        void readFunc(std::ostream& out, uint32 regAddr){
            out << std::hex <<"[" <<(unsigned)(regAddr) << "]:" 
                << (unsigned)(dev->read((uint32)(regAddr))) << "\n";
        }       
    private:
        shared_basedev_ptr dev;
        std::string devName;

};

// template<typename T>
// class BaseDevCli
// {
//     public:
//         BaseDevCli(BaseDev* dev, std::string devName):dev(dev),devName(devName){
//             rootMenu->Insert(
//                 devName + ".read", {"regAddr", "len"},
//                 [&](std::ostream& out, T regAddr, int len)
//                 {
//                     readFuncLen(out,regAddr,len);
//                 },
//                 "read lens of regs" );
//             rootMenu->Insert(
//                 devName + ".read", {"regAddr"},
//                 [&](std::ostream& out, T regAddr)
//                 {
//                     readFunc(out,regAddr);
//                 },
//                 "read lens of regs" );            
               
//         }
//         ~BaseDevCli(){}
//         void readFuncLen(std::ostream& out, T regAddr, int len){
//                 int step = sizeof(T);
//                 for(int i = 0; i < len; i++)
//                     out << std::hex <<"[" <<(unsigned)(regAddr + step * i) << "]:" 
//                         << (unsigned)(dev->read((T)(regAddr + step * i))) << "\n";
//         }
//         void readFunc(std::ostream& out, T regAddr){
//             out << std::hex <<"[" <<(unsigned)(regAddr) << "]:" 
//                 << (unsigned)(dev->read((T)(regAddr))) << "\n";
//         }       
//     private:
//         BaseDev* dev;
//         std::string devName;

// };



