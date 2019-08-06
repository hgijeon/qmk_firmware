#include "trackpad.h"

#include "pinnacle/Hardware.h"
#include "pinnacle/Pinnacle.h"


bool isScrollMode = false;
extern report_mouse_t mouse_report;

#define Assert_CS() TP_CS_LO
#define DeAssert_CS() TP_CS_HI

// Masks for Cirque Register Access Protocol (RAP)
#define WRITE_MASK  0x80
#define READ_MASK   0xA0

// Register config values for this demo
#define SYSCONFIG_1   0x00
#define FEEDCONFIG_1  0x01
#define FEEDCONFIG_2  0x1F
#define Z_IDLE_COUNT  0x05

bool DR_Asserted(void){
  return (PIND & (1 << 3));
}

void move_pointer(int x){
  report_mouse_t currentReport = pointing_device_get_report();
    currentReport.x = x;
    currentReport.y = 0;

    currentReport.buttons = mouse_report.buttons;
    pointing_device_set_report(currentReport);
    pointing_device_send();
}




void level_shift_init(void){
  LVL_SHIFT_EN_INIT;
  wait_ms(10);

  // Reset level shifter
  LVL_SHIFT_EN_LO;
  wait_ms(10);
  LVL_SHIFT_EN_HI;
  wait_ms(10);
}


touchData_t touchData;

void pointing_device_init(void){
  level_shift_init();

  HW_init();
  SPI_init(0, 0, 0);

  Pinnacle_init(&touchData, 0);
}


void pointing_device_task(void){
  if (isScrollMode){

  }

  static int cnt = 0;
  ++cnt;

  if((cnt % 8 == 0) || DR_Asserted())
  {
    if(touchData.mode == RELATIVE){
      touchData.relative.xDelta = touchData.relative.yDelta = 0;
      Pinnacle_getTouchData(&touchData, 0);

      report_mouse_t currentReport = pointing_device_get_report();

      currentReport.x = touchData.relative.xDelta;
      currentReport.y = touchData.relative.yDelta;

      currentReport.buttons = mouse_report.buttons;
      pointing_device_set_report(currentReport);
      pointing_device_send();
    }
  }
}











