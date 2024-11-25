#include <NewPing.h>  //Librería para el HC-SR04

#define STBY 6 //StandBy. Funciona con lógica inversa.
//--------Motor A - Derecho
#define PWMA 3 //Control de velocidad
#define AIN1 4 //Dirección
#define AIN2 5 //Dirección

//-------Motor B - Izquierdo
#define PWMB 9 //Control de velocidad
#define BIN1 7 //Dirección
#define BIN2 8 //Dirección

//-------Sensor Ultrasonidos
#define pinEcho 10
#define pinTrigger 11

//---- Variables
unsigned long tiempo, distancia;
NewPing sonar(pinTrigger,pinEcho);

void setup() {
  //Inicializamos pines de motores
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  /*
  tiempo = sonar.ping_median();
  distancia = tiempo / US_ROUNDTRIP_CM;
  Serial.print("Distancia...");
  Serial.println(distancia);
  delay(100);

  if (distancia < 10){
    parar();
   }
   else {
      adelante();
    }
  */
  adelante();
  delay(1000);
  parar();
  delay(2000);
  atras();
  delay(1000);
  parar();
  delay(2000);
  
}

void atras(){
  digitalWrite(STBY,HIGH); //Activa los motores
   //Adelante (Cuidado, tener en cuenta cómo se conectan los cables del motor)
 
 digitalWrite(STBY,HIGH); //Activa los motores
  digitalWrite(PWMA,60);    //Motor Derecho (A)
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);

  digitalWrite(PWMB,60);    //Motor Izquierdo (B)
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW); 
}

void adelante(){
  digitalWrite(STBY,HIGH); //Activa los motores
   //Atrás (Cuidado, tener en cuenta cómo se conectan los cables del motor)
  digitalWrite(PWMA,100);  //Motor Derecho (A)
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  
  digitalWrite(PWMB,100);  //Motor Izquierdo (B)
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
}

void parar(){
  digitalWrite(STBY,LOW);
}
