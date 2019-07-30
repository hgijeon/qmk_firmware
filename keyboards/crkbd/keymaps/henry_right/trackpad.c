#include "trackpad.h"


bool isScrollMode = false;
extern report_mouse_t mouse_report;

#define Assert_CS() TP_CS_LO
#define DeAssert_CS() TP_CS_HI

// Masks for Cirque Register Access Protocol (RAP)
#define WRITE_MASK  0x80
#define READ_MASK   0xA0

// Register config values for this demo
#define SYSCONFIG_1   0x00
#define FEEDCONFIG_1  0x03
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

uint8_t last_result = 13;

// Writes single-byte <data> to <address>
void RAP_Write(uint8_t address, uint8_t data)
{
  uint8_t cmdByte = WRITE_MASK | address;  // Form the WRITE command byte

  SPI_Init(SPI_SPEED_FCPU_DIV_16 | SPI_MODE_MASTER | SPI_SCK_LEAD_RISING | SPI_SAMPLE_TRAILING);
  Assert_CS();
  wait_ms(1);

  SPI_TransferByte(cmdByte);  // Signal a write to register at <address>
  last_result = SPI_TransferByte(data);    // Send <value> to be written to register

  wait_ms(1);
  DeAssert_CS();

}


// Reads single-byte <data> from <address>
uint8_t RAP_Read(uint8_t address)
{
  uint8_t cmdByte = READ_MASK | address;  // Form the WRITE command byte

  Assert_CS();
  wait_ms(1);

  SPI_TransferByte(cmdByte);  // Signal a write to register at <address>
  uint8_t data = SPI_TransferByte(0xfb);    // Send <value> to be written to register

  wait_ms(1);
  DeAssert_CS();

  return data;
}


// Clears Status1 register flags (SW_CC and SW_DR)
void Pinnacle_ClearFlags(void){
  RAP_Write(0x02, 0x00);
  wait_ms(50);
}

/*  Pinnacle-based TM040040 Functions  */
void Pinnacle_Init(void)
{
  DeAssert_CS();
  wait_ms(10);

  wait_ms(10);
  SPI_Init(SPI_SPEED_FCPU_DIV_16 | SPI_MODE_MASTER | SPI_SCK_LEAD_RISING | SPI_SAMPLE_TRAILING);

  wait_ms(10);
  TP_CS_INIT;
  DDRD &= ~(1 << 3);
  //pinMode(DR_PIN, INPUT);



  LVL_SHIFT_EN_INIT;
  wait_ms(10);

  // Reset level shifter
  LVL_SHIFT_EN_LO;
  wait_ms(10);
  LVL_SHIFT_EN_HI;
  wait_ms(10);



  // Host clears SW_CC flag
  Pinnacle_ClearFlags();

  wait_ms(10);
  // Host configures bits of registers 0x03 and 0x05
  RAP_Write(0x03, SYSCONFIG_1);
  RAP_Write(0x05, FEEDCONFIG_2);

  // Host enables preferred output mode (absolute)
  RAP_Write(0x04, FEEDCONFIG_1);

  // Host sets z-idle packet count to 5 (default is 30)
  RAP_Write(0x0A, Z_IDLE_COUNT);
}






void pointing_device_init(void){
  Pinnacle_Init();
}

void pointing_device_task(void){
  report_mouse_t currentReport = pointing_device_get_report();
  if(last_result == 0xff) move_pointer(1);
  if (isScrollMode){}
  if(DR_Asserted())
  {
    currentReport.x = 0;
    currentReport.y = 0;

    currentReport.buttons = mouse_report.buttons;
    pointing_device_set_report(currentReport);
    pointing_device_send();
  }
}











