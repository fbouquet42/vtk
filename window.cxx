#include "window.h"
#include "renderWindow.h"
#include "toolBar.h"

//#include <QPlainTextEdit>

tel::Window::Window() : QMainWindow()
{
    this->setCentralWidget(new tel::RenderWindow());

    this->addToolBar(new tel::ToolBar(this));

    this->showFullScreen();
    this->showMaximized();

    this->setUnifiedTitleAndToolBarOnMac(true);
}
