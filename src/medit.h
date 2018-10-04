/***************************************************************************
 *   Copyright (C) 2008 by Graham Morrison   *
 *   graham.morrison@futurenet.co.uk   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef MEDIT_H
#define MEDIT_H

#include <QMainWindow>
#include <QCloseEvent>

#include "combodelegate.h"

class QAction;
class QMenu;
class QTextEdit;

// GM Added
class QTreeView;
class QTreeWidget;
class QStandardItem;
class QStandardItemModel;
class QByteArray;
class ComboDelegate;

class medit:public QMainWindow
{
      Q_OBJECT

public:
      medit();
      ~medit();

protected:
      void closeEvent(QCloseEvent *event);

private slots:
      void newFile();
      void open();
      bool save();
      bool saveAs();
      void about();
      void documentWasModified();

private:
      void createActions();
      void createMenus();
      void createToolBars();
      void createStatusBar();
      void readSettings();
      void writeSettings();
      bool maybeSave();
      void loadFile(const QString &fileName);
      bool saveFile(const QString &fileName);
      void setCurrentFile(const QString &fileName);
      QString strippedName(const QString &fullFileName);
	  QList<QStandardItem*> returnTheItems();
	  
      QTextEdit *textEdit;
      QTreeView *treeView;
      QStandardItemModel *model;
      QString curFile;
	  ComboDelegate catCombo;
	  QByteArray convertToSyx(QByteArray patch);
	  QByteArray convertFromSyx(QByteArray patch);

      QMenu *fileMenu;
      QMenu *editMenu;
      QMenu *helpMenu;
      QToolBar *fileToolBar;
      QToolBar *editToolBar;
      QAction *newAct;
      QAction *openAct;
      QAction *saveAct;
      QAction *saveAsAct;
      QAction *exitAct;
      QAction *cutAct;
      QAction *copyAct;
      QAction *pasteAct;
      QAction *aboutAct;
      QAction *aboutQtAct;
};

#endif
