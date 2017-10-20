/*++

Module Name:

device.h

Abstract:

This file contains the device definitions.

Environment:

Kernel-mode Driver Framework

--*/

#include "public.h"

EXTERN_C_START

#include "DeviceContext.h"

//
// This macro will generate an inline function called DeviceGetContext
// which will be used to get a pointer to the device context memory
// in a type safe manner.
//
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext)

//
// Function to initialize the device's queues and callbacks
//
NTSTATUS
ScrollingUSBCreateDevice(
	_Inout_ PWDFDEVICE_INIT DeviceInit
);

//
// Function to select the device's USB configuration and get a WDFUSBDEVICE
// handle
//
EVT_WDF_DEVICE_PREPARE_HARDWARE ScrollingUSBEvtDevicePrepareHardware;

EXTERN_C_END
