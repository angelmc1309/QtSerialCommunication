#include "arduinoblinkerstate.h"

ArduinoBlinkerState::ArduinoBlinkerState(QObject *parent)
    : QObject{parent},
    m_led_state(false)
{

}

bool ArduinoBlinkerState::led_state() const
{
    return m_led_state;
}

void ArduinoBlinkerState::setled_state(bool newLed_state)
{
    if (m_led_state == newLed_state)
        return;
    m_led_state = newLed_state;
    emit led_stateChanged(newLed_state);
}

void ArduinoBlinkerState::switch_led_state()
{
    setled_state(!led_state());
}
