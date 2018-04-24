`timescale 1ns / 1ps

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:55:33 03/22/2018 
// Design Name: 
// Module Name:    Reader 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Reader(
	sysclk,
	counter,
	//clock,      //The clock used to collect the results of AD
	start,      //start working signal
	rst_n,      //reset signal
	data_ad,    //the results of AD module
	ready,      //鍙戠粰CPU缁撴潫鏈疆鏁版嵁鍙戦€
	tx
);
	input sysclk;
	//input clock;
	input start;
	input rst_n;
	input [19:0] counter;
	input [11:0] data_ad;
	output reg ready;
	output tx;
	 
	wire ad_clk;
	reg [5:0] i;
	reg [6:0] j;
	reg [511:0] Data;
	reg [7:0] tx_data;
	reg start_tx;
	wire tx_busy;
	wire rx,rdy,rdy_clr;
	wire [7:0]dout;
	reg [2:0] state, next_state;
	 
	localparam  INIT			= 3'b000,
					WAIT_READ	= 3'b001,
					READ			= 3'b010,
					WAIT_CLK		= 3'b011,
					WAIT			= 3'b100,
					SEND			= 3'b101,
					MIDIA			= 3'b110,
					END			= 3'b111;
	
	localparam SIZE = 32;
	localparam SEND_SIZE = 64;
					
					
	always@(negedge sysclk or negedge rst_n) begin
		state <= (!rst_n) ? INIT : next_state;
	end
	
//	always@(start or state or clock or tx_busy)begin
	always@(posedge sysclk)begin
		case(state)
			INIT:begin
				i <= 6'b0;
				j <= 6'b0;
				ready <= 0;
				Data <= 512'b0;
				start_tx <= 0;
				tx_data <= 8'b0;
				if(start)begin
					next_state <= WAIT_READ;
				end
				else 
					next_state <= INIT;
			end
			WAIT_READ:begin
				next_state <= (ad_clk == 1)? READ:state;
			end
			READ:begin 
				if(i == SIZE) begin
					start_tx <= 0;
					j <= 6'd0;
					next_state <= SEND;
				end
				else begin
					Data <= {4'b0000,data_ad,Data[511:16]};
					i <= i + 1'b1;
					tx_data <= tx_data;
					start_tx <= start_tx;
					next_state <= WAIT_CLK;
				end
			end
			WAIT_CLK:begin
				next_state <= (ad_clk == 1)? WAIT_CLK:WAIT_READ;
			end
			WAIT:begin
				i <= i;
				j <= j;
				tx_data <= tx_data;
				start_tx <= start_tx;
				Data <= Data;
				next_state <= (tx_busy == 1)?SEND:state;
			end
			SEND:begin
				if(!tx_busy)begin
					start_tx <= 0;
					tx_data <= Data[7:0];
					Data <= {8'b0,Data[511:8]};
					j <= j+1;
					i <= i;
					next_state <= (j == SEND_SIZE)? END : MIDIA;
				end
				else begin
					i <= i;
					j <= j;
					tx_data <= tx_data;
					start_tx <= start_tx;
					Data <= Data;
					next_state <= state;	
				end
			end
			MIDIA:begin
				i <= i;
				j <= j;
				tx_data <= tx_data;
				start_tx <= (tx_busy == 1)? 0:1;
				Data <= Data;
				next_state <= (tx_busy == 1)?SEND:state;
			end

			END:begin
				i <= i;
				j <= j;
				ready <= 1;
				start_tx <= 0;
				tx_data <= tx_data;
				if(start == 0)
					next_state <= INIT;
				else
					next_state <= END;
			end
			default:
				next_state <= INIT;
		endcase
	end
	uart uart
	(
		.din(tx_data),
		.wr_en(start_tx),
	   .clk_50m(sysclk),
	   .tx(tx),
	   .tx_busy(tx_busy),
	   .rx(rx),
	   .rdy(rdy),
	   .rdy_clr(rdy_clr),
	   .dout(dout)
		);
	divider divider(
		.counter(counter),
		.clk(sysclk),
		.ad_clk(ad_clk),
		.rst_n(rst_n)
	);
endmodule
