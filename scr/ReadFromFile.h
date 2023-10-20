#pragma once
#include <QTextStream>
#include <QStringList>
#include <QFile>
#include <QVector>

QVector<QString> ReadFromFile(const QString& fileName)
{
    QTextStream out(stdout);
    //QStringList lstLine;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        file.close();
    }
    QTextStream in(&file);
    QVector<QString> vectr;
    while (!in.atEnd())
    {
        QString line = in.readLine(); //specifying number = # of characters
        vectr.push_back(line);
    }
    for(const auto& iter: vectr)
    {
        out  << iter << "\n";
    }
    file.close();
    return vectr;
}
