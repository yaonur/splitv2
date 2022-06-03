
#include "Key_declerations.h"

int c1 = 2;
int c2 = 3;
int c3 = 4;
int c4 = 5;
int c5 = 6;
int c6 = 7;
int rest = 9;
int r1 = 15;
int r2 = 14;
int r3 = 16;
int r4 = 10;

void setup()
{
  // put your setup code here, to run once:
  pinMode(c1, INPUT_PULLUP);
  pinMode(c2, INPUT_PULLUP);
  pinMode(c3, INPUT_PULLUP);
  pinMode(c4, INPUT_PULLUP);
  pinMode(c5, INPUT_PULLUP);
  pinMode(c6, INPUT_PULLUP);
  pinMode(rest, INPUT_PULLUP);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);

  Serial.begin(9600);
  Serial1.begin(9600);
  Keyboard.begin();
  debugln("setup comlete");
  // delay(4000);
}
void process_serial()
{
  int key_num = Serial1.read();
  // debug("kye num from serial read");
  // debugln(key_num);
  if (key_num == 1 || key_num == 129)
  {
    slave_r1c1.process_slave(key_num);
  }
  if (key_num == 2 || key_num == 130)
  {
    slave_r1c2.process_slave(key_num);
  }
  if (key_num == 3 || key_num == 131)
  {
    slave_r1c3.process_slave(key_num);
  }
  if (key_num == 4 || key_num == 132)
  {
    slave_r1c4.process_slave(key_num);
  }
  if (key_num == 5 || key_num == 133)
  {
    slave_r1c5.process_slave(key_num);
  }
  if (key_num == 6 || key_num == 134)
  {
    slave_r1c6.process_slave(key_num);
  }

  if (key_num == 7 || key_num == 135)
  {
    slave_r2c1.process_slave(key_num);
  }
  if (key_num == 8 || key_num == 136)
  {
    slave_r2c2.process_slave(key_num);
  }
  if (key_num == 9 || key_num == 137)
  {
    slave_r2c3.process_slave(key_num);
  }
  if (key_num == 10 || key_num == 138)
  {
    slave_r2c4.process_slave(key_num);
  }
  if (key_num == 11 || key_num == 139)
  {
    slave_r2c5.process_slave(key_num);
  }
  if (key_num == 12 || key_num == 140)
  {
    slave_r2c6.process_slave(key_num);
  }

   if (key_num == 13 || key_num == 141)
  {
    slave_r3c1.process_slave(key_num);
  }
  if (key_num == 14 || key_num == 142)
  {
    slave_r3c2.process_slave(key_num);
  }
  if (key_num == 15 || key_num == 143)
  {
    slave_r3c3.process_slave(key_num);
  }
    if (key_num == 16 || key_num == 144)
  {
    slave_r3c4.process_slave(key_num);
  }
  if (key_num == 17 || key_num == 145)
  {
    slave_r3c5.process_slave(key_num);
  }
  if (key_num == 18 || key_num == 146)
  {
    slave_r3c6.process_slave(key_num);
  }


  if (key_num == 19 || key_num == 147)
  {
    slave_r4c3.process_slave(key_num);
  }
    if (key_num == 20 || key_num == 148)
  {
    slave_r4c4.process_fn_slave(key_num);
  }
  if (key_num == 21 || key_num == 149)
  {
    slave_r4c5.process_slave(key_num);
  }
  if (key_num == 22 || key_num == 150)
  {
    slave_r4c6.process_slave(key_num);
  }


  

}

void loop()
{
  if (digitalRead(rest) == LOW)
    delay(5000);

  if (Serial1.available() > 0)
    process_serial();

  digitalWrite(r1, LOW);
  r1c1.process_master(c1);
  r1c2.process_master(c2);
  r1c3.process_master(c3);
  r1c4.process_master(c4);
  r1c5.process_master(c5);
  r1c6.process_master(c6);
  digitalWrite(r1, HIGH);

  digitalWrite(r2, LOW);
  r2c1.process_master(c1);
  r2c2.process_master(c2);
  r2c3.process_master(c3);
  r2c4.process_master(c4);
  r2c5.process_master(c5);
  r2c6.process_master(c6);
  digitalWrite(r2, HIGH);

  digitalWrite(r3, LOW);
  r3c1.process_master(c1);
  r3c2.process_master(c2);
  r3c3.process_master(c3);
  r3c4.process_master(c4);
  r3c5.process_master(c5);
  r3c6.process_master(c6);
  digitalWrite(r3, HIGH);

  digitalWrite(r4, LOW);
  r4c3.process_master(c3);
  r4c4.process_master(c4);
  r4c5.process_fn_master(c5);
  r4c6.process_master(c6);
  digitalWrite(r4, HIGH);
  delay(20);

  // swrite();
  // swrite();
  // sread();
}