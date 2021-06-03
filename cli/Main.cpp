#include <cli/cli.h>
#include <cli/clilocalsession.h>
#include <cli/loopscheduler.h>

#include "MyDev.h"

#include "BaseDevCli.h"
#include "MyDevCli.h"
#include "MyCli.h"
using namespace cli;
using namespace std;


int main(int argc, char const *argv[])
{
    // auto shareLogger = spdlog::stdout_color_mt(logName);


    
    try
    {
        SetColor();
        // setup cli                                                                       
    

        //  BaseBus* myBus = new MyBus();
        //  BaseDev* myDev8 = new MyDev8(myBus);
        //  BaseDev* myDev16 = new MyDev16(myBus);
        //  BaseDev* myDev32 = new MyDev32(myBus);
        //  MyDev8Cli myDev8Cli(myDev8, "dev8");
        //  MyDev16Cli myDev16Cli(myDev16, "dev16");
        //  MyDev32Cli myDev32Cli(myDev32, "dev32");

        shared_basebus_ptr myBus = std::make_shared<MyBus>();
        shared_basedev_ptr myDev8 = std::make_shared<MyDev8>(myBus);       
        shared_basedev_ptr myDev16 = std::make_shared<MyDev16>(myBus);       
        shared_basedev_ptr myDev32 = std::make_shared<MyDev32>(myBus);       
        MyDev8Cli myDev8Cli(myDev8, "dev8");
        MyDev16Cli myDev16Cli(myDev16, "dev16");
        MyDev32Cli myDev32Cli(myDev32, "dev32");


        // create a cli with the given root menu and a persistent storage
        // you must pass to FileHistoryStorage the path of the history file
        // if you don't pass the second argument, the cli will use a VolatileHistoryStorage object that keeps in memory
        // the history of all the sessions, until the cli is shut down.
        Cli cli( std::move(rootMenu));
        // global exit action
        cli.ExitAction( [](auto& out){ out << "Goodbye and thanks for all the fish.\n"; } );
        // std exception custom handler
        cli.StdExceptionHandler(
            [](std::ostream& out, const std::string& cmd, const std::exception& e)
            {
                out << "Exception caught in cli handler: "
                    << e.what()
                    << " handling command: "
                    << cmd
                    << ".\n";
            }
        );

        LoopScheduler scheduler;
        CliLocalTerminalSession localSession(cli, scheduler, std::cout, 200);
        localSession.ExitAction(
            [&scheduler](auto& out) // session exit action
            {
                out << "Closing App...\n";
                scheduler.Stop();
            }
        );



        scheduler.Run();

        return 0;

    }
    catch (const std::exception& e)
    {
        cerr << "Exception caugth in main: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown exception caugth in main." << endl;
    }
    return -1;
}


