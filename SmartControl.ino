#include "Config.h"
#include "Alimentador.h"
#include "Thread.h"
#include "ThreadController.h"

#define botaoReset 38
int valorBotao = 0;
Config config;
Alimentador alimentador;
uint8_t minuto_ultima_exec;

void setup() {
  pinMode(botaoReset,INPUT);
  config.setup(9600);
}


void loop() {
 alimentador.shouldRunThenRun();
 valorBotao = digitalRead(botaoReset);

 if(valorBotao){
  // simular ciclo alimentador
  DateTime now = rtc.now();
  if(minuto_ultima_exec != now.minute()){
    minuto_ultima_exec = now.minute();
    alimentador.exec(minuto_ultima_exec);
  }
 }
}




