#include "hthing.h"

hthing::hthing(int passed_speed_pin, int passed_direction_pin)
{
    speed_pin = passed_speed_pin;
    direction_pin = passed_direction_pin;
    pinMode(speed_pin, OUTPUT);
    pinMode(direction_pin, OUTPUT);
    stop();
}

void run(int direction, int speed)
{
    if (speed >= 0 && speed <= 255)
    {
        if (direction == 0)
        {
            digitalWrite(direction_pin, LOW);
            analogWrite(speed_pin, 255 - speed);
        }
        else if (direction == 1)
        {
            digitalWrite(direction_pin, HIGH);
            analogWrite(speed_pin, speed);
        }
        else
        {
            stop();
        }
    }
    else
    {
        stop();
    }
}

void run(int vector)
{
    if (speed >= -255 && speed <= 255)
    {
        if (speed < 0)
        {
            run(0, -speed);
        }
        else
        {
            run(1, speed);
        }
    }
}

void stop()
{
    digitalWrite(direction_pin, HIGH);
    digitalWrite(speed_pin, HIGH);
}