QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_plant.cpp \
    basic_widget.cpp \
    basic_zombie.cpp \
    battlewindow.cpp \
    grid.cpp \
    main.cpp \
    mainwindow.cpp \
    pea.cpp \
    peashooter.cpp \
    seedbank.cpp \
    seedpacket.cpp \
    shovelbank.cpp \
    sun.cpp \
    zombie.cpp

HEADERS += \
    basic_plant.h \
    basic_widget.h \
    basic_zombie.h \
    battlewindow.h \
    config.h \
    grid.h \
    mainwindow.h \
    pea.h \
    peashooter.h \
    seedbank.h \
    seedpacket.h \
    shovelbank.h \
    sun.h \
    zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
