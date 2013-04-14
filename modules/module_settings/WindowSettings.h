#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <pugixml.hpp>
#include <string>
#include <map>
#include <OGRE\Ogre.h>
#include <QtGui\QApplication>
#include <QtGui\qmessagebox.h>
#include "closeprojectdialog.h"

namespace OQSettings
{
	template<class T>
	struct tValue
	{
		T min;
		T current;
		T max;
	};

	template<class T>
	struct dValue
	{
		T def;
		T value;
	};
	typedef std::pair< tValue<int>, tValue<int> > iValueSizeInfo;

	enum DIALOG_TYPE
	{
		DT_WARNING_YNC = 0, //yes, no, cancel
		DT_WARNING_YN, //yes, no
		DT_WARNING_OC, //ok, cancel
		DT_WARNING_O, //ok
		DT_ERROR_O, //ok
	};

	enum ERROR_TYPE
	{
		ET_WARNING,
		ET_CONFIRM,
		ET_CRITICAL,
		ET_ERROR
	};

	template <typename T>
	struct vlist_of : public std::vector<T> 
	{
		vlist_of(const T& t) 
		{
			(*this)(t);
		}

		vlist_of& operator()(const T& t) 
		{
			this->push_back(t);
			return *this;
		}
	};

	struct ProjectTypeInfo
	{
		enum ProjectTypes
		{
			EditorProject = 0,
			GameProject = 1
		};

		struct _ProjectTypeInfo
		{
			_ProjectTypeInfo()
				: _type("")
				, _ext("")
				, _base_filename("")
			{}

			_ProjectTypeInfo(std::string const& type, std::string const& ext, std::string const& base_filename = "")
				: _type(type)
				, _ext(ext)
				, _base_filename(base_filename)

			{}

			std::string _type;
			std::string _ext;
			std::string _base_filename;
		};

		static const std::string _projectRootName;
		static const std::string _emptyName;

		typedef std::vector<_ProjectTypeInfo> ProjectTypeInfoVector;

		static std::string const getExtByProjectType(std::string const& type)
		{
			for (ProjectTypeInfoVector::const_iterator it = _allProjectTypesInfo.begin(); it != _allProjectTypesInfo.end(); ++it)
			{
				if (it->_type == type)
				{
					return it->_ext;
				}
			}

			return "";
		}

		static std::string const getTypeByProjectExt(std::string const& ext)
		{
			for (ProjectTypeInfoVector::const_iterator it = _allProjectTypesInfo.begin(); it != _allProjectTypesInfo.end(); ++it)
			{
				if (it->_ext == ext)
				{
					return it->_type;
				}
			}

			return "";
		}

		static bool const checkProjectType(std::string const& type)
		{
			for (ProjectTypeInfoVector::const_iterator it = _allProjectTypesInfo.begin(); it != _allProjectTypesInfo.end(); ++it)
			{
				if (it->_type == type)
				{
					return true;
				}
			}

			return false;
		}

		static const ProjectTypeInfoVector _allProjectTypesInfo;
	};







	class ErrorMessanger : public Ogre::Singleton<ErrorMessanger>
	{
	public:
		ErrorMessanger(QWidget *parent = NULL);
		~ErrorMessanger();

		int const lastError(int const& code, std::string const& description, std::string const& source, 
							bool const& needShowMessage = false, DIALOG_TYPE const& dialogType = DT_WARNING_O, std::string const& title = "");

		void printMessage();
		std::string const getLastError() const;
		int const showMessage(DIALOG_TYPE const& dialogType, std::string title = "");
		int showExCloseProjectDialog();

		//setters
		inline void setParent(QWidget *parent)
		{
			_parent = parent;
		}

		//getters
		inline QWidget *getParent() const
		{
			return _parent;
		}

		inline Ui::CloseProjectDialog *getCloseProjectDialog() const
		{
			return _closeProjectDialog;
		}

		static ErrorMessanger& getSingleton(void);
		static ErrorMessanger* getSingletonPtr(void);

	private:
		Ogre::Exception *_lastError;
		int _messageResult;
		QWidget *_parent;
		Ui::CloseProjectDialog *_closeProjectDialog;
	};
	














	class BaseSettings
	{
	public:
		BaseSettings(pugi::xml_node &parent);
		virtual ~BaseSettings();

		virtual void defaults();
		virtual void clear();
		virtual bool const checkFields() const;
		virtual bool const& createNode();
		virtual bool const saveNode();
		virtual bool const& loadNode(pugi::xml_node &node);

		//setters
	protected:
		inline void setNodeName(std::string const& name)
		{
			_nodeName = name;
		}

	public:
		inline void setNodeParameter(std::string const& fieldName, bool const& value)
		{
			_node.attribute(fieldName.c_str()).set_value(value);
		}

		inline void setNodeParameter(std::string const& fieldName, char* const& value)
		{
			_node.attribute(fieldName.c_str()).set_value(value);
		}

		inline void setNodeParameter(std::string const& fieldName, unsigned int const& value)
		{
			_node.attribute(fieldName.c_str()).set_value(value);
		}

		inline void setNodeParameter(std::string const& fieldName, int const& value)
		{
			_node.attribute(fieldName.c_str()).set_value(value);
		}

		inline void setNodeParameter(std::string const& fieldName, double const& value)
		{
			_node.attribute(fieldName.c_str()).set_value(value);
		}

		inline void setNeedShowMessage(bool const& needShowMessage)
		{
			_needShowMessage = needShowMessage;
		}

		//getters
		inline bool const& isCreated() const
		{
			return _created;
		}

		inline std::string const& getNodeName() const
		{
			return _nodeName;
		}

		inline pugi::xml_node getNode() const
		{
			return _node;
		}

		inline pugi::xml_node getParent() const
		{
			return _parent;
		}

		inline bool const& isNeedShowMessage() const
		{
			return _needShowMessage;
		}

		inline std::string const& getType()
		{
			return _type;
		}

		inline std::string const& getExt()
		{
			return _ext;
		}

	protected:
		BaseSettings() {}
		BaseSettings(BaseSettings const&) {}

		void checkError();
		
	protected:
		pugi::xml_node _node;
		pugi::xml_node _parent;
		std::string _nodeName;
		bool _created;
		bool _needShowMessage;
		std::string _type;
		std::string _ext;
	};












	class EditorSettings : public BaseSettings
	{
	public:
		EditorSettings(pugi::xml_node &parent);
		virtual ~EditorSettings();

		virtual void defaults();
		virtual void clear();
		virtual bool const checkFields() const;
		virtual bool const& createNode();
		virtual bool const saveNode();
		virtual bool const& loadNode(pugi::xml_node &node);

	private:
		EditorSettings() {}
		EditorSettings(EditorSettings const&) {}
	};













	class GameProjectSettings : public BaseSettings
	{
	public:
		GameProjectSettings(pugi::xml_node &parent);
		virtual ~GameProjectSettings();

		virtual void defaults();
		virtual void clear();
		virtual bool const checkFields() const;
		virtual bool const& createNode();
		virtual bool const saveNode();
		virtual bool const& loadNode(pugi::xml_node &node);

		//getters
		inline std::string const& getProjectName() const
		{ 
			return _projectName; 
		}

		inline std::string const& getPathToProjectFolder() const 
		{ 
			return _pathToProjectFolder; 
		}

		inline std::string const& getCurrentOS() const 
		{ 
			return _currentOS; 
		}

		inline bool const& isMode3D() const 
		{ 
			return _mode3D; 
		}

		inline tValue<int> const& getScreenWidthInfo() const 
		{ 
			return _screenSizeInfo.first; 
		}

		inline tValue<int> const& getScreenHeightInfo() const 
		{ 
			return _screenSizeInfo.second; 
		}

		inline iValueSizeInfo const& getScreenSizeInfo() const 
		{
			return _screenSizeInfo; 
		}

		inline int const& getScreenWidth() const 
		{ 
			return _screenSizeInfo.first.current; 
		}

		inline int const& getScreenHeight() const 
		{ 
			return _screenSizeInfo.second.current; 
		}

		inline void getScreenSize(int &width, int &height) const 
		{
			width = _screenSizeInfo.first.current; 
			height = _screenSizeInfo.second.current; 
		}

		//setters
		inline void setProjectName(std::string const& newName) 
		{ 
			_projectName = newName;
		}

		inline void setPathToProjectFolder(std::string const& newPath)
		{ 
			_pathToProjectFolder = newPath;
		}

		inline void setCurrentOS(std::string const& newOS) 
		{
			_currentOS = newOS;
		}

		inline void setMode3D(bool const& mode)
		{
			_mode3D = mode; 
		}

		inline void setScreenWidthInfo(tValue<int> const& width)
		{ 
			_screenSizeInfo.first = width;
		}

		inline void setScreenHeightInfo(tValue<int> const& height)
		{ 
			_screenSizeInfo.second = height;
		}

		inline void setScreenSizeInfo(iValueSizeInfo const& newSize)
		{
			_screenSizeInfo = newSize;
		}

		inline void setScreenWidth(int const& width)
		{ 
			_screenSizeInfo.first.current = width;
		}

		inline void setScreenHeight(int const& height)
		{ 
			_screenSizeInfo.second.current = height;
		}

		inline void setScreenSize(int const& width, int const& height)
		{
			_screenSizeInfo.first.current = width;
			_screenSizeInfo.second.current = height;
		}

	private:
		GameProjectSettings() {}
		GameProjectSettings(GameProjectSettings const&) {}

	private:
		std::string _projectName;
		std::string _pathToProjectFolder;
		std::string _currentOS;
		bool _mode3D;
		iValueSizeInfo _screenSizeInfo;
	};









	class SettingsManager : public Ogre::Singleton<SettingsManager>
	{
	public:
		struct ProjectFileInfo
		{
			ProjectFileInfo()
				: _filename(ProjectTypeInfo::_emptyName)
				, _projectName(ProjectTypeInfo::_emptyName)
				, _path(ProjectTypeInfo::_emptyName)
				, _loaded(false)
				, _active(false)
				, _settings(NULL)
			{
			}

			ProjectFileInfo(std::string const& filename, std::string const& projectName)
				: _filename(filename)
				, _projectName(projectName)
				, _path(ProjectTypeInfo::_emptyName)
				, _loaded(false)
				, _active(false)
				, _settings(NULL)
			{
			}

			inline BaseSettings *getProjectBaseSettings()
			{
				return _settings;
			}

			BaseSettings* _settings;
			pugi::xml_document _settingsDocument;
			pugi::xml_parse_result _parseResult;
			std::string _filename;
			std::string _projectName;
			std::string _path;
			bool _loaded;
			bool _active;
		};

		typedef std::map <std::string, ProjectFileInfo*> ProjectsMap;

		struct nodeFinder
		{
			nodeFinder(std::string const& nodeName) : _nodeName(nodeName) {}

			bool operator()(pugi::xml_node const& node) const
			{
				return std::strcmp(node.name(), _nodeName.c_str()) == 0;
			}

			std::string _nodeName;
		};

	public:
		SettingsManager();
		~SettingsManager();

		ProjectFileInfo *newProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType);
		bool const closeProjects(bool const& showConfirmDialog = true);
		void closeProject(std::string const& projectName);
		bool closeActiveProject();
		bool const openProject(std::string const& fileName);
		bool const saveProject(std::string const& projectName = ProjectTypeInfo::_emptyName);
		bool const saveAsProject(std::string const& fileName);

		inline bool findProject(std::string const& name)
		{
			return _projectsMap.find(name) != _projectsMap.end();
		}

		//setters
		void setProjectName(std::string const& oldName, std::string const& newName, std::string const& path = ProjectTypeInfo::_emptyName);
		void setActiveProject(std::string const& projectName);

		inline void setNeedShowMessage(bool const& needShowMessage)
		{
			_needShowMessage = needShowMessage;
		}

		//getters
		inline ProjectFileInfo *getActiveProject()
		{
			return _projectsMap[_activeProject];
		}

		inline bool const& isNeedShowMessage() const
		{
			return _needShowMessage;
		}

		ProjectFileInfo *getProject(std::string const& projectName);
		std::vector<std::string> getProjectsNames();

		static SettingsManager& getSingleton(void);
		static SettingsManager* getSingletonPtr(void);

	private:
		inline bool const acceptProject()
		{
			if (_currentNumberOfOpenProjects < _maxNumberOfOpenProjets)
			{
				_currentNumberOfOpenProjects++;
				return true;
			}

			return false;
		}

		inline std::string const makeFilename(std::string const& path, std::string const& projectName, std::string const& projectType)
		{
			std::string projectNameExt = ProjectTypeInfo::getExtByProjectType(projectType);
			
			if (projectNameExt.empty())
			{
				ErrorMessanger::getSingleton().lastError(ET_CONFIRM, "Wrong project type: " + projectType + ".", "SettingsManager::makeFilename()", _needShowMessage, DT_WARNING_O);
				return "";
			}

			if (path.empty())
			{
				return projectName + "." + projectNameExt;
			}

			if (path[path.length()-1] == '/' || path[path.length()-1] == std::string("\\")[0])
			{
				return path + projectName + "." + projectNameExt;
			}

			return path + "/" + projectName + "." + projectNameExt;
		}

		bool addNewProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType);
		bool addProject(std::string const& projectPath, std::string const& projectName, std::string const& projectType);
		bool initProject(std::string const& projectType, ProjectFileInfo *project);
		BaseSettings *instanceOfProjectSettings(std::string const& type, pugi::xml_node &node);
		bool createOrLoadNode(BaseSettings *settings, ProjectFileInfo *project);

	private:
		ProjectsMap _projectsMap;
		bool _needShowMessage;
		short _maxNumberOfOpenProjets;
		short _minNumberOfOpenProjets;
		short _currentNumberOfOpenProjects;
		std::string _activeProject;
	};
}

#endif