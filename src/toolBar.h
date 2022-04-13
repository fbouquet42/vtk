#ifndef EASYLIB_TOOLBAR_H
# define EASYLIB_TOOLBAR_H

#include <QToolBar>

namespace tel {

	class ToolBar : public QToolBar
	{
		Q_OBJECT

		public:
			ToolBar(QWidget *parent);
			virtual ~ToolBar() {};
	};

} //el

#endif //EASYLIB_TOOLBAR_H
