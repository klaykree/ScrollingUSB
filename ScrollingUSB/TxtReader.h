#pragma once
#include <ntddk.h>

EXTERN_C_START

extern PCWSTR FileName;
#define BUFFER_SIZE 23

NTSTATUS ReadTxt(CHAR buffer[BUFFER_SIZE]);

EXTERN_C_END