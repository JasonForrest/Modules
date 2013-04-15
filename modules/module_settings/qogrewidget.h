//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : EditorInterface
//  @ File Name : qogrewidget.h
//  @ Date : 10.03.2013
//  @ Author : Sergei Forrest
//
//

#if !defined(_QOGREWIDGET_H)
#define _QOGREWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <OGRE/Ogre.h>
#include <QtGui/qscrollarea.h>

namespace QtOgre
{
	/*class QOgreWidget : public QGLWidget
    {
        Q_OBJECT

	public:
        QOgreWidget(Ogre::Root* ogreRoot);
        ~QOgreWidget();

	private:
		QOgreWidget() {}

	public:
		//getters
		Ogre::RenderWindow* getOgreWindow();

    protected:
		virtual void paintEvent(QPaintEvent* pEvent);
		virtual void resizeEvent(QResizeEvent* rEvent);
		virtual void update();

    private:
		Ogre::RenderWindow* _ogreRenderWindow;
		Ogre::Root* _ogreRoot;
	};*/

	class OgreWidget : public QGLWidget
	{
	public:
		OgreWidget(int const& width, int const& height, QWidget *parent=0)
			: QGLWidget(parent)
			, _mOgreWindow(NULL)
		{
			this->setGeometry(0, 0, width, height);
			this->setMaximumSize(width, height);

			init("plugins.cfg", "ogre.cfg", "ogre.log");
		}

		virtual ~OgreWidget()
		{
			_mOgreRoot->shutdown();
			delete _mOgreRoot;
			_mOgreRoot = NULL;
			destroy();
		}

	protected:
		virtual void initializeGL();
		virtual void resizeGL(int, int);
		virtual void paintGL();
		virtual void updateGL();

		void init(std::string const&, std::string const&, std::string const&);

		virtual Ogre::RenderSystem* chooseRenderer(Ogre::RenderSystemList*);

		Ogre::Root *_mOgreRoot;
		Ogre::RenderWindow *_mOgreWindow;
		Ogre::Camera *_mCamera;
		Ogre::Viewport *_mViewport;
		Ogre::SceneManager *_mSceneMgr;
	};
}

#endif  //_QOGREWIDGET_H
