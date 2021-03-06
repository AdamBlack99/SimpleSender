QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:LIBS += -lWS2_32

SOURCES += \
    Models/client.cpp \
    Models/model.cpp \
    Models/server.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Models/client.h \
    Models/model.h \
    Models/server.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

SUBDIRS += /models/simplesender/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
