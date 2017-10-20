#include "TxtReader.h"
#include "Display.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, ReadTxt)
#endif

PCWSTR FileName = L"\\DosDevices\\C:\\Data.txt";

NTSTATUS ReadTxt(CHAR buffer[BUFFER_SIZE])
{
	NTSTATUS status = STATUS_SUCCESS;

	HANDLE handle;
	UNICODE_STRING uniName;
	OBJECT_ATTRIBUTES objAttr;
	IO_STATUS_BLOCK ioStatusBlock;
	LARGE_INTEGER byteOffset;

	PAGED_CODE();

	RtlInitUnicodeString(&uniName, FileName);
	InitializeObjectAttributes(&objAttr, &uniName,
		OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
		NULL, NULL);

	if(KeGetCurrentIrql() != PASSIVE_LEVEL)
		return STATUS_INVALID_DEVICE_STATE;

	status = ZwCreateFile(&handle,
		GENERIC_READ,
		&objAttr, &ioStatusBlock,
		NULL,
		FILE_ATTRIBUTE_NORMAL,
		0,
		FILE_OPEN,
		FILE_SYNCHRONOUS_IO_NONALERT,
		NULL, 0);

	if(NT_SUCCESS(status)) {
		byteOffset.LowPart = byteOffset.HighPart = 0;

		status = ZwReadFile(handle, NULL, NULL, NULL, &ioStatusBlock,
			buffer, BUFFER_SIZE - 1, &byteOffset, NULL);

		buffer[BUFFER_SIZE - 1] = '\0';

		ZwClose(handle);
	}

	return status;
}