#define USUP_ECHO1 2
#define USUP_TRIG1 3
#define Pump 7
#define Buzz 6
#define Led 5

void beep(){
   digitalWrite(Buzz, HIGH);  
   delay(500); 
   digitalWrite(Buzz, LOW);}

void setup() {
  pinMode(Pump,OUTPUT);  
  pinMode(Led,OUTPUT); 
  pinMode(USUP_ECHO1,INPUT);
  pinMode(USUP_TRIG1,OUTPUT);   
  pinMode(Buzz,OUTPUT);
  Serial.begin(9600);
  digitalWrite(Pump,HIGH);
}

int flag=0;
void loop() {
    long duration1,distance1;
     digitalWrite(USUP_TRIG1, LOW);  
     delayMicroseconds(2); 
     digitalWrite(USUP_TRIG1, HIGH);
     delayMicroseconds(10); 
     digitalWrite(USUP_TRIG1, LOW);
     duration1 = pulseIn(USUP_ECHO1, HIGH);
     distance1 = (duration1/2) / 29.1;
     if (distance1>35)
        {distance1=0;}
    else{distance1=map(distance1,0,35,100,0);}
     
     Serial.print("L ");
     Serial.print(distance1);
     
   if(distance1<20)
     {
      digitalWrite(Led,HIGH); 
      digitalWrite(Pump,LOW);      
      Serial.print("P1");beep();}
   else{
        digitalWrite(Led,LOW); 
        digitalWrite(Pump,HIGH);      
        Serial.print("P0");}   
   Serial.println();    
   delay(15000);
   
}                                                
