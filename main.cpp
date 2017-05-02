#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWindow>
#include <QValidator>
#include <QIntValidator>
#include "dynamicform.h"

int main(int argc, char *argv[])
{
    // Load the window and engine
    QGuiApplication app(argc, argv);


    QmlApplicationEngine engine;
    Motters::DynamicForm form(0, engine);






    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickWindow *window = qobject_cast<QQuickWindow*>(engine.rootObjects().at(0));
    if (!window) {
        qFatal("Error: Your root item has to be a window.");
        return -1;
    }
    window->show();
    QQuickItem *root = window->contentItem();




    Motters::DynamicForm* form = new Motters::DynamicForm(&engine, root, nullptr);
    form->createTextBox("test4", 0);
    form->createTextBox("test4", 100);
    form->createSubmitButton();*/





    return app.exec();
}

void hellow()
{

}
