#include "window.h"
#include "renderWindow.h"
#include "toolBar.h"

#include <QMenu>
#include <QContextMenuEvent>
//#include <QPlainTextEdit>

tel::Window::Window() : QMainWindow()
{
    this->setCentralWidget(new tel::RenderWindow());

    this->addToolBar(new tel::ToolBar(this));

    this->showFullScreen();
    this->showMaximized();

    this->setUnifiedTitleAndToolBarOnMac(true);

    this->cutAct = new QAction(tr("&Cut"), this);
    //cutAct->setShortcuts(QKeySequence::New);
    cutAct->setStatusTip(tr("To cut"));

    this->copyAct = new QAction(tr("&Copy"), this);
    //copyAct->setShortcuts(QKeySequence::New);
    copyAct->setStatusTip(tr("To copy"));

    this->pasteAct = new QAction(tr("&Paste"), this);
    //copyAct->setShortcuts(QKeySequence::New);
    pasteAct->setStatusTip(tr("To paste"));
}

#ifndef QT_NO_CONTEXTMENU
void tel::Window::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU
