#ifndef ARDUINOBLINKERSTATE_H
#define ARDUINOBLINKERSTATE_H

#include <QObject>

class ArduinoBlinkerState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool led_state READ led_state WRITE setled_state NOTIFY led_stateChanged)

public:
    explicit ArduinoBlinkerState(QObject *parent = nullptr);

    bool led_state() const;
    void setled_state(bool newLed_state);
    Q_INVOKABLE void switch_led_state();
signals:

    void led_stateChanged(bool newLed_state);
private:
    bool m_led_state;
};

#endif // ARDUINOBLINKERSTATE_H
