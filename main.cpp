#include "Session.h"
#include <csignal>
#include <iostream>
#include "Tester.h"
using namespace std;

//Coded By Ron Rachev

Tester * testGenerator;
void signalHandler(int signal){
    std::cout << "Unknown Exception! Try running generatedTest.json Manually!" << std::endl;
    exit(signal);
}
int main(int argc, char** argv){

//
//        Session sess(argv[1]);
//        sess.simulate();
//          return 0;

//    Session testSession("../config4.json");
//    testSession.simulate();


    signal(SIGSEGV,signalHandler);
    //srand(time(NULL));
    srand(time_t(NULL));
    int testerOptionChosen = 0;

    std::cout << "---------------\r\nWelcome\r\n---------------\r\nPlease type 1 to generate tests or 2 to run tests file" << std::endl;
    cin >> testerOptionChosen ;

    if(testerOptionChosen == 2) {
        testGenerator = new Tester(2, 1);
        testGenerator->initate();
        std::cout << "----------------------\r\nTotal Passed Tests : " << testGenerator->numPassedTests
                  << "\r\nFailed Tests : " << testGenerator->numInvalidTests << "\r\n----------------------\r\n"
                  << std::endl;
        delete (testGenerator);
    }else
    if(testerOptionChosen == 1){
        std::cout << " Generating Random 4000 Tests " << std::endl;
        for(int i = 0 ;i < 4000 ; i ++)
        {
            testGenerator = new Tester(1,i);
            testGenerator->initate();
            delete(testGenerator);
        }
        std::cout << "\r\nTests Written To tests.json, have fun." << std::endl;
    }else
        std::cout << "Invalid Input" << std::endl;
    return 0;
//    if(argc != 2){
//        cout << "usage cTrace <config_path>" << endl;
//        return 0;
//    }

}