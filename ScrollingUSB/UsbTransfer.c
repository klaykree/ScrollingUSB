#include "UsbTransfer.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (PAGE, AttachToUSB)
#endif

WDFUSBPIPE DataPipe;

NTSTATUS AttachToUSB(WDFDEVICE* Device, DEVICE_CONTEXT* Context)
{
	NTSTATUS status = STATUS_SUCCESS;

	WDF_USB_DEVICE_CREATE_CONFIG DeviceCreateConfig;
	WDF_USB_DEVICE_CREATE_CONFIG_INIT(&DeviceCreateConfig, USBD_CLIENT_CONTRACT_VERSION_602);

	status = WdfUsbTargetDeviceCreateWithParameters(*Device,
		&DeviceCreateConfig,
		WDF_NO_OBJECT_ATTRIBUTES,
		&Context->UsbDevice
		);

	if(!NT_SUCCESS(status))
	{
		return status;
	}

	WDFUSBINTERFACE UsbInterface = WdfUsbTargetDeviceGetInterface(Context->UsbDevice, 0);
	BYTE NumEndpoints = WdfUsbInterfaceGetNumEndpoints(UsbInterface, 0);

	Log("Number of endpoints on interface index 0: ", FALSE);
	LogValue(NumEndpoints, TRUE);

	WDF_USB_DEVICE_SELECT_CONFIG_PARAMS DeviceSelectParams;
	WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_SINGLE_INTERFACE(&DeviceSelectParams);
	WdfUsbTargetDeviceSelectConfig(Context->UsbDevice, WDF_NO_OBJECT_ATTRIBUTES, &DeviceSelectParams);

	BYTE NumPipes = WdfUsbInterfaceGetNumConfiguredPipes(UsbInterface);

	Log("Number of pipes: ", FALSE);
	LogValue(NumPipes, TRUE);

	WDF_USB_PIPE_INFORMATION PipeInformation;
	WDF_USB_PIPE_INFORMATION_INIT(&PipeInformation);
	DataPipe = WdfUsbInterfaceGetConfiguredPipe(
		UsbInterface,
		1,
		&PipeInformation
	);
	
	Log("PipeType: ", FALSE);
	LogValue(PipeInformation.PipeType, TRUE);

	CHAR buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);

	/*buffer[0] = 'y';
	buffer[1] = 'o';
	DrawPixels(&DataPipe, buffer);*/

	ReadTxt(buffer);
	DrawPixels(&DataPipe, buffer);

	return status;
}