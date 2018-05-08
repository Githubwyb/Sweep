int main()
{
	printf("Hello from Nios II!\n");
	int i = 0,j=0;
	uart_input.init();
	float input[32] = {0};

	for(i=2;i<150000;i+=350){
		printf("%d i\n",i);
		double fre = 50000000/(i * 32);
		AD9833_WaveSeting(fre,0,SIN_WAVE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_INPUT_BASE,i);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,0);
		for(j =0 ;j < 100;j ++);
		LOG_DEBUG("OK");
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,1);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_START_BASE,1);
		while(uart_input.receive_flag != 1);
		LOG_DEBUG("OK");
		parseAdData(input,uart_input.receive_buffer);
		log_hex(uart_input.receive_buffer, 64);
		for(j=0; j < 32; j++)
		{
			printf("%d,",(int)(input[j] * 1000000));
//			printf("%x  ",uart.receive_buffer[j]);
		}
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_START_BASE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RST_BASE,0);
		uart_input.receive_flag = 0;
		printf("\n");
	}
	return 0;
}
