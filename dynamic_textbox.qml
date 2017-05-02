import QtQuick 2.4
import QtQuick.Controls 2.1


Item
{
    // Set the id of the textbox
    property string textboxId: ""

    // Set value of textbox
    property int value: 0

    // Set the upper and lower limits
    property int topnumber: 50
    property int bottomnumber: 0

    // Set the desired error message
    property string errorMessage: "Only numbers are accepted"

    // Set the textbox label name
    property string name: "Default"
    property int nameWidth: 180

    // Set the long description for the textbox
    property string longDescription: ""
    property int longDescriptionWidth: 200

    Column
    {
        Row
        {

            Rectangle {
                //width: childrenRect.width
                width: nameWidth
                height: 40
                color: "red"
                Label
                {
                    padding: 10
                    text: name
                    font.pixelSize: 15
                    color: "steelblue"
                    wrapMode: Text.Wrap
                }
            }

            TextField
            {
                id: textboxId
                objectName: "FirstTextbox"
                text: value
                validator: IntValidator{bottom: bottomnumber; top: topnumber;}
            }

            Rectangle {
                width: longDescriptionWidth
                height: 40
                color: "red"
                visible: (longDescription != "") ? true : false
                Label
                {
                    width: parent.width
                    text: longDescription
                    wrapMode: Text.Wrap
                }
            }
        }

        Label
        {
            text: errorMessage
        }
    }
}



