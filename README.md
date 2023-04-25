# DE2-115-NIOS-USB1362-VGA
Designing an image output device via a USB interface based on FPGA  
For building:  
Start quartus -> compile project -> open NIOS II Eclipse -> Rigth click on BSP_test -> properties -> generate BSP project ->   after generation bsp project you should to comment //ALT_LINK_ERROR("alt_remap_uncached() is not available because Nios II Gen2 cores with data caches don't support mixing cacheable and uncacheable data on the same line.");  
-> that line placed at software\test_bsp\HAL\src\alt_remap_uncached.c  
-> build all nios II project.
 
Directory structure:  
1. Software  
implementation of whats in vhdl, but in C and on nios II processor.  
2. Usb_quarus   
python software to send image via usb.
The software has been tested under Windows 10 x64 21H2.  

On the Host PC side, Install the libusb-win32 driver through  [Zadig](https://zadig.akeo.ie/)  (Following this [WinUSB WiKi](https://github.com/libusb/libusb/wiki/Windows#How_to_use_libusb_on_Windows))  
