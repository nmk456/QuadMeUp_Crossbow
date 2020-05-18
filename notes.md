# Features

Buttons - done - working

Buzzer

OLED - done?

PPM - done

RX PWM Output

Change frequency to 915

# Files

config.h - Build config definitions
lora.cpp - Borrowed LoRa lib
lora.h - Borrowed LoRa lib
main_variables.h - TX/RX sequences
main.cpp - main code
platform_node.cpp - Saves data to EEPROM
platform_node.h - Saves data to EEPROM
qsp.cpp - Decodes data and computes CRC
qsp.h - Decodes data and computes CRC
radio_node.cpp - Wrapper for LoRa and QSP functions
radio_node.h - Wrapper for LoRa and QSP functions
sbus.cpp - SBUS
sbus.h - SBUS
tactile.cpp - Button debouncing and monitoring
tactile.h - Button debouncing and monitoring
tx_input.h - ?
tx_oled.cpp - OLED wrapper
tx_oled.h - OLED wrapper
txbuzzer.cpp - Buzzer wrapper
txbuzzer.h - Buzzer wrapper
variables.h - Misc variables, definitions, structs

# TX Pins

0 - Boot button
2 - LED
4 - OLED_SDA
5 - LORA_SCK
12 --- PPM Input
13 - 
14 - LORA_RST
15 - OLED_SCL
16 - OLED_RST
17 - 
18 - LORA_CS
19 - LORA_MISO
21 --- BUTTON_0
22 --- BUTTON_1
23 - 
25 --- BUZZER
26 - LORA_IRQ
27 - LORA_MOSI
32 - 
33 - 
34 - 
35 - 
36 - 
37 - 
38 - 
39 - 

# RX Pins

0 - Boot button
2 - LED
4 - 
5 - LORA_SCK
12 -
13 - 
14 - LORA_RST
15 - 
16 - 
17 - 
18 - LORA_CS
19 - LORA_MISO
21 - 
22 - 
23 - 
25 - 
26 - LORA_IRQ
27 - LORA_MOSI
32 - 
33 - 
34 - 
35 - 
36 - 
37 - 
38 -
39 -