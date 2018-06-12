#pragma once
#include <Arduino.h>

class hthing
{
  public:
	/**
	 * Attaches an H-THING to pins on the TINAH/Arduino/Blue Pill
	 * 
	 * Speed pin should be a PWM pin, direction should be a regular digital I/O
	 * Be careful when enterning the pins here; you could burn something out.
	 */
	hthing(int speed_pin, int direction_pin);
	/**
	 * Runs the motor in the specified direction, with the specified speed
	 * 
	 * Direction must be 1 for forward, 0 for backward.
	 * Speed must be an integer between 0 (full stop) and 255 (max speed) inclusive.
	 * All other conditions will result in a motor stop.
	 */
	void run(int direction, int speed);
	/**
	 * Runs the motor with the specified vector.
	 * 
	 * Parameter must be a number between -255 and 255.
	 * All other conditions will result in a motor stop.
	 */
	void run(int vector);
	/**
	 * Stops the motor
	 */
	void stop();

  private:
	int speed_pin;
	int direction_pin;
};
