#include "SPI.h" 
#include "MFRC522.h"

const int block1 = 2;
const int block2 = A3;
const int seg1 = 3;
const int seg2 = 4;
const int seg3 = 5;
const int seg4 = 6;
const int seg5 = 7;
const int seg6 = 8;
const int seg7 = A2;
unsigned long previoustime = 0;
unsigned long start_time = millis();
int card_count = 0;

#define SS_PIN 10 
#define RST_PIN 9 
#define SP_PIN 8

MFRC522 rfid (SS_PIN, RST_PIN);

MFRC522 :: MIFARE_Key key;

void setup () {
  Serial.begin (9600);
  SPI.begin ();
  rfid.PCD_Init ();

  pinMode(block1, OUTPUT);
  pinMode(block2, OUTPUT);
  pinMode(seg1, OUTPUT);
  pinMode(seg2, OUTPUT);
  pinMode(seg3, OUTPUT);
  pinMode(seg4, OUTPUT);
  pinMode(seg5, OUTPUT);
  pinMode(seg6, OUTPUT);
  pinMode(seg7, OUTPUT);
}

void loop () {
  
    start_time = millis();
    zerod();
//    delay(500);
   if (! rfid.PICC_IsNewCardPresent () ||! rfid.PICC_ReadCardSerial ())
     return ;

  // Serial.print (F ("PICC type:"));
  MFRC522 :: PICC_Type piccType = rfid.PICC_GetType (rfid.uid.sak);
  // Serial.println (rfid.PICC_GetTypeName (piccType));

  // Check is the PICC of Classic MIFARE type 
  if ( piccType != MFRC522 :: PICC_TYPE_MIFARE_MINI && piccType != MFRC522 :: PICC_TYPE_MIFARE_1K && piccType != MFRC522 :: PICC_TYPE_MIFARE_4K) {
    Serial.println (F ( "Your tag is not of type MIFARE Classic." ));
    return ;
  }

  String strID = "" ;
  for (byte i = 0; i <4; i ++) {
    strID = strID + 
    (rfid.uid.uidByte [i] <0x10? "0" : "" ) +
    String (rfid.uid.uidByte [i], HEX) + ( i!= 3? ":" : "" );
  }
  strID.toUpperCase ();

  // When this variable to store the UID of the tag strID already 
  // able to use it as input to IF to tube 
  // LED illuminated or extinguished 
//  Serial.print ( "Developer Tap Key Card. :" );
  Serial.println (strID);
  card_count = card_count + 1;
//  if (card_count == 1){
//    oned();
//    delay(1000);
//  }
//  if (card_count == 2){
//    twod();
//    delay(1000);
//  }
  Serial.println(card_count);
  
  rfid.PICC_HaltA ();
  rfid.PCD_StopCrypto1 ();

//  char inByte = ' ';
//  if(Serial.available()){ // only send data back if data has been sent
//  char inByte = Serial.read(); // read the incoming data
//  Serial.println(inByte); // send the data back in a new line so that it is not all one long line
//
//}


switch (card_count) {
  case 0:
    zerod();
    delay(2000);
    break;
  case 1:
    oned();
    delay(2000);
    break;
  case 2:
    twod();
    delay(2000);
    break;
  case 3:
    threed();
    delay(2000);
    break;
  case 4:
    fourd();
    delay(2000);
    break;
  case 5:
    fived();
    delay(2000);
    break;
  case 6:
    sixd();
    delay(2000);
    break;
  case 7:
    sevend();
    delay(2000);
    break;
  case 8:
    eightd();
    delay(2000);
    break;
  case 9:
    nined();
    delay(2000);
    break;
  case 10:
for (int i = 0; i <= 40; i++){
    tend();
 }
    break;
  case 11:
for (int i = 0; i <= 40; i++){
    elevend();
 }
    break;
  case 12:
for (int i = 0; i <= 40; i++){
    twelved();
 }
 
    break;
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
}

//number zero
void zerod(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, LOW);
}

//number one
void oned(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, LOW);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, LOW);
}

//number two
void twod(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, LOW);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
}

//number three
void threed(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
}

//number four
void fourd(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, LOW);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
}

//number five
void fived(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, LOW);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
}

//number six
void sixd(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, LOW);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
}

//number seven 
void sevend(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
}

//number eight
void eightd(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
}

//number nine
void nined(){
  digitalWrite(block1, HIGH);
  digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
}

//number ten 
void tend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
    digitalWrite(block1, LOW);
    digitalWrite(block2, HIGH);
    digitalWrite(seg1, HIGH);
    digitalWrite(seg2, HIGH);
    digitalWrite(seg3, HIGH);
    digitalWrite(seg4, HIGH);
    digitalWrite(seg5, HIGH);
    digitalWrite(seg6, HIGH);
    digitalWrite(seg7, LOW);
    delay(10);
  }
}

//number eleven 
void elevend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, LOW);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, LOW);
    delay(10);
  }
}

//number twelve
void twelved(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, LOW);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}



//number thirteen
void thirteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}

//number fourteen
void fourteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, LOW);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}

//number fifteen
void fifteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, LOW);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}


//number sixteen
void sixteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, LOW);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}


//number seventeen
void seventeend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}



//number eighteen
void eighteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}


//number nineteen
void nineteend(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
      digitalWrite(seg1, LOW);
      digitalWrite(seg2, HIGH);
      digitalWrite(seg3, HIGH);
      digitalWrite(seg4, LOW);
      digitalWrite(seg5, LOW);
      digitalWrite(seg6, LOW);
      digitalWrite(seg7, LOW);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, LOW);
  digitalWrite(seg5, LOW);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, HIGH);
    delay(10);
  }
}

//number twenty
void twentyd(){
    if (start_time - previoustime >= 0){
      previoustime = start_time;
      digitalWrite(block1, HIGH);
      digitalWrite(block2, LOW);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, LOW);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, LOW);
  digitalWrite(seg7, HIGH);
      delay(10);
}

  if (start_time - previoustime >= 0){
  digitalWrite(block1, LOW);
  digitalWrite(block2, HIGH);
  digitalWrite(seg1, HIGH);
  digitalWrite(seg2, HIGH);
  digitalWrite(seg3, HIGH);
  digitalWrite(seg4, HIGH);
  digitalWrite(seg5, HIGH);
  digitalWrite(seg6, HIGH);
  digitalWrite(seg7, LOW);
    delay(10);
  }
}
