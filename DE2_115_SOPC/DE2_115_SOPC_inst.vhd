	component DE2_115_SOPC is
		port (
			altpll_sys                   : out   std_logic;                                        -- clk
			altpll_io                    : out   std_logic;                                        -- clk
			c3_out_clk_clk               : out   std_logic;                                        -- clk
			clk_50                       : in    std_logic                     := 'X';             -- clk
			reset_n                      : in    std_logic                     := 'X';             -- reset_n
			in_port_to_the_key           : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			LCD_RS_from_the_lcd          : out   std_logic;                                        -- RS
			LCD_RW_from_the_lcd          : out   std_logic;                                        -- RW
			LCD_data_to_and_from_the_lcd : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- data
			LCD_E_from_the_lcd           : out   std_logic;                                        -- E
			out_port_from_the_ledg       : out   std_logic_vector(8 downto 0);                     -- export
			out_port_from_the_ledr       : out   std_logic_vector(17 downto 0);                    -- export
			altpll_sdram                 : out   std_logic;                                        -- clk
			locked_from_the_pll          : out   std_logic;                                        -- export
			zs_addr_from_the_sdram       : out   std_logic_vector(12 downto 0);                    -- addr
			zs_ba_from_the_sdram         : out   std_logic_vector(1 downto 0);                     -- ba
			zs_cas_n_from_the_sdram      : out   std_logic;                                        -- cas_n
			zs_cke_from_the_sdram        : out   std_logic;                                        -- cke
			zs_cs_n_from_the_sdram       : out   std_logic;                                        -- cs_n
			zs_dq_to_and_from_the_sdram  : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			zs_dqm_from_the_sdram        : out   std_logic_vector(3 downto 0);                     -- dqm
			zs_ras_n_from_the_sdram      : out   std_logic;                                        -- ras_n
			zs_we_n_from_the_sdram       : out   std_logic;                                        -- we_n
			SEG7_from_the_seg7           : out   std_logic_vector(63 downto 0);                    -- export
			in_port_to_the_sw            : in    std_logic_vector(17 downto 0) := (others => 'X'); -- export
			usb_conduit_end_DATA         : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DATA
			usb_conduit_end_ADDR         : out   std_logic_vector(1 downto 0);                     -- ADDR
			usb_conduit_end_RD_N         : out   std_logic;                                        -- RD_N
			usb_conduit_end_WR_N         : out   std_logic;                                        -- WR_N
			usb_conduit_end_CS_N         : out   std_logic;                                        -- CS_N
			usb_conduit_end_RST_N        : out   std_logic;                                        -- RST_N
			usb_conduit_end_INT0         : in    std_logic                     := 'X';             -- INT0
			usb_conduit_end_INT1         : in    std_logic                     := 'X';             -- INT1
			vga_data_CLK                 : out   std_logic;                                        -- CLK
			vga_data_HS                  : out   std_logic;                                        -- HS
			vga_data_VS                  : out   std_logic;                                        -- VS
			vga_data_BLANK               : out   std_logic;                                        -- BLANK
			vga_data_SYNC                : out   std_logic;                                        -- SYNC
			vga_data_R                   : out   std_logic_vector(7 downto 0);                     -- R
			vga_data_G                   : out   std_logic_vector(7 downto 0);                     -- G
			vga_data_B                   : out   std_logic_vector(7 downto 0);                     -- B
			pll_areset_conduit_export    : in    std_logic                     := 'X'              -- export
		);
	end component DE2_115_SOPC;

	u0 : component DE2_115_SOPC
		port map (
			altpll_sys                   => CONNECTED_TO_altpll_sys,                   --               c0_out_clk.clk
			altpll_io                    => CONNECTED_TO_altpll_io,                    --               c2_out_clk.clk
			c3_out_clk_clk               => CONNECTED_TO_c3_out_clk_clk,               --               c3_out_clk.clk
			clk_50                       => CONNECTED_TO_clk_50,                       --            clk_50_clk_in.clk
			reset_n                      => CONNECTED_TO_reset_n,                      --      clk_50_clk_in_reset.reset_n
			in_port_to_the_key           => CONNECTED_TO_in_port_to_the_key,           --  key_external_connection.export
			LCD_RS_from_the_lcd          => CONNECTED_TO_LCD_RS_from_the_lcd,          --             lcd_external.RS
			LCD_RW_from_the_lcd          => CONNECTED_TO_LCD_RW_from_the_lcd,          --                         .RW
			LCD_data_to_and_from_the_lcd => CONNECTED_TO_LCD_data_to_and_from_the_lcd, --                         .data
			LCD_E_from_the_lcd           => CONNECTED_TO_LCD_E_from_the_lcd,           --                         .E
			out_port_from_the_ledg       => CONNECTED_TO_out_port_from_the_ledg,       -- ledg_external_connection.export
			out_port_from_the_ledr       => CONNECTED_TO_out_port_from_the_ledr,       -- ledr_external_connection.export
			altpll_sdram                 => CONNECTED_TO_altpll_sdram,                 --                   pll_c1.clk
			locked_from_the_pll          => CONNECTED_TO_locked_from_the_pll,          --       pll_locked_conduit.export
			zs_addr_from_the_sdram       => CONNECTED_TO_zs_addr_from_the_sdram,       --               sdram_wire.addr
			zs_ba_from_the_sdram         => CONNECTED_TO_zs_ba_from_the_sdram,         --                         .ba
			zs_cas_n_from_the_sdram      => CONNECTED_TO_zs_cas_n_from_the_sdram,      --                         .cas_n
			zs_cke_from_the_sdram        => CONNECTED_TO_zs_cke_from_the_sdram,        --                         .cke
			zs_cs_n_from_the_sdram       => CONNECTED_TO_zs_cs_n_from_the_sdram,       --                         .cs_n
			zs_dq_to_and_from_the_sdram  => CONNECTED_TO_zs_dq_to_and_from_the_sdram,  --                         .dq
			zs_dqm_from_the_sdram        => CONNECTED_TO_zs_dqm_from_the_sdram,        --                         .dqm
			zs_ras_n_from_the_sdram      => CONNECTED_TO_zs_ras_n_from_the_sdram,      --                         .ras_n
			zs_we_n_from_the_sdram       => CONNECTED_TO_zs_we_n_from_the_sdram,       --                         .we_n
			SEG7_from_the_seg7           => CONNECTED_TO_SEG7_from_the_seg7,           --         seg7_conduit_end.export
			in_port_to_the_sw            => CONNECTED_TO_in_port_to_the_sw,            --   sw_external_connection.export
			usb_conduit_end_DATA         => CONNECTED_TO_usb_conduit_end_DATA,         --          usb_conduit_end.DATA
			usb_conduit_end_ADDR         => CONNECTED_TO_usb_conduit_end_ADDR,         --                         .ADDR
			usb_conduit_end_RD_N         => CONNECTED_TO_usb_conduit_end_RD_N,         --                         .RD_N
			usb_conduit_end_WR_N         => CONNECTED_TO_usb_conduit_end_WR_N,         --                         .WR_N
			usb_conduit_end_CS_N         => CONNECTED_TO_usb_conduit_end_CS_N,         --                         .CS_N
			usb_conduit_end_RST_N        => CONNECTED_TO_usb_conduit_end_RST_N,        --                         .RST_N
			usb_conduit_end_INT0         => CONNECTED_TO_usb_conduit_end_INT0,         --                         .INT0
			usb_conduit_end_INT1         => CONNECTED_TO_usb_conduit_end_INT1,         --                         .INT1
			vga_data_CLK                 => CONNECTED_TO_vga_data_CLK,                 --                 vga_data.CLK
			vga_data_HS                  => CONNECTED_TO_vga_data_HS,                  --                         .HS
			vga_data_VS                  => CONNECTED_TO_vga_data_VS,                  --                         .VS
			vga_data_BLANK               => CONNECTED_TO_vga_data_BLANK,               --                         .BLANK
			vga_data_SYNC                => CONNECTED_TO_vga_data_SYNC,                --                         .SYNC
			vga_data_R                   => CONNECTED_TO_vga_data_R,                   --                         .R
			vga_data_G                   => CONNECTED_TO_vga_data_G,                   --                         .G
			vga_data_B                   => CONNECTED_TO_vga_data_B,                   --                         .B
			pll_areset_conduit_export    => CONNECTED_TO_pll_areset_conduit_export     --       pll_areset_conduit.export
		);

