// C++ code
//
// Arduino UNO - Lab Sistemas Computacionais
const int btn = 2; 
const int red = 6;
const int yellow = 4;
const int green = 3; 

void light(int, unsigned long);
void restart_lights();
void interruption();
void timer(int);

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  
  light(red, 15000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
}

void light(int btnled, unsigned long time) {
  
    if (btnled == red) {
      interruption();
      digitalWrite(red, HIGH);
      timer(time); 
    } else if (btnled == yellow) {
      interruption();
      digitalWrite(yellow, HIGH); 
      timer(time); 
    } else if (btnled == green) {
      interruption();
      digitalWrite(green, HIGH);
      timer(time); 
    }
}

void restart_lights() {
  
  light(red, 10000);
  light(yellow, 5000);
  light(green, 15000);
  light(yellow, 5000);
}

void interruption() { //Apaga todas as LEDs
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}  

void timer(int time){
  /*Funcao para quebrar o delay em ciclos pequenos 
  para poder verificar o botao a cada instante*/
  int count = 0;
  for (count=0; count <= time; count += 100) {
  	// Verifica o botão a cada intervalo definido
    if (digitalRead(btn) == LOW) {
      restart_lights(); 
      return;
    }
    delay(100);
  }
}
