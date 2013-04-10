#include "mainwindow.h"

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

		_tempEdit = new QPlainTextEdit(this);
		_tempEdit->setGeometry(40, 60, 600, 600);
    }

    MainWindow::~MainWindow()
    {
		delete _tempEdit;
		_tempEdit = NULL;

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
			_settingsManager->openProject(dir.toStdString());
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
}
