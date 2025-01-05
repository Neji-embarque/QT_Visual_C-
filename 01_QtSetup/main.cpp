#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxlayout>
#include <QVBoxlayout>

class Window : public QWidget
{
public:
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{
		setWindowTitle("Login");
		setFixedSize(300, 200);

		mainlayout = new QVBoxLayout();
		setLayout(mainlayout);

		row1layout = new QHBoxLayout();
		row1layout->setSpacing(10);
		username_label = new QLabel("username : ");
		username_box = new QLineEdit();
		row1layout->addWidget(username_label);
		row1layout->addWidget(username_box);

		mainlayout->addLayout(row1layout);


		row2layout = new QHBoxLayout();
		row2layout->setSpacing(10);
		password_label = new QLabel("password : ");
		password_box = new QLineEdit();
		password_box->setEchoMode(QLineEdit::EchoMode::Password);
		row2layout->addWidget(password_label);
		row2layout->addWidget(password_box);

		mainlayout->addLayout(row2layout);


		row3layout = new QHBoxLayout();
		row3layout->addStretch();

		login = new QPushButton("login");
		cancel = new QPushButton("cancel");
		row3layout->addWidget(login);
		row3layout->addWidget(cancel);

		mainlayout->addLayout(row3layout);

		//connectiion
		connect(login, &QPushButton::clicked, this, &Window::Login_pressed);
		connect(cancel, &QPushButton::clicked, this, &Window::Cancel_pressed);

	}
	void Login_pressed()
	{
		QMessageBox msg;
		msg.setText("logged in : "+ username_box->text() + "  password : " + password_box->text());
		msg.exec();
	}
	void Cancel_pressed()
	{
		QMessageBox msg;
		msg.setText("Cancel Result");
		msg.exec();
	}

private:
	QVBoxLayout* mainlayout;
	QHBoxLayout* row1layout;
	QHBoxLayout* row2layout;
	QHBoxLayout* row3layout;

	QLabel* username_label;
	QLabel* password_label;

	QLineEdit* username_box;
	QLineEdit* password_box;

	QPushButton* login;
	QPushButton* cancel;
};

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Window window;
	window.show();

	return app.exec();
}