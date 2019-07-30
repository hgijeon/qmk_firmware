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

// Writes single-byte <data> to <address>
void RAP_Write(uint8_t address, uint8_t data)
{
  uint8_t cmdByte = WRITE_MASK | address;  // Form the WRITE command byte

  Assert_CS();

  SPI_TransferByte(cmdByte);  // Signal a write to register at <address>
  SPI_TransferByte(data);     // Send <value> to be written to register

  DeAssert_CS();

}




// Clears Status1 register flags (SW_CC and SW_DR)
void Pinnacle_ClearFlags(void){
  RAP_Write(0x02, 0x00);
  wait_ms(50);
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

void spi_init(void){
  TP_CS_INIT;
  DeAssert_CS();
  SPI_Init(SPI_SPEED_FCPU_DIV_4 | SPI_MODE_MASTER | SPI_SCK_LEAD_RISING | SPI_SAMPLE_TRAILING);
}

void glidepoint_circle_init(void){
  TP_CS_INIT;
  // data ready pin init
  DDRD &= ~(1 << 3);

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
  level_shift_init();
  spi_init();
  glidepoint_circle_init();
}


// Convenient way to store and access measurements
typedef struct _absData
{
  uint16_t xValue;
  uint16_t yValue;
  uint16_t zValue;
  uint8_t buttonFlags;
  bool touchDown;
} absData_t;

typedef struct _relData
{
  int8_t xValue;
  int8_t yValue;
  uint8_t buttonFlags;
  bool touchDown;
} relData_t;

relData_t touchData;

/*  RAP Functions */
// Reads <count> Pinnacle registers starting at <address>
void RAP_ReadBytes(uint8_t address, uint8_t * data, uint8_t count)
{
  uint8_t cmdByte = READ_MASK | address;   // Form the READ command byte

  Assert_CS();

  SPI_TransferByte(cmdByte);  // Signal a RAP-read operation starting at <address>
  SPI_TransferByte(0xFC);     // Filler byte
  SPI_TransferByte(0xFC);     // Filler byte
  for(uint8_t i = 0; i < count; i++)
  {
    data[i] = SPI_TransferByte(0xFC);  // Each subsequent SPI transfer gets another register's contents
  }

  DeAssert_CS();
}


// Reads XYZ data from Pinnacle registers 0x14 through 0x17
// Stores result in absData_t struct with xValue, yValue, and zValue members
void Pinnacle_GetAbsolute(absData_t * result)
{
  uint8_t data[6] = { 0,0,0,0,0,0 };
  RAP_ReadBytes(0x12, data, 6);

  Pinnacle_ClearFlags();

  result->buttonFlags = data[0] & 0x3F;
  result->xValue = data[2] | ((data[4] & 0x0F) << 8);
  result->yValue = data[3] | ((data[4] & 0xF0) << 4);
  result->zValue = data[5] & 0x3F;

  result->touchDown = result->xValue != 0;
}

void Pinnacle_GetRelative(relData_t * result)
{
  uint8_t data[4] = { 0,0,0,0 };
  RAP_ReadBytes(0x12, data, 4);

  Pinnacle_ClearFlags();

  if((data[0] & 0xc8) != 0x08 ) move_pointer(10);

  result->xValue = (int8_t)data[1];
  result->yValue = (int8_t)data[2];
}


void pointing_device_task(void){
  touchData.xValue = touchData.yValue = 0;

  Pinnacle_GetRelative(&touchData);

  report_mouse_t currentReport = pointing_device_get_report();
  if (isScrollMode){}
  //if(DR_Asserted())
    currentReport.x = touchData.xValue;
    currentReport.y = touchData.yValue;

    currentReport.buttons = mouse_report.buttons;
    pointing_device_set_report(currentReport);
    pointing_device_send();
}











