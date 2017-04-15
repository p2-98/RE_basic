### Tổng kết về OllyDBG

> Tài liệu tham khảo: [Reverse](http://ctf.ist-vnisa.org.vn/category/reverse); [OllyDBG](https://kienmanowar.wordpress.com/2008/09/03/ollydbg_tut1/)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 15/04/2017

----

### Mục lục:

- [1. Tổng kết sơ lược về Resever Engineering](#1)

	- [1.1 Dịch ngược là gì và mục đích](#1.1)
	- [1.2 Công cụ](#1.2)

- [2. OllyDBG](#2)

	- [2.1 Khái quát sơ lược](#2.1)
	- [2.2 Tổng kết về OllyDBG](#2.2)

		- [2.2.1 Chức năng](#2.2.1)
		- [2.2.2 Các lệnh, hàm và cấu trúc thường dùng](#2.2.2)
		- [2.2.3 Các trick và AntiDebugger](#2.2.3)

----

<a name="1"> </a>

### 1. Tổng kết sơ lược về Reverse Engineering:

<a name="1.1"> </a>

#### 1.1 Dịch ngược là gì và mục đích:

- **Dịch ngược là gì?**
- Dịch ngược là quá trình cố gắng tìm hiểu cách thức chương trình làm việc dựa vào file đã biên dịch. Ban đầu lập trình viên viết code bằng ngôn ngữ lập trình bậc cao như  C, C++, Visual Basic … Sau đó chúng được dịch ra mã máy để giúp máy tính có thể hiểu được. Nhưng đối với con người thì mã máy thật sự khó hiểu, vì thế dịch ngược giúp ta hiểu được chương trình cần làm gì mà không có file code ban đầu.

- **Mục đích**
- Dịch ngược được sử dụng ở rất nhiều mảng trong khoa học máy tính nhưng sau đây là những mảng chính:

	- Có được trong tay ý tưởng code của tác giả
	- Phá vỡ cơ chế bảo vệ phần mềm
	- Học tập nghiên cứu virus hay mã độc
	- Kiểm tra chất lượng phần mềm
	- Bổ sung thêm tính năng vào chương trình

<a name="1.2"> </a>

#### 1.2 Các công cụ cần thiết:

- 1. Disassemblers
- 2. Debugger
- 3. Hex editors
- 4. PE and Resource viewers/editors
- 5. System Monitoring tools
- 6. Miscellaneous tools and information

<a name="2"> </a>

### 2. OllyBBG:

<a name="2.1"> </a>

#### 2.1 Khái quát sơ lược:

-  OllyDBG hay còn gọi tắt là Olly là công cụ debug rất phổ biến. Nhờ giao diện trực quan và dễ sử dụng nên Olly phù hợp với người dùng ở mọi trình độ khác nhau.

<a name="2.2"> </a>

#### 2.2 Tổng kết:

<a name="2.2.1"> </a>

#### 2.2.1 Các công cụ:

- Để mở 1 file .exe ta vào File -> Open hoặc ấn phím F3. Sau đó chọn đúng file .exe cần dùng.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=964&stc=1">

- Ta có các thông tin OllyDBG hiển thị ra như sau:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=965&stc=1">

- Cửa sổ OllyDBG được chia ra làm 5 cửa sổ con :

	- **1: Disassembler window:** Các đoạn mã của chương trình dưới dạng code assembly và các comment tại các dòng code đó.
	- **2: Register window:** Các thanh ghi và giá trị của chúng.
	- **3: Tip window:** Các thông tin bổ sung cho 1 dòng code. Các thông tin này khá hữu ích trong quá trình debug.
	- **4: Dump window:** Cho phép người sử dụng xem và chỉnh sửa các giá trị trong bộ nhớ của chương trình đang được debug.
	- **5: Stack window:** Thông tin về stack của chương trình.

- Ngoài 5 cửa sổ trên thì Olly còn có một số cửa sổ khác. Để ý trên thanh menu có các chức năng:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=966&stc=1">

– Click vào nút L ta thấy cửa số Log data của Olly. Chứa các thông tin về các module, các import library và các plugins được load cùng chương trình tại thời điểm chương trình được load vào Olly.
– Click vào nút E ta thấy cửa sổ Executable modules, danh sách các file thực thi được chương trình sử dụng.
– Click vào nút M ta thấy cửa sổ Memory Map, chứa thông tin về bộ nhớ được chương trình của ta sử dụng.
– Click vào nút T là cửa sổ Threads, liệt kê các thread của chương trình.
– Click vào nút W là Windows
– Nút H là cửa sổ Handles.
– Nút / là Patches, cửa sổ chứa các thông tin về những câu lệnh ta đã sửa ở trong chương trình.
– Nút K là cửa sổ Call Stack.
– Nút B là cửa sổ Breakpoints, hiển thị các breakpoint ta đặt trong chương trình.
– Nút R – References chứa thông tin về kết quả cho chức năng tìm kiếm trong Olly.

- *Những chức năng không thể thiếu đó là các chức năng phục vụ cho công việc debug:*

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=967&stc=1">

– Đặt Breakpoint: `F2`
– Run: `F9`
– Step into: `F7`
– Step over: `F8`
– Restart: `Ctrl + F2`

<a name="2.2.2"> </a>

#### 2.2.2 Các lệnh, hàm và cấu trúc thường dùng:

- **Các câu lệnh ASM thường dùng:**

	- NOP
	- Push
	- POP
	- PUSHAD
	- POPAD
	- MOV, MOVSX và MOVZX
	- LEA
	- XCHG
	- INC và DEC
	- ADD vaf ADC
	- SUB và SBB
	- MUL và IMUL
	- XADD
	- NEG
	- Tập lệnh Logic: AND, OR, XOR, NOT

- **Các lệnh so sánh và nhảy:**

	- Nhảy có điều kiện CMP
	- Nhảy không điều kiện JMP
	- TEST
	- JE/ JZ
	- JNE/ JNZ
	- JS
	- JP/ JPE và JNP/ JNPE
	- JO/ JNO
	- JB
	- JBE
	- JL

- **Hàm và cấu trúc:**

	- CALL và RET

- **Các lệnh liên quan đến chuỗi, vòng lặp và các chế độ địa chỉ:**

	- Vòng lặp và lệnh LOOP
	- MOVS
	- REP
	- LODS
	- STOS
	- CPMS
	- Chế độ địa chỉ: DIRECT (Trực tiếp) và INDIRECT(Gián tiếp)

- **Thuật ngữ cơ bản, làm việc với API**

	- EP (Entry Point) và OEP (Original Entry Point)

<a name="2.2.3"> </a>

#### 2.2.3 Các trick và Anti Debugger:

- **IsDebuggerPresent:** Có lẽ phương pháp đơn giản nhất là gọi hàm IsDebuggerPresent. Chức năng này phát hiện nếu quá trình gọi đang được debugger bởi một người gỡ lỗi chế độ người dùng. Đoạn mã dưới đây đại diện cho một ví dụ bảo vệ cơ bản
- **NtGlobalFlag:** 

	- Trong Windows NT, có một bộ cờ, được lưu trữ trong biến toàn cục NtGlobalFlag, phổ biến cho toàn bộ hệ thống. Khi bắt đầu hệ thống, biến hệ thống toàn cục NtGlobalFlag được khởi tạo với giá trị từ khoá hệ thống
	- Gía trị biến được sử dụng để dò tìm hệ thống, gỡ lỗi và điều khiển. Các cờ biến không được cung cấp tài liệu, nhưng SDK bao gồm tiện ích gflags, cho phép chỉnh sửa giá trị cờ toàn cục. Cấu trúc PEB cũng bao gồm trường NtGlobalFlag, và cấu trúc bit của nó không tương ứng với biến hệ thống toàn cầu NtGlobalFlag. Trong quá trình gỡ lỗi, các cờ như vậy được đặt trong trường NtGlobalFlag
	- Để kiểm tra nếu một quá trình được khởi động với trình gỡ lỗi, bạn nên kiểm tra giá trị của trường NtGlobalFlag của cấu trúc PEB. Trường này được định vị bằng 0x068 và 0x0bc bù đắp cho các hệ thống x32 và x64 tương ứng liên quan đến sự khởi đầu của cấu trúc PEB.

- **NtGlobalFlag and IMAGE_LOAD_CONFIG_DIRECTORY**

- Tập tin thực thi có thể bao gồm cấu trúc IMAGE_LOAD_CONFIG_DIRECTORY, chứa các thông số cấu hình bổ sung cho trình nạp hệ thống. Cấu trúc này không được tích hợp vào một tệp thực thi theo mặc định, nhưng nó có thể được thêm vào sử dụng một miếng vá. Cấu trúc này có trường GlobalFlagsClear chỉ ra cờ nào của trường NtGlobalFlag của cấu trúc PEB nên được đặt lại. Nếu một thực thi ban đầu được tạo ra mà không có cấu trúc đã đề cập hoặc với GlobalFlagsClear = 0, trong khi trên đĩa hoặc trong bộ nhớ, lĩnh vực này có giá trị khác không, sau đó có ẩn trình gỡ lỗi làm việc. Ví dụ mã dưới đây kiểm tra trường GlobalFlagsClear trong bộ nhớ của quá trình chạy và trên đĩa do đó minh hoạ một trong những kỹ thuật gỡ lỗi phổ biến:

```C
PIMAGE_NT_HEADERS GetImageNtHeaders(PBYTE pImageBase)
{
    PIMAGE_DOS_HEADER pImageDosHeader = (PIMAGE_DOS_HEADER)pImageBase;
    return (PIMAGE_NT_HEADERS)(pImageBase + pImageDosHeader->e_lfanew);
}
PIMAGE_SECTION_HEADER FindRDataSection(PBYTE pImageBase)
{
    static const std::string rdata = ".rdata";
    PIMAGE_NT_HEADERS pImageNtHeaders = GetImageNtHeaders(pImageBase);
    PIMAGE_SECTION_HEADER pImageSectionHeader = IMAGE_FIRST_SECTION(pImageNtHeaders);
    int n = 0;
    for (; n < pImageNtHeaders->FileHeader.NumberOfSections; ++n)
    {
        if (rdata == (char*)pImageSectionHeader[n].Name)
        {
            break;
        }
    }
    return &pImageSectionHeader[n];
}
void CheckGlobalFlagsClearInProcess()
{
    PBYTE pImageBase = (PBYTE)GetModuleHandle(NULL);
    PIMAGE_NT_HEADERS pImageNtHeaders = GetImageNtHeaders(pImageBase);
    PIMAGE_LOAD_CONFIG_DIRECTORY pImageLoadConfigDirectory = (PIMAGE_LOAD_CONFIG_DIRECTORY)(pImageBase
        + pImageNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].VirtualAddress);
    if (pImageLoadConfigDirectory->GlobalFlagsClear != 0)
    {
        std::cout << "Stop debugging program!" << std::endl;
        exit(-1);
    }
}
void CheckGlobalFlagsClearInFile()
{
    HANDLE hExecutable = INVALID_HANDLE_VALUE;
    HANDLE hExecutableMapping = NULL;
    PBYTE pMappedImageBase = NULL;
    __try
    {
        PBYTE pImageBase = (PBYTE)GetModuleHandle(NULL);
        PIMAGE_SECTION_HEADER pImageSectionHeader = FindRDataSection(pImageBase);
        TCHAR pszExecutablePath[MAX_PATH];
        DWORD dwPathLength = GetModuleFileName(NULL, pszExecutablePath, MAX_PATH);
        if (0 == dwPathLength) __leave;
        hExecutable = CreateFile(pszExecutablePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
        if (INVALID_HANDLE_VALUE == hExecutable) __leave;
        hExecutableMapping = CreateFileMapping(hExecutable, NULL, PAGE_READONLY, 0, 0, NULL);
        if (NULL == hExecutableMapping) __leave;
        pMappedImageBase = (PBYTE)MapViewOfFile(hExecutableMapping, FILE_MAP_READ, 0, 0,
            pImageSectionHeader->PointerToRawData + pImageSectionHeader->SizeOfRawData);
        if (NULL == pMappedImageBase) __leave;
        PIMAGE_NT_HEADERS pImageNtHeaders = GetImageNtHeaders(pMappedImageBase);
        PIMAGE_LOAD_CONFIG_DIRECTORY pImageLoadConfigDirectory = (PIMAGE_LOAD_CONFIG_DIRECTORY)(pMappedImageBase 
            + (pImageSectionHeader->PointerToRawData
                + (pImageNtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].VirtualAddress - pImageSectionHeader->VirtualAddress)));
        if (pImageLoadConfigDirectory->GlobalFlagsClear != 0)
        {
            std::cout << "Stop debugging program!" << std::endl;
            exit(-1);
        }
    }
    __finally
    {
        if (NULL != pMappedImageBase)
            UnmapViewOfFile(pMappedImageBase);
        if (NULL != hExecutableMapping)
            CloseHandle(hExecutableMapping);
        if (INVALID_HANDLE_VALUE != hExecutable)
            CloseHandle(hExecutable);
    } 
}    
```

- Trong mẫu mã này, chức năng CheckGlobalFlagsClearInProcess tìm cấu trúc PIMAGE_LOAD_CONFIG_DIRECTORY theo địa chỉ của quá trình tải đang chạy và kiểm tra giá trị trường GlobalFlagsClear. Nếu nó không phải là 0, thì quá trình này có thể bị gỡ lỗi. CheckGlobalFlagsClearInFile chức năng thực hiện kiểm tra tương tự nhưng đối với các thực thi trên đĩa.

- **Heap Flags and Force Flags**

	- Cấu trúc PEB chứa con trỏ tới quá trình heap - cấu trúc _HEAP
	- Nếu quá trình đang được gỡ lỗi, cả hai trường Flags và ForceFlags đều có các giá trị gỡ lỗi cụ thể:

		- 1. Nếu trường Flags không có cờ HEAP_GROWABLE (0x00000002), thì quá trình này đang được gỡ lỗi.
		- 2. Nếu giá trị của ForceFlags = 0, thì quá trình đang được gỡ lỗi.
	
	- Cần lưu ý rằng cấu trúc _HEAP không được cung cấp tài liệu và các giá trị của các hiệu số của trường Flags và ForceFlags có thể khác nhau tùy thuộc vào phiên bản hệ điều hành

- **Trap Flag Check:**

- TF (Trap Flag) nằm trong đăng ký EFLAGS. Nếu TF được đặt thành 1, CPU sẽ tạo INT 01h hoặc ngoại lệ «Single Step» sau mỗi lần thực hiện lệnh. Ví dụ gỡ lỗi sau đây dựa trên thiết lập TF và gọi kiểm tra: 

```C
BOOL isDebugged = TRUE;
__try
{
    __asm
    {
        pushfd
        or dword ptr[esp], 0x100 // set the Trap Flag 
        popfd                    // Load the value into EFLAGS register
        nop
    }
}
__except (EXCEPTION_EXECUTE_HANDLER)
{
    // If an exception has been raised – debugger is not present
    isDebugged = FALSE;
}
if (isDebugged)
{
    std::cout << "Stop debugging program!" << std::endl;
    exit(-1);
}
```
      
- Ở đây TF được cố tình thiết lập để tạo ra một ngoại lệ. Nếu quá trình đang được gỡ lỗi, ngoại lệ sẽ bị gỡ lỗi bởi trình gỡ rối.

- **CheckRemoteDebuggerPresent and NtQueryInformationProcess**

- Không giống như chức năng IsDebuggerPresent, CheckRemoteDebuggerPresent kiểm tra nếu một quá trình đang được debugged bởi một quá trình song song khác. Ở đây bạn có một ví dụ về kỹ thuật gỡ lỗi gỡ lỗi dựa trên CheckRemoteDebuggerPresent

```C
int main(int argc, char *argv[])
{
    BOOL isDebuggerPresent = FALSE;
    if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebuggerPresent ))
    {
        if (isDebuggerPresent )
        {
            std::cout << "Stop debugging program!" << std::endl;
            exit(-1);
        }
    }
    return 0;
}
```

- Bên trong CheckRemoteDebuggerPresent, hàm NtQueryInformationProcess được gọi:

```C
0:000> uf kernelbase!CheckRemotedebuggerPresent
KERNELBASE!CheckRemoteDebuggerPresent:
...
75207a24 6a00            push    0
75207a26 6a04            push    4
75207a28 8d45fc          lea     eax,[ebp-4]
75207a2b 50              push    eax
75207a2c 6a07            push    7
75207a2e ff7508          push    dword ptr [ebp+8]
75207a31 ff151c602775    call    dword ptr [KERNELBASE!_imp__NtQueryInformationProcess (7527601c)]
75207a37 85c0            test    eax,eax
75207a39 0f88607e0100    js      KERNELBASE!CheckRemoteDebuggerPresent+0x2b (7521f89f)
...	
```

- Nếu chúng ta xem xét tài liệu NtQueryInformationProcess, danh sách Assembler này sẽ cho chúng ta thấy rằng hàm CheckRemoteDebuggerPresent nhận giá trị DebugPort, vì giá trị tham số ProcessInformationClass (thứ hai) là 7. Mẫu mã gỡ lỗi gỡ lỗi sau đây dựa trên gọi NtQueryInformationProcess:

```C
typedef NTSTATUS(NTAPI *pfnNtQueryInformationProcess)(
    _In_      HANDLE           ProcessHandle,
    _In_      UINT             ProcessInformationClass,
    _Out_     PVOID            ProcessInformation,
    _In_      ULONG            ProcessInformationLength,
    _Out_opt_ PULONG           ReturnLength
    );
const UINT ProcessDebugPort = 7;
int main(int argc, char *argv[])
{
    pfnNtQueryInformationProcess NtQueryInformationProcess = NULL;
    NTSTATUS status;
    DWORD isDebuggerPresent = 0;
    HMODULE hNtDll = LoadLibrary(TEXT("ntdll.dll"));
     
    if (NULL != hNtDll)
    {
        NtQueryInformationProcess = (pfnNtQueryInformationProcess)GetProcAddress(hNtDll, "NtQueryInformationProcess");
        if (NULL != NtQueryInformationProcess)
        {
            status = NtQueryInformationProcess(
                GetCurrentProcess(),
                ProcessDebugPort,
                &isDebuggerPresent,
                sizeof(DWORD),
                NULL);
            if (status == 0x00000000 && isDebuggerPresent != 0)
            {
                std::cout << "Stop debugging program!" << std::endl;
                exit(-1);
            }
        }
    }
    return 0;
}
```

- **Các kỹ thuật khác AntiDebugger dựa trên NtQueryInformationProcess**

	- 1. ProcessDebugPort 0x07 – was discussed above.
	- 2. ProcessDebugObjectHandle 0x1E
	- 3. ProcessDebugFlags 0x1F
	- 4. ProcessBasicInformation 0x00

- **Breakpoint: Hardware và Software**

- **SEH (Structured Exception Handling)**

- Xử lý ngoại lệ có cấu trúc là một cơ chế được cung cấp bởi hệ điều hành cho một ứng dụng cho phép nó nhận các thông báo về các tình huống đặc biệt như phân chia bởi số không, tham chiếu đến con trỏ không tồn tại hoặc thực hiện chỉ dẫn bị giới hạn. Cơ chế này cho phép xử lý ngoại lệ bên trong ứng dụng, mà không cần sự tham gia của hệ điều hành. Nếu ngoại lệ không được xử lý, nó sẽ dẫn đến kết thúc chương trình bất thường. Các nhà phát triển thường định vị các con trỏ tới SEH trong ngăn xếp, chúng được gọi là khung SEH. Địa chỉ khung SEH hiện tại được định vị bởi số 0 tương ứng với bộ chọn FS hoặc bộ chọn GS cho các hệ thống x64. Địa chỉ này chỉ tới cấu trúc ntdll! _EXCEPTION_REGISTRATION_RECORD

- **VEH (Vectored Exception Handler)**

- VEH đã được giới thiệu bắt đầu từ Windows XP và là một biến thể của SEH. VEH và SEH không phụ thuộc lẫn nhau và làm việc đồng thời. Khi một trình xử lý VEH mới được thêm vào, chuỗi SEH không bị ảnh hưởng bởi danh sách các trình xử lý VEH được lưu trữ trong biến ntdll! LdrpVectorHandlerList non-export. VEH và SEH cơ chế khá giống nhau, sự khác biệt duy nhất là các chức năng được ghi lại được sử dụng để thiết lập và gỡ bỏ trình xử lý VEN. Các thanh ghi của các chức năng thêm và gỡ bỏ VEH handler cũng như chức năng xử lý VEH chính nó như sau:

```C
PVOID WINAPI AddVectoredExceptionHandler(
    ULONG                       FirstHandler,
    PVECTORED_EXCEPTION_HANDLER VectoredHandler
);
ULONG WINAPI RemoveVectoredExceptionHandler(
    PVOID Handler
);
LONG CALLBACK VectoredHandler(
    PEXCEPTION_POINTERS ExceptionInfo
);
The _EXCEPTION_POINTERS structure looks like this:  
typedef struct _EXCEPTION_POINTERS {
  PEXCEPTION_RECORD ExceptionRecord;
  PCONTEXT          ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
```

- **NtSetInformationThread – hiding thread from debugger:**

- Trong Windows 2000, một lớp thông tin mới được chuyển đến NtSetInformationThread xuất hiện - ThreadHideFromDebugger. Đây là một trong những kỹ thuật gỡ lỗi đầu tiên do Windows cung cấp, và nó rất mạnh mẽ. Nếu cờ này được đặt cho một chủ đề, nó sẽ ngừng gửi thông báo về các sự kiện gỡ rối. Các sự kiện này bao gồm các điểm ngắt và thông báo về kết thúc chương trình, nếu ThreadHideFromDebugger được thiết lập cho chủ đề chính. Giá trị của cờ này được lưu trữ trong trường HideFromDebugger của cấu trúc _ETHREAD

- Windows Vista giới thiệu chức năng NtCreateThreadEx, có cấu trúc như sau:

```C
NTSTATUS NTAPI NtCreateThreadEx (
    _Out_    PHANDLE              ThreadHandle,
    _In_     ACCESS_MASK          DesiredAccess,
    _In_opt_ POBJECT_ATTRIBUTES   ObjectAttributes,
    _In_     HANDLE               ProcessHandle,
    _In_     PVOID                StartRoutine,
    _In_opt_ PVOID                Argument,
    _In_     ULONG                CreateFlags,
    _In_opt_ ULONG_PTR            ZeroBits,
    _In_opt_ SIZE_T               StackSize,
    _In_opt_ SIZE_T               MaximumStackSize,
    _In_opt_ PVOID                AttributeList
);
```

- Tham số thú vị nhất là CreateFlags. Tham số này được các cờ như sau:

```C
#define THREAD_CREATE_FLAGS_CREATE_SUSPENDED 0x00000001
#define THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH 0x00000002
#define THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER 0x00000004
#define THREAD_CREATE_FLAGS_HAS_SECURITY_DESCRIPTOR 0x00000010
#define THREAD_CREATE_FLAGS_ACCESS_CHECK_IN_TARGET 0x00000020
#define THREAD_CREATE_FLAGS_INITIAL_THREAD 0x00000080	
```

- Nếu một chủ đề mới được cờ THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER, nó sẽ bị ẩn khỏi trình gỡ lỗi khi nó được tạo. Đó là ThreadHideFromDebugger giống nhau, được thiết lập bởi hàm NtSetInformationThread. Mã, chịu trách nhiệm về các tác vụ bảo mật, có thể được thực hiện trong luồng với cờ THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER.
