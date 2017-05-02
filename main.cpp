#include <QGuiApplication>
//#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include "dynamicform.h"

int main(int argc, char *argv[])
{
    // Start the applcation
    QGuiApplication app(argc, argv);

    // Load the engine
    QQmlApplicationEngine engine;

    // Load the main QML file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Load the window
    (qobject_cast<QQuickWindow*>(engine.rootObjects().at(0)))->show();

    // start the dynamic form library
    DynamicForm managedForm(0, &engine);

    // Attach the for listener
    engine.rootContext()->setContextProperty("FormClass", &managedForm);
    managedForm.run();

    // Create a Form
    managedForm.createTextBox("FirstTextbox", 0);
    managedForm.createTextBox("SecondTextBox", 100);
    managedForm.createSubmitButton();

    // Return application
    return app.exec();
}
