#define LED_VERDE  11
#define LED_AMARELO  12
#define LED_VERMELHO  13
#define TMP36 A0 

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valor_analogico = 0;
  double temperatura = 0;
  
  valor_analogico = analogRead(TMP36);
  temperatura = (500/1023);
  temperatura = (double)(temperatura * valor_analogico) - 50;
  Serial.print(temperatura);
  
  if(temperatura <= 20){
    digitalWrite(LED_VERDE,HIGH);
    digitalWrite(LED_AMARELO,LOW);
    digitalWrite(LED_VERMELHO,LOW);
  }
  if(temperatura >20 && temperatura<=50){
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(LED_AMARELO,HIGH);
    digitalWrite(LED_VERMELHO,LOW);
  }
  if(temperatura >50){
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(LED_AMARELO,LOW);
    digitalWrite(LED_VERMELHO,HIGH);
  }
}
