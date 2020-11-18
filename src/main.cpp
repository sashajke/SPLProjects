#include "Session.h"
#include <csignal>
#include <iostream>
using namespace std;

//Coded By Ron Rachev


void signalHandler(int signal){
    std::cout << "Unknown Exception! Try running generatedTest.json Manually!" << std::endl;
    exit(signal);
}
int main(int argc, char** argv){

        if(argc != 2) {
            cout << "usage cTrace <config_path>" << endl;
            return 0;
        }
        Session sess(argv[1]);
        sess.simulate();
        return 0;
}