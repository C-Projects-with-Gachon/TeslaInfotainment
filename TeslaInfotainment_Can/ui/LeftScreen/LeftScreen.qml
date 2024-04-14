import QtQuick 2.0
import QtQuick 2.9
import QtQuick.Controls 2.0
import QtQuick.Window 2.2
//import ConnectEvent 1.0//등록한 클래스 타입을 import해준다.
import "."

Rectangle {
    id: leftScreen
    anchors {
        left: parent.left
        right: rightScreen.left
        bottom: bottomBar.top
        top: parent.top
    }
    color: "white"

    ListModel {
        id: todoModel
        ListElement { text: "집가기" }
        ListElement { text: "힐링하기" }
        // 필요에 따라 ListElement를 추가
    }

    ListView {
        anchors.fill: parent
        model: todoModel
        delegate: Item {
            width: parent.width
            height: 50
            Row {
                spacing: 10

                Text {
                    width: parent.width * 0.45
                    text: model.text
                }

                Button {    //edit
                    text: "수정"
                    onClicked: {
                        editTextInput.text = model.text//현재 항목의 텍스트를 입력 필드에 표시한다.
                        editTextInput.visible = true//입력 필드를 보이도록한다.
                        editTextInput.forceActiveFocus()//입력 필드에 포커스를 주어 수정이 바로 시작될 수 잇도록 한다.
                        editTextInput.selectAll()//입력 필드의 텍스트를 전체 선택, 이렇게 하면 사용자가 수정을 시작할 때 기존 텍스트가 선택되어 바로 수정가능
                        editButton.visible = false// 수정버튼을 숨기고
                        saveButton.visible = true//저장버튼이 표시되도록 한다.
                    }
                }

                Button {    //delete
                    id: editButton
                    text: "삭제"
                    onClicked: {
                        todoModel.remove(index)//현재 선택 되어진 항목의 인덱스를 삭제한다.
                    }
                }

                Button {    //save
                    id: saveButton
                    text: "저장"
                    visible: false
                    onClicked: {
                        if (editTextInput.text.trim() !== "") {
                            todoModel.set(index, { "text": editTextInput.text.trim() })
                            editTextInput.visible = false
                            editButton.visible = true
                            saveButton.visible = false
                            editTextInput.text = ""
                        }
                    }
                }
            }
        }
    }

    Row {
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        TextField {
            id: newTaskInput
            width: parent.width * 0.7
            placeholderText: "새로운 할 일 추가"
        }

        Button {
            text: "추가"
            onClicked: {
                if (newTaskInput.text.trim() !== "") {
                    todoModel.append({ "text": newTaskInput.text.trim() })
                    newTaskInput.text = ""
                }
            }
        }
    }

    TextField {
        id: editTextInput
        visible: false
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        onAccepted: {
            if (editTextInput.text.trim() !== "") {
                todoModel.set(index, { "text": editTextInput.text.trim() })
                editTextInput.visible = false
                editButton.visible = true
                saveButton.visible = false
                editTextInput.text = ""
            }
        }
    }
    /*Image{
    //         id: carRender
    //         anchors.centerIn: parent
    //         width: parent.width * .85
    //         fillMode: Image.PreserveAspectFit
    //         source: "qrc:/ui/assets/carRender.png"
    //     }
    //     */
}
