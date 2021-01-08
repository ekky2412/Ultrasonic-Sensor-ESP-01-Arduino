#include <SoftwareSerial.h>

#define RX 3
#define TX 2
#define echo_pin 8
#define trigger_pin 9

String AP = "RAFHY.2324";       // WIFI NAME
String PASS = "pakdokipunyaanak"; // WIFI PASSWORD
String HOST = "192.168.100.48";  // UBAH SESUAI DENGAN IP DARI WEBSITENYA
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
  
SoftwareSerial esp8266(RX,TX); 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
  setupUltrasonic();
}

void loop() {
 String getData = "GET /iot/insert.php?jarak="+getJarakValue();
 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
}

void setupUltrasonic(){
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}

String getJarakValue(){

   Serial.print(" Jarak (cm)= ");
   digitalWrite(trigger_pin, LOW); delayMicroseconds(2);
   digitalWrite(trigger_pin, HIGH);delayMicroseconds(10);
   digitalWrite(trigger_pin, LOW);
   long duration = pulseIn(echo_pin,HIGH);
   long distance = duration/29/2;
   Serial.println(distance); 
   delay(50);
   return String(distance); 
  
}


void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OK");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
