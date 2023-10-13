#define F_CPU 16000000UL
#define _BV(bit) (1<<bit)
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>

void UART_0_init(void);
void UART1_transmit(char data);
unsigned char UART1_receive(void);

void UART_0_init(void){
	UBRR0H = 0x00;		// 9,600������ ����
	UBRR0L = 207;
	UCSR0A = UCSR0A | (1<<1);		// 2��� ���(= _BV(U2X1))
	UCSR0C |= 0x06;
	
	UCSR0B |= _BV(RXEN0);		// �ۼ��� ����
	UCSR0B |= _BV(TXEN0);
}

void UART1_transmit(char data){
	while(!(UCSR0A & (1 << UDRE0)));		// �۽� ���� ���
	UDR0 = data;		//������ ����
}

unsigned char UART1_receive(void){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

int main(void){
	UART_0_init();		// UART0 �ʱ�ȭ
	
	while(1){
		UART1_transmit(UART1_receive());
	}
	
	return 0;
}