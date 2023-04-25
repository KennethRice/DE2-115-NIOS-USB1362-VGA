#include "hal.h"
#include "drv.h"
#include "isr.h"
#include "common.h"
#include "SEG7.h"
#include "./Graphics/simple_graphics.h"
#include "terasic_includes.h"
#include "./Pantalla/alt_video_display.h"
#include <math.h>
#include <stdio.h>
#include "system.h"

#define LCD_SGDMA_NAME "/dev/lcd_sgdma"
#define framePacket 57600
#define numBytePerRow 4096
#define numPacketPerRow 1024
#define numPacketPerFrame 768432
#define numEndByte 16*numPacket
//-------------------------------------------------------------------------
//  Global Variables
D13FLAGS bD13flags;
DEVICE_REQUEST DeviceRequest;


unsigned int red 	= 255;
unsigned int green 	= 0;
unsigned int blue 	= 0;
unsigned int color	= 0xFF00FF;//0x9AFAB0;
unsigned int color1	= 0xFF0000;//0x9AFAB0;
char* line;
int i, addr, addr1;
int num_buf = 0;
int bytes_per_line = 2560, bytes_per_pixel = 4;

int descr, descr1;

int count_packet = 0;
int write_image = 0;
int bol = 0;
int result;


int main(void)
{
	//printf("hello world");
	int sent = 0;
	RaiseIRQL();
	Hal4D13_ResetDevice();
	usleep(100);
	check_chip_id();
	configure_isp();
	Hal4D13_AcquireD13(ISP1362_IF_0_DC_IRQ, (void*) usb_isr);



	LowerIRQL();
//	unsigned short j;


	alt_video_display * display;
	display = alt_video_display_init( LCD_SGDMA_NAME,                    // char* sgdma_name
	                                    1024,//ALT_VIDEO_DISPLAY_COLS,                               // int width
	                                    768,//ALT_VIDEO_DISPLAY_ROWS,                               // int height
	                                    32,                                // int color_depth
	                                    ALT_VIDEO_DISPLAY_USE_HEAP,                              // int buffer_location
	                                    ALT_VIDEO_DISPLAY_USE_HEAP,                              // int descriptor_location
	                                    2 );
	if( display ){printf("-- VGA Resolution 640x480 OK\n");}
	else{printf("-- VGA FAILED\n");}

		//------------------------------------------------------

		/*line = malloc(bytes_per_line + 12);
		for (i = 0; i < bytes_per_line; i+=4)
			{
			  *(int*)(line +  i) = (unsigned int)0;
		}*/
/*
//	alt_video_display_clear_screen(display,7);
	vid_draw_box (0, 0, 1024, 768, color, 1, display);
	vid_draw_circle(250, 250, 100, color1, 112, display);
	alt_video_display_register_written_buffer( display );
	while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
	addr1 = (int)(display->buffer_ptrs[display->buffer_being_written]->buffer);
	printf("addr1 = %x", addr1);
	usleep(1000);
	usleep(1000000);
//	alt_video_display_clear_screen(display,7);

	vid_draw_box (0, 0, 1028, 768, color1, 1, display);
	vid_draw_circle(500, 500, 100, color, 112, display);
	alt_video_display_register_written_buffer( display );
	while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
	addr = (int)(display->buffer_ptrs[display->buffer_being_written]->buffer);
	printf("addr = %x", addr);

	usleep(1000000);
	alt_video_display_register_written_buffer( display );
*/
	//vid_draw_box (0, 0, 1024, 768, 0x00FF00, 1, display);
	//vid_draw_circle(250, 250, 100, color, 112, display);
	/*addr1 = (int)(display->buffer_ptrs[(display->buffer_being_written+1)%2]->buffer);
	descr1 = (int)(display->buffer_ptrs[(display->buffer_being_written+1)%2]->desc_base);
	printf("addr1 : %x desc1: %x", addr1, descr1);
	//alt_video_display_register_written_buffer( display );
	addr = (int)(display->buffer_ptrs[display->buffer_being_written]->buffer);
	descr = (int)(display->buffer_ptrs[display->buffer_being_written]->desc_base);
	printf("addr : %x desc: %x", addr, descr);
	*//*
    while(count<400)
    {
    	count2++;
    	count++;

		col = rand()%255;
		x1 = abs(rand()%600);
		y1 = abs(rand()%400);

	    for (i=0;i<2;i++)//2 buffers
	    {

			vid_draw_circle((int)x1, (int)y1,50, col, 1, display);//fill circle
			//vid_draw_circle((int)x1, (int)y1,50, 0, 0, display);//do not fill

			//draw count
			iton(count,str_data);
			vid_draw_box (10, 400, 100, 415, (int)7, (int)1, display);
			vid_print_string( 10, 400, 4, cour10_font, display,str_data );

			//draw progress
			vid_draw_line(0, 470, (int)count, 470, 3, 4, display);//4 - blue
			vid_draw_line(0, 460, 400, 460, 3, 4, display);//4 - blue

			//send to screen
			vid_draw_line(0, 0, 0, 767, 1, 0, display);//black
			alt_video_display_register_written_buffer( display );
			while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
	    }
    }
*/

	while(1) {
		if (bD13flags.DCP_state == USBFSM4DCP_SETUPPROC)
					SetupToken_Handler();
		if ((bD13flags.DCP_state == USBFSM4DCP_REQUESTPROC))
					DeviceRequest_Handler();




		//if(write_image)
		/*if(line[sizeof(line)- 20] != 0) {
		for (i = 0; i < 480; i++)
		  {
			memcpy( (void*)addr, line, bytes_per_line );
			addr += (display->width * bytes_per_pixel);
		  }
		}*/
		//free (line);
//		vid_draw_line(0, 0, 0, 767, 1, 0, display);//black


//		printf("buffer written");
		if(count_packet == (1024*768/16)) {
			alt_video_display_register_written_buffer( display );
			while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
			/*display->buffer_being_displayed = display->buffer_being_written;
			display->buffer_being_written = (display->buffer_being_written+1)%2;
			result = alt_avalon_sgdma_do_async_transfer(
					display->sgdma,
					display->buffer_ptrs[display->buffer_being_displayed]->desc_base);
			if(result){ printf("null");}
			printf("\ncpt addr write: %x", (int)(display->buffer_ptrs[display->buffer_being_written]->buffer));
			printf("\n cpt addr display: %x", (int)(display->buffer_ptrs[display->buffer_being_displayed]->buffer));
			printf("cpt desc: %x", display->buffer_ptrs[display->buffer_being_displayed]->desc_base);
			*///alt_video_display_register_written_buffer( display );
//while ( alt_video_display_buffer_is_available( display ) != 0 ){ }

			if(num_buf == 0){
				addr = (int)(display->buffer_ptrs[display->buffer_being_displayed]->buffer);
			} else {addr1 = (int)(display->buffer_ptrs[display->buffer_being_displayed]->buffer); }
			num_buf = (num_buf + 1) % 2;
			/*	if((int)(display->buffer_ptrs[display->buffer_being_written]->buffer) == (int)(display->buffer_ptrs[0]->buffer))
			display->buffer_being_displayed = 1;
			else display->buffer_being_displayed = 0;
			//while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
*/
			count_packet = 0;
			bol +=1;
			/*if(display->buffer_being_written == 0) {
			display->buffer_being_written = 1;
			} else if(display->buffer_being_written == 1) {
				display->buffer_being_written = 0;
			}*/
			//if( display->buffer_being_written != display->buffer_being_displayed ) printf("hueta"); else{




			//addr+=4;

			}
		//}
			//printf("addr1 = %x", addr);
		/*	for(int i = 1024*768-4; i < 1024*768+8; i++){
				col = vid_get_pixel(i, 0, display);
				printf("pix[ %x ] = %x ", i, col);
				alt_video_display_register_written_buffer( display );
				col = vid_get_pixel(i, 0, display);
				printf("pix[ %x ] = %x \n", i, col);
				alt_video_display_register_written_buffer( display );

			}
*/
	//}
		if(bol==3){
			usleep(1000000);
			bol = 0;
				alt_video_display_register_written_buffer( display );
//display->buffer_being_displayed = display->buffer_ptrs[0];
				while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
		}


	}
//--------------------------------------------------------------------------------------
/*	while(1){
		if (bD13flags.DCP_state == USBFSM4DCP_SETUPPROC){
					SetupToken_Handler();
		}

		if (bD13flags.DCP_state == USBFSM4DCP_REQUESTPROC){
					DeviceRequest_Handler();
		}

		for (unsigned int count = 0; count < 765; count++){
			if(count < 255){
				red--;
				green++;
			}
			if(count > 255 && count < 510){
				green--;
				blue++;
			}
			if(count > 510 && count < 765){
				blue--;
				red++;
			}
			color = blue << 16 | green << 8 | red;
			vid_draw_box (0, 0, 1024, 768, color, 1, display);
			SEG7_Hex(color, 0);
			alt_video_display_register_written_buffer( display );
			addr = (int)(display->buffer_ptrs[display->buffer_being_written]->buffer);
			printf("addr: %x \n", addr);
			while ( alt_video_display_buffer_is_available( display ) != 0 ){ }
			usleep(1000);
		}
	}
*/
//--------------------------------------------------------------------------------------
/*
	SEG7_Hex(color, 0);

	vid_draw_box (50, 50, 400, 300, 25486, 0xFF00BB, display);
	vid_draw_circle(250, 250, 100, 0x00AABB, 112, display);
	vid_print_char (150, 150, 0xFFFFFF, 'P', cour10_font, display);
	vid_print_char (170, 150, 0xFFFFFF, 'N', cour10_font, display);
	vid_print_char (190, 150, 0xFFFFFF, 'U', cour10_font, display);


	alt_video_display_register_written_buffer( display );
	while ( alt_video_display_buffer_is_available( display ) != 0 ){ }

	*/
}

void iton(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


