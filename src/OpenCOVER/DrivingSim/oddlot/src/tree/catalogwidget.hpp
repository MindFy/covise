/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/**************************************************************************
** ODD: OpenDRIVE Designer
**   Frank Naegele (c) 2010
**   <mail@f-naegele.de>
**   10/11/2010
**
**************************************************************************/

#ifndef CATALOGWIDGET_HPP
#define CATALOGWIDGET_HPP

#include "src/util/odd.hpp"

#include <QWidget>

class MainWindow;
class OSCBase;
class OSCElement;
class CatalogTreeWidget;

class QDragEnterEvent;
class QDragLeaveEvent;
class QDragMoveEvent;
class QDropEvent;


namespace OpenScenario
{
class oscObject;
}

class CatalogWidget : public QWidget
{
    Q_OBJECT

    //################//
    // FUNCTIONS      //
    //################//

public:
	explicit CatalogWidget(MainWindow *mainWindow, OpenScenario::oscObject *object);
    virtual ~CatalogWidget();

	void setActiveProject(ProjectWidget *projectWidget)
	{
		projectWidget_ = projectWidget ;
	}

	void onDeleteCatalogItem();

protected:
private:
    CatalogWidget(); /* not allowed */
    CatalogWidget(const CatalogWidget &); /* not allowed */
    CatalogWidget &operator=(const CatalogWidget &); /* not allowed */

    void init();


    //################//
    // PROPERTIES     //
    //################//

private:
	ProjectWidget *projectWidget_;
    ProjectData *projectData_; // Model, linked
	MainWindow *mainWindow_;

	CatalogTreeWidget *catalogTreeWidget_;

	// OpenScenario Base //
	//
	OSCBase *base_;

	OpenScenario::oscObject *object_;
	OSCElement *oscElement_;

};

//#######################################################//
// DropArea for the recycle bin of the catalog widget //
//
//#######################################################//
#include <QLabel>

class DropArea : public QLabel
{
    Q_OBJECT

public:
    DropArea(const QPixmap &pixmap, CatalogWidget *parent = 0);

	//################//
    // SLOTS          //
    //################//
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    QLabel *recycleLabel_;
	CatalogWidget *parent_;
};

#endif // CATALOGWIDGET_HPP
