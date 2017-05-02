import QtQuick 2.4
import QtQuick.Controls 2.1

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    id: windowMain
    visible: true;


    Row{
        id: contentrow
        x:200
        y:300
    }


    function addItem(name)
    {
        //var component = testItem.createObject(contentrow.contentItem, {objectName: name});
        //return component;
        var component = Qt.createComponent("dynamic_textbox.qml");
        component.createObject(contentrow, {value: 100, objectName: name});

        return true;
   }
}
