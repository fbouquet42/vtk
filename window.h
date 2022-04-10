#ifndef EASYLIB_WINDOW_H
# define EASYLIB_WINDOW_H

#include <QMainWindow>

namespace tel {

	class Window : public QMainWindow
	{
		Q_OBJECT

		public:
			Window();
			virtual ~Window() {};
	};

} //el

#endif //EASYLIB_WINDOW_H
