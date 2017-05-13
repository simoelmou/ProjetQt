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
        view/mainwindow.cpp \
        view/logindialog.cpp \
        view/ajouterpatientdialog.cpp \
        view/ajoutpersonneldialog.cpp \
        view/aboutdialog.cpp \
        model/patient.cpp \
        model/patienttablemodel.cpp \
        model/personneltreemodel.cpp \
        model/ressource.cpp \
        model/compte.cpp \
        model/consultation.cpp \
        data/dbmanager.cpp \
        data/c_init_bd.cpp \
        model/type.cpp

HEADERS  += view/mainwindow.h \
        view/logindialog.h \
        view/ajouterpatientdialog.h \
        view/ajoutpersonneldialog.h \
        view/aboutdialog.h \
        model/patient.h \
        model/patienttablemodel.h \
        model/personneltreemodel.h \
        model/ressource.h \
        model/compte.h \
        model/consultation.h \
        data/dbmanager.h \
        data/c_init_bd.h \
        model/type.h

FORMS    += view/mainwindow.ui \
        view/logindialog.ui \
        view/ajouterpatientdialog.ui \
        view/ajoutpersonneldialog.ui \
        view/aboutdialog.ui

RESOURCES += \
        images.qrc
