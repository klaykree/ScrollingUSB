#include "Display.h"

unsigned char DisplayBits[DISPLAY_HEIGHT_BYTES][DISPLAY_WIDTH_BYTES];

void CharToBits(char Char, unsigned char Bits[3])
{
	if(Char == 'A' || Char == 'a')
	{
		Bits[0] = 0b01001010;
		Bits[1] = 0b11101010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'B' || Char == 'b')
	{
		Bits[0] = 0b11001010;
		Bits[1] = 0b11001010;
		Bits[2] = 0b11000000;
	}
	else if(Char == 'C' || Char == 'c')
	{
		Bits[0] = 0b01101000;
		Bits[1] = 0b10001000;
		Bits[2] = 0b01100000;
	}
	else if(Char == 'D' || Char == 'd')
	{
		Bits[0] = 0b11001010;
		Bits[1] = 0b10101010;
		Bits[2] = 0b11000000;
	}
	else if(Char == 'E' || Char == 'e')
	{
		Bits[0] = 0b11101000;
		Bits[1] = 0b11001000;
		Bits[2] = 0b11100000;
	}
	else if(Char == 'F' || Char == 'f')
	{
		Bits[0] = 0b11101000;
		Bits[1] = 0b11001000;
		Bits[2] = 0b10000000;
	}
	else if(Char == 'G' || Char == 'g')
	{
		Bits[0] = 0b01101000;
		Bits[1] = 0b10101010;
		Bits[2] = 0b01100000;
	}
	else if(Char == 'H' || Char == 'h')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b11101010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'I' || Char == 'i')
	{
		Bits[0] = 0b11100100;
		Bits[1] = 0b01000100;
		Bits[2] = 0b11100000;
	}
	else if(Char == 'J' || Char == 'j')
	{
		Bits[0] = 0b11100100;
		Bits[1] = 0b01000100;
		Bits[2] = 0b11000000;
	}
	else if(Char == 'K' || Char == 'k')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b11001010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'L' || Char == 'l')
	{
		Bits[0] = 0b10001000;
		Bits[1] = 0b10001000;
		Bits[2] = 0b11100000;
	}
	else if(Char == 'M' || Char == 'm')
	{
		Bits[0] = 0b10101110;
		Bits[1] = 0b11101010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'N' || Char == 'n')
	{
		Bits[0] = 0b10101110;
		Bits[1] = 0b11101110;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'O' || Char == 'o')
	{
		Bits[0] = 0b01001010;
		Bits[1] = 0b10101010;
		Bits[2] = 0b01000000;
	}
	else if(Char == 'P' || Char == 'p')
	{
		Bits[0] = 0b11001010;
		Bits[1] = 0b11001000;
		Bits[2] = 0b10000000;
	}
	else if(Char == 'Q' || Char == 'q')
	{
		Bits[0] = 0b01001010;
		Bits[1] = 0b10101100;
		Bits[2] = 0b00100000;
	}
	else if(Char == 'R' || Char == 'r')
	{
		Bits[0] = 0b11001010;
		Bits[1] = 0b11001010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'S' || Char == 's')
	{
		Bits[0] = 0b11101000;
		Bits[1] = 0b11100010;
		Bits[2] = 0b11100000;
	}
	else if(Char == 'T' || Char == 't')
	{
		Bits[0] = 0b11100100;
		Bits[1] = 0b01000100;
		Bits[2] = 0b01000000;
	}
	else if(Char == 'U' || Char == 'u')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b10101010;
		Bits[2] = 0b11100000;
	}
	else if(Char == 'V' || Char == 'v')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b10101010;
		Bits[2] = 0b01000000;
	}
	else if(Char == 'W' || Char == 'w')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b11101110;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'X' || Char == 'x')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b01001010;
		Bits[2] = 0b10100000;
	}
	else if(Char == 'Y' || Char == 'y')
	{
		Bits[0] = 0b10101010;
		Bits[1] = 0b01000100;
		Bits[2] = 0b01000000;
	}
	else if(Char == 'Z' || Char == 'z')
	{
		Bits[0] = 0b11100010;
		Bits[1] = 0b01001000;
		Bits[2] = 0b11100000;
	}
	else if(Char == ':')
	{
		Bits[0] = 0b01000100;
		Bits[1] = 0b00000100;
		Bits[2] = 0b01000000;
	}
	else if(Char == '0')
	{
		Bits[0] = 0b11101010;
		Bits[1] = 0b10101010;
		Bits[2] = 0b11100000;
	}
	else if(Char == '1')
	{
		Bits[0] = 0b01001100;
		Bits[1] = 0b01000100;
		Bits[2] = 0b11100000;
	}
	else if(Char == '2')
	{
		Bits[0] = 0b11100010;
		Bits[1] = 0b11101000;
		Bits[2] = 0b11100000;
	}
	else if(Char == '3')
	{
		Bits[0] = 0b11100010;
		Bits[1] = 0b11100010;
		Bits[2] = 0b11100000;
	}
	else if(Char == '4')
	{
		Bits[0] = 0b10001000;
		Bits[1] = 0b11100100;
		Bits[2] = 0b01000000;
	}
	else if(Char == '5')
	{
		Bits[0] = 0b11101000;
		Bits[1] = 0b11100010;
		Bits[2] = 0b11000000;
	}
	else if(Char == '6')
	{
		Bits[0] = 0b11101000;
		Bits[1] = 0b11101010;
		Bits[2] = 0b11100000;
	}
	else if(Char == '7')
	{
		Bits[0] = 0b11100010;
		Bits[1] = 0b00100010;
		Bits[2] = 0b00100000;
	}
	else if(Char == '8')
	{
		Bits[0] = 0b11101010;
		Bits[1] = 0b11101010;
		Bits[2] = 0b11100000;
	}
	else if(Char == '9')
	{
		Bits[0] = 0b11101010;
		Bits[1] = 0b11100010;
		Bits[2] = 0b11100000;
	}
	else if(Char == ' ')
	{
		Bits[0] = 0b00000000;
		Bits[1] = 0b00000000;
		Bits[2] = 0b00000000;
	}
}

DisplayBitsArray* GetDisplayPixels(char* Text)
{
	unsigned char Bits[3];
	char CurrentChar;
	int Index = 0;
	int NextLine = 0;
	while(TRUE)
	{
		CurrentChar = Text[Index];
		if(CurrentChar == '\0') //NULL terminated string
			break;
		
		memset(Bits, 0, 3);
		CharToBits(CurrentChar, Bits);

		int Odd = Index % 2;
		if(NextLine == 1)
		{
			Odd ^= 1; //Invert even and odd for the next line
		}

		int XByte = (Index - (NextLine * 11)) / 2;

		//Each character is 4 LEDs wide and 5 LEDs high, each LED is 1 bit
		unsigned char HighByte = Bits[0] & 0b11110000;
		unsigned char LowByte = Bits[0] & 0b00001111;
		//Shift bits for every second character, since each character is 4 bits wide
		HighByte >>= Odd * 4;
		if(Odd == 0)
			LowByte <<= 4;
		DisplayBits[0 + (NextLine * 6)][XByte] ^= HighByte; //Add bits to existing byte
		DisplayBits[1 + (NextLine * 6)][XByte] ^= LowByte;

		//Repeat for lines 3, 4, and 5
		HighByte = Bits[1] & 0b11110000;
		LowByte = Bits[1] & 0b00001111;
		HighByte >>= Odd * 4;
		if(Odd == 0)
			LowByte <<= 4;
		DisplayBits[2 + (NextLine * 6)][XByte] ^= HighByte;
		DisplayBits[3 + (NextLine * 6)][XByte] ^= LowByte;

		HighByte = Bits[2] & 0b11110000;
		HighByte >>= Odd * 4;
		DisplayBits[4 + (NextLine * 6)][XByte] ^= HighByte;

		++Index;

		//Move to the lower 5 LED rows
		if(Index == 11)
			NextLine = 1;
	}

	return DisplayBits;
}

NTSTATUS SendData(UCHAR* Buffer, ULONG Size, WDFUSBPIPE* DataPipe)
{
	WDF_MEMORY_DESCRIPTOR MemDesc;
	WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&MemDesc, Buffer, Size);

	ULONG BytesWritten;
	NTSTATUS status = WdfUsbTargetPipeWriteSynchronously(*DataPipe,
		NULL, NULL,
		&MemDesc, &BytesWritten
	);

	Log("Bytes written: ", FALSE);
	LogValue(BytesWritten, TRUE);

	return status;
}

NTSTATUS DrawPixels(WDFUSBPIPE* DataPipe, char* Text)
{
	NTSTATUS status;

	PAGED_CODE();

	UCHAR Buffer[64];

	//'Hello' packet
	memset(Buffer, 0, 64);
	memcpy_s(Buffer, sizeof(Buffer), "Hello", 6);
	status = SendData(Buffer, 6, DataPipe);

	//Header packet, defines size of data packets as well as scroll speed and animation type
	//'74' (byte two) means: Dont animate, speed 8 (the speed is not used with dont animate)
	//00 74 11 22 33 44 55 66 77 00 08 00 00 XX 08 XX	.t."3DUfw.......
	//00 00 08 XX 00 00 08 XX 00 00 08 XX 00 00 08 XX   ................
	//00 00 08 XX 00 00 08 XX                           ........
	memset(Buffer, 0, 64);
	#define BytesPerPacket 0x06 //XX

	Buffer[1] = 0x74;
	Buffer[2] = 0x11;
	Buffer[3] = 0x22;
	Buffer[4] = 0x33;
	Buffer[5] = 0x44;
	Buffer[6] = 0x55;
	Buffer[7] = 0x66;
	Buffer[8] = 0x77;
	Buffer[10] = 0x08;
	Buffer[13] = BytesPerPacket;
	Buffer[14] = 0x08;
	Buffer[15] = BytesPerPacket;

	Buffer[18] = 0x08;
	Buffer[19] = BytesPerPacket;
	Buffer[22] = 0x08;
	Buffer[23] = BytesPerPacket;
	Buffer[26] = 0x08;
	Buffer[27] = BytesPerPacket;
	Buffer[30] = 0x08;
	Buffer[31] = BytesPerPacket;

	Buffer[34] = 0x08;
	Buffer[35] = BytesPerPacket;
	Buffer[38] = 0x08;
	Buffer[39] = BytesPerPacket;
	status = SendData(Buffer, 64, DataPipe);

	//Data packets
	memset(Buffer, 0, 64);
	DisplayBitsArray* Pixels = GetDisplayPixels(Text);

	status = SendData(Pixels[0], BytesPerPacket, DataPipe);
	status = SendData(Pixels[1], BytesPerPacket, DataPipe);
	status = SendData(Pixels[2], BytesPerPacket, DataPipe);
	status = SendData(Pixels[3], BytesPerPacket, DataPipe);
	status = SendData(Pixels[4], BytesPerPacket, DataPipe);
	status = SendData(Pixels[5], BytesPerPacket, DataPipe);
	status = SendData(Pixels[6], BytesPerPacket, DataPipe);
	status = SendData(Pixels[7], BytesPerPacket, DataPipe);
	status = SendData(Pixels[8], BytesPerPacket, DataPipe);
	status = SendData(Pixels[9], BytesPerPacket, DataPipe);
	status = SendData(Pixels[10], BytesPerPacket, DataPipe);

	return status;
}