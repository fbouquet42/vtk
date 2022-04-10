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
		protected:
#ifndef QT_NO_CONTEXTMENU
			void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
		private:
			QAction *cutAct;
			QAction *copyAct;
			QAction *pasteAct;
	};

} //el

#endif //EASYLIB_WINDOW_H
