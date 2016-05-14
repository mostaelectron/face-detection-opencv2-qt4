#-------------------------------------------------
#
# Project created by QtCreator 2012-12-22T14:42:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = detect_face
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += C:\OpenCV2.2MinGw\include\

LIBS += -LC:\OpenCV2.2MinGw\bin \
    -lopencv_core220 \
    -lopencv_highgui220 \
    -lopencv_imgproc220 \
    -lopencv_features2d220 \
    -lopencv_calib3d220 \
    -lopencv_objdetect220
