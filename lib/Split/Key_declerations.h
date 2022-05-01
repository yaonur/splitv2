#include "Keys.cpp"

Keys r1c1(KEY_TAB, '`', KEY_F12); // tab ` f12
Keys r1c2('q', '1', KEY_F1);	  // q and 1 fq1
Keys r1c3('w', '2', KEY_F2);	  // w and 2 f2
Keys r1c4('e', '3', KEY_F3);	  // e and 3 f3
Keys r1c5('r', '4', KEY_F4);	  // r and 4 f4
Keys r1c6('t', '5', KEY_F5);	  // t and 5 f5

Keys r2c1(KEY_ESC, '~', 0, KEY_RIGHT_CTRL);	   // esc and ~
Keys r2c2('a', '\\', 0, KEY_LEFT_SHIFT, true); // a and
Keys r2c3('s', '|');						   // s and |
Keys r2c4('d', '(');						   // d and (
Keys r2c5('f', ')');						   // f and )
Keys r2c6('g', '&');						   // g and &

Keys r3c1(KEY_LEFT_GUI); // key left gui
Keys r3c2('z', '!');	 // z and !
Keys r3c3('x', '@');	 // x and @
Keys r3c4('c', '#');	 // c and#
Keys r3c5('v', '$');	 // v and $
Keys r3c6('b', '^');	 // b and ^

Keys r4c3(129); // caps
Keys r4c4(KEY_SPACE);	  // space
Keys r4c5(0);			  // fn
Keys r4c6(KEY_RIGHT_ALT); // right alT

Keys slave_r1c1('[', KEY_BACKSPACE, KEY_F11); // [ backspace f11
Keys slave_r1c2('p', '0', KEY_F6);			  // f6
Keys slave_r1c3('o', '9', KEY_F7);			  // f7
Keys slave_r1c4('i', '8', KEY_F8);			  // f8
Keys slave_r1c5('u', '7', KEY_F9);			  // f9
Keys slave_r1c6('y', '6', KEY_F10);			  // f10

Keys slave_r2c1('\'', '_', 0);											// esc and ~
Keys slave_r2c2(';', KEY_DELETE, KEY_BACKSPACE, KEY_RIGHT_SHIFT, true); // a and
Keys slave_r2c3('l', KEY_RIGHT_ARROW, KEY_END);							// s and |
Keys slave_r2c4('k', KEY_UP_ARROW, KEY_PAGE_UP);						// d and (
Keys slave_r2c5('j', KEY_DOWN_ARROW, KEY_PAGE_DOWN);					// 214);			 // f and )
Keys slave_r2c6('h', KEY_LEFT_ARROW, KEY_HOME);							// g and &

Keys slave_r3c1(']', KEY_DELETE); // key left gui
Keys slave_r3c2('/', '=');		  // z and !
Keys slave_r3c3('.', '%');		  // x and @
Keys slave_r3c4(',', '*');		  // c and#
Keys slave_r3c5('m', '+');		  // v and $
Keys slave_r3c6('n', '-');		  // b and ^

Keys slave_r4c3(KEY_RIGHT_ALT);	  // right alt
Keys slave_r4c4(KEY_RETURN);	  // return
Keys slave_r4c5(0);				  // fn
Keys slave_r4c6(KEY_PRINTSCREEN); // printscreen