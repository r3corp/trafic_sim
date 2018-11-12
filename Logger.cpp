#include "Logger.hpp"


void Logger::registerLog(int line, std::string fileName, std::string message)
{
    if (getInstance().logFileName.empty()) return;
    getInstance().destinationFileWriter.open(getInstance().logFileName);
    getInstance().destinationFileWriter << "Linha[" << line << "]" << "Arquivo[" << fileName << "]" << "Mensagem[" << message << "]" << std::endl;
    getInstance().destinationFileWriter.close();
}


void Logger::configureDestinationFile(std::string logFileName)
{
    getInstance().logFileName = logFileName;
}

Logger &Logger::getInstance(void)
{
    static Logger instance;
    return instance;
}
