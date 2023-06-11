#include<Embedded_Protocol_2.h>
#include<ArduinoJson.h>
#include <Servo.h>

Communication communication;

Servo rpServo1;
Servo rpServo2;
Servo rpServo3;
Servo rpServo4;

#define botao1 0
#define botao2 1
#define botao3 2
#define botao4 3
#define pinoServo1 10
#define pinoServo2 11
#define pinoServo3 12
#define pinoServo4 13

int att = 1;
int buff = 0;
int rack = 0;
int mov = 0;
int pos = 0;
int b = 0;
int r = 0;

void setup()
{
  Serial.begin(9600);
  Serial.print("iniciando....");
  rpServo1.attach(pinoServo1);
  rpServo2.attach(pinoServo2);
  rpServo3.attach(pinoServo3);
  rpServo4.attach(pinoServo4);
  pinMode(botao1, INPUT);
  attachInterrupt(digitalPinToInterrupt(botao1),capture1, RISING);
  pinMode(botao2, INPUT);
  attachInterrupt(digitalPinToInterrupt(botao2),capture2, RISING);
  pinMode(botao3, INPUT);
  attachInterrupt(digitalPinToInterrupt(botao3),capture3, RISING);
  pinMode(botao4, INPUT);
  attachInterrupt(digitalPinToInterrupt(botao4),capture4, RISING);
  rpServo1.write(110);
  rpServo2.write(30);
  rpServo3.write(180);
  rpServo4.write(125);

  delay(10000); //wait 30 seconds (to set up the multi-agent system)
}

void capture1(){
 buff = 0;
 att = 1;
}

void capture2(){
 buff = 1;
 att = 1;
}

void capture3(){
 rack = 0;
 att = 1;
}

void capture4(){
 rack = 1;
 att = 1;
}


void loop()
{ 
  while(Serial.available() > 0){
     String s = Serial.readString();
     if(s.equals("captBuffer")){
      att = 1;
      for(pos = 110; pos >= 5; pos -= 1){
        rpServo1.write(pos);
        delay(15);
      }
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 125; pos <= 170; pos += 1){
        rpServo4.write(pos);
        delay(15);
      }
      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 5; pos <= 175; pos += 1){
        rpServo1.write(pos);
        delay(15);
      }
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 170; pos >= 125; pos -= 1){
        rpServo4.write(pos);
        delay(15);
      }
      rack = 1;

      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 175; pos >= 110; pos -= 1){
        rpServo1.write(pos);
        delay(15);
      }
      buff = 0;
      mov = 0;
    }

    if(s.equals("captRack")){
      for(pos = 110; pos <= 175; pos += 1){
        rpServo1.write(pos);
        delay(15);
      }
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 125; pos <= 170; pos += 1){
        rpServo4.write(pos);
        delay(15);
      }
      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      rack = 0;
      
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 175; pos >= 110; pos -= 1){
        rpServo1.write(pos);
        delay(15);
      }
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 170; pos >= 125; pos -= 1){
        rpServo4.write(pos);
        delay(15);
      }
      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
    }

    if(s.equals("captCar")){
      att = 1;
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 125; pos <= 170; pos += 1){
        rpServo4.write(pos);
        delay(15);
      }
      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 110; pos <= 175; pos += 1){
        rpServo1.write(pos);
        delay(15);
      }
      for(pos = 30; pos <= 120; pos += 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 180; pos >= 115; pos -= 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 170; pos >= 125; pos -= 1){
        rpServo4.write(pos);
        delay(15);
      }
      rack = 1;

      for(pos = 115; pos <= 180; pos += 1){
        rpServo3.write(pos);
        delay(15);
      }
      for(pos = 120; pos >= 30; pos -= 1){
        rpServo2.write(pos);
        delay(15);
      }
      for(pos = 175; pos >= 110; pos -= 1){
        rpServo1.write(pos);
        delay(15);
      }
      mov = 0;
     }
     
     if(s.equals("movArm")){
      att = 1;
      mov = 1;
     }
   }

  if(att == 1){
    communication.startBelief("buffer");
    communication.beliefAdd(buff);
    communication.endBelief();
    communication.startBelief("rack");
    communication.beliefAdd(rack);
    communication.endBelief();
    communication.startBelief("movimentando");
    communication.beliefAdd(mov);
    communication.endBelief();
    communication.sendMessage();
    att = 0;
  }
}
