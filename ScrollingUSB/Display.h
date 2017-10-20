#pragma once
#include <ntddk.h>
#include <wdf.h>
#include <usb.h>
#include <usbdlib.h>
#include <wdfusb.h>

#include "Log.h"
#define DISPLAY_WIDTH_BYTES 6
#define DISPLAY_HEIGHT_BYTES 11
#define DISPLAY_WIDTH_BITS 44
#define DISPLAY_HEIGHT_BITS 11
typedef unsigned char DisplayBitsArray[DISPLAY_WIDTH_BYTES];

//Text must be null terminated
DisplayBitsArray* GetDisplayPixels(char* Text);

NTSTATUS SendData(UCHAR* Buffer, ULONG Size, WDFUSBPIPE* DataPipe);

NTSTATUS DrawPixels(WDFUSBPIPE* DataPipe, char* Text);