String readString;
#define WRITEPIN 3 // which pin to analogWrite()

void setup() {
  Serial.begin(57600);
  pinMode(WRITEPIN,OUTPUT);
  Serial.print("type a number 0-255 to analogWrite to pin ");
  Serial.println(WRITEPIN);
}

void loop() {

  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      if (c == char(13) || c == char(10)) {
        int val = readString.toInt();
        Serial.println(val); //see what was received
        analogWrite(WRITEPIN,val); // could also use myservo1.writeMicroseconds()
        readString = "";
      }
      else readString += c; //makes the string readString
    } 
  }
}
