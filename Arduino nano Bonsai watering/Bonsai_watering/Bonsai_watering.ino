// aansluiting Relais in op D2
// aansluiting relais vcc en gnd op de arduino
// aansluiting 2e 5v op output relais
// aansluitng sensor A0
// aalsuiting sensor vcc en gnd op arduino



int pinOut = 2;

void setup()
{
  Serial.begin(9600); 
  pinMode(2, OUTPUT);

}
  
void loop()
{
   digitalWrite(pinOut, HIGH);
   delay(120000);    
   float sensor0 = analogRead(0);
   Serial.print("Vochtigheid: ");   
   Serial.println(sensor0);
    
  float sensor0P = 100.00 - ( ( 100.00 * sensor0 ) / 1023.00 );
  int sensorInt = (int) sensor0P;
  Serial.print("Vochtigheid procent: ");   
  Serial.println(sensorInt);   
     if (sensorInt <= 40){
        digitalWrite(pinOut, LOW);
        Serial.println("pomp");
        delay(300);
        digitalWrite(pinOut, HIGH);
  }
  else {
    digitalWrite(pinOut, HIGH);

  }
  
}