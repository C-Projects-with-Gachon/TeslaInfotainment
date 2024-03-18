#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QTimer>

class System : public QObject   //System 클래스는 QObject 클래스를 상속한다. 이 뜻은 QT에서 시그널 및 슬롯 메커니즘을 사용하기 위해 필요한 것이다.
{
    //Q_PROPERTY는 Qt 프레임워크에서 사용되는 매크로로, 클래스의 속성(property)을 선언할 때 사용됩니다.
    //이를 통해 해당 클래스의 속성들이 Qt의 메타오브젝트 시스템에 등록되어 다른 Qt 모듈들과 상호작용할 수 있습니다.
    Q_OBJECT
    Q_PROPERTY(bool carLocked READ carLocked WRITE setCarLocked NOTIFY carLockedChanged)
    Q_PROPERTY(int outdoorTemp READ outdoorTemp WRITE setOutdoorTemp NOTIFY outdoorTempChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString currentTime READ currentTime WRITE setCurrentTime NOTIFY currentTimeChanged)
    //Q_PROPERTY(type name READ getter WRITE setter NOTIFY signal)
    //READ-GET, WRITE-SET, NOTIFY-SIGNAL

public: //QT의 프로퍼티로 정의되어 있어서 다른 Qt 클래스나 QML에서 이러한 속성들에 접근할 수 있다.
    explicit System(QObject *parent = nullptr);

    bool carLocked() const;
    int outdoorTemp() const;
    QString userName() const;
    QString currentTime() const;

public slots:   //속성값들의 값을 설정하기 위한 메서드, 값을 바꾸는 곳은 여기다. 슬롯을 갔다가 시그널로 알리는 방식인거지
    void setCarLocked(bool carLocked);
    void setOutdoorTemp(int outdoorTemp);
    void setUserName(QString userName);
    void setCurrentTime(QString currentTime);
    void currentTimeTimerTimeout();

signals:    //각 변수들의 값이 변경될 때 발생시키는 시그널이다. 이 시그널을 발생시키면 변경사항을 통지.
    void carLockedChanged(bool carLocked);
    void outdoorTempChanged(int outdoorTemp);
    void userNameChanged(QString userName);
    void currentTimeChanged(QString currentTime);

private:    //멤버 변수들은 각각 속성들의 값을 저장한다.
    bool m_carLocked;
    int m_outdoorTemp;
    QString m_userName;
    QString m_currentTime;
    QTimer * m_currentTimeTimer;
};

#endif // SYSTEM_H
