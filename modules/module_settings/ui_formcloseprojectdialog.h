/********************************************************************************
** Form generated from reading UI file 'closeprojectdialog.ui'
**
** Created: Sun 14. Apr 20:17:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCLOSEPROJECTDIALOG_H
#define UI_FORMCLOSEPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FormCloseProjectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layoutList;
    QLabel *labelCloseProjects;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeProjects;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonRemoveProject;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkboxCheckAll;
    QLabel *labelSavAndClose;
    QGridLayout *layoutButtons;
    QPushButton *buttonCancel;
    QPushButton *buttonYes;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonNo;

    void setupUi(QDialog *FormCloseProjectDialog)
    {
        if (FormCloseProjectDialog->objectName().isEmpty())
            FormCloseProjectDialog->setObjectName(QString::fromUtf8("FormCloseProjectDialog"));
        FormCloseProjectDialog->setWindowModality(Qt::WindowModal);
        FormCloseProjectDialog->resize(480, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormCloseProjectDialog->sizePolicy().hasHeightForWidth());
        FormCloseProjectDialog->setSizePolicy(sizePolicy);
        FormCloseProjectDialog->setMinimumSize(QSize(480, 320));
        verticalLayout = new QVBoxLayout(FormCloseProjectDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        layoutList = new QVBoxLayout();
        layoutList->setObjectName(QString::fromUtf8("layoutList"));
        labelCloseProjects = new QLabel(FormCloseProjectDialog);
        labelCloseProjects->setObjectName(QString::fromUtf8("labelCloseProjects"));

        layoutList->addWidget(labelCloseProjects);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        treeProjects = new QTreeWidget(FormCloseProjectDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeProjects->setHeaderItem(__qtreewidgetitem);
        treeProjects->setObjectName(QString::fromUtf8("treeProjects"));
        treeProjects->setColumnCount(1);
        treeProjects->header()->setVisible(false);
        treeProjects->header()->setDefaultSectionSize(100);

        horizontalLayout->addWidget(treeProjects);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        buttonRemoveProject = new QPushButton(FormCloseProjectDialog);
        buttonRemoveProject->setObjectName(QString::fromUtf8("buttonRemoveProject"));

        verticalLayout_2->addWidget(buttonRemoveProject);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        layoutList->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        checkboxCheckAll = new QCheckBox(FormCloseProjectDialog);
        checkboxCheckAll->setObjectName(QString::fromUtf8("checkboxCheckAll"));

        horizontalLayout_2->addWidget(checkboxCheckAll);


        layoutList->addLayout(horizontalLayout_2);

        labelSavAndClose = new QLabel(FormCloseProjectDialog);
        labelSavAndClose->setObjectName(QString::fromUtf8("labelSavAndClose"));

        layoutList->addWidget(labelSavAndClose);

        layoutButtons = new QGridLayout();
        layoutButtons->setObjectName(QString::fromUtf8("layoutButtons"));
        buttonCancel = new QPushButton(FormCloseProjectDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        layoutButtons->addWidget(buttonCancel, 0, 3, 1, 1);

        buttonYes = new QPushButton(FormCloseProjectDialog);
        buttonYes->setObjectName(QString::fromUtf8("buttonYes"));

        layoutButtons->addWidget(buttonYes, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer, 0, 0, 1, 1);

        buttonNo = new QPushButton(FormCloseProjectDialog);
        buttonNo->setObjectName(QString::fromUtf8("buttonNo"));

        layoutButtons->addWidget(buttonNo, 0, 2, 1, 1);


        layoutList->addLayout(layoutButtons);


        verticalLayout->addLayout(layoutList);


        retranslateUi(FormCloseProjectDialog);

        QMetaObject::connectSlotsByName(FormCloseProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *FormCloseProjectDialog)
    {
        FormCloseProjectDialog->setWindowTitle(QApplication::translate("FormCloseProjectDialog", "Close projets", 0, QApplication::UnicodeUTF8));
        labelCloseProjects->setText(QApplication::translate("FormCloseProjectDialog", "Select the projects that you want to close:", 0, QApplication::UnicodeUTF8));
        buttonRemoveProject->setText(QApplication::translate("FormCloseProjectDialog", "Remove", 0, QApplication::UnicodeUTF8));
        checkboxCheckAll->setText(QApplication::translate("FormCloseProjectDialog", "Check all", 0, QApplication::UnicodeUTF8));
        labelSavAndClose->setText(QApplication::translate("FormCloseProjectDialog", "Save and close selected projects?", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("FormCloseProjectDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonYes->setText(QApplication::translate("FormCloseProjectDialog", "Yes", 0, QApplication::UnicodeUTF8));
        buttonNo->setText(QApplication::translate("FormCloseProjectDialog", "No", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormCloseProjectDialog: public Ui_FormCloseProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCLOSEPROJECTDIALOG_H
