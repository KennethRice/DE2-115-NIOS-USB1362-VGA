# DE2-115-NIOS-USB1362-VGA
Designing an image output device via a USB interface based on FPGA  
Directory structure:  
1. Software  
implementation of whats in vhdl, but in C and on nios II processor.  
2. Usb_quarus   
python software to send image via usb.
The software has been tested under Windows 10 x64 21H2.  

On the Host PC side, Install the libusb-win32 driver through  [Zadig](https://zadig.akeo.ie/)  (Following this [WinUSB WiKi](https://github.com/libusb/libusb/wiki/Windows#How_to_use_libusb_on_Windows))  
