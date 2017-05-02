#pragma once
#include <QObject>
#include <QQuickItem>
//#include <QVariantList>

class QQmlApplicationEngine;

class DynamicForm : public QObject
{
    Q_OBJECT
    public:
        DynamicForm(QObject *parent, QQmlApplicationEngine *engine);

        void run();

        void createTextBox(QString name, int y);
        void createSubmitButton();

    public slots:
       void onSubmittionSignal(QString fieldJson);

    private:

        QQmlApplicationEngine* m_engine;
        QObject* m_root;
        QQuickItem* m_window;

        QVariantList m_fields;

        explicit DynamicForm(const DynamicForm& rhs) = delete;
        DynamicForm& operator= (const DynamicForm& rhs) = delete;
};



