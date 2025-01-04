#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QWidget* widget = new QWidget();
	widget->setWindowTitle("Hello Mr Naji Belgasmi");
	widget->show();

	return app.exec();
}