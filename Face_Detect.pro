#-------------------------------------------------
#
# Project created by QtCreator 2013-08-10T11:55:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Face_Detect
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDEPATH += C:\opencv2.3.1_mingw\include
LIBS += -LC:\\opencv2.3.1_mingw\bin\
    -lopencv_core231 \
    -lopencv_highgui231 \
    -lopencv_imgproc231 \
    -lopencv_features2d231 \
    -lopencv_calib3d231 \
    -lopencv_objdetect231 \
    -lopencv_video231\
    -lopencv_ml231\
    -lopencv_legacy231\
    -lopencv_gpu231\
    -lopencv_flann231\

