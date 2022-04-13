#ifndef EASYLIB_RENDERWINDOW_H
# define EASYLIB_RENDERWINDOW_H

#include <QVTKOpenGLNativeWidget.h>

namespace tel {

	class RenderWindow : public QVTKOpenGLNativeWidget
	{
		Q_OBJECT

		public:
			RenderWindow();
			virtual ~RenderWindow() {};
	};

} //el

#endif //EASYLIB_RENDERWINDOW_H
