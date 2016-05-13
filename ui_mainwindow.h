/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 10. Aug 23:10:11 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *org_img;
    QLabel *gray_img;
    QLabel *gray_img_;
    QLabel *des_img;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(631, 422);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        org_img = new QLabel(centralWidget);
        org_img->setObjectName(QString::fromUtf8("org_img"));

        gridLayout->addWidget(org_img, 0, 0, 1, 1);

        gray_img = new QLabel(centralWidget);
        gray_img->setObjectName(QString::fromUtf8("gray_img"));

        gridLayout->addWidget(gray_img, 0, 1, 1, 1);

        gray_img_ = new QLabel(centralWidget);
        gray_img_->setObjectName(QString::fromUtf8("gray_img_"));

        gridLayout->addWidget(gray_img_, 1, 0, 1, 1);

        des_img = new QLabel(centralWidget);
        des_img->setObjectName(QString::fromUtf8("des_img"));

        gridLayout->addWidget(des_img, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Detect Face OpenCV+Qt", 0, QApplication::UnicodeUTF8));
        org_img->setText(QApplication::translate("MainWindow", "image1", 0, QApplication::UnicodeUTF8));
        gray_img->setText(QApplication::translate("MainWindow", "image2", 0, QApplication::UnicodeUTF8));
        gray_img_->setText(QApplication::translate("MainWindow", "image3", 0, QApplication::UnicodeUTF8));
        des_img->setText(QApplication::translate("MainWindow", "image1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
