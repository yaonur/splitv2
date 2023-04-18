#include <Arduino.h>
#include <Keyboard.h>
#include "Definitions.h"
const uint8_t DOUBLE_KEY_SCREEN_TIME = 160;
bool alt_one_status = false;
bool alt_one_pressed_with = false;
bool alt_two_status = false;
uint8_t is_shift_pressed = 0;

class Keys
{
public:
	uint8_t Primary;
	uint8_t Alt1;
	uint8_t Alt2;
	uint8_t Secondary;
	bool IsShift = false;
	unsigned long timer;
	char isPressed = 0;
	Keys(uint8_t primary, uint8_t alt1, uint8_t alt2, uint8_t secondary, bool is_shift);

	void process_master(uint8_t pin_num);
	void process_slave(uint8_t key_num);
	void process_keydown();
	void process_keyup();
	void process_fn_master(int pin_num);
	void process_fn_slave(int key_num);
};
Keys::Keys(uint8_t primary = 0, uint8_t alt1 = 0, uint8_t alt2 = 0, uint8_t secondary = 0, bool is_shift = 0)
{
	Primary = primary;
	Alt1 = alt1;
	Alt2 = alt2;
	Secondary = secondary;
	IsShift = is_shift;
}

void Keys::process_master(uint8_t pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressed == 0)
	{
		process_keydown();
	}
	else if (digitalRead(pin_num) == HIGH && isPressed)
	{
		process_keyup();
	}
}
void Keys::process_slave(uint8_t key_num)
{
	if (key_num < 128 && isPressed == 0)
	{
		process_keydown();
	}
	else if (isPressed)
	{
		process_keyup();
	}
}

void Keys::process_keydown()
{
	if (alt_one_status && !Alt1 == 0)
	{
		isPressed = Alt1;
		Keyboard.press(Alt1);
		alt_one_pressed_with = true;
	}
	else if (alt_two_status && !Alt2 == 0)
	{
		isPressed = Alt2;
		Keyboard.press(Alt2);
	}
	else if (Secondary)
	{
		debug("have secondary and is shift is:");
		debugln(IsShift);
		debug("is_shift pressed is:");
		debugln(is_shift_pressed);
		if (IsShift && is_shift_pressed)
		{
			debug("isshift:");
			debugln(Secondary);
			Keyboard.press(Primary);
			isPressed = Primary;
			return;
		}
		else if (IsShift)
		{
			is_shift_pressed = Secondary;
		}
		timer = millis();
		Keyboard.press(Secondary);
		isPressed = Secondary;
		return;
	}
	else
	{
		isPressed = Primary;
		Keyboard.press(Primary);
	}
}

void Keys::process_keyup()
{
	if (Secondary)
	{

		if (millis() - timer < DOUBLE_KEY_SCREEN_TIME)
		{
			Keyboard.release(Secondary);
			Keyboard.write(Primary);
			isPressed = 0;
			if (IsShift)
				is_shift_pressed = 0;
			return;
		}
		if (IsShift && is_shift_pressed == Secondary)
			is_shift_pressed = 0;
	}
	Keyboard.release(isPressed);
	isPressed = 0;
}

void Keys::process_fn_master(int pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressed == 0)
	{
		timer = millis();
		alt_one_status = true;
		isPressed = 1;
	}
	else if (digitalRead(pin_num) == HIGH && isPressed)
	{
		if (millis() - timer < DOUBLE_KEY_SCREEN_TIME && alt_one_pressed_with == false)

		{
			Keyboard.write(Primary);
		}
		alt_one_status = false;
		alt_one_pressed_with = false;
		isPressed = 0;
	}
}

void Keys::process_fn_slave(int key_num)
{
	if (key_num < 128 && isPressed == 0)
	{
		timer = millis();
		alt_two_status = true;
		isPressed = 1;
	}
	else if (isPressed)
	{
		if (millis() - timer < DOUBLE_KEY_SCREEN_TIME)
		{

			Keyboard.write(Primary);
		}
		isPressed = 0;
		alt_two_status = false;
	}
}
