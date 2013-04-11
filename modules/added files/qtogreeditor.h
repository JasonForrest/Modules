//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : EditorInterface
//  @ File Name : qtogreeditor.h
//  @ Date : 10.03.2013
//  @ Author : Sergei Forrest
//
//

#if !defined(_QTOGREEDITOR_H)
#define _QTOGREEDITOR_H

#include "mainwindow.h"
#include "qogrewidget.h"
#include <Ogre.h>

namespace QtOgre
{
    class QtOgreEditor : public Ui::MainWindow
	{
        Q_OBJECT

	public:
        QtOgreEditor();
        ~QtOgreEditor();

	private:
		QOgreWidget* ogreOGLWidget;
		Ogre::Root* ogreRoot;
		Ogre::Viewport* ogreViewport;
		Ogre::SceneManager* sceneManager;
		Ogre::RenderSystem* renderSystem;
		Ogre::Camera* mainCamera;
	};
}

#endif  //_QTOGREEDITOR_H
