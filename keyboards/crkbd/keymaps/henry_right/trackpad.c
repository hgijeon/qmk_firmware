#include "trackpad.h"

#include "pinnacle/Hardware.h"
#include "pinnacle/Pinnacle.h"


bool isScrollMode = false;
touchData_t touchData;
extern report_mouse_t mouse_report;

///// TMP FIELD ////
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
//// END TMP FIELD ////

void pointing_device_init(void){
  level_shift_init();

//spi init이 hw init보다 앞에 있어야 한다.
  SPI_init(0, 0, 0);
  HW_init();

  Pinnacle_cyclePower(0);
  Pinnacle_init(&touchData, 0);
}

void pointing_device_task(void){
  if (isScrollMode){}

  static int accum_x = 0, accum_y = 0;

  if(HW_drAsserted(0))
  {
    if(touchData.mode == RELATIVE){
      touchData.relative.xDelta = touchData.relative.yDelta = 0;
      Pinnacle_getTouchData(&touchData, 0);

      report_mouse_t currentReport = pointing_device_get_report();

      int raw_x = touchData.relative.xDelta;
      int raw_y = touchData.relative.yDelta;
      accum_x += raw_y;
      accum_y += -raw_x;

      static int cnt = 0;
      ++cnt;
      bool to_send = (cnt % 2) == 0;
      if(to_send){
        currentReport.x = accum_x;
        currentReport.y = accum_y;
        accum_x = accum_y = 0;

        currentReport.buttons = mouse_report.buttons;
        pointing_device_set_report(currentReport);
        pointing_device_send();
      }
    }
  }
}











