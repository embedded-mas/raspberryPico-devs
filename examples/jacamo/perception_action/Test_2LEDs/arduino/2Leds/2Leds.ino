#include<Embedded_Protocol_2.h>
#include<ArduinoJson.h>

#define botao1 21
#define botao2 18
#define led1  28
#define led2  27

Communication communication;
const int capacity = JSON_OBJECT_SIZE(6);
StaticJsonDocument<capacity> doc;
int interrupt1 = 0;
int interrupt2 = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(botao1),lidaLed1, RISING);
  attachInterrupt(digitalPinToInterrupt(botao2),lidaLed2, RISING);
}

void lidaLed1(){
 interrupt1 = 1;
}

void lidaLed2(){
 interrupt2 = 1;
}

void loop()
{
 if(interrupt1){
  if(digitalRead(led1)){
   communication.startBelief("light_state1");
   communication.beliefAdd(0);
   communication.endBelief();
   communication.sendMessage();
  }
  else{
   communication.startBelief("light_state1");
   communication.beliefAdd(1);
   communication.endBelief();
   communication.sendMessage();
  }
 }
 interrupt1 = 0;
 
 if(interrupt2){
  if(digitalRead(led2)){
   communication.startBelief("light_state2");
   communication.beliefAdd(0);
   communication.endBelief();
   communication.sendMessage();
  }
  else{
   communication.startBelief("light_state2");
   communication.beliefAdd(1);
   communication.endBelief();
   communication.sendMessage();
  }
 }
 interrupt2 = 0;


 while(Serial.available() > 0){ //check whether there is some information from the serial (possibly from the agent)
      String s = Serial.readString();
      if(s.equals("light_on1")){ //if the agent sends "light_on", then switch the light on
         digitalWrite(led1,1);
      }
      if(s.equals("light_off1")){ //if the agent sends "light_on", then switch the light on
         digitalWrite(led1,0);
      }
      if(s.equals("light_on2")){ //if the agent sends "light_on", then switch the light on
         digitalWrite(led2,1);
      }
      if(s.equals("light_off2")){ //if the agent sends "light_on", then switch the light on
         digitalWrite(led2,0); 
      }
    }
}
