#include <QApplication>
#include <QVTKOpenGLNativeWidget.h>

#include "window.h"

int main(int argc, char **argv)
{
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
	QCoreApplication::setOrganizationName("fbouquet personal work");
	QCoreApplication::setApplicationName("The Easy Lib");

	QApplication app (argc, argv);

	tel::Window mWindow;

	mWindow.show();

	// QPushButton button ("Hello world !");
	// button.show();

	return app.exec();
}
