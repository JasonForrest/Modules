#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addPage("ololo");
    addPage("ololo3");
    addPage("ololo2");

    removePage("ololo");
    removePage("ololoasdkj");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removePage(std::string const& name)
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        if (ui->tabWidget->tabText(i) == name.c_str())
        {
            ui->tabWidget->removeTab(i);
            return;
        }
    }
}

void MainWindow::addPage(std::string const& name)
{
    ui->tabWidget->addTab(pageTemplate(), name.c_str());
}

QWidget* MainWindow::pageTemplate()
{
    QGridLayout *mainWidgetWorkPlaceLayout = new QGridLayout;
    mainWidgetWorkPlaceLayout->setMargin(0);
    mainWidgetWorkPlaceLayout->setSpacing(3);

    QWidget *newTab = new QWidget;
    newTab->setLayout(mainWidgetWorkPlaceLayout);
    newTab->layout()->setSpacing(3);
    newTab->layout()->setMargin(3);

    QWidget *mainWidget = new QWidget(newTab);
    mainWidget->setLayout(mainWidgetWorkPlaceLayout);
    mainWidget->layout()->setSpacing(3);
    mainWidget->layout()->setMargin(0);

    QScrollArea *workPlaceScrollArea = new QScrollArea(mainWidget);
    QWidget *workPlaceScrollAreaWidget = new QWidget(workPlaceScrollArea);

    return newTab;
}
