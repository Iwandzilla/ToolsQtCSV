#include "csvparser.h"
#include <iostream>

CSVParser::CSVParser()
{
}

CSVParser::CSVParser(QString filePath)
{
    file.setFileName(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    std::cout<<"New CSVParser Created using filePath"<<std::flush;
}

CSVParser::~CSVParser()
{
    if(!file.close())
    std::cout<<"New CSVParser destroyed"<<std::flush;
}
