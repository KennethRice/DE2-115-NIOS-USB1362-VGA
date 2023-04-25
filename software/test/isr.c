#include <stdio.h>
#include "common.h"
#include "hal.h"
//#include "hal.c"
#include "isr.h"
#include "drv.h"
//#include "drv.c"
#include "SEG7.h"
//#include "SEG7.c"
#include "./Pantalla/alt_video_display.h"
#include <math.h>
#include <stdio.h>

#define numPacketPerFrame 1024*768/16

USBCHECK_DEVICE_STATES bUSBCheck_Device_State;

extern int addr, addr1;
int addr_res, addr1_res;
extern int write_image;
extern int count_packet;
//extern char* line;
int read_image = 0;
unsigned char bbuf[64], bbuf1[64];
char line[64];
int h = 0, w = 0;
int col;
int color;
int i = 0;
extern int num_buf;

// ************************************************************************
//  ISR Subroutine
// ************************************************************************
void usb_isr(void)
{
	ULONG i_st;
	RaiseIRQL();
	i_st = Hal4D13_ReadInterruptRegister();
	if (i_st != 0)
	{
		if (i_st & INTSRC_BUSRESET){
			Isr_BusReset();
		}
		else{
			//printf("i_st = %lXh \n", i_st);
			if (i_st & INTSRC_EP0OUT)
				Isr_Ep00RxDone();
			if (i_st & INTSRC_EP01)
				Isr_Ep01Done();
			if (i_st & INTSRC_EP02)
				Isr_Ep02Done();
		}

	}
	LowerIRQL();
}

void Isr_BusReset(void)
{

	printf(("BUS RESET\n"));
	configure_isp();
}

void Isr_Ep00RxDone(void)
{
	UCHAR ep_last;
	//printf("RX %d\n", bUSBCheck_Device_State.State_bits.FOUR_RESERVED_BITS++);
	ep_last = Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP0_CONTROL_OUT); /* Clear interrupt flag */
	//printf("EP0RX = %x\n", ep_last);
	if (ep_last & EPSTS_SETUP)
	{
		//printf("Setup \n");
		bD13flags.DCP_state = USBFSM4DCP_SETUPPROC;
	}
}


/*void Isr_Ep01Done(void)
{
	Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP01);
//	Hal4D13_ReadEndpoint(EPINDEX4EP01, (UCHAR *)addr, 64);
	Hal4D13_ReadEndpoint(EPINDEX4EP01, (UCHAR *)&bbuf, 64);

//	printf("addrEP1 = %x\n", addr);
	//int i;

	count_packet++;
//	if (count_packet == numPacketPerFrame){
	//	printf("count = packet");
		write_image = 1;
//		printf("size bbuf: %x\n", sizeof(*bbuf));
		Hal4D13_WriteEndpoint(EPINDEX4EP02, 0x55, 1);

		//count_packet = 0;
	//}
//	else{
		//for(i = 0; i < 64; i+=4){
		//addr += 64;

	//	addr+=4;
//		printf("addr += 64");
	//	}
		for(i = 0; i < 64; i++){
//	col = bbuf[i+3] << 24 | bbuf[i+2] << 16 | bbuf[i+1] << 8 | bbuf[i+0];
	//		 *(int*)(line +  i) = (unsigned int)col;
			//printf("%x, %x", col, addr);
			 IOWR_8DIRECT( addr, 0, bbuf[i]);
			 addr++;

		//	addr += 4;
		}
//		memcpy( (void*)addr, line, 64 );
	//	addr += 64;
		col = bbuf[i+3] << 24 | bbuf[i+2] << 16 | bbuf[i+1] << 8 | bbuf[i+0];
		IOWR_32DIRECT( addr, 0, (unsigned int)(col));
		addr += 4;

	//}

	//SEG7_Hex(bbuf[32], 0);


}*/
void Isr_Ep01Done(void)
{
	if(!num_buf) {
			Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP01);
			Hal4D13_ReadEndpoint(EPINDEX4EP01, (UCHAR *)addr, 64);
//	Hal4D13_ReadEndpoint(EPINDEX4EP01, (UCHAR *)&bbuf, 64);
			count_packet++;
	/*	for(i = 0; i < 64; i++){
//	col = bbuf[i+3] << 24 | bbuf[i+2] << 16 | bbuf[i+1] << 8 | bbuf[i+0];
//		 *(int*)(line +  i) = (unsigned int)col;
		//printf("%x, %x", col, addr);
			IOWR_8DIRECT( addr, 0, bbuf[i]);
			addr++;
*/
			addr += 64;
	}
	else if (num_buf) {
			Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP01);
			Hal4D13_ReadEndpoint(EPINDEX4EP01, (UCHAR *)addr1, 64);
			count_packet++;
			addr1 += 64;
	}
}

void Isr_Ep02Done(void)
{
	//Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP02);
	//printf("addrEP2 = %x\n", addr);
	//Hal4D13_WriteEndpoint(EPINDEX4EP02, (UCHAR *)addr, 64);
	//Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP02);

	if (!read_image){
	//	printf("read image");
		printf("addrEP2 = %x\n", addr);
		Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP02);
		Hal4D13_WriteEndpoint(EPINDEX4EP02, (UCHAR *) addr, 64);
		read_image = 1;

	}
	else{
			if (count_packet == numPacketPerFrame - 1){
		//		printf("ep2_end");
				read_image = 0;
				count_packet = 0;
				addr = addr - 3145724;
			}
			else{
				count_packet++;
				addr += 4;
	/*			for(i = 0; i < 64; i+=4){
						//addr += 64;
						addr = bbuf[i+3] << 24 | bbuf[i+2] << 16 | bbuf[i+1] << 8 | bbuf[i];
						addr++;
				//		printf("addr += 64");
		*/	//			}
			//	printf ("ep2 addr+=64");
			}
		Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP02);
		Hal4D13_WriteEndpoint(EPINDEX4EP02, (UCHAR *) addr, 64);
	}

	//Hal4D13_WriteEndpoint(EPINDEX4EP02, (UCHAR *) addr, 64);
	//Hal4D13_GetEndpointStatusWInteruptClear(EPINDEX4EP02);
}
