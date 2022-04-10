#include "toolBar.h"

tel::ToolBar::ToolBar(QWidget *parent) : QToolBar(parent)
{
	this->addAction(new QAction("Load File"));
	this->addAction(new QAction("Save"));
//    this->addToolBar();

}
