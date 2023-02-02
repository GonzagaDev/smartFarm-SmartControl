// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include "Reles.h"
Reles reles;
RTC_DS1307 rtc;

class Config {
  char daysOfTheWeek[7][12] = { "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado" };
  // char* agendamentosAlimentador[6] = { "12:14", "12:25", "12:16", "17:00", "22:53", "22:54" };
public:
  Config() {}

  // char getSchedullesOfAlimentador(){
  //   return agendamentosAlimentador;
  // }
  void setup(int configSerial) {
    Serial.begin(configSerial);
    Serial.println("INICIO DO SETUP");
    if (!rtc.begin()) {
      Serial.println("Couldn't find RTC");
      while (1);
    }
    if (!rtc.isrunning()) {
      Serial.println("RTC is NOT running!");
      //     // following line sets the RTC to the date & time this sketch was compiled
      //     //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
      //     // This line sets the RTC with an explicit date & time, for example to set
      //     // January 21, 2014 at 3am you would call:
      //    //rtc.adjust(DateTime(2023, 2, 1, 21, 50, 0));
         }
        // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
      reles.setup();
     Serial.println("FIM DO SETUP");
  };
};

void addLogConsole(String message){
   Serial.println(message);
}
