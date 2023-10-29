QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT+=sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admincfwindow.cpp \
    adminrswindow.cpp \
    adminwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mycfsql.cpp \
    reservewindow.cpp \
    roomwindow.cpp \
    signwindow.cpp \
    usercfwindow.cpp \
    userrswindow.cpp \
    userwindow.cpp

HEADERS += \
    admincfwindow.h \
    adminrswindow.h \
    adminwindow.h \
    mainwindow.h \
    mycfsql.h \
    reservewindow.h \
    roomwindow.h \
    signwindow.h \
    usercfwindow.h \
    userrswindow.h \
    userwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
