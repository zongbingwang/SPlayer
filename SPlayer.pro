#-------------------------------------------------
#
# Project created by QtCreator 2016-06-30T14:49:03
#
#-------------------------------------------------

QT       += core gui
QT       += phonon

TARGET = SPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    skin.cpp \
    player.cpp \
    tabtest.cpp \
    media.cpp \
    videolist.cpp \
    setting.cpp

HEADERS  += mainwindow.h \
    skin.h \
    player.h \
    tabtest.h \
    media.h \
    videolist.h \
    gif.h \
    setting.h

FORMS    += mainwindow.ui \
    skin.ui \
    player.ui \
    tabtest.ui \
    setting.ui

RESOURCES += \
    img.qrc

OTHER_FILES += \
    my.qss \
    my1.qss \
    my2.qss \
    my3.qss \
    my4.qss \
    my5.qss
