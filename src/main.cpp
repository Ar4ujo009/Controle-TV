
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ArduinoJson.h>
//-----------------
#include "WiFiManager.h"
#include "MQTTmanager.h"
#include "DebugManager.h"
#include "secrets.h"

const uint16_t pinIR = 4; //?Pino onde o LED IR está conectado. 

 
const uint32_t codigoPower = 0x20DF10EF;
const uint32_t codigoVolMais = 0x20DF40BF;
const uint32_t codigoVolMenos = 0x20DFC03F;
const uint32_t codigoSetaDireita = 0x20DF609F;
const uint32_t codigoSetaEsquerda = 0x20DFE01F
const uint32_t codigoSetaCima = 0x20DF02FD;
const uint32_t codigoSetaBaixo = 0x20DF827D;
const uint32_t codigoOK = 0x20DF22DD;

const char TOPICO_COMANDO[] = "senai134/dev/yoshi/teste";

IRsend irsend(pinIR); //?Cria um objeto IRsend para controlar o LED IR conectado ao pino especificado.



void tratarMensagemRecebida(const char *topico, const String &mensagem);
void tratarJsonComando(const String &mensagem);
void PowerTV();
void VolumeMais();
void VolumeMenos();


void setup()
{
    // Inicia serial
    Serial.begin(115200);
    irsend.begin();

    configurarDebug();  //?Configura o sistema de debug (geralmente para monitorar o status do dispositivo e mensagens de erro).

    conectarWifi();
    conectarMQTT();
    registrarCallbackMensagem(tratarMensagemRecebida);
    conectarMQTT();
}

void loop()
{
    garantirWifiConectado();
    garantirMQTTConectado();
    loopMQTT();
}   

// TODO - Adicionar DebugInfo e DebugErro para monitorar o status do dispositivo e mensagens de erro.
// TODO - Criar função para tratar o JSON recebido via MQTT e executar as ações correspondentes (Ligar/Desligar TV, Aumentar/Diminuir Volume).





void PowerTV()
{
  irsend.sendLG(codigoPower, 32);
  debugInfo("TV Ligada/Desligada"); 
}

void VolumeMais()
{
  irsend.sendLG(codigoVolMais, 32);
  debugInfo("Volume Aumentado");
}

void VolumeMenos()
{
  irsend.sendLG(codigoVolMenos, 32);
  debugInfo("Volume Diminuido");
}

void ShareTela()
{
  // TODO - Implementar macro de sequencia para compartilhar tela


}

void SetaDireita()
{
  irsend.sendLG(codigoSetaDireita, 32);
  debugInfo("Seta Direita");
}

void SetaEsquerda()
{
  irsend.sendLG(codigoSetaEsquerda, 32);
  debugInfo("Seta Esquerda");
}

void SetaCima()
{
  irsend.sendLG(codigoSetaCima, 32);
  debugInfo("Seta Cima");
}

void SetaBaixo()
{
  irsend.sendLG(codigoSetaBaixo, 32);
  debugInfo("Seta Baixo");
}   

void OK()
{
  irsend.sendLG(codigoOK, 32);
  debugInfo("OK");
}