#pragma once
#include <QTableWidget>
#include <QWidget>
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QPushButton>

class Table : public QDialog {
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
     ~Table();
    //void addNewRow();
public slots:
    void uploadData();
    void saveFileChanging();
    void addNewRow();
    void highlightRows();
    void flushAllFromTable();
    void ableUnAbleHighlightRows();
    //void GetStatusOfValidate();

private:
    QTableWidget* m_table;
    QFile* m_file;
    QVBoxLayout* layout;
    QPushButton* btm;
    QPushButton* dataUploader;
    QPushButton* getFlush;
    QPushButton* on_addNewRow;
    QPushButton* on_saveChangin;
};
