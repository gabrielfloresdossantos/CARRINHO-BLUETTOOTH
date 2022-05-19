#include "BluetoothSerial.h"

// saidas que ligam as entradas na ponte H
int IN1 = 12;
int IN2 = 14;
int IN3 = 27;
int IN4 = 26;
int led1 = 34;
int led2 = 35;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
//#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#error Bluetooth não esta habilitado! Porfavor entre nas configurações e habilita o Bluetooth.
#endif

BluetoothSerial SerialBT;

void setup() {
  // declaração dos pinos
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

    Serial.begin(9600);
  SerialBT.begin("Carrinho Bluetooth"); //nome do dispositivo Bluetooth
 // Serial.println("O dispositivo foi iniciado, agora você pode emparelhá-lo com bluetooth!");
}

void loop() {
  char Z;
  if (SerialBT.available() > 0) {
    Z = SerialBT.read();
    
    /* habilitando esse comando voce consegue
    visualizar se esta recebendo os comandos do app*/
    
    // Serial.println(Z); 
    delay(20); // so para atualizar as informaçoes
    //PRA FRENTE
    if (Z == 'F') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    //PRA TRAS
    if (Z == 'B') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

    }

    // PRA ESQUERDA
    if (Z == 'L') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    //PRA DIREITA
    if (Z == 'R') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    // PARADO
    if (Z == 'S') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    if (Z == 'W') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    }
    if (Z == 'w') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }
}
