#include "WindowSettings.h"

template<> OQSettings::ErrorMessanger* Ogre::Singleton<OQSettings::ErrorMessanger>::msSingleton = 0;
OQSettings::ErrorMessanger* OQSettings::ErrorMessanger::getSingletonPtr(void)
{
	return msSingleton;
}

OQSettings::ErrorMessanger& OQSettings::ErrorMessanger::getSingleton(void)
{  
	assert( msSingleton ); 
	return ( *msSingleton );  
}

template<> OQSettings::SettingsManager* Ogre::Singleton<OQSettings::SettingsManager>::msSingleton = 0;
OQSettings::SettingsManager* OQSettings::SettingsManager::getSingletonPtr(void)
{
	return msSingleton;
}

OQSettings::SettingsManager& OQSettings::SettingsManager::getSingleton(void)
{  
	assert( msSingleton ); 
	return ( *msSingleton );  
}

namespace OQSettings
{
	ErrorMessanger::ErrorMessanger(QWidget *parent)
					: _lastError(NULL)
					, _closeProjectDialog(NULL)
					, _parent(parent)
					, _messageResult(0)
	{
	}

	ErrorMessanger::~ErrorMessanger() 
	{
		delete _lastError;
		_lastError = NULL;

		delete _closeProjectDialog;
		_closeProjectDialog = NULL;
	}

	int ErrorMessanger::showExCloseProjectDialog()
	{
		delete _closeProjectDialog;
		_closeProjectDialog = NULL;

		_closeProjectDialog = new Ui::CloseProjectDialog(_parent);

		return _closeProjectDialog->showDialog(SettingsManager::getSingleton().getProjectsNames());
	}

	int const ErrorMessanger::lastError(int const& code, std::string const& description, std::string const& source, 
										bool const& needShowMessage, DIALOG_TYPE const& dialogType, std::string const& title)
	{
		delete _lastError;
		_lastError = NULL;

		_lastError = new Ogre::Exception(code, description, source);

		printMessage();

		if (needShowMessage)
		{
			return showMessage(dialogType, title);
		}

		return -1;
	}

	void ErrorMessanger::printMessage()
	{
		std::cout << getLastError() << std::endl;

		if (_lastError->getNumber() == ET_CRITICAL)
		{
			std::cout << "Critical error: shutdown!" << std::endl;
			assert(false);
		}
	}

	std::string const ErrorMessanger::getLastError() const
	{
		if (_lastError)
		{
			return _lastError->getFullDescription();
		}

		return "";
	}

	int const ErrorMessanger::showMessage(DIALOG_TYPE const& dialogType, std::string title)
	{
		int result = QMessageBox::No;

		if (dialogType == DT_WARNING_YNC)
		{
			if (title.empty()) 
			{
				title = "Warning";
			}

			result = QMessageBox::warning(NULL, /*tr*/(title.c_str()),
							/*tr*/(_lastError->getDescription().c_str()),
							QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);
		}
		else if (dialogType == DT_WARNING_OC)
		{
			if (title.empty()) 
			{
				title = "Confirm";
			}

			result = QMessageBox::warning(NULL, /*tr*/(title.c_str()),
							/*tr*/(_lastError->getDescription().c_str()),
							QMessageBox::Ok, QMessageBox::Cancel);
		}
		else if (dialogType == DT_WARNING_YN)
		{
			if (title.empty()) 
			{
				title = "Warning";
			}

			result = QMessageBox::warning(NULL, /*tr*/(title.c_str()),
							/*tr*/(_lastError->getDescription().c_str()),
							QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel);
		}
		else if (dialogType == DT_WARNING_O)
		{
			if (title.empty()) 
			{
				title = "Warning";
			}

			result = QMessageBox::warning(NULL, /*tr*/(title.c_str()),
							/*tr*/(_lastError->getDescription().c_str()),
							QMessageBox::Ok);
		}
		else if (dialogType == DT_ERROR_O)
		{
			if (title.empty()) 
			{
				title = "Error";
			}

			result = QMessageBox::critical(NULL, /*tr*/(title.c_str()),
							/*tr*/(_lastError->getFullDescription().c_str()),
							QMessageBox::Ok);
		}

		if (result == QMessageBox::Yes) 
		{
			_messageResult = DR_YES;
		} 
		else if (result == QMessageBox::Ok)
		{
			_messageResult = DR_OK;
		}
		else if (result == QMessageBox::Cancel)
		{
			_messageResult = DR_CANCEL;
		}
		else
		{
			_messageResult = DR_NO;
		}

		return _messageResult;
	}
	










	const std::string ProjectTypeInfo::_projectRootName = "ProjectRoot";
	const std::string ProjectTypeInfo::_emptyName = "";

	const ProjectTypeInfo::ProjectTypeInfoVector ProjectTypeInfo::_allProjectTypesInfo = vlist_of<ProjectTypeInfo::_ProjectTypeInfo>
		(ProjectTypeInfo::_ProjectTypeInfo("EditorSettings", "eproj", "editor"))
		(ProjectTypeInfo::_ProjectTypeInfo("GameProjectSettings", "proj"));





	BaseSettings::BaseSettings(pugi::xml_node &parent) 
		: _created(false)
		, _needShowMessage(false)
		, _parent(parent)
		, _nodeName("")
		, _type("")
		, _ext("")
	{
	}

	BaseSettings::~BaseSettings() {}

	void BaseSettings::defaults()
	{
		_created = false;
	}

	void BaseSettings::clear()
	{
		BaseSettings::defaults();
	}

	bool const BaseSettings::checkFields() const
	{
		if (!_created) return false;

		return false;
	}

	bool const& BaseSettings::createNode()
	{
		if (_created) return _created;

		_node = _parent.append_child(_nodeName.c_str());

		checkError();

		return _created;
	}
		
	bool const BaseSettings::saveNode()
	{
		checkError();

		return _created;
	}

	bool const& BaseSettings::loadNode(pugi::xml_node &node)
	{
		if (_created) return _created;

		_node = node;

		checkError();

		return _created;
	}

	void BaseSettings::checkError()
	{
		if (_created) return;

		if (_node.empty() || _node.name() == "")
		{
			_created = false;

			ErrorMessanger::getSingleton().lastError(ET_ERROR, "Node name or node data cannot be empty. Node name is: " + std::string(_node.name()) + ".", _type + "::checkError()", _needShowMessage, DT_ERROR_O);
		}
		else
		{
			_created = true;
		}
	}


















	EditorSettings::EditorSettings(pugi::xml_node &parent)
		: BaseSettings(parent)
	{
		_type = ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._type;
		_ext = ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._ext;
		setNodeName(_type);
	}

	EditorSettings::~EditorSettings() 
	{}

	void EditorSettings::defaults()
	{
	}

	void EditorSettings::clear()
	{
		BaseSettings::clear();

		defaults();
	}

	bool const EditorSettings::checkFields() const
	{
		//перед проверкой значения полей не должны перезаписываться
		//чтобы можно было вызвать отмену изменений
		/*
		проверям все поля на допустимость значений
		*/

		return false;
	}

	bool const& EditorSettings::createNode()
	{
		if (!BaseSettings::createNode()) return _created;
		//функция создает узел
		/*

		if (_error) return;

		забиваем узел данными по умолчанию
		*/

		return _created;
	}
		
	bool const EditorSettings::saveNode()
	{
		if (!BaseSettings::saveNode()) return _created;
		/*
		сохраняем данные в узел
		*/

		return _created;
	}

	bool const& EditorSettings::loadNode(pugi::xml_node &node)
	{
		if (!BaseSettings::loadNode(node)) return _created;
		/*
		забиваем данные из узла в поля
		*/

		return _created;
	}


















	GameProjectSettings::GameProjectSettings(pugi::xml_node &parent)
		: BaseSettings(parent)
	{
		_type = ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::GameProject]._type;
		_ext = ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::GameProject]._ext;
		setNodeName(_type);

		GameProjectSettings::clear();
	}

	GameProjectSettings::~GameProjectSettings() {}

	void GameProjectSettings::defaults()
	{
		_projectName = "";
		_mode3D = false;
		_pathToProjectFolder = "";
		_currentOS = "";
		_screenSizeInfo.first.min = 320;
		_screenSizeInfo.first.max = 2048;
		_screenSizeInfo.first.current = -1;
		_screenSizeInfo.second.min = 240;
		_screenSizeInfo.second.max = 1536;
		_screenSizeInfo.second.current = -1;
	}

	void GameProjectSettings::clear()
	{
		BaseSettings::clear();

		defaults();
	}

	bool const GameProjectSettings::checkFields() const
	{
		if (_projectName.empty()
			|| _pathToProjectFolder.empty()
			|| _currentOS.empty()
			|| _screenSizeInfo.first.current == -1
			|| _screenSizeInfo.second.current == -1)
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Some field(s) have wrong value(s).", "ProjectSettings::saveNode()", _needShowMessage, DT_WARNING_O);
			return false;
		}

		return true;
	}

	bool const& GameProjectSettings::createNode()
	{
		if (!BaseSettings::createNode()) return _created;

		GameProjectSettings::defaults();

		_node.append_child("Params");
		_node.child("Params").append_attribute("projectName");
		_node.child("Params").append_attribute("pathToProjectFolder");
		_node.child("Params").append_attribute("currentOS");
		_node.child("Params").append_attribute("mode3D");
		_node.child("Params").append_attribute("screenWidth");
		_node.child("Params").append_attribute("screenHeight");

		return _created;
	}
		
	bool const GameProjectSettings::saveNode()
	{
		if (!BaseSettings::saveNode()) return _created;

		if (!GameProjectSettings::checkFields()) 
		{
			return false;
		}

		_node.child("Params").attribute("projectName").set_value(_projectName.c_str());
		_node.child("Params").attribute("pathToProjectFolder").set_value(_pathToProjectFolder.c_str());
		_node.child("Params").attribute("currentOS").set_value(_currentOS.c_str());
		_node.child("Params").attribute("mode3D").set_value(_mode3D);
		_node.child("Params").attribute("screenWidth").set_value(_screenSizeInfo.first.current);
		_node.child("Params").attribute("screenHeight").set_value(_screenSizeInfo.second.current);

		return _created;
	}

	bool const& GameProjectSettings::loadNode(pugi::xml_node &node)
	{
		if (!BaseSettings::loadNode(node)) return _created;
		/*
		забиваем данные из узла в поля
		*/

		pugi::xml_node params = _node.child("Params");

		_projectName = params.attribute("projectName").as_string();
		_pathToProjectFolder = params.attribute("pathToProjectFolder").as_string();
		_currentOS = params.attribute("currentOS").as_string();
		_mode3D = params.attribute("mode3D").as_bool();
		_screenSizeInfo.first.current = params.attribute("screenWidth").as_int(_screenSizeInfo.first.min);
		_screenSizeInfo.second.current = params.attribute("screenHeight").as_int(_screenSizeInfo.second.min);

		return _created;
	}
















	SettingsManager::SettingsManager()
		: _maxNumberOfOpenProjets(2)
		, _minNumberOfOpenProjets(1)
		, _currentNumberOfOpenProjects(0)
		, _needShowMessage(false)
		, _activeProject(ProjectTypeInfo::_emptyName)
	{
		std::string name;
		name = ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._base_filename;
		name += ".";
		name += ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._ext;

		openProject(name);
	}

	SettingsManager::~SettingsManager()
	{
		closeProject(ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._base_filename);
	}

	//Сначала создается пустой проект
	//в который заносится вся необходимая информация
	//
	SettingsManager::ProjectFileInfo* SettingsManager::newProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType)
	{
		bool result = false;

		if (!ProjectTypeInfo::checkProjectType(projectType))
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Wrong project type: " + projectType + ".", "SettingsManager::newProject()", _needShowMessage, DT_WARNING_O);
			return NULL;
		}

		result = addNewProject(projectPath, projectName, projectType);

		if (result)
		{
			if (!initProject(projectType, getProject(projectName)))
			{
				ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't initialise new project with type: " + projectType + ".", "SettingsManager::newProject()", _needShowMessage, DT_WARNING_O);
				return NULL;
			}

			return getProject(projectName);
		}

		return NULL;
	}

	void SettingsManager::closeProject(std::string const& projectName)
	{
		if (_currentNumberOfOpenProjects > _minNumberOfOpenProjets) 
		{
			_currentNumberOfOpenProjects--;
		}
		else if (_currentNumberOfOpenProjects == _minNumberOfOpenProjets)
		{
			return;
		}
		else
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't close project with name: " + projectName + ".", "SettingsManager::closeProject()", _needShowMessage, DT_WARNING_O);
			return;
		}

		delete _projectsMap[projectName]->_settings;
		_projectsMap[projectName]->_settings = NULL;

		_projectsMap[projectName]->_settingsDocument.reset();
		_projectsMap[projectName]->_loaded = false;
		_projectsMap[projectName]->_active = false;
		_projectsMap[projectName]->_filename = ProjectTypeInfo::_emptyName;

		ProjectsMap::iterator project_it = _projectsMap.find(projectName);
		if (project_it != _projectsMap.end())
		{
			delete (*project_it).second;
			(*project_it).second = NULL;
			_projectsMap.erase(project_it);
		}

		if (_projectsMap.size() > 1)
		{
			ProjectsMap::iterator it = _projectsMap.begin();

			if (it->second->_settings->getType() == ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._type)
			{
				it++;
			}

			setActiveProject(it->first);
		}
		else
		{
			setActiveProject(ProjectTypeInfo::_emptyName);
		}
	}

	bool const SettingsManager::closeProjects(bool const& showConfirmDialog)
	{
		int result = DR_NO;
		std::vector<std::string> closableProjects;

		if (showConfirmDialog)
		{
			if (_projectsMap.size() == 1)
			{
				result = DR_NO;
			}
			else
			{
				result = ErrorMessanger::getSingleton().showExCloseProjectDialog();
				closableProjects = ErrorMessanger::getSingleton().getCloseProjectDialog()->getClosedProjects();

				if (result == DR_YES && closableProjects.empty())
				{
					result = DR_CANCEL;
				}
			}
		}

		if (result == DR_YES) //yes
		{
			for (size_t i = 0; i < closableProjects.size(); i++)
			{
				setActiveProject(closableProjects[i]);
				saveProject();
			}
		}
		else if (result == DR_CANCEL) //cancel
		{
			return false;
		} 
		
		if (result == DR_NO && !showConfirmDialog)
		{
			ProjectFileInfo *project = getActiveProject();

			if (project)
			{
				closeProject(project->_projectName);
			}
		}

		for (size_t i = 0; i < closableProjects.size(); i++)
		{
			closeProject(closableProjects[i]);
		}

		return true;
	}

	bool SettingsManager::initProject(std::string const& type, ProjectFileInfo *project)
	{
		project->_settingsDocument.append_child(ProjectTypeInfo::_projectRootName.c_str());
		if (createOrLoadNode(instanceOfProjectSettings(type, project->_settingsDocument.first_child()), project)) return true;

		return false;
	}

	bool const SettingsManager::openProject(std::string const& fileName)
	{
		std::string baseName;
		std::string baseExt;
		std::string path;
		Ogre::StringUtil::splitFullFilename(fileName, baseName, baseExt, path);

		bool result = false;

		std::string projectType = ProjectTypeInfo::getTypeByProjectExt(baseExt);

		if (projectType == ProjectTypeInfo::_emptyName)
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Project type can't be empty.", "SettingsManager::openProject()", _needShowMessage, DT_WARNING_O);
			return result;
		}

		std::string projectName = baseName;

		result = addNewProject(path, projectName, projectType);

		if (!result) 
		{
			return result;
		}

		ProjectFileInfo *project = getProject(projectName);

		project->_parseResult = project->_settingsDocument.load_file(fileName.c_str());

		if (project->_parseResult)
		{
			if (createOrLoadNode(instanceOfProjectSettings(projectType, project->_settingsDocument.first_child()), project))
			{
				project->_filename = fileName;
				project->_projectName = baseName;
				project->_path = path;

				setActiveProject(project->_projectName);
			}
			else
			{
				result = false;
			}
		}
		else
		{
			if (projectType == ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._type)
			{
				if (initProject(projectType, project))
				{
					project->_filename = fileName;
					if (saveProject(project->_projectName))
					{
						ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Editor settings file was not found and was generated.", "SettingsManager::openProject()");
					}
				}
				else
				{
					result = false;
				}
			}
			else
			{
				ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Wrong project type: " + projectType + ".", "SettingsManager::openProject()", _needShowMessage, DT_WARNING_O);
				result = false;
			}
		}

		return result;
	}

	bool const SettingsManager::saveProject(std::string const& projectName)
	{
		bool result = false;

		ProjectFileInfo *project = NULL;
		if (projectName.empty())
		{
			project = getActiveProject();
		}
		else
		{
			project = getProject(projectName);
		}

		if (project && project->_settings)
		{
			if (project->_settings->saveNode())
			{
				if (!project->_settingsDocument.save_file(project->_filename.c_str()))
				{
					ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't save xml to file: " + project->_filename, "SettingsManager::saveProject()", _needShowMessage, DT_WARNING_O);
				}
				else
				{
					result = true;
				}
			}
		}
		else
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Project was not loaded.", "SettingsManager::saveProject()", _needShowMessage, DT_WARNING_O);
		}

		return result;
	}

	bool const SettingsManager::saveAsProject(std::string const& fileName)
	{
		bool result = false;

		if (getActiveProject())
		{
			std::string baseName;
			std::string baseExt;
			std::string basePath;
			Ogre::StringUtil::splitFullFilename(fileName, baseName, baseExt, basePath);

			GameProjectSettings *project = (GameProjectSettings*)getActiveProject()->_settings;
			project->setPathToProjectFolder(basePath);
			project->setProjectName(baseName);

			getActiveProject()->_filename = fileName;

			if (getActiveProject()->_settings->saveNode())
			{
				if (!getActiveProject()->_settingsDocument.save_file(getActiveProject()->_filename.c_str()))
				{
					ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't save xml to file: " + getActiveProject()->_filename, "SettingsManager::saveAsProject()", _needShowMessage, DT_WARNING_O);
				}
				else
				{
					result = true;
				}
			}
		}
		else
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Project was not loaded.", "SettingsManager::saveAsProject()", _needShowMessage, DT_WARNING_O);
		}

		return result;
	}

	bool SettingsManager::addNewProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType)
	{
		bool result = false;

		if (acceptProject())
		{
			result = addProject(projectPath, projectName, projectType);
		}
		else
		{
			if (closeProjects())
			{
				result = addProject(projectPath, projectName, projectType);

				if (result)
				{
					if (_currentNumberOfOpenProjects < _maxNumberOfOpenProjets)
					{
						_currentNumberOfOpenProjects++;
					}
					else
					{
						closeProject(projectName);
						ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't add project with name: " + projectName + ".", "SettingsManager::addNewProject()");
						result = false;
					}
				}
			}
		}

		return result;
	}

	bool SettingsManager::addProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType)
	{
		std::pair<ProjectsMap::iterator, bool> result;

		std::string filename = makeFilename(projectPath, projectName, projectType);

		if (filename.empty())
		{
			return false;
		}

		result = _projectsMap.insert(std::make_pair(projectName, new ProjectFileInfo(filename, projectName)));
		if (!result.second)
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't add project with name: " + projectName + ".", "SettingsManager::addProject()", _needShowMessage, DT_WARNING_O);
		}

		return result.second;
	}

	BaseSettings* SettingsManager::instanceOfProjectSettings(std::string const& projectType, pugi::xml_node &node)
	{
		if (projectType == ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::GameProject]._type)
		{
			return new GameProjectSettings(node);
		}
		else if (projectType == ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._type)
		{
			return new EditorSettings(node);
		}

		ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Wrong project type: " + projectType + ".", "SettingsManager::instanceOfProjectSettings()", _needShowMessage, DT_WARNING_O);
		return NULL;
	}

	bool SettingsManager::createOrLoadNode(BaseSettings *settings, ProjectFileInfo *project)
	{
		bool result = false;

		pugi::xml_node &settingsNode = project->_settingsDocument.find_node(nodeFinder(settings->getType()));
		if (!settingsNode)
		{
			result = settings->createNode();
		}
		else
		{
			result = settings->loadNode(settingsNode);
		}

		if (result)
		{
			project->_loaded = true;
			project->_settings = settings;

			if (project->_settings->getType() != ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._type)
			{
				setActiveProject(project->_projectName);
			}
		}

		return result;
	}

	//setters
	void SettingsManager::setProjectName(std::string const& oldName, std::string const& newName, std::string const& path)
	{
		if (oldName == newName) return;
		if (newName.empty()) return;

		bool found = findProject(oldName);

		if (found)
		{
			_projectsMap[newName] = _projectsMap[oldName];
			_projectsMap.erase(oldName);
			_projectsMap[newName]->_filename = makeFilename(path, newName, _projectsMap[newName]->_settings->getType());
			_projectsMap[newName]->_path = path;
			_projectsMap[newName]->_projectName = newName;
		}
		else
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Project with name: " + oldName + "not found.", "SettingsManager::setProjectName()", _needShowMessage, DT_WARNING_O);
		}
	}

	void SettingsManager::setActiveProject(std::string const& projectName)
	{
		if (findProject(_activeProject))
		{
			_projectsMap[_activeProject]->_active = false;
		}

		if (projectName.empty())
		{
			_activeProject = ProjectTypeInfo::_emptyName;
			return;
		}

		ProjectFileInfo *project = getProject(projectName);

		if (project)
		{
			project->_active = true;
			_activeProject = projectName;
		}
		else
		{
			_activeProject = ProjectTypeInfo::_emptyName;
		}
	}

	//getters
	SettingsManager::ProjectFileInfo* SettingsManager::getProject(std::string const& projectName)
	{
		ProjectsMap::iterator project_it = _projectsMap.find(projectName);
		if (project_it == _projectsMap.end())
		{
			ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Can't find project with name: " + projectName + ".", "SettingsManager::getProject()", _needShowMessage, DT_WARNING_O);
			return NULL;
		}

		return  project_it->second;
	}

	std::vector<std::string> SettingsManager::getProjectsNames()
	{
		std::vector<std::string> result;

		for (ProjectsMap::iterator it = _projectsMap.begin(); it != _projectsMap.end(); ++it)
		{
			if (it->first != ProjectTypeInfo::_allProjectTypesInfo[ProjectTypeInfo::EditorProject]._base_filename)
			{
				result.push_back(it->first);
			}
		}

		return result;
	}
}