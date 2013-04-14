/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 14. Apr 20:17:35 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAINWINDOW_H
#define UI_FORMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMainWindow
{
public:
    QAction *actionNew;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionClose;
    QWidget *centralWidget;
    QGridLayout *centralLayout;
    QTabWidget *tabProjectPages;
    QMenuBar *mainMenuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *mainStatusBar;

    void setupUi(QMainWindow *FormMainWindow)
    {
        if (FormMainWindow->objectName().isEmpty())
            FormMainWindow->setObjectName(QString::fromUtf8("FormMainWindow"));
        FormMainWindow->resize(886, 674);
        actionNew = new QAction(FormMainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSaveAs = new QAction(FormMainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionExit = new QAction(FormMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSave = new QAction(FormMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(true);
        actionOpen = new QAction(FormMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setEnabled(true);
        actionClose = new QAction(FormMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralWidget = new QWidget(FormMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralLayout = new QGridLayout(centralWidget);
        centralLayout->setSpacing(3);
        centralLayout->setContentsMargins(11, 11, 11, 11);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        centralLayout->setContentsMargins(3, 3, 3, 3);
        tabProjectPages = new QTabWidget(centralWidget);
        tabProjectPages->setObjectName(QString::fromUtf8("tabProjectPages"));

        centralLayout->addWidget(tabProjectPages, 0, 0, 1, 1);

        FormMainWindow->setCentralWidget(centralWidget);
        mainMenuBar = new QMenuBar(FormMainWindow);
        mainMenuBar->setObjectName(QString::fromUtf8("mainMenuBar"));
        mainMenuBar->setGeometry(QRect(0, 0, 886, 21));
        menuFile = new QMenu(mainMenuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        FormMainWindow->setMenuBar(mainMenuBar);
        mainToolBar = new QToolBar(FormMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FormMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        mainStatusBar = new QStatusBar(FormMainWindow);
        mainStatusBar->setObjectName(QString::fromUtf8("mainStatusBar"));
        FormMainWindow->setStatusBar(mainStatusBar);

        mainMenuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(FormMainWindow);

        QMetaObject::connectSlotsByName(FormMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FormMainWindow)
    {
        FormMainWindow->setWindowTitle(QApplication::translate("FormMainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("FormMainWindow", "New...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("FormMainWindow", "Save as...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("FormMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("FormMainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("FormMainWindow", "Open...", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("FormMainWindow", "Close", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("FormMainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormMainWindow: public Ui_FormMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAINWINDOW_H
