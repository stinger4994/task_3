#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#include <QtWidgets>
#endif

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QWidget *widget = new QWidget;
    QPushButton *quitButton = new QPushButton("Quit");
    QLineEdit *first = new QLineEdit();
    QLineEdit *second = new QLineEdit();
    QVBoxLayout *buttonLayout = new QVBoxLayout;

    buttonLayout->addWidget(first);
    buttonLayout->addWidget(second);
    buttonLayout->addWidget(quitButton);

    QObject::connect(quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(first,SIGNAL(textEdited(QString)),second,SLOT(setText(QString)));
    QObject::connect(second,SIGNAL(textEdited(QString)),first,SLOT(setText(QString)));

    widget->setLayout(buttonLayout);
    widget->setWindowFlags(Qt::Window);
    widget->show();

    return app.exec();
}
