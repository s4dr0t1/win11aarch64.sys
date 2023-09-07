#include <ntddk.h>


void SampleUnload(
	_In_ PDRIVER_OBJECT DriverObject
);

extern "C" NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
) {

	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);



	DriverObject->DriverUnload = SampleUnload;

	KdPrint(("My name is Rohitr"));


	return STATUS_SUCCESS;

}


void SampleUnload(
	_In_ PDRIVER_OBJECT DriverObject
) {
	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("Driver unloaded"));
}
