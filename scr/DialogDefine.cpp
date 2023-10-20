#include <QDialog>
#include <QtGui>
#include <QPushButton>

class Dialog : public QDialog
{
public:
    Dialog()
    {
        QDialog *subDialog = new QDialog;
        subDialog->setWindowTitle("Sub Dialog");
        QPushButton *button = new QPushButton("Push to open new dialog", this);
        connect(button, SIGNAL(clicked()), subDialog, SLOT(show()));
    }
};
