/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that app can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_ScrollingUSB,
    0x778bff5b,0x8a67,0x4aab,0xb5,0x3f,0x85,0x81,0x5e,0xc7,0xa1,0x1a);
// {778bff5b-8a67-4aab-b53f-85815ec7a11a}
