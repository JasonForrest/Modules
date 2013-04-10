/********************************************************************************
** Form generated from reading UI file 'closeprojectdialog.ui'
**
** Created: Wed 10. Apr 01:17:35 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCLOSEPROJECTDIALOG_H
#define UI_FORMCLOSEPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

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
            FormCloseProjectDialog->setObjectName(QStringLiteral("FormCloseProjectDialog"));
        FormCloseProjectDialog->setWindowModality(Qt::WindowModal);
        FormCloseProjectDialog->resize(480, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormCloseProjectDialog->sizePolicy().hasHeightForWidth());
        FormCloseProjectDialog->setSizePolicy(sizePolicy);
        FormCloseProjectDialog->setMinimumSize(QSize(480, 320));
        verticalLayout = new QVBoxLayout(FormCloseProjectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        layoutList = new QVBoxLayout();
        layoutList->setObjectName(QStringLiteral("layoutList"));
        labelCloseProjects = new QLabel(FormCloseProjectDialog);
        labelCloseProjects->setObjectName(QStringLiteral("labelCloseProjects"));

        layoutList->addWidget(labelCloseProjects);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        treeProjects = new QTreeWidget(FormCloseProjectDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeProjects->setHeaderItem(__qtreewidgetitem);
        treeProjects->setObjectName(QStringLiteral("treeProjects"));
        treeProjects->setColumnCount(1);
        treeProjects->header()->setVisible(false);
        treeProjects->header()->setDefaultSectionSize(100);

        horizontalLayout->addWidget(treeProjects);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        buttonRemoveProject = new QPushButton(FormCloseProjectDialog);
        buttonRemoveProject->setObjectName(QStringLiteral("buttonRemoveProject"));

        verticalLayout_2->addWidget(buttonRemoveProject);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        layoutList->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        checkboxCheckAll = new QCheckBox(FormCloseProjectDialog);
        checkboxCheckAll->setObjectName(QStringLiteral("checkboxCheckAll"));

        horizontalLayout_2->addWidget(checkboxCheckAll);


        layoutList->addLayout(horizontalLayout_2);

        labelSavAndClose = new QLabel(FormCloseProjectDialog);
        labelSavAndClose->setObjectName(QStringLiteral("labelSavAndClose"));

        layoutList->addWidget(labelSavAndClose);

        layoutButtons = new QGridLayout();
        layoutButtons->setObjectName(QStringLiteral("layoutButtons"));
        buttonCancel = new QPushButton(FormCloseProjectDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));

        layoutButtons->addWidget(buttonCancel, 0, 3, 1, 1);

        buttonYes = new QPushButton(FormCloseProjectDialog);
        buttonYes->setObjectName(QStringLiteral("buttonYes"));

        layoutButtons->addWidget(buttonYes, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutButtons->addItem(horizontalSpacer, 0, 0, 1, 1);

        buttonNo = new QPushButton(FormCloseProjectDialog);
        buttonNo->setObjectName(QStringLiteral("buttonNo"));

        layoutButtons->addWidget(buttonNo, 0, 2, 1, 1);


        layoutList->addLayout(layoutButtons);


        verticalLayout->addLayout(layoutList);


        retranslateUi(FormCloseProjectDialog);

        QMetaObject::connectSlotsByName(FormCloseProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *FormCloseProjectDialog)
    {
        FormCloseProjectDialog->setWindowTitle(QApplication::translate("FormCloseProjectDialog", "Close projets", 0));
        labelCloseProjects->setText(QApplication::translate("FormCloseProjectDialog", "Select the projects that you want to close:", 0));
        buttonRemoveProject->setText(QApplication::translate("FormCloseProjectDialog", "Remove", 0));
        checkboxCheckAll->setText(QApplication::translate("FormCloseProjectDialog", "Check all", 0));
        labelSavAndClose->setText(QApplication::translate("FormCloseProjectDialog", "Save and close selected projects?", 0));
        buttonCancel->setText(QApplication::translate("FormCloseProjectDialog", "Cancel", 0));
        buttonYes->setText(QApplication::translate("FormCloseProjectDialog", "Yes", 0));
        buttonNo->setText(QApplication::translate("FormCloseProjectDialog", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class FormCloseProjectDialog: public Ui_FormCloseProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCLOSEPROJECTDIALOG_H
