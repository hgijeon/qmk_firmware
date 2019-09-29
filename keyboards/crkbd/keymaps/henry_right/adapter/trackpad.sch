EESchema Schematic File Version 4
LIBS:trackpad-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Trackpad adapter"
Date "11/21/2018"
Rev "1.0"
Comp "vlukash"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L trackpad-rescue:corne-classic-rescue_ProMicro-kbd-corne-classic-cache-trackpad-rescue U2
U 1 1 5BF8BB0A
P 8350 5000
F 0 "U2" H 8350 6037 60  0000 C CNN
F 1 "ProMicro" H 8350 5931 60  0000 C CNN
F 2 "trackpad:ArduinoProMicro" H 8450 3950 60  0001 C CNN
F 3 "" H 8450 3950 60  0000 C CNN
	1    8350 5000
	1    0    0    -1  
$EndComp
$Comp
L trackpad-rescue:Elite-C-keebio-trackpad-rescue U1
U 1 1 5BF8DE68
P 8300 2200
F 0 "U1" H 8300 3037 60  0000 C CNN
F 1 "Elite-C" H 8300 2931 60  0000 C CNN
F 2 "trackpad:Elite-C" V 9350 -300 60  0001 C CNN
F 3 "" V 9350 -300 60  0001 C CNN
	1    8300 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5BFB3888
P 7050 4550
F 0 "#PWR0101" H 7050 4300 50  0001 C CNN
F 1 "GND" H 7050 4400 50  0000 C CNN
F 2 "" H 7050 4550 50  0001 C CNN
F 3 "" H 7050 4550 50  0001 C CNN
	1    7050 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 4550 7500 4550
$Comp
L power:GND #PWR0102
U 1 1 5BFC66DA
P 9650 4350
F 0 "#PWR0102" H 9650 4100 50  0001 C CNN
F 1 "GND" V 9655 4222 50  0000 R CNN
F 2 "" H 9650 4350 50  0001 C CNN
F 3 "" H 9650 4350 50  0001 C CNN
	1    9650 4350
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5BFC7635
P 9650 4550
F 0 "#PWR0103" H 9650 4400 50  0001 C CNN
F 1 "+5V" V 9665 4678 50  0000 L CNN
F 2 "" H 9650 4550 50  0001 C CNN
F 3 "" H 9650 4550 50  0001 C CNN
	1    9650 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 4450 7500 4450
Connection ~ 7500 4550
Wire Wire Line
	7500 4550 7650 4550
Wire Wire Line
	7500 4450 7500 4550
Text GLabel 9350 4450 2    47   Input ~ 0
RST
Text GLabel 7350 4350 0    50   Input ~ 0
PD2
Wire Wire Line
	7350 4350 7650 4350
Wire Wire Line
	9050 4350 9650 4350
Wire Wire Line
	9050 4450 9350 4450
Wire Wire Line
	9050 4550 9650 4550
Text GLabel 7350 4650 0    50   Input ~ 0
PD1
Wire Wire Line
	7350 4650 7650 4650
Text GLabel 7350 4750 0    50   Input ~ 0
PD0
Wire Wire Line
	7350 4750 7650 4750
Text GLabel 7350 4850 0    50   Input ~ 0
PD4
Wire Wire Line
	7350 4850 7650 4850
Text GLabel 7350 4950 0    50   Input ~ 0
PC6
Wire Wire Line
	7350 4950 7650 4950
Text GLabel 7350 5050 0    50   Input ~ 0
PD7
Wire Wire Line
	7350 5050 7650 5050
Text GLabel 7350 5150 0    50   Input ~ 0
PE6
Wire Wire Line
	7350 5150 7650 5150
$Comp
L power:GND #PWR0104
U 1 1 5BFDDB09
P 7000 1950
F 0 "#PWR0104" H 7000 1700 50  0001 C CNN
F 1 "GND" H 7000 1800 50  0000 C CNN
F 2 "" H 7000 1950 50  0001 C CNN
F 3 "" H 7000 1950 50  0001 C CNN
	1    7000 1950
	0    1    1    0   
$EndComp
Wire Wire Line
	7000 1950 7450 1950
Wire Wire Line
	7600 1850 7450 1850
Connection ~ 7450 1950
Wire Wire Line
	7450 1950 7600 1950
Wire Wire Line
	7450 1850 7450 1950
Text GLabel 7300 1750 0    50   Input ~ 0
PD2
Text GLabel 7300 2050 0    50   Input ~ 0
PD1
Wire Wire Line
	7300 2050 7600 2050
Text GLabel 7300 2150 0    50   Input ~ 0
PD0
Wire Wire Line
	7300 2150 7600 2150
Text GLabel 7300 2250 0    50   Input ~ 0
PD4
Wire Wire Line
	7300 2250 7600 2250
Text GLabel 7300 2350 0    50   Input ~ 0
PC6
Wire Wire Line
	7300 2350 7600 2350
Text GLabel 7300 2450 0    50   Input ~ 0
PD7
Wire Wire Line
	7300 2450 7600 2450
Text GLabel 7300 2550 0    50   Input ~ 0
PE6
Wire Wire Line
	7300 2550 7600 2550
Text GLabel 7300 2650 0    50   Input ~ 0
PB4
Wire Wire Line
	7300 2650 7600 2650
Text GLabel 7300 2750 0    50   Input ~ 0
PB5
Wire Wire Line
	7300 2750 7600 2750
Wire Wire Line
	9350 5350 9050 5350
Wire Wire Line
	9350 5150 9050 5150
Wire Wire Line
	9350 5050 9050 5050
Text GLabel 9350 4950 2    50   Input ~ 0
PF7
Wire Wire Line
	9350 4950 9050 4950
Text GLabel 9350 4850 2    50   Input ~ 0
PF6
Wire Wire Line
	9350 4850 9050 4850
Text GLabel 9350 4750 2    50   Input ~ 0
PF5
Wire Wire Line
	9350 4750 9050 4750
Text GLabel 9350 4650 2    50   Input ~ 0
PF4
Wire Wire Line
	9350 4650 9050 4650
Text GLabel 9350 5350 2    50   Input ~ 0
PB6
Text GLabel 7350 4250 0    50   Input ~ 0
PD3
Wire Wire Line
	7350 4250 7650 4250
Wire Wire Line
	8100 3300 8100 3150
$Comp
L power:GND #PWR0105
U 1 1 5C025FA6
P 9600 1750
F 0 "#PWR0105" H 9600 1500 50  0001 C CNN
F 1 "GND" V 9605 1622 50  0000 R CNN
F 2 "" H 9600 1750 50  0001 C CNN
F 3 "" H 9600 1750 50  0001 C CNN
	1    9600 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5C025FAC
P 9600 1950
F 0 "#PWR0106" H 9600 1800 50  0001 C CNN
F 1 "+5V" V 9615 2078 50  0000 L CNN
F 2 "" H 9600 1950 50  0001 C CNN
F 3 "" H 9600 1950 50  0001 C CNN
	1    9600 1950
	0    1    1    0   
$EndComp
Text GLabel 9300 1850 2    47   Input ~ 0
RST
Wire Wire Line
	9000 1750 9600 1750
Wire Wire Line
	9000 1850 9300 1850
Wire Wire Line
	9000 1950 9600 1950
Wire Wire Line
	9300 2750 9000 2750
Wire Wire Line
	9300 2650 9000 2650
Wire Wire Line
	9300 2550 9000 2550
Wire Wire Line
	9300 2450 9000 2450
Text GLabel 9300 2350 2    50   Input ~ 0
PF7
Wire Wire Line
	9300 2350 9000 2350
Text GLabel 9300 2250 2    50   Input ~ 0
PF6
Wire Wire Line
	9300 2250 9000 2250
Text GLabel 9300 2150 2    50   Input ~ 0
PF5
Wire Wire Line
	9300 2150 9000 2150
Text GLabel 9300 2050 2    50   Input ~ 0
PF4
Wire Wire Line
	9300 2050 9000 2050
Text GLabel 9300 2750 2    50   Input ~ 0
PB6
Wire Wire Line
	8200 3300 8200 3150
Text GLabel 7350 5250 0    50   Input ~ 0
PB4
Wire Wire Line
	7350 5250 7650 5250
Wire Wire Line
	8300 3300 8300 3150
Wire Wire Line
	9300 1650 9000 1650
Text GLabel 7300 1650 0    50   Input ~ 0
PD3
Wire Wire Line
	7300 1650 7600 1650
Wire Wire Line
	8400 3300 8400 3150
Wire Wire Line
	8500 3300 8500 3150
$Comp
L power:+5V #PWR0107
U 1 1 5C03A73E
P 4650 4050
F 0 "#PWR0107" H 4650 3900 50  0001 C CNN
F 1 "+5V" V 4665 4178 50  0000 L CNN
F 2 "" H 4650 4050 50  0001 C CNN
F 3 "" H 4650 4050 50  0001 C CNN
	1    4650 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5950 4050 5750 4050
Wire Wire Line
	5000 4050 4850 4050
$Comp
L power:GND #PWR0109
U 1 1 5C04B434
P 5300 4600
F 0 "#PWR0109" H 5300 4350 50  0001 C CNN
F 1 "GND" H 5305 4427 50  0000 C CNN
F 2 "" H 5300 4600 50  0001 C CNN
F 3 "" H 5300 4600 50  0001 C CNN
	1    5300 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4350 5300 4600
$Comp
L power:GND #PWR0110
U 1 1 5C04CB46
P 5750 4600
F 0 "#PWR0110" H 5750 4350 50  0001 C CNN
F 1 "GND" H 5755 4427 50  0000 C CNN
F 2 "" H 5750 4600 50  0001 C CNN
F 3 "" H 5750 4600 50  0001 C CNN
	1    5750 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5C04E0D2
P 4850 4600
F 0 "#PWR0111" H 4850 4350 50  0001 C CNN
F 1 "GND" H 4855 4427 50  0000 C CNN
F 2 "" H 4850 4600 50  0001 C CNN
F 3 "" H 4850 4600 50  0001 C CNN
	1    4850 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4250 5750 4050
Connection ~ 5750 4050
Wire Wire Line
	5750 4050 5600 4050
Wire Wire Line
	4850 4250 4850 4050
Connection ~ 4850 4050
Wire Wire Line
	4850 4050 4650 4050
Wire Wire Line
	4850 4450 4850 4600
Wire Wire Line
	5750 4450 5750 4600
$Comp
L Device:R_Small_US R1
U 1 1 5C07A1A9
P 4600 1800
F 0 "R1" V 4395 1800 50  0000 C CNN
F 1 "3.3K" V 4486 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 4600 1800 50  0001 C CNN
F 3 "~" H 4600 1800 50  0001 C CNN
	1    4600 1800
	0    1    1    0   
$EndComp
Text GLabel 4700 1550 1    50   Input ~ 0
LVL_SHIFT
Text GLabel 7350 5350 0    50   Input ~ 0
PB5
Wire Wire Line
	7350 5350 7650 5350
Wire Wire Line
	9050 4250 9350 4250
Wire Wire Line
	9050 5250 9350 5250
$Comp
L Logic_LevelTranslator:TXB0104D U4
U 1 1 5D4E5066
P 5250 2300
F 0 "U4" H 5250 1511 50  0000 C CNN
F 1 "TXB0104D" H 5250 1420 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 5250 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 5360 2395 50  0001 C CNN
	1    5250 2300
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:NCP1117-3.3_SOT223 U3
U 1 1 5D4E82C1
P 5300 4050
F 0 "U3" H 5300 4292 50  0000 C CNN
F 1 "NCP1117-3.3_SOT223" H 5300 4201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5300 4250 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 5400 3800 50  0001 C CNN
	1    5300 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5D4F60AD
P 4850 4350
F 0 "C1" H 4942 4396 50  0000 L CNN
F 1 "10uF" H 4942 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4850 4350 50  0001 C CNN
F 3 "~" H 4850 4350 50  0001 C CNN
	1    4850 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5D502666
P 5750 4350
F 0 "C2" H 5842 4396 50  0000 L CNN
F 1 "10uF" H 5842 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5750 4350 50  0001 C CNN
F 3 "~" H 5750 4350 50  0001 C CNN
	1    5750 4350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR01
U 1 1 5D519034
P 5950 4050
F 0 "#PWR01" H 5950 3900 50  0001 C CNN
F 1 "+3.3V" V 5965 4178 50  0000 L CNN
F 2 "" H 5950 4050 50  0001 C CNN
F 3 "" H 5950 4050 50  0001 C CNN
	1    5950 4050
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR04
U 1 1 5D5345C8
P 5150 1250
F 0 "#PWR04" H 5150 1100 50  0001 C CNN
F 1 "+3.3V" V 5165 1423 50  0000 C CNN
F 2 "" H 5150 1250 50  0001 C CNN
F 3 "" H 5150 1250 50  0001 C CNN
	1    5150 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR05
U 1 1 5D536D5D
P 5350 1250
F 0 "#PWR05" H 5350 1100 50  0001 C CNN
F 1 "+5V" V 5365 1378 50  0000 L CNN
F 2 "" H 5350 1250 50  0001 C CNN
F 3 "" H 5350 1250 50  0001 C CNN
	1    5350 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5D5377AE
P 5550 1350
F 0 "C4" H 5642 1396 50  0000 L CNN
F 1 "100nF" H 5642 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5550 1350 50  0001 C CNN
F 3 "~" H 5550 1350 50  0001 C CNN
	1    5550 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 5D5387B2
P 4950 1350
F 0 "C3" H 5042 1396 50  0000 L CNN
F 1 "100nF" H 5042 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4950 1350 50  0001 C CNN
F 3 "~" H 4950 1350 50  0001 C CNN
	1    4950 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5D539FF6
P 5550 1450
F 0 "#PWR06" H 5550 1200 50  0001 C CNN
F 1 "GND" H 5555 1277 50  0000 C CNN
F 2 "" H 5550 1450 50  0001 C CNN
F 3 "" H 5550 1450 50  0001 C CNN
	1    5550 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5D53A4E3
P 4950 1450
F 0 "#PWR03" H 4950 1200 50  0001 C CNN
F 1 "GND" H 4955 1277 50  0000 C CNN
F 2 "" H 4950 1450 50  0001 C CNN
F 3 "" H 4950 1450 50  0001 C CNN
	1    4950 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1250 5150 1250
Wire Wire Line
	5150 1250 5150 1600
Connection ~ 5150 1250
Wire Wire Line
	5350 1600 5350 1250
Wire Wire Line
	5350 1250 5550 1250
Connection ~ 5350 1250
Text GLabel 5650 2000 2    50   Input ~ 0
SDA
Text GLabel 5650 2200 2    50   Input ~ 0
SCL
Wire Wire Line
	4850 1800 4700 1800
$Comp
L power:GND #PWR02
U 1 1 5D565A2C
P 4500 1800
F 0 "#PWR02" H 4500 1550 50  0001 C CNN
F 1 "GND" H 4505 1627 50  0000 C CNN
F 2 "" H 4500 1800 50  0001 C CNN
F 3 "" H 4500 1800 50  0001 C CNN
	1    4500 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 1550 4700 1800
Connection ~ 4700 1800
$Comp
L power:GND #PWR0108
U 1 1 5D4A1B9F
P 2600 1600
F 0 "#PWR0108" H 2600 1350 50  0001 C CNN
F 1 "GND" V 2605 1427 50  0000 C CNN
F 2 "" H 2600 1600 50  0001 C CNN
F 3 "" H 2600 1600 50  0001 C CNN
	1    2600 1600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0112
U 1 1 5D4A230C
P 2600 1500
F 0 "#PWR0112" H 2600 1350 50  0001 C CNN
F 1 "+3.3V" V 2615 1673 50  0000 C CNN
F 2 "" H 2600 1500 50  0001 C CNN
F 3 "" H 2600 1500 50  0001 C CNN
	1    2600 1500
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J1
U 1 1 5D572BD5
P 2400 2000
F 0 "J1" H 2318 1175 50  0000 C CNN
F 1 "Conn_01x12" H 2318 1266 50  0000 C CNN
F 2 "Connector_FFC-FPC:Hirose_FH12-12S-0.5SH_1x12-1MP_P0.50mm_Horizontal" H 2318 1267 50  0001 C CNN
F 3 "~" H 2400 2000 50  0001 C CNN
	1    2400 2000
	-1   0    0    -1  
$EndComp
Text GLabel 2750 2600 2    50   Input ~ 0
SCK_3V3
Text GLabel 2750 2500 2    50   Input ~ 0
MISO_3V3
Text GLabel 2750 2400 2    50   Input ~ 0
TP_CS_3V3
Text GLabel 2750 2200 2    50   Input ~ 0
MOSI_3V3
Text GLabel 2750 2300 2    50   Input ~ 0
TP_DR_3V3
Text GLabel 2750 2000 2    50   Input ~ 0
TP_BTN3_3V3
Text GLabel 2750 2100 2    50   Input ~ 0
TP_BTN2_3V3
Text GLabel 2750 1900 2    50   Input ~ 0
TP_BTN1_3V3
Text GLabel 8500 3300 3    50   Input ~ 0
LVL_SHIFT
NoConn ~ 2600 1900
NoConn ~ 2600 2000
NoConn ~ 2600 2100
NoConn ~ 2750 2100
NoConn ~ 2750 2000
NoConn ~ 2750 1900
$Comp
L power:GND #PWR0113
U 1 1 5D4BD70B
P 5250 3000
F 0 "#PWR0113" H 5250 2750 50  0001 C CNN
F 1 "GND" H 5255 2827 50  0000 C CNN
F 2 "" H 5250 3000 50  0001 C CNN
F 3 "" H 5250 3000 50  0001 C CNN
	1    5250 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 1750 7600 1750
Text GLabel 8100 3300 3    50   Input ~ 0
TP_DR
Text GLabel 9300 1650 2    50   Input ~ 0
PB0
Text GLabel 9350 4250 2    50   Input ~ 0
PB0
Text GLabel 9300 2450 2    50   Input ~ 0
PB1
Text GLabel 9300 2550 2    50   Input ~ 0
PB3
Text GLabel 9300 2650 2    50   Input ~ 0
PB2
Text GLabel 9350 5050 2    50   Input ~ 0
PB1
Text GLabel 9350 5150 2    50   Input ~ 0
PB3
Text GLabel 9350 5250 2    50   Input ~ 0
PB2
Text GLabel 2750 1700 2    50   Input ~ 0
TP_SDA_3V3
Text GLabel 2750 1800 2    50   Input ~ 0
TP_SCL_3V3
Text GLabel 4850 2000 0    50   Input ~ 0
TP_SDA_3V3
Text GLabel 4850 2200 0    50   Input ~ 0
TP_SCL_3V3
Text GLabel 4850 2600 0    50   Input ~ 0
TP_DR_3V3
Text GLabel 5650 2600 2    50   Input ~ 0
TP_DR
Text GLabel 7400 2050 3    50   Input ~ 0
SDA
Text GLabel 7550 2150 3    50   Input ~ 0
SCL
NoConn ~ 2600 2200
NoConn ~ 2600 2400
NoConn ~ 2600 2500
NoConn ~ 2600 2600
NoConn ~ 2750 2600
NoConn ~ 2750 2500
NoConn ~ 2750 2400
NoConn ~ 2750 2200
Wire Wire Line
	2600 1700 2750 1700
Wire Wire Line
	2600 1800 2750 1800
Wire Wire Line
	2600 2300 2750 2300
$EndSCHEMATC
