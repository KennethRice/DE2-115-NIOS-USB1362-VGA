
module DE2_115_SOPC (
	altpll_sys,
	altpll_io,
	c3_out_clk_clk,
	clk_50,
	reset_n,
	in_port_to_the_key,
	LCD_RS_from_the_lcd,
	LCD_RW_from_the_lcd,
	LCD_data_to_and_from_the_lcd,
	LCD_E_from_the_lcd,
	out_port_from_the_ledg,
	out_port_from_the_ledr,
	altpll_sdram,
	locked_from_the_pll,
	zs_addr_from_the_sdram,
	zs_ba_from_the_sdram,
	zs_cas_n_from_the_sdram,
	zs_cke_from_the_sdram,
	zs_cs_n_from_the_sdram,
	zs_dq_to_and_from_the_sdram,
	zs_dqm_from_the_sdram,
	zs_ras_n_from_the_sdram,
	zs_we_n_from_the_sdram,
	SEG7_from_the_seg7,
	in_port_to_the_sw,
	usb_conduit_end_DATA,
	usb_conduit_end_ADDR,
	usb_conduit_end_RD_N,
	usb_conduit_end_WR_N,
	usb_conduit_end_CS_N,
	usb_conduit_end_RST_N,
	usb_conduit_end_INT0,
	usb_conduit_end_INT1,
	vga_data_CLK,
	vga_data_HS,
	vga_data_VS,
	vga_data_BLANK,
	vga_data_SYNC,
	vga_data_R,
	vga_data_G,
	vga_data_B,
	pll_areset_conduit_export);	

	output		altpll_sys;
	output		altpll_io;
	output		c3_out_clk_clk;
	input		clk_50;
	input		reset_n;
	input	[3:0]	in_port_to_the_key;
	output		LCD_RS_from_the_lcd;
	output		LCD_RW_from_the_lcd;
	inout	[7:0]	LCD_data_to_and_from_the_lcd;
	output		LCD_E_from_the_lcd;
	output	[8:0]	out_port_from_the_ledg;
	output	[17:0]	out_port_from_the_ledr;
	output		altpll_sdram;
	output		locked_from_the_pll;
	output	[12:0]	zs_addr_from_the_sdram;
	output	[1:0]	zs_ba_from_the_sdram;
	output		zs_cas_n_from_the_sdram;
	output		zs_cke_from_the_sdram;
	output		zs_cs_n_from_the_sdram;
	inout	[31:0]	zs_dq_to_and_from_the_sdram;
	output	[3:0]	zs_dqm_from_the_sdram;
	output		zs_ras_n_from_the_sdram;
	output		zs_we_n_from_the_sdram;
	output	[63:0]	SEG7_from_the_seg7;
	input	[17:0]	in_port_to_the_sw;
	inout	[15:0]	usb_conduit_end_DATA;
	output	[1:0]	usb_conduit_end_ADDR;
	output		usb_conduit_end_RD_N;
	output		usb_conduit_end_WR_N;
	output		usb_conduit_end_CS_N;
	output		usb_conduit_end_RST_N;
	input		usb_conduit_end_INT0;
	input		usb_conduit_end_INT1;
	output		vga_data_CLK;
	output		vga_data_HS;
	output		vga_data_VS;
	output		vga_data_BLANK;
	output		vga_data_SYNC;
	output	[7:0]	vga_data_R;
	output	[7:0]	vga_data_G;
	output	[7:0]	vga_data_B;
	input		pll_areset_conduit_export;
endmodule
