#include "TableCls.h"
#include "ValidatorCls.h"
#include <QTableWidget>
#include <QWidget>
#include <QString>
#include <QTextStream>
#include <QPalette>
#include <QColor>
#include <iostream>
#include <QVector>
#include <string>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "CurrentAddress.h"
#include <boost/asio.hpp>
#include <QLabel>
#include <QLineEdit>
#include  "mainwindow.h"




Table::Table(QWidget *parent) : QDialog(parent) {

    //doing this creates the table, then you set the row count

    m_table = new QTableWidget;
    m_table->setRowCount(100);
    m_table->setColumnCount(2);
    m_table->setColumnWidth(0,200);
    m_table->setColumnWidth(1,200);
    m_table->setHorizontalHeaderLabels({"Address","Status"});
    m_file = new QFile("/home/valeriikupriianov/Desktop/QtIpValidator/IpValidatorUI/scr/iplist.txt");
    m_file->open(QIODevice::ReadOnly | QIODevice::Text);
    //Table::uploadData();

   // dataUploader = new QPushButton("Upload data to table",this);
    //connect(dataUploader,&QPushButton::clicked,this,&Table::uploadData);


    btm = new QPushButton("Highlight Rows and get Status", this);
    connect(btm, &QPushButton::clicked, this, &Table::highlightRows);

    getAddresses = new QPushButton("Check Current Adreses",this);
    connect(getAddresses,&QPushButton::clicked,this,&Table::getCurrrentIpInfo);
    subDialog = new QDialog;

    getFlush = new QPushButton("Flush all from Table",this);
    connect(getFlush,&QPushButton::clicked,this,&Table::flushAllFromTable);

    on_addNewRow = new QPushButton("Add new Row",this);
    connect(on_addNewRow,&QPushButton::clicked,this,&Table::addNewRow);

    on_saveChangin = new QPushButton("Save changing in Table",this);
    connect(on_saveChangin,&QPushButton::clicked,this,&Table::saveFileChanging);


    QWidget *topWidget = new QWidget;
    QHBoxLayout *topWidgetLayout = new QHBoxLayout(topWidget);
    topWidgetLayout->addWidget(btm);
    topWidgetLayout->addWidget(getFlush);
    topWidget->setFixedHeight(50);

    //layout = new QBoxLayout;
    layout = new QVBoxLayout;
    layout->addWidget(m_table);
    layout->addWidget(btm);
    layout->addWidget(getAddresses);
    setLayout(layout);
    btm->setFixedHeight(50);
    btm->setFixedWidth(200);
    getFlush->setFixedWidth(200);
    getFlush->setFixedHeight(50);

    on_addNewRow->setFixedHeight(50);
    on_addNewRow->setFixedWidth(200);

    getAddresses->setFixedHeight(50);
    getAddresses->setFixedWidth(200);


    on_saveChangin->setFixedWidth(200);
    on_saveChangin->setFixedHeight(50);

//    this->layout->addWidget(dataUploader);
    this->layout->addWidget(btm);
    this->layout->addWidget(getFlush);
    this->layout->addWidget(on_addNewRow);
    this->layout->addWidget(on_saveChangin);
}


void Table::uploadData()
{
    int rowCount = 0;
    QTextStream in(m_file);
    std::string liner;
    // QTextStream in(m_file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        //line.erase(std::remove(std::begin(line), std::end(line), '\r'), line.end());
        QStringList columns = line.split(" ");
        m_table->insertRow(rowCount + 1);
        QTableWidgetItem* item1 = new QTableWidgetItem(columns[0]);
        m_table->setItem(rowCount, 0, item1);
        ++rowCount;
    }
}

QTextStream& qStdOut()
{
    static QTextStream ts( stdout );
    return ts;
}

void Table::getCurrrentIpInfo()
{
     QVBoxLayout* layoutIp = new QVBoxLayout;


    using boost::asio::ip::tcp;
            boost::asio::io_service io_service;
            tcp::resolver resolver(io_service);
            tcp::resolver::query query(boost::asio::ip::host_name(), "");
            tcp::resolver::iterator iter = resolver.resolve(query);
            tcp::resolver::iterator end; // End marker.
            while (iter != end)
            {
                tcp::endpoint ep = *iter++;
                QLabel* addressLabel = new QLabel("Address: " + QString::fromStdString(ep.address().to_string()));
                QLabel* portLabel = new QLabel("Port: " + QString::number(ep.port()));
                QLabel* Capacity = new QLabel("Capacity: " + QString::number(ep.capacity()));
                layoutIp->addWidget(addressLabel);
                layoutIp->addWidget(portLabel);
                layoutIp->addWidget(Capacity);
                subDialog->setLayout(layoutIp);
            }
        //subDialog->setFixedSize(600,300);
        subDialog->show();
       //if(getAddresses->isChecked())
        //{
         //   subDialog->hide();
        //}


   // layout->addWidget(subDialog);


}




void Table::highlightRows()
{
    int rowCount = 0;
    QTextStream in(m_file);
   //QTextStream in(m_file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        //line.erase(std::remove(std::begin(line), std::end(line), '\r'), line.end());
        QStringList columns = line.split(" ");
        QTableWidgetItem *item2 = new QTableWidgetItem(" --> Invalid Ip");
        QTableWidgetItem *item3 = new QTableWidgetItem(" --> Valid Ip");
        m_table->insertRow(rowCount + 1);
        QTableWidgetItem* item1 = new QTableWidgetItem(columns[0]);
        m_table->setItem(rowCount, 0, item1);
        if(ValidatorIPAddresses::isValidIp(line))
        {
            m_table->item(rowCount,0)->setBackground(QColor(Qt::green));
            m_table->setItem(rowCount,1,item3);
        }
        else
        {
            m_table->item(rowCount,0)->setBackground(QColor(Qt::red));
             m_table->setItem(rowCount,1,item2);
        }
        //показывается что возможно утечка памяти но я не буду писать delete item2,item3
        ++rowCount;
    }
}





    /*QTextStream in(m_file);
    int rowCounts = 0;
    //QString line = in.readLine();
    if(dataUploader)
    {
         //int rowCounts = 0;
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList columns = line.split(" ");
            m_table->insertRow(rowCounts + 1);
           // line.erase(std::remove(std::begin(line), std::end(line), '\r'), line.end());
            if(ValidatorIPAddresses::isValidIp(line))
            {
                m_table->item(rowCounts,0)->setBackground(QColor(Qt::green));
            }
            else
            {
                m_table->item(rowCounts,0)->setBackground(QColor(Qt::red));
            }
            //показывается что возможно утечка памяти но я не буду писать delete item2,item3
        }
        rowCounts++;
    }
*/


void Table::ableUnAbleHighlightRows()
{
    int rowCount = 0;
    QTextStream in(m_file);
    std::string liner;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(ValidatorIPAddresses::isValidIp(line))
        {
            m_table->item(rowCount,0)->setBackground(QColor(Qt::green));
        }
        else
        {
            m_table->item(rowCount,0)->setBackground(QColor(Qt::red));
        }
        //показывается что возможно утечка памяти но я не буду писать delete item2,item3
        ++rowCount;
    }
}





void Table::saveFileChanging()
{
    /*
    QTableWidgetItem *item2 = new QTableWidgetItem(" --> Invalid Ip");
    QTableWidgetItem *item3 = new QTableWidgetItem(" --> Valid Ip");
    delete item2;

    */
}



void Table::addNewRow()
{
    m_table->setRowCount(m_table->rowCount() + 1);
    //good
    //m_table->setColumnCount(m_table->columnCount() + 1);

    //m_table->insertRow(m_table->currentRow() + 1);
}

void Table::flushAllFromTable()
{
    m_table->clearContents();
}


Table::~Table() {
    //m_file->close();
    delete m_table;
}
