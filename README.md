
A2DP-Wired headphones adapter

<img width="646" height="751" alt="image" src="https://github.com/user-attachments/assets/654f31db-9eda-49c6-8ebe-77281fe39f38" />


Idea: My parents are, well, old, so they have a lot of old wired headphones lying around their house. However, most of these are useless as their phones don't have the right kind of audio connector. I built this project to let them use all of their wired headphones with Bluetooth so they don't have to throw them away. This combines the best and easiest-to-solder chips that I could possibly find to make a device that turns these old pieces of hardware into useful music streaming tools.





Portable Bluetooth wired headphones adapter.

Features

• ESP32-WROOM-32E: Bluetooth classic streaming

• PCM5102A DAC: audio 

• SSD1306 OLED: status screen

• 5V USB-C / LiPo: power

• SPDT Switch: Power input switching

• MIC5219 LDO: holds 3V3

• CH340C Serial: Easy USB programming

• 0805 Footprints: Hand-solder friendly

<img width="590" height="721" alt="image" src="https://github.com/user-attachments/assets/713d7ead-2f05-4e67-bf0b-9c3142ac599b" />

Onboard Parts & Connectors
|Designators        |Value                    |Package  |LCSC#    |MPN                |Manufacturer             |
|-------------------|-------------------------|---------|---------|-------------------|-------------------------|
|C1                 |10uF                     |0603     |C19702   |CL10A106KP8NNNC    |Samsung Electro-Mechanics|
|C2                 |470pF                    |0603     |C22396   |CL10B471KB8NNNC    |Samsung Electro-Mechanics|
|C3                 |10uF                     |0805     |C440198  |GRM21BR61H106KE43L |muRata                   |
|C4,C5,C6,C9        |100nF                    |0603     |C1591    |CL10B104KB8NNNC    |Samsung Electro-Mechanics|
|C7,C8              |2.2uF                    |0805     |C19110   |CL21B225KAFNNNE    |Samsung Electro-Mechanics|
|C10,C11            |2.2nF                    |0603     |C16033   |CL10B222KB8NNNC    |Samsung Electro-Mechanics|
|R1,R2              |5.1k                     |0603     |C2907044 |FRC0603F5101TS     |FOJAN                    |
|R3,R4              |10k                      |0603     |C98220   |RC0603FR-0710KL    |YAGEO                    |
|R5                 |330                      |0603     |C23138   |0603WAF3300T5E     |UNI-ROYAL                |
|R6                 |2k                       |0603     |C22975   |0603WAF2001T5E     |UNI-ROYAL                |
|R7,R10             |470                      |0603     |C23179   |0603WAF4700T5E     |UNI-ROYAL                |
|R8,R9              |100k                     |0603     |C14675   |RC0603FR-07100KL   |YAGEO                    |
|R11,R12            |4.7k                     |0603     |C99782   |RC0603FR-074K7L    |YAGEO                    |
|D1                 |LED Red                  |0603     |C2286    |KT-0603R           |Hubei KENTO              |
|U1                 |ESP32-WROOM-32E-N16      |Module   |C701343  |ESP32-WROOM-32E-N16|ESPRESSIF                |
|U2                 |CH340C                   |SOP-16   |C84681   |CH340C             |WCH                      |
|U3                 |MIC5219-3.3YM5 Compatible|SOT-23-5L|C41381680|HMIC5219-3.3YM5    |HXY                      |
|U4                 |MCP73831T-2ACI/OT        |SOT-23-5 |C424093  |MCP73831T-2ACI/OT  |MICROCHIP                |
|U5                 |PCM5102APW               |TSSOP-20 |C1520792 |PCM5102APW         |TI                       |
|J1                 |USB-C Receptacle         |SMD      |C165948  |TYPE-C-31-M-12     |Hroparts                 |
|J4                 |3.5mm Audio Jack         |SMD      |C431535  |PJ-320D            |SHOU HAN                 |
|SW1,SW2            |Tactile Switch           |SMD      |C2886894 |TL3342F260QG       |E-Switch                 |
|SW3                |Slide Switch SPDT        |SMD      |C221841  |PCM12SMTR          |C&K                      |
|SW4,SW5,SW6,SW7,SW8|Tactile Switch           |THT      |C393938  |TS665CJ            |SHOU HAN                 |

<img width="3508" height="2480" alt="image" src="https://github.com/user-attachments/assets/d1a8912e-9c80-4ae9-84e7-c0217a4262f7" />
