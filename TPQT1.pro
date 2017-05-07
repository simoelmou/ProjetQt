#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T16:52:03
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPQT1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    ajouterpatientdialog.cpp \
    ajoutpersonneldialog.cpp \
    aboutdialog.cpp \
    patient.cpp \
    patienttablemodel.cpp \
    personneltreemodel.cpp \
    ressource.cpp \
    compte.cpp \
    consultation.cpp \
    dbmanager.cpp \
    c_init_bd.cpp \
    type.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    ajouterpatientdialog.h \
    ajoutpersonneldialog.h \
    aboutdialog.h \
    patient.h \
    patienttablemodel.h \
    personneltreemodel.h \
    ressource.h \
    compte.h \
    consultation.h \
    dbmanager.h \
    c_init_bd.h \
    type.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    ajouterpatientdialog.ui \
    ajoutpersonneldialog.ui \
    aboutdialog.ui

RESOURCES += \
    images.qrc
