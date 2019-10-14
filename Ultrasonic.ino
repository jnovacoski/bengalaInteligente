#include <Ultrasonic.h>

int trigger = 7;
int echo = 8;
int vibracall = 10;
long distancia;

Ultrasonic ultrasonic(trigger, echo);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(vibracall, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  distancia = ultrasonic.Ranging(CM);
  float valor;

  if(distancia > 100){
    Serial.println("Acima de um metro");
    Serial.println(potencia);
    digitalWrite(vibracall, 0);
    delay(100);
  } else {
    if(distancia != 0)
      valor = 100/distancia -1;
    valor = valor * 2.55;
    int potencia = (int) valor;
    digitalWrite(vibracall, potencia);
    Serial.println(potencia);
    delay(100);
  }

}
