module divider(counter, rst_n, clk, ad_clk);
	input clk;
	input rst_n;
	input [19:0]counter;
	output ad_clk;
	

	reg [19:0] cnt_p;// 上升沿计数单位
	reg [19:0] cnt_n;// 下降沿计数单位
	reg             clk_p;// 上升沿时钟
	reg             clk_n;// 下降沿时钟

	assign ad_clk = (counter == 1) ? clk :
						(counter[0])   ? (clk_p | clk_n) : (clk_p);//其中counter==1是判断不分频，counter[0]是判断是奇数还是偶数，若为1则是奇数分频，若是偶数则是偶数分频。
			  
	always@(posedge clk or negedge rst_n) begin
		if (!rst_n)
			 cnt_p <= 0;
		else if (cnt_p == (counter-1))
			 cnt_p <= 0;
		else
			 cnt_p <= cnt_p + 1;
		end

	always@(posedge clk or negedge rst_n) begin
		if (!rst_n) 
			 clk_p <= 1;
		else if (cnt_p < (counter>>1))
			 clk_p <= 1;
		else
			 clk_p <= 0;    
	end

	always@(negedge clk or negedge rst_n) begin
		if (!rst_n)
			 cnt_n <= 0;
		else if (cnt_n == (counter-1))
			 cnt_n <= 0;
		else
			 cnt_n <= cnt_n + 1;
	end

	always@(negedge clk or negedge rst_n) begin
		if (!rst_n)
			 clk_n <= 1;
		else if (cnt_n < (counter>>1))
			 clk_n <= 1;
		else
			 clk_n <= 0;
	end
endmodule
