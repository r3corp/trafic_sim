#pragma once

#include <string>
#include <iostream>
#include <fstream>

//Singleton Loging
class Logger
{
    private:
        std::string logFileName;
        std::ofstream destinationFileWriter;

        Logger() {}
        // C++ 03
        // ========
        // Don't forget to declare these two. You want to make sure they
        // are unacceptable otherwise you may accidentally get copies of
        // your singleton appearing.
        Logger(Logger const&);              // Don't Implement
        void operator=(Logger const&); // Don't implement
        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.

        ~Logger();

    public:
        //Logger(Logger const&) = delete;
        //void operator=(Logger const&) = delete;
        
        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status

        static Logger &getInstance(void);
        void configureDestinationFile(std::string logFileName);
        void registerLog(int line, std::string filename, std::string message);
};

