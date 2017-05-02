import QtQuick 2.4
import QtQuick.Controls 2.1




Button {
    signal dynamicFormSubmittion(string fields)
    property var formFields: []
    x: 0
    y: 0
    text: "Coolsss"
    highlighted: false
    objectName: "btnDynamic"
    onClicked: {
        dynamicFormSubmittion(JSON.stringify(formFields));
    }
}


