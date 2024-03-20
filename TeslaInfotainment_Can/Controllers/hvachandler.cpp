#include "hvachandler.h"

HVACHandler::HVACHandler(QObject *parent)
    : QObject(parent)
    , m_targetTemperature( 70 )
{

}

int HVACHandler::targetTemperature() const
{
    return m_targetTemperature;
}
void HVACHandler::incrementTargetTemperature(const int &val)
{
    //int newTargetTemp = m_targetTemperature + val;
    int newTargetTemp = m_targetTemperature + val;
    setTargetTemperature(newTargetTemp);//set메서드를 호출해야 속성에 반영된다. 그러니까 까먹지말고 넣어라
}
void HVACHandler::setTargetTemperature(int targetTemperature)
{
    if (m_targetTemperature == targetTemperature)
        return;
    m_targetTemperature = targetTemperature;
    emit targetTemperatureChanged(m_targetTemperature);
}
