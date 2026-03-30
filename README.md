<b>Sentinel-RTOS: Distributed Edge Security Node | C, FreeRTOS, STM32, RP2040 Pico, I2C, UART</b> <br>
#### **What it is:**<br>

It is a smart, two-piece security system designed to protect personal belongings like a backpack, bike, or expensive lab equipment.<br>

#### **What it does:**<br>
The system consists of a "Lookout" (the Pico) and a "Brain" (the STM32).<br>

- The **Lookout** is attached directly to your bag or bike. It constantly feels for motion and has a panic button. It packages this information and continuously streams a heartbeat to the Brain.<br>
- The **Brain** lives safely inside the bag or a secure enclosure. It analyzes the stream of data. If it detects a quick snatch, sustained suspicious movement, or a panic button press, it triggers a warning or a full alarm.<br>
- **The Killer Feature:** If a thief tries to be smart and cuts the wire connecting the Lookout to the Brain, the Brain immediately notices the missing heartbeat and triggers the alarm anyway.<br>
