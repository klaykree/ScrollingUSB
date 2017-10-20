#pragma once
#include <ntddk.h>

EXTERN_C_START

HANDLE LogHandle;

NTSTATUS OpenLog();
NTSTATUS CloseLog();
NTSTATUS Log(const char* message, BOOLEAN NewLine);
NTSTATUS LogValue(UINT32 Value, BOOLEAN NewLine);

EXTERN_C_END