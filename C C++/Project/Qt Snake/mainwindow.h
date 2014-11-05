#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "Controller.h"
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qlayout.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	private:
		Ui::MainWindowClass ui;
		QGraphicsScene *m_scene;
		QGraphicsView *m_view;
		Controller *m_controller;
		bool m_ResumeOrPause;
		QTimer *m_timer;
		int m_GameTime;

		void DrawBackGround();
	public:
		MainWindow(QWidget *parent = 0);
		~MainWindow();
	private slots:
		void ChangeTextResumeOrPause();
		void ChangeLcdText();
		void WindowGameOver();
};

