/* 
========================================
CONTROLE IR TV LG COM ESP32-S3
========================================

Funcoes:
- Liga/Desliga TV
- Volume +
- Volume -

Comandos enviados pelo Monitor Serial

Digite:
P -> POWER
+ -> VOLUME +
- -> VOLUME -

========================================
*/

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// ======================================
//PINO DO LED INFRAVERMELHO
// ======================================

const uint16_t pinIR = 4;

// ======================================
// CODIGOS IR DA TV LG
// (podem mudar dependendo da TV)
// ======================================

const uint32_t codigoPower = 0x20DF10EF;
const uint32_t codigoVolMais = 0x20DF40BF;
const uint32_t codigoVolMenos = 0x20DFC03F;

// ======================================
// OBJETO RESPONSAVEL PELO IR
// ======================================

IRsend irsend(pinIR);

void setup()
{
    // Inicia serial
    Serial.begin(115200);

    // Inicializa transmissor IR
    irsend.begin();

    Serial.println("================================");
    Serial.println("CONTROLE TV LG");
    Serial.println("================================");
    Serial.println("P -> POWER");
    Serial.println("+ -> VOLUME +");
    Serial.println("- -> VOLUME -");
    Serial.println("================================");
}

void loop()
{
    // Verifica se algo foi digitado
    if (Serial.available())
    {
        // Le caractere digitado
        char comando = Serial.read();

        // ==========================
        // POWER
        // ==========================

        if (comando == 'P' || comando == 'p')
        {
            irsend.sendLG(codigoPower, 32);

            Serial.println("TV Ligada/Desligada");
        }

        // ==========================
        // VOLUME +
        // ==========================

        else if (comando == '+')
        {
            irsend.sendLG(codigoVolMais, 32);

            Serial.println("Volume Aumentado");
        }

        // ==========================
        // VOLUME -
        // ==========================

        else if (comando == '-')
        {
            irsend.sendLG(codigoVolMenos, 32);

            Serial.println("Volume Diminuido");
        }
    }
}
