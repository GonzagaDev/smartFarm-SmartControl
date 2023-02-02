#include "Thread.h"
class Scheduler {
  String _time;
public:
  Scheduler(String time) {
    _time = time;
  }

  String getHour() {
    return _time.substring(0, 2);
  }
  String getMinute() {
    return _time.substring(3, 5);
  }
};

Thread ligaAlimentador;
Thread desligaAlimentador;

class Alimentador {
  static const int qtdschedulers = 6;                                                                       // OBRIGATÓRIO INFORMAR A QUANTIDADE DE AGENDAMENTOS+
  char* agendamentosAlimentador[qtdschedulers] = { "12:43", "12:44", "12:45", "12:46", "22:53", "22:54" };  // INFORMAR OS AGENDAMENTOS
  uint8_t minuto_ultima_exec;


public:
  Alimentador() {
    ligaAlimentador.onRun(on);
    desligaAlimentador.setInterval(10000);
    desligaAlimentador.onRun(off);
  }

  Scheduler getScheduler(int index) {
    Scheduler scheduler(agendamentosAlimentador[index]);
    return scheduler;
  }

  int getQtdSchedulers() {
    return qtdschedulers;
  }

  void shouldRunThenRun() {
    DateTime now = rtc.now();
    if (minuto_ultima_exec != now.minute()) {
      for (int i = 0; i < getQtdSchedulers(); i++) {
        String hora = getScheduler(i).getHour();
        String minuto = getScheduler(i).getMinute();
        if (hora == String(now.hour())) {
          if (minuto == String(now.minute())) {
            minuto_ultima_exec = now.minute();
            ligaAlimentador.run();
          }
        }
      }
    }
    if (desligaAlimentador.shouldRun(millis())) {
      desligaAlimentador.run();
    }
  }

  static void on() {
    reles.on(0);
    desligaAlimentador.enabled = true;
    desligaAlimentador.restartTime();
    addLogConsole("Ligou o relé");
  }
  static void off() {
    reles.off(0);
    desligaAlimentador.enabled = false;
    addLogConsole("Desligou o relé");
  }
};