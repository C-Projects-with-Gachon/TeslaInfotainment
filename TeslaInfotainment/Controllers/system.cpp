#include "system.h"
#include <QDateTime>
#include <QDebug>

System::System(QObject *parent) //생성자(고정값임..)
    : QObject(parent)
    , m_carLocked( true )
    , m_outdoorTemp(64)
    , m_userName("Can")
{
    m_currentTimeTimer = new QTimer(this);
    m_currentTimeTimer->setInterval(500);
    m_currentTimeTimer->setSingleShot(true);
    connect(m_currentTimeTimer, &QTimer::timeout, this, &System::currentTimeTimerTimeout);
    //아래 메서드를 주기적으로 호출한다.
    currentTimeTimerTimeout();
}
bool System::carLocked() const
{
    return m_carLocked;
}
int System::outdoorTemp() const
{
    return m_outdoorTemp;
}
QString System::userName() const
{
    return m_userName;
}
QString System::currentTime() const
{
    return m_currentTime;
}
//아래 녀석들은 각 속성의 값을 설정하고 해당 속성이 변경될 때 시그널을 발생한다. 이 시그널을 헤더에서 받아서 처리하는거지..
void System::setCarLocked(bool CarLocked)   //자 여기서 CarLocked 값을 전에 값인 m_carLocked 값이랑 비교를 한다.
{
    if (m_carLocked == CarLocked)
        return;
    m_carLocked = CarLocked;    //값이 다르면 새로운 값으로 받아서 업데이트를 하고, carLockedChanged함수를 작동시켜서 새로운 값으로 대처하게 만든다.
    emit carLockedChanged(m_carLocked);
}
void System::setOutdoorTemp(int OutdoorTemp)
{
    if (m_outdoorTemp == OutdoorTemp)
        return;
    m_outdoorTemp = OutdoorTemp;
    emit outdoorTempChanged(m_outdoorTemp);
}
void System::setUserName(QString userName)
{
    if (m_userName == userName)
        return;
    m_userName = userName;
    emit userNameChanged(m_userName);
}
void System::setCurrentTime(QString CurrentTime)
{
    if (m_currentTime == CurrentTime)
        return;
    m_currentTime = CurrentTime;
    emit currentTimeChanged(m_currentTime);
}
//currentTimeTimerTimeout 메서드는 타이머가 만료되었을 때 호출되어 현재 시간을 업데이트합니다.
void System::currentTimeTimerTimeout()
{
    QDateTime dateTime;
    QString currentTime = dateTime.currentDateTime().toString("hh:mm ap");
    //qDebug() << currentTime;
    setCurrentTime(currentTime);

    m_currentTimeTimer->start();
}
