#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <QObject>
#include <QFile>

class CSVParser: public QObject
{
public:
    CSVParser();
    CSVParser(QString filePath);
    ~CSVParser();

private:
    QFile file;
};


#endif // CSVPARSER_H
