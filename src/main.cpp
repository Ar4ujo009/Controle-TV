
#include <Arduino.h>  
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ArduinoJson.h>
//-----------------


const uint16_t pinIR = 10; //?Pino onde o LED IR está conectado. 

 
const uint32_t codigoPower = 0x20DF10EF;
const uint32_t codigoVolMais = 0x20DF40BF;
const uint32_t codigoVolMenos = 0x20DFC03F;
const uint32_t codigoSetaDireita = 0x20DF609F;
const uint32_t codigoSetaEsquerda = 0x20DFE01F;
const uint32_t codigoSetaCima = 0x20DF02FD;
const uint32_t codigoSetaBaixo = 0x20DF827D;
const uint32_t codigoSelect = 0x20DF22DD;
const uint32_t codigoBack = 0x20DF14EB;
const char TOPICO_COMANDO[] = "senai134/dev/yoshi/teste";

IRsend irsend(pinIR); //?Cria um objeto IRsend para controlar o LED IR conectado ao pino especificado.


void PowerTV();
void VolumeMais();
void VolumeMenos();
void SetaDireita();
void SetaEsquerda();
void SetaCima();
void SetaBaixo();
void Select();
void Back();

void setup()
{
    // Inicia serial
    Serial.begin(115200);
    irsend.begin();
   

    SetaBaixo();
}

void loop()
{


}   


//---------------------------------------------
//---------COMANDOS DE TELA-------------------
//---------------------------------------------
void PowerTV()
{
  irsend.sendNEC(codigoPower, 32);
  Serial.println("TV Ligada/Desligada"); 
}

void VolumeMais()
{
  irsend.sendNEC(codigoVolMais, 32);
  Serial.println("Volume Aumentado");
}

void VolumeMenos()
{
  irsend.sendNEC(codigoVolMenos, 32);
  Serial.println("Volume Diminuido");
}

//---------------------------------------------
//---------DIRECIONAIS E OK--------------------
//---------------------------------------------

void SetaDireita()
{
  irsend.sendNEC(codigoSetaDireita, 32);
  Serial.println("Seta Direita");
}

void SetaEsquerda()
{
  irsend.sendNEC(codigoSetaEsquerda, 32);
  Serial.println("Seta Esquerda");
}

void SetaCima()
{
  irsend.sendNEC(codigoSetaCima, 32);
  Serial.println("Seta Cima");
}

void SetaBaixo()
{
  irsend.sendNEC(codigoSetaBaixo, 32);
  Serial.println("Seta Baixo");
}   

void Select()
{
  irsend.sendNEC(codigoSelect, 32);
  Serial.println("Select");
}

void Back()
{
  irsend.sendNEC(codigoBack, 32);
  Serial.println("Back");
}