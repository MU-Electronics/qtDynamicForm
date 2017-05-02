#pragma once
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QString>
#include <map>

namespace Motters{
    class DynamicForm : public QObject
    {
        Q_OBJECT
    public:
        explicit DynamicForm(QQmlApplicationEngine *engine, QQuickItem* root, QObject *parent);
        void createTextBox(QString name, int y);
        void createSubmitButton();

    public slots:
        void onDynamicFormSubmittion(QString fieldsJson);

    private:

        QQmlApplicationEngine* m_engine;
        QQuickItem* m_root;

        //std::map<QString, QQuickItem*> m_fields;
        QVariantList m_fields;

        explicit DynamicForm(const DynamicForm& rhs) = delete;
        DynamicForm& operator= (const DynamicForm& rhs) = delete;
    };
}


