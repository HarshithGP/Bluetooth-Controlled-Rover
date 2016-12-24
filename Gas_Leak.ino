int PIN = 7;

int sensor = 0;

void setup() {

pinMode (PIN,INPUT);

Serial.begin(9600);

delay(5000); }

void loop() {

sensor = digitalRead (PIN);

if (sensor == HIGH){

Serial.println("AT");

delay(1000);

Serial.println("AT+CMGF=1");

delay(1000);

Serial.println("AT+CMGS=\"+918892664210\""); //CHANGE TO DESTINATION NUMBER

delay(1000);

Serial.print("GAS LEAKAGE!!!!! Attention required");

Serial.write(26);

delay(300000); }

}
