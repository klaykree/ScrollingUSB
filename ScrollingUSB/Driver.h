/*++

Module Name:

driver.h

Abstract:

This file contains the driver definitions.

Environment:

Kernel-mode Driver Framework

--*/

#define INITGUID

#include <ntddk.h>
#include <wdf.h>
#include <usb.h>
#include <usbdlib.h>
#include <wdfusb.h>

#include "device.h"
#include "queue.h"
#include "trace.h"
#include "Log.h"

#include "UsbTransfer.h"

EXTERN_C_START

//
// WDFDRIVER Events
//

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD ScrollingUSBEvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP ScrollingUSBEvtDriverContextCleanup;

EXTERN_C_END
