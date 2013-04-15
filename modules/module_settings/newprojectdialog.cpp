#include "newprojectdialog.h"

namespace Ui
{
    NewProjectDialog::NewProjectDialog(QWidget *parent)
        : QDialog(parent)
        , _newProjectDialogForm(new FormNewProjectDialog)
    {
        _newProjectDialogForm->setupUi(this);

		_newProjectDialogForm->buttonOk->setEnabled(false);

		_sizes["320x240"] = QPoint(320, 240);
		_sizes["480x640"] = QPoint(480, 640);
		_sizes["800x600"] = QPoint(800, 600);
		_sizes["960x640"] = QPoint(960, 640);
		_sizes["1024x768"] = QPoint(1024, 768);
		_sizes["1136x640"] = QPoint(1136, 640);
		_sizes["1280x720"] = QPoint(1280, 720);
		_sizes["1600x900"] = QPoint(1600, 900);
		_sizes["1980x1080"] = QPoint(1980, 1080);
		_sizes["2048x1536"] = QPoint(2048, 1536);

		_newProjectDialogForm->comboboxSceernSize->addItem("320x240", QVariant(_sizes["320x240"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("480x640", QVariant(_sizes["480x640"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("800x600", QVariant(_sizes["800x600"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("960x640", QVariant(_sizes["960x640"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("1024x768", QVariant(_sizes["1024x768"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("1136x640", QVariant(_sizes["1136x640"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("1280x720", QVariant(_sizes["1280x720"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("1600x900", QVariant(_sizes["1600x900"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("1980x1080", QVariant(_sizes["1980x1080"]));
		_newProjectDialogForm->comboboxSceernSize->addItem("2048x1536", QVariant(_sizes["2048x1536"]));
		_newProjectDialogForm->comboboxSceernSize->setCurrentIndex(0);

		_newProjectDialogForm->comboboxCurrentOS->addItem("Windows");
		_newProjectDialogForm->comboboxCurrentOS->addItem("Windows8");
		_newProjectDialogForm->comboboxCurrentOS->addItem("Linux");
		_newProjectDialogForm->comboboxCurrentOS->addItem("Android");
		_newProjectDialogForm->comboboxCurrentOS->addItem("iOS");
		_newProjectDialogForm->comboboxCurrentOS->setCurrentIndex(0);

		_newProjectDialogForm->comboboxProjectType->addItem("Game", QVariant(QString(OQSettings::ProjectTypeInfo::_allProjectTypesInfo[OQSettings::ProjectTypeInfo::GameProject]._type.c_str())));
		_newProjectDialogForm->comboboxProjectType->setCurrentIndex(0);

		connect(_newProjectDialogForm->buttonOk, SIGNAL(clicked()), this, SLOT(setSettings()));
		connect(_newProjectDialogForm->buttonCancel, SIGNAL(clicked()), this, SLOT(close()));
		connect(_newProjectDialogForm->checkboxScreenSizeByHand, SIGNAL(toggled(bool)), this, SLOT(modeToggled(bool)));

		connect(_newProjectDialogForm->buttonPathToProjectFolder, SIGNAL(clicked()), this, SLOT(openFolderDialog()));

		connect(_newProjectDialogForm->editPathToProjectFolder, SIGNAL(textChanged(QString)), this, SLOT(enableOkButton()));
		connect(_newProjectDialogForm->editProjectName, SIGNAL(textChanged(QString)), this, SLOT(enableOkButton()));
    }

    NewProjectDialog::~NewProjectDialog()
    {
        delete _newProjectDialogForm;
		_newProjectDialogForm = NULL;
    }

	void NewProjectDialog::resetFields()
	{
		_newProjectDialogForm->editPathToProjectFolder->setText("");
		_newProjectDialogForm->editProjectName->setText("");
		_newProjectDialogForm->checkbox3DMode->setChecked(false);
		_newProjectDialogForm->checkboxScreenSizeByHand->setChecked(false);
		_newProjectDialogForm->spinboxScreenSizeWidth->setValue(_newProjectDialogForm->comboboxSceernSize->itemData(0).toPoint().x());
		_newProjectDialogForm->spinboxScreenSizeHeight->setValue(_newProjectDialogForm->comboboxSceernSize->itemData(0).toPoint().y());
		_newProjectDialogForm->comboboxSceernSize->setCurrentIndex(0);
		_newProjectDialogForm->comboboxCurrentOS->setCurrentIndex(0);
		_newProjectDialogForm->comboboxProjectType->setCurrentIndex(0);
	}

	void NewProjectDialog::setSettings()
	{
		OQSettings::SettingsManager *settingsManager = OQSettings::SettingsManager::getSingletonPtr();

		if (!settingsManager) return;

		OQSettings::SettingsManager::ProjectFileInfo *justCreatedProject = settingsManager->newProject(	_newProjectDialogForm->editPathToProjectFolder->text().toStdString(),
																										_newProjectDialogForm->editProjectName->text().toStdString(),
																										_newProjectDialogForm->comboboxProjectType->itemData(_newProjectDialogForm->comboboxProjectType->currentIndex()).toString().toStdString());
		if (!justCreatedProject) return;

		OQSettings::GameProjectSettings *projectSettings = (OQSettings::GameProjectSettings*)justCreatedProject->getProjectBaseSettings();
		projectSettings->setNeedShowMessage(true);

		projectSettings->setProjectName(_newProjectDialogForm->editProjectName->text().toStdString());
		projectSettings->setPathToProjectFolder(_newProjectDialogForm->editPathToProjectFolder->text().toStdString());

		projectSettings->setCurrentOS(_newProjectDialogForm->comboboxCurrentOS->itemText(_newProjectDialogForm->comboboxSceernSize->currentIndex()).toStdString());

		projectSettings->setMode3D(_newProjectDialogForm->checkbox3DMode->isChecked());

		int height = -1;
		int width = -1;
		bool syzeByHand = _newProjectDialogForm->checkboxScreenSizeByHand->isChecked();
		if (syzeByHand)
		{
			height = _newProjectDialogForm->spinboxScreenSizeHeight->value();
			width = _newProjectDialogForm->spinboxScreenSizeWidth->value();
		}
		else
		{
			QVariant size = _newProjectDialogForm->comboboxSceernSize->itemData(_newProjectDialogForm->comboboxSceernSize->currentIndex());
			width = size.toPoint().x();
			height = size.toPoint().y();
		}

		if (height != -1 && width != -1)
		{
			int minW = projectSettings->getScreenSizeInfo().first.min;
			int maxW = projectSettings->getScreenSizeInfo().first.max;
			int minH = projectSettings->getScreenSizeInfo().second.min;
			int maxH = projectSettings->getScreenSizeInfo().second.max;
			if (width < minW)
			{
				width = minW;
			}
			else if (width > maxW)
			{
				width = minW;
			}

			if (height < minH)
			{
				height = minH;
			}
			else if (height > maxH)
			{
				height = maxH;
			}
		}

		projectSettings->setScreenHeight(height);
		projectSettings->setScreenWidth(width);

		if (settingsManager->saveProject(projectSettings->getProjectName()))
		{
			settingsManager->setActiveProject(projectSettings->getProjectName());
			Q_EMIT addProjectPage(projectSettings->getProjectName());
			close();
		}
		else
		{
			settingsManager->closeProject(justCreatedProject->_projectName);
		}
	}

	void NewProjectDialog::enableOkButton()
	{
		if (_newProjectDialogForm->editPathToProjectFolder->text().size()
			&& _newProjectDialogForm->editProjectName->text().size())
		{
			_newProjectDialogForm->buttonOk->setEnabled(true);
		}
		else
		{
			_newProjectDialogForm->buttonOk->setEnabled(false);
		}
	}

	void NewProjectDialog::showDialog()
	{
		resetFields();
		show();
	}

	void NewProjectDialog::modeToggled(bool checked)
	{
		if (checked)
		{
			_newProjectDialogForm->comboboxSceernSize->setEnabled(false);
			_newProjectDialogForm->spinboxScreenSizeHeight->setEnabled(true);
			_newProjectDialogForm->spinboxScreenSizeWidth->setEnabled(true);
		}
		else
		{
			_newProjectDialogForm->comboboxSceernSize->setEnabled(true);
			_newProjectDialogForm->spinboxScreenSizeHeight->setEnabled(false);
			_newProjectDialogForm->spinboxScreenSizeWidth->setEnabled(false);
		}
	}

	void NewProjectDialog::openFolderDialog()
	{
		QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
														"",
														QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

		if (dir.size())
		{
			dir += "/";
			_newProjectDialogForm->editPathToProjectFolder->setText(dir);
		}
	}
}
