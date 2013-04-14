#include "mainwindow.h"
#include <QtGui/qscrollarea.h>
#include <QtGui/qevent.h>

namespace Ui
{
    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        _mainWindowForm(new FormMainWindow)
    {
        _mainWindowForm->setupUi(this);

		_errorMessanger = new OQSettings::ErrorMessanger(this);
		_settingsManager = new OQSettings::SettingsManager;
		_settingsManager->setNeedShowMessage(true);

		_newProjectDialog = new NewProjectDialog(this);
		
        connect(_mainWindowForm->actionExit, SIGNAL(triggered()), this, SLOT(quitEditor()));
		connect(_mainWindowForm->actionNew, SIGNAL(triggered()), this, SLOT(newProjectDialog()));
		connect(_mainWindowForm->actionOpen, SIGNAL(triggered()), this, SLOT(openProjectDialog()));
		connect(_mainWindowForm->actionSave, SIGNAL(triggered()), this, SLOT(saveProjectDialog()));
		connect(_mainWindowForm->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAsProjectDialog()));
		connect(_mainWindowForm->actionClose, SIGNAL(triggered()), this, SLOT(removePageForRemovedActiveProject()));

		connect(_newProjectDialog, SIGNAL(addProjectPage(std::string)), this, SLOT(addPageForAddedProject(std::string)));
		
		connect(_errorMessanger->getCloseProjectDialog(), SIGNAL(removeProjectPages()), this, SLOT(removePagesForRemovedProjects()));
    }

    MainWindow::~MainWindow()
    {
        delete _mainWindowForm;
		_mainWindowForm = NULL;
		delete _newProjectDialog;
		_newProjectDialog = NULL;
		delete _settingsManager;
		_settingsManager = NULL;
    }

	void MainWindow::newProjectDialog()
	{
		_newProjectDialog->showDialog();
	}

	void MainWindow::openProjectDialog()
	{
		QString dir = QFileDialog::getOpenFileName(	this, tr("Open project"),
													"",
													tr("Project (*.proj)"));

		if (dir.size())
		{
			if (_settingsManager->openProject(dir.toStdString()))
			{
				addPage(_settingsManager->getActiveProject()->_projectName);
			}
		}
	}

	void MainWindow::saveProjectDialog()
	{
		_settingsManager->saveProject();
	}

	void MainWindow::saveAsProjectDialog()
	{
		QString dir = QFileDialog::getOpenFileName(	this, tr("SaveAs project"),
													"",
													tr("Project (*.proj)"));

		if (dir.size())
		{
			_settingsManager->saveAsProject(dir.toStdString());
		}
	}

	void MainWindow::quitEditor()
	{
		close();
	}

	void MainWindow::closeEvent(QCloseEvent *cevent)
	{
		if (_settingsManager->closeProjects())
		{
			QMainWindow::closeEvent(cevent);
		}
		else
		{
			cevent->ignore();
		}
	}

	void MainWindow::removePage(std::string const& name)
	{
		for (int i = 0; i < _mainWindowForm->tabProjectPages->count(); i++)
		{
			if (_mainWindowForm->tabProjectPages->tabText(i) == name.c_str())
			{
				_mainWindowForm->tabProjectPages->removeTab(i);
				return;
			}
		}
	}

	void MainWindow::addPage(std::string const& name)
	{
		//_mainWindowForm->tabProjectPages->addTab(pageTemplate(name), name.c_str());

    QWidget *window = new QWidget;
 
    //window->resize(800, 600);
    //window->setWindowTitle("Simple example");

	_mainWindowForm->tabProjectPages->addTab(window, "OLOLO");
 
    QtOgre::OgreWidget* ogreWidget = new QtOgre::OgreWidget;
 
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ogreWidget);
 
    window->setLayout(layout);
    //window->show();
	}

	QWidget* MainWindow::pageTemplate(std::string const& name)
	{    
		QWidget *newTab = new QWidget();
		newTab->setObjectName(QString("newTab_") + name.c_str());
    
		QGridLayout *newTabLayout = new QGridLayout(newTab);
		newTabLayout->setSpacing(3);
		newTabLayout->setObjectName(QString("newTabLayout_") + name.c_str());
		newTabLayout->setContentsMargins(3, 3, 3, 3);
    
		QWidget *mainWidget = new QWidget(newTab);
		mainWidget->setObjectName(QString("mainWidget_") + name.c_str());
    
		QGridLayout *mainWidgetLayout = new QGridLayout(mainWidget);
		mainWidgetLayout->setSpacing(3);
		mainWidgetLayout->setObjectName(QString("mainWidgetLayout_") + name.c_str());
		mainWidgetLayout->setContentsMargins(0, 0, 0, 0);
    
		QGridLayout *mainWidgetWorkPlaceLayout = new QGridLayout(); 
		mainWidgetWorkPlaceLayout->setSpacing(3);
		mainWidgetWorkPlaceLayout->setObjectName(QString("mainWidgetWorkPlaceLayout_") + name.c_str());
    
		QScrollArea *workPlaceScrollArea = new QScrollArea(mainWidget);
		workPlaceScrollArea->setObjectName(QString("workPlaceScrollArea_") + name.c_str());
		workPlaceScrollArea->setWidgetResizable(false);
    
		QWidget *workPlaceScrollAreaWidget = new QWidget();
		workPlaceScrollAreaWidget->setObjectName(QString("workPlaceScrollAreaWidget_") + name.c_str());

		OQSettings::GameProjectSettings *project = (OQSettings::GameProjectSettings*)_settingsManager->getActiveProject()->_settings;
		int width = project->getScreenWidth();
		int height = project->getScreenHeight();
		workPlaceScrollAreaWidget->setGeometry(QRect(0, 0, width, height));
    
		workPlaceScrollArea->setWidget(workPlaceScrollAreaWidget);

		mainWidgetWorkPlaceLayout->addWidget(workPlaceScrollArea, 0, 0, 1, 1);

		mainWidgetLayout->addLayout(mainWidgetWorkPlaceLayout, 0, 0, 1, 1);
		newTabLayout->addWidget(mainWidget, 0, 0, 1, 1);

		return newTab;
	}

	void MainWindow::addPageForAddedProject(std::string name)
	{
		addPage(name);
	}

	void MainWindow::removePageForRemovedActiveProject()
	{
		std::string activeProjectName(_settingsManager->getActiveProject()->_projectName);
		if (_settingsManager->closeActiveProject())
		{
			removePage(activeProjectName);
		}
	}

	void MainWindow::removePagesForRemovedProjects()
	{
		for (size_t i = 0; i < _errorMessanger->getCloseProjectDialog()->getClosableProjects().size(); i++)
		{
			removePage(_errorMessanger->getCloseProjectDialog()->getClosableProjects()[i]);
		}
	}
}