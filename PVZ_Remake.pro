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
    bucketzombie.cpp \
    cherrybomb.cpp \
    coffeebean.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    button.cpp \
    grid.cpp \
    main.cpp \
    mainwindow.cpp \
    mushroom.cpp \
    pea.cpp \
    peashooter.cpp \
    plant_card.cpp \
    plantselectwindow.cpp \
    potatomine.cpp \
    puff.cpp \
    puffshroom.cpp \
    repeater.cpp \
    screenzombie.cpp \
    sunflower.cpp \
    sunshroom.cpp \
    switchbutton.cpp \
    text.cpp \
    selection_button.cpp\
    seedbank.cpp \
    seedpacket.cpp \
    shovelbank.cpp \
    sun.cpp \
    wallnut.cpp \
    zombie.cpp



HEADERS += \
    basic_plant.h \
    basic_widget.h \
    basic_zombie.h \
    battlewindow.h \
    bucketzombie.h \
    cherrybomb.h \
    coffeebean.h \
    conezombie.h \
    button.h \
    config.h \
    footballzombie.h \
    grid.h \
    mainwindow.h \
    mushroom.h \
    pea.h \
    peashooter.h \
    plantselectwindow.h \
    potatomine.h \
    puff.h \
    puffshroom.h \
    repeater.h \
    screenzombie.h \
    sunflower.h \
    sunshroom.h \
    wallnut.h \
    switchbutton.h \
    zombie.h \
    plant_card.h \
    text.h \
    selection_button.h\
    seedbank.h \
    seedpacket.h \
    shovelbank.h \
    sun.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
