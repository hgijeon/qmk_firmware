#include "trackpad.h"

// bool isScrollingMode = false;
bool isScrollMode = false;
extern report_mouse_t mouse_report;

void pointing_device_init(void){

  SPI_Init(SPI_SPEED_FCPU_DIV_8 | SPI_MODE_MASTER);

  // Set as output
  TP_RESET_INIT;
  wait_ms(100);
  TP_SHUTDOWN_INIT;
  wait_ms(100);
  TP_CS_INIT;
  wait_ms(100);
  LVL_SHIFT_EN_INIT;
  wait_ms(100);

  // Reset level shifter
  LVL_SHIFT_EN_LO;
  wait_ms(100);
  LVL_SHIFT_EN_HI;
  wait_ms(100);

  // Force a BB-8520 reset
  TP_RESET_HI;
  wait_ms(100);
  TP_RESET_LO;
  wait_ms(100);
    
  // Turn on BB-8520 trackpad
  TP_SHUTDOWN_LO;
  wait_ms(100);

  TP_CS_HI;
}

uint8_t readRegister(uint8_t address) {
  uint8_t data;

  TP_CS_LO;

  // Read the data
  SPI_TransferByte(address);
  data = SPI_TransferByte(0x00);

  TP_CS_HI;

  return data;
}

void pointing_device_task(void){
    if(readRegister(0x00) != 0x0D) return;
  uint8_t motion = readRegister(0x02);

  // Motion has occurred on the trackpad
  if (motion > 127) {

  int8_t dx, dy;

    dy = -readRegister(0x03);
    dx = -readRegister(0x04);

    report_mouse_t currentReport = pointing_device_get_report();
    if (isScrollMode)
    {
        static int accum_x = 0, accum_y = 0;
        accum_x += dx; accum_y += dy;
      currentReport.h = accum_x/SCROLL_SPEED_DIVIDER;
      currentReport.v = -accum_y/SCROLL_SPEED_DIVIDER;
        accum_x %= SCROLL_SPEED_DIVIDER; accum_y %= SCROLL_SPEED_DIVIDER;
    }
    else
    {
      currentReport.x = dx * POINTER_SPEED_MULTIPLIER;
      currentReport.y = dy * POINTER_SPEED_MULTIPLIER;
    }

    currentReport.buttons = mouse_report.buttons;
    pointing_device_set_report(currentReport);
    pointing_device_send();
  }
}
