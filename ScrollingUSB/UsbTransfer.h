#pragma once

#include <ntddk.h>
#include <wdf.h>
#include <usb.h>
#include <usbdlib.h>
#include <wdfusb.h>

#include "Log.h"
#include "DeviceContext.h"
#include "Display.h"
#include "TxtReader.h"

NTSTATUS AttachToUSB(WDFDEVICE* Device, DEVICE_CONTEXT* Context);