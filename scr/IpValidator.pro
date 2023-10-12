QT += widgets
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += D:/boost/boost_1_82_0
LIBS += "-LD:/boost/boost_1_82_0/libs"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DefineTableCls.cpp \
    HighLighterColumns.cpp \
    ValidatorDefine.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ReadFromFile.h \
    TableCls.h \
    ValidatorCls.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
