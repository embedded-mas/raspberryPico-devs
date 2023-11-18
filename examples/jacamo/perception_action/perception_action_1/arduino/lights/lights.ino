#include<Embedded_Protocol_2_old.h>
#include<ArduinoJson.h>

Communication communication;

const int LIGHT = 10;

int delay_time;
int light_state = 1;
int var;
String t;
/*
String paramStr(String s){
    int var[10]={1};
    int n = s.length();
    int p1;
    char a='(';
    
    for (int i=0; i<=n; i++){
      if(s[i]==a){
        p1 = i;
      }
    }
    if(p1!=0){
      t = s.substring(0,p1);
    }
    else{
      t = s;
    }
    return t;
}

int paramInt(String s, int p=0){
    int var[10]={1};
    int p1=0, p2, d, v=0;
    char a='(', b=')', c = ',';
    int n = s.length();
    int p3[n-3];
  
    for (int i=0; i<=n; i++)
    {
      if(s[i]==c)
      {
        p3[v] = i;
        v++;
      }
    }
    
    for (int i=0; i<=n; i++){
      if(s[i]==a){
        p1 = i;
      }
      if(s[i]==b){
        p2 = i;
      }
    }

    if(p1!=0){
      char tC[10];
      for (int j=0; j<=v; j++){
        if(j==0){
          int d, p1aux;
            d = p3[j]-p1;
            p1aux = p1;
            for (int k=0; k<=d; k++){
              tC[k] = s[p1aux+1];
              p1aux++;
            }
            var[j] = atoi(tC);
        }
        if(j!=0 && j!=v){
          int d, p1aux;
            d = p3[j]-p3[j-1];
            p1aux = p3[j-1];
            for (int k=0; k<=d; k++){
              tC[k] = s[p1aux+1];
              p1aux++;
            }
            var[j] = atoi(tC);
        }
        if(j==v){
          int d, p1aux;
            d = p2-p3[j-1];
            p1aux = p3[j-1];
            for (int k=0; k<=d; k++){
              tC[k] = s[p1aux+1];
              p1aux++;
            }
            var[j] = atoi(tC);
        }
      }
    }
    else{
      var[0] = 1;
    }
    return var[p];
}
*/
void setup() 
{
  pinMode(LIGHT,OUTPUT);
  digitalWrite(LIGHT,1);  //light starts on
     
  Serial.begin(9600);
  Serial.print("iniciando....");
  // Build perception that the lihgt is on and send it to the upper layers 
  communication.startBelief("light_state");
  communication.beliefAdd(1);
  communication.endBelief();
  communication.sendMessage();
  delay(30000); //wait 20 seconds (to set up the multi-agent system)
}

void loop() 
{
  while(Serial.available() > 0){ //check whether there is some information from the serial (possibly from the agent)
    String s = Serial.readString();

    t = communication.paramStr(s);
    var = communication.paramInt(s, 0);
     
     if(t.equals("light_on")){ //if the agent sends "light_on", then switch the light on
        digitalWrite(LIGHT,1); 
        light_state = 1; 
        communication.startBelief("light_state");
        communication.beliefAdd(light_state);
        communication.endBelief();
        communication.sendMessage();
     } 
   }
  
  
  if(light_state==1){ 
    // wait a random time and switch the light off if it is on 
     //delay_time = random(2,10)*1000;
     delay_time = var*1000;
     delay(delay_time);
     digitalWrite(LIGHT,0);
     light_state = 0;
     communication.startBelief("light_state");
     communication.beliefAdd(light_state);
     communication.endBelief();
     communication.sendMessage();
     var = 1;
  }
}
