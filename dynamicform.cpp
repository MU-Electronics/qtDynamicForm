#include "dynamicform.h"
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QDebug>
#include <QQmlComponent>

#include <QQuickWindow>


DynamicForm::DynamicForm(QObject *parent, QQmlApplicationEngine *engine) :
    QObject(parent),
    m_engine(engine)
{

}

void DynamicForm::run()
{
    // Set the roor
    auto rootObjects = this->m_engine->rootObjects();

    if(rootObjects.count() < 1) return;

    this->m_root = rootObjects[0];

    // Set the window
    this->m_window = (qobject_cast<QQuickWindow*>(this->m_root))->contentItem();

    qDebug() << "Class Ready";
}

void DynamicForm::onSubmittionSignal(QString fieldJson)
{

    qDebug() << "c++ fired ";
    qDebug() << fieldJson;

//    QVariant retVal;
//    QMetaObject::invokeMethod(this->m_root, "addItem", Qt::DirectConnection,
//                               Q_RETURN_ARG(QVariant, retVal),
//                               Q_ARG(QVariant, "test"));

//    qWarning() << retVal;

//    auto textboxes = this->m_root->findChild<QQuickItem*>("test");

//    if(textboxes != nullptr)
//    {
//        qDebug()  << textboxes->property("value").toString();
//    }else{
//        qDebug() << "No textbox found";
//    }

}


void DynamicForm::createTextBox(QString name, int y)
{

    QVariant retVal;
    QMetaObject::invokeMethod(this->m_root, "addItem", Qt::DirectConnection,
                               Q_RETURN_ARG(QVariant, retVal),
                               Q_ARG(QVariant, name),
                               Q_ARG(QVariant, y));
    qWarning() << retVal;

    auto textbox = this->m_root->findChild<QQuickItem*>(name);

    connect(textbox, SIGNAL(submittionSignal(QString)), this, SLOT(onSubmittionSignal(QString)));

//    // Load Textbox
//    QQmlComponent textboxQML(this->m_engine,QUrl(QStringLiteral("qrc:/dynamic_textbox.qml")));

//    // Create the button
//    QQuickItem *textbox = qobject_cast<QQuickItem*>(textboxQML.create());

//    // Register the component to the class's fields index
//    this->m_fields.append(name);

//    // Set the ownership the c++
//    QQmlEngine::setObjectOwnership(textbox, QQmlEngine::CppOwnership);

//    // Set the main window
//    textbox->setParentItem(this->m_window);
//    textbox->setParent(this->m_engine);

//    // Set the properties
//    textbox->setProperty("text", QVariant(QString("12")));
//    textbox->setProperty("width", QVariant(QString("200")));
//    textbox->setProperty("topnumber", QVariant(200));
//    textbox->setProperty("value", QVariant(10));
//    textbox->setProperty("y", y);
//    textbox->setProperty("textboxId", QVariant(name));
//    textbox->setProperty("objectName", name);
//    textbox->property("value");

//    connect(textbox, SIGNAL(submittionSignal(QString)), this, SLOT(onSubmittionSignal(QString)));
}

void DynamicForm::createSubmitButton()
{
    // Load button / submittion component
    QQmlComponent buttonQML(this->m_engine,QUrl(QStringLiteral("qrc:/dynamic_button.qml")));

    // Create the button
    QQuickItem *button = qobject_cast<QQuickItem*>(buttonQML.create());

    // Set the ownership the c++
    QQmlEngine::setObjectOwnership(button, QQmlEngine::CppOwnership);

    // Set the main window
    button->setParentItem(this->m_window);
    button->setParent(this->m_engine);

    // Set the properties
    button->setProperty("text", QVariant(QString("Submit Form")));
    button->setProperty("formFields", this->m_fields);
    button->setWidth(200);
    button->setX(0);
    button->setY(200);

    // Connect the buttom
    //connect(button, SIGNAL(submittionSignal(QString)), this, SLOT(onSubmittionSignal(QString)));
}

