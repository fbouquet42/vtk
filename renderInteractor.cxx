#include "renderInteractor.h"

#include <vtkObjectFactory.h>

#include <QPoint>
#include <QCursor>
#include <QTranslator>
#include <QMenu>

vtkStandardNewMacro(tel::RenderInteractor);

tel::RenderInteractor::RenderInteractor() : vtkInteractorStyleTrackballCamera()
{
	this->cutAct = new QAction(QObject::tr("&Cut"));
	//cutAct->setShortcuts(QKeySequence::New);
	cutAct->setStatusTip(QObject::tr("To cut"));

	this->copyAct = new QAction(QObject::tr("&Copy"));
	//copyAct->setShortcuts(QKeySequence::New);
	copyAct->setStatusTip(QObject::tr("To copy"));

	this->pasteAct = new QAction(QObject::tr("&Paste"));
	//copyAct->setShortcuts(QKeySequence::New);
	pasteAct->setStatusTip(QObject::tr("To paste"));
}

tel::RenderInteractor::~RenderInteractor()
{
}

void tel::RenderInteractor::OnRightButtonDown()
{
	QPoint globalCursorPos = QCursor::pos();
	QMenu menu;
	menu.addAction(cutAct);
	menu.addAction(copyAct);
	menu.addAction(pasteAct);
	menu.exec(globalCursorPos);
}
