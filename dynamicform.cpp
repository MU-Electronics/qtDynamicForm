#include "dynamicform.h"
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <map>

namespace Motters
{
    DynamicForm::DynamicForm(QQmlApplicationEngine* engine, QQuickItem* root, QObject *parent=0) :
        QObject(parent),
        m_engine(engine),
        m_root(root)
    {
    }

    void DynamicForm::createTextBox(QString name)
    {
        // Load button
        QQmlComponent textboxQML(this->m_engine,QUrl(QStringLiteral("qrc:/dynamic_textbox.qml")));
        // Create the button
        QQuickItem *textbox = qobject_cast<QQuickItem*>(textboxQML.create());
        // Register the compoent
        m_fields[name] = textbox;
        // Set the ownership the c++
        QQmlEngine::setObjectOwnership(textbox, QQmlEngine::CppOwnership);
        // Set the main window
        textbox->setParentItem(this->m_root);
        textbox->setParent(this->m_engine);
        // Set the properties
        textbox->setProperty("text", QVariant(QString("12")));
        textbox->setProperty("width", QVariant(QString("200")));
        textbox->setProperty("topnumber", QVariant(200));
        textbox->setProperty("value", QVariant(10));
        textbox->setProperty("textboxId", QVariant(name));
        textbox->property("value");
        //connect(textbox, SIGNAL(editingFinished()), this, SLOT(this->editedTextBox()));
    }

    void DynamicForm::createSubmitButton()
    {
        QQmlComponent buttonQML(this->m_engine,QUrl(QStringLiteral("qrc:/dynamic_button.qml")));
        // Create the button
        QQuickItem *button = qobject_cast<QQuickItem*>(buttonQML.create());
        // Set the ownership the c++
        QQmlEngine::setObjectOwnership(button, QQmlEngine::CppOwnership);
        // Set the main window
        button->setParentItem(this->m_root);
        button->setParent(this->m_engine);
        // Set the properties
        button->setProperty("text", QVariant(QString("Submit Fomr")));
        button->setWidth(200);
        button->setX(0);
        button->setY(100);
    }

}
