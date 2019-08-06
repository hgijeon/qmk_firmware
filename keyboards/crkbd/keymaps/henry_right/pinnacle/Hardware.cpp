// Copyright (c) 2018 Cirque Corp. Restrictions apply. See: www.cirque.com/sw-license

#include "Hardware.h"
#include "../../lib/lufa/LUFA/Drivers/Peripheral/SPI.h"

#define MACRO_CONCAT(a, b) a##b

#define pinModeOutput(port, pin) (MACRO_CONCAT(DDR, port) |= (1 << pin))
#define pinModeInput(port, pin)  (MACRO_CONCAT(DDR, port) &= ~ (1 << pin))

#define pinWriteHigh(port, pin) (MACRO_CONCAT(PORT, port) |= (1 << pin))
#define pinWriteLow(port, pin)  (MACRO_CONCAT(PORT, port) &= ~ (1 << pin))
#define pinRead(port, pin)  ((MACRO_CONCAT(PIN, port) >> pin) & 1)

#define CS0_PORT  B
#define CS0_PIN   0      // Chip Select pin for Sensor 0
#define DR0_PORT  D
#define DR0_PIN   3       // Data Ready pin for Sensor 0

typedef struct _sensorPort
{
  uint8_t CS_Pin;
  uint8_t DR_Pin;
  uint8_t sensorId;     // also the index of the sensor in the code.
} sensorPort_t;

sensorPort_t sensorList[1];

void HW_init()
{
  // set the CS pins as output and DR pins as inputs
  pinModeOutput(CS0_PORT, CS0_PIN);
  pinModeInput(DR0_PORT, DR0_PIN);

  // create sensorPort objects for the sensorList and insert them into the array
  sensorPort_t temp;

  temp.CS_Pin = CS0_PIN;
  temp.DR_Pin = DR0_PIN;
  temp.sensorId = 0;

  sensorList[0] = temp;
}

void HW_assertCS(uint8_t sensorId)
{
  pinWriteLow(CS0_PORT, sensorList[sensorId].CS_Pin);
}

void HW_deAssertCS(uint8_t sensorId)
{
  pinWriteHigh(CS0_PORT, sensorList[sensorId].CS_Pin);
}

bool HW_drAsserted(uint8_t sensorId)
{
  return pinRead(DR0_PORT, sensorList[sensorId].DR_Pin);
}

void TIMER_delayMicroseconds(uint32_t microSeconds)
{
  //FIXME: disabled
  //delayMicroseconds(microSeconds);
}

void SPI_init(uint32_t bitRate, uint8_t bitOrder, uint8_t spiMode)
{
  SPI_Init(SPI_SPEED_FCPU_DIV_2 | SPI_MODE_MASTER | SPI_SCK_LEAD_RISING | SPI_SAMPLE_TRAILING);
}

void SPI_end()
{
  //SPI.end();
}

void SPI_beginTransaction()
{
  //SPI.beginTransaction(_spiSettings);
}

void SPI_endTransaction()
{
  //SPI.endTransaction();
}

uint8_t SPI_transfer(uint8_t data)
{
  return SPI_TransferByte(data);
}

void SPI_transferBytes(uint8_t * data, uint16_t count)
{
  for(int i = 0; i < count; ++i) SPI_TransferByte(data[i]);
}
