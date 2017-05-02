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


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickWindow *window = qobject_cast<QQuickWindow*>(engine.rootObjects().at(0));
    if (!window) {
        qFatal("Error: Your root item has to be a window.");
        return -1;
    }
    window->show();
    QQuickItem *root = window->contentItem();




    Motters::DynamicForm* form = new Motters::DynamicForm(&engine, root, nullptr);
    form->createTextBox("test4");
    form->createSubmitButton();




    /**
     * Create a button dynamically
     */
    /*// Load button
    QQmlComponent buttonQML(&engine,QUrl(QStringLiteral("qrc:/dynamic_button.qml")));
    // Create the button
    QQuickItem *button = qobject_cast<QQuickItem*>(buttonQML.create());
    // Set the ownership the c++
    QQmlEngine::setObjectOwnership(button, QQmlEngine::CppOwnership);
    // Set the main window
    button->setParentItem(root);
    button->setParent(&engine);
    // Set the properties
    button->setProperty("color", QVariant(QColor(255, 0, 255)));
    button->setProperty("text", QVariant(QString("foo")));
    button->setWidth(200);
    button->setX(200);
    button->setY(400);*/



    /**
     * Create a textbox dynamically
     */
    /*
    // Load button
    QQmlComponent textboxQML(&engine,QUrl(QStringLiteral("qrc:/dynamic_textbox.qml")));
    // Create the button
    QQuickItem *textbox = qobject_cast<QQuickItem*>(textboxQML.create());
    // Set the ownership the c++
    QQmlEngine::setObjectOwnership(textbox, QQmlEngine::CppOwnership);
    // Set the main window
    textbox->setParentItem(root);
    textbox->setParent(&engine);
    // Set the properties
    textbox->setProperty("text", QVariant(QString("12")));
    textbox->setProperty("width", QVariant(QString("200")));
    textbox->setProperty("topnumber", QVariant(200));
    textbox->setProperty("value", QVariant(10));
    textbox->setProperty("textboxId", QVariant("textboxid"));
    textbox->setObjectName("Textboxname");


    QQmlComponent textboxQML2(&engine,QUrl(QStringLiteral("qrc:/dynamic_textbox.qml")));
    // Create the button
    QQuickItem *textbox2 = qobject_cast<QQuickItem*>(textboxQML2.create());
    // Set the ownership the c++
    QQmlEngine::setObjectOwnership(textbox2, QQmlEngine::CppOwnership);
    // Set the main window
    textbox2->setParentItem(root);
    textbox2->setParent(&engine);
    // Set the properties
    textbox2->setProperty("y", QVariant(100));
    textbox2->setProperty("errorMessage", QVariant(QString("Only numbers between 12 and 200 are allowed")));
    textbox2->setProperty("longDescription", QVariant(QString("Enter the desired pressure")));
    textbox2->setProperty("name", QVariant(QString("Pressure")));
    textbox2->setProperty("width", QVariant(QString("200")));
    textbox2->setProperty("topnumber", QVariant(200));
    textbox2->setProperty("bottomnumber", QVariant(12));
    textbox2->setProperty("value", QVariant(100));
    textbox2->setProperty("textboxId", QVariant("textboxid2"));
    //connect(textbox2, SIGNAL(editingFinished()), this, SLOT(hellow()));
    */

    return app.exec();
}

void hellow()
{

}
