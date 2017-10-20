#include "Log.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, OpenLog)
#pragma alloc_text (PAGE, CloseLog)
#pragma alloc_text (PAGE, Log)
#endif

void dec_to_str(char* str, UINT32 val, UINT8 digits)
{
	size_t i = 1u;

	for(; i <= digits; i++)
	{
		str[digits - i] = (char)((val % 10u) + '0');
		val /= 10u;
	}

	str[i - 1u] = '\0'; //null terminated string
}

char LogOpen = FALSE;

NTSTATUS OpenLog()
{
	NTSTATUS status = STATUS_SUCCESS;

	PAGED_CODE();

	if(LogOpen == FALSE)
	{
		IO_STATUS_BLOCK    ioStatusBlock;
		UNICODE_STRING     uniName;
		OBJECT_ATTRIBUTES  objAttr;

		RtlInitUnicodeString(&uniName, L"\\DosDevices\\C:\\log.txt");
		InitializeObjectAttributes(&objAttr, &uniName,
			OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
			NULL, NULL);

		status = ZwCreateFile(&LogHandle,
			FILE_GENERIC_WRITE,
			&objAttr, &ioStatusBlock, NULL,
			FILE_ATTRIBUTE_NORMAL,
			FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
			FILE_OVERWRITE_IF,
			FILE_SYNCHRONOUS_IO_NONALERT,
			NULL, 0);

		if(NT_SUCCESS(status))
			LogOpen = TRUE;
	}

	return status;
}

NTSTATUS CloseLog()
{
	NTSTATUS status = 1;

	PAGED_CODE();

	if(LogOpen == TRUE)
	{
		status = ZwClose(LogHandle);

		if(NT_SUCCESS(status))
			LogOpen = FALSE;
	}

	return status;
}

NTSTATUS Log(const char* message, BOOLEAN NewLine)
{
	NTSTATUS status = STATUS_SUCCESS;

	PAGED_CODE();

	if(LogOpen == TRUE)
	{
		#define MAXLENGTH 128
		size_t length = strnlen_s(message, MAXLENGTH);
		ULONG ActualLength = (ULONG)min(length, MAXLENGTH);
		char LogMessage[MAXLENGTH];
		memcpy_s(LogMessage, ActualLength, message, ActualLength);

		ULONG NewLineLength = 0;
		if(NewLine)
		{
			LogMessage[ActualLength] = '\r';
			LogMessage[ActualLength + 1] = '\n';
			NewLineLength = 2;
		}

		IO_STATUS_BLOCK ioStatusBlock;
		LARGE_INTEGER ByteOffset;
		ByteOffset.HighPart = -1;
		//ByteOffset.LowPart = FILE_WRITE_TO_END_OF_FILE;
		ByteOffset.LowPart = FILE_USE_FILE_POINTER_POSITION;

		status = ZwWriteFile(LogHandle,
			NULL, NULL, NULL,
			&ioStatusBlock,
			LogMessage, ActualLength + NewLineLength,
			&ByteOffset, NULL);
	}

	return status;
}

NTSTATUS LogValue(UINT32 Value, BOOLEAN NewLine)
{
	char ValueString[14];

	PAGED_CODE();

	if(Value < 10u) dec_to_str(ValueString, Value, 1);
	else if(Value < 100u) dec_to_str(ValueString, Value, 2);
	else if(Value < 1000u) dec_to_str(ValueString, Value, 3);
	else if(Value < 10000u) dec_to_str(ValueString, Value, 4);
	else if(Value < 100000u) dec_to_str(ValueString, Value, 5);
	else if(Value < 1000000u) dec_to_str(ValueString, Value, 6);
	else if(Value < 10000000u) dec_to_str(ValueString, Value, 7);
	else if(Value < 100000000u) dec_to_str(ValueString, Value, 8);
	else if(Value < 1000000000u) dec_to_str(ValueString, Value, 9);
	else dec_to_str(ValueString, Value, 10);

	return Log(ValueString, NewLine);
}