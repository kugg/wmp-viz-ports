# Windows API Function Reference for Trilogy DLL Decompilation

This document provides a quick reference for the Windows API functions commonly found in the Trilogy decompiled code, with their signatures and typical usage patterns.

## Memory Management

### HeapAlloc
```c
LPVOID HeapAlloc(
    HANDLE hHeap,    // Heap handle (usually from GetProcessHeap())
    DWORD dwFlags,   // Heap allocation flags (0 or HEAP_ZERO_MEMORY)
    SIZE_T dwBytes   // Number of bytes to allocate
);
// Returns: Pointer to allocated memory, or NULL on failure
```

### HeapFree
```c
BOOL HeapFree(
    HANDLE hHeap,    // Heap handle
    DWORD dwFlags,   // Heap free flags (0)
    LPVOID lpMem     // Pointer to memory to free
);
// Returns: TRUE on success, FALSE on failure
```

### HeapCreate
```c
HANDLE HeapCreate(
    DWORD flOptions,      // Heap creation flags
    SIZE_T dwInitialSize, // Initial heap size
    SIZE_T dwMaximumSize  // Maximum heap size (0 = dynamic)
);
// Returns: Handle to new heap, or NULL on failure
```

### HeapDestroy
```c
BOOL HeapDestroy(
    HANDLE hHeap  // Heap handle to destroy
);
// Returns: TRUE on success, FALSE on failure
```

### VirtualAlloc
```c
LPVOID VirtualAlloc(
    LPVOID lpAddress,        // Address (NULL = auto)
    SIZE_T dwSize,           // Size in bytes
    DWORD flAllocationType,  // MEM_COMMIT | MEM_RESERVE
    DWORD flProtect          // PAGE_READWRITE, etc.
);
// Returns: Pointer to allocated memory, or NULL on failure
```

### VirtualFree
```c
BOOL VirtualFree(
    LPVOID lpAddress,  // Pointer to memory to free
    SIZE_T dwSize,     // Size (0 for entire region)
    DWORD dwFreeType   // MEM_RELEASE
);
// Returns: TRUE on success, FALSE on failure
```

## COM Memory Management

### CoTaskMemAlloc
```c
LPVOID CoTaskMemAlloc(
    SIZE_T cb  // Number of bytes to allocate
);
// Returns: Pointer to allocated memory, or NULL on failure
// Memory must be freed with CoTaskMemFree()
```

### CoTaskMemRealloc
```c
LPVOID CoTaskMemRealloc(
    LPVOID pv,    // Pointer to memory to reallocate
    SIZE_T cb    // New size in bytes
);
// Returns: Pointer to reallocated memory, or NULL on failure
```

### CoTaskMemFree
```c
void CoTaskMemFree(
  LPVOID pv  // Pointer to memory to free
);
```

## String Conversion

### MultiByteToWideChar
```c
int MultiByteToWideChar(
    UINT CodePage,          // CP_ACP for ANSI, CP_UTF8 for UTF-8
    DWORD dwFlags,          // 0
    LPCSTR lpMultiByteStr,  // Input string
    int cbMultiByte,        // Input length (-1 = null-terminated)
    LPWSTR lpWideCharStr,   // Output buffer
    int cchWideChar         // Output buffer size (0 = required size)
);
// Returns: Number of characters written, or 0 on failure
```

### WideCharToMultiByte
```c
int WideCharToMultiByte(
    UINT CodePage,           // CP_ACP for ANSI
    DWORD dwFlags,           // 0
    LPCWSTR lpWideCharStr,   // Input string
    int cchWideChar,         // Input length (-1 = null-terminated)
    LPSTR lpMultiByteStr,    // Output buffer
    int cbMultiByte,         // Output buffer size (0 = required size)
    LPCSTR lpDefaultChar,    // Default char for unmappable chars
    LPBOOL lpUsedDefaultChar // Flag for default char used
);
// Returns: Number of bytes written, or 0 on failure
```

### LCMapString
```c
int LCMapStringA(
    LCID Locale,           // Locale identifier
    DWORD dwMapFlags,      // Mapping flags (NORM_IGNORECASE, etc.)
    LPCSTR lpSrcStr,       // Source string
    int cchSrc,            // Source length (-1 = null-terminated)
    LPSTR lpDestStr,       // Destination buffer
    int cchDest            // Destination buffer size (0 = required size)
);
// Returns: Number of characters written, or 0 on failure
```

## Thread Synchronization

### InitializeCriticalSection
```c
void InitializeCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection  // Critical section object
);
```

### DeleteCriticalSection
```c
void DeleteCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection  // Critical section object
);
```

### EnterCriticalSection
```c
void EnterCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection  // Critical section object
);
```

### LeaveCriticalSection
```c
void LeaveCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection  // Critical section object
);
```

## Thread Management

### CreateThread
```c
HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,  // Security attrs (NULL)
    DWORD dwStackSize,                         // Stack size (0 = default)
    LPTHREAD_START_ROUTINE lpStartAddress,     // Thread function
    LPVOID lpParameter,                        // Parameter to thread func
    DWORD dwCreationFlags,                     // 0 = run immediately
    LPDWORD lpThreadId                         // Thread ID output
);
// Returns: Thread handle, or NULL on failure
```

### WaitForSingleObject
```c
DWORD WaitForSingleObject(
    HANDLE hHandle,        // Object handle
    DWORD dwMilliseconds   // Timeout (INFINITE = wait forever)
);
// Returns: WAIT_OBJECT_0, WAIT_TIMEOUT, or WAIT_FAILED
```

### InterlockedIncrement / InterlockedDecrement
```c
LONG InterlockedIncrement(
    LPLONG lpAddend  // Pointer to variable to increment
);
// Returns: New value

LONG InterlockedDecrement(
    LPLONG lpAddend  // Pointer to variable to decrement
);
// Returns: New value
```

## Thread-Local Storage (TLS)

### TlsAlloc
```c
DWORD TlsAlloc(VOID);
// Returns: TLS index, or TLS_OUT_OF_INDEXES on failure
```

### TlsFree
```c
BOOL TlsFree(
    DWORD dwTlsIndex  // TLS index to free
);
// Returns: TRUE on success, FALSE on failure
```

### TlsSetValue
```c
BOOL TlsSetValue(
    DWORD dwTlsIndex,  // TLS index
    LPVOID lpTlsValue  // Value to store
);
// Returns: TRUE on success, FALSE on failure
```

### TlsGetValue
```c
LPVOID TlsGetValue(
    DWORD dwTlsIndex  // TLS index
);
// Returns: Value stored at index, or NULL on failure
```

## Module Management

### LoadLibraryA
```c
HMODULE LoadLibraryA(
    LPCSTR lpLibFileName  // DLL filename
);
// Returns: Module handle, or NULL on failure
```

### FreeLibrary
```c
BOOL FreeLibrary(
    HMODULE hLibModule  // Module handle
);
// Returns: TRUE on success, FALSE on failure
```

### GetProcAddress
```c
FARPROC GetProcAddress(
    HMODULE hModule,    // Module handle
    LPCSTR lpProcName  // Function name or ordinal
);
// Returns: Function pointer, or NULL on failure
```

### GetModuleHandleA
```c
HMODULE GetModuleHandleA(
    LPCSTR lpModuleName  // Module name (NULL = current process)
);
// Returns: Module handle, or NULL on failure
```

### GetModuleFileNameA
```c
DWORD GetModuleFileNameA(
    HMODULE hModule,   // Module handle (NULL = current process)
    LPSTR lpFilename,  // Filename buffer
    DWORD nSize        // Buffer size
);
// Returns: Length of filename, or 0 on failure
```

## Error Handling

### GetLastError
```c
DWORD GetLastError(VOID);
// Returns: Last error code
```

### SetLastError
```c
void SetLastError(
    DWORD dwErrCode  // Error code to set
);
```

## Timing

### GetTickCount
```c
DWORD GetTickCount(VOID);
// Returns: Milliseconds since system start
```

### QueryPerformanceCounter
```c
BOOL QueryPerformanceCounter(
    LARGE_INTEGER *lpPerformanceCount  // Counter value output
);
// Returns: TRUE on success, FALSE on failure
```

### QueryPerformanceFrequency
```c
BOOL QueryPerformanceFrequency(
    LARGE_INTEGER *lpFrequency  // Frequency output
);
// Returns: TRUE on success, FALSE on failure
```

## Resource Management

### FindResourceA
```c
HRSRC FindResourceA(
    HMODULE hModule,   // Module handle (NULL = current process)
    LPCSTR lpName,     // Resource name
    LPCSTR lpType      // Resource type
);
// Returns: Resource info handle, or NULL on failure
```

### LoadResource
```c
HGLOBAL LoadResource(
    HMODULE hModule,  // Module handle
    HRSRC hResInfo    // Resource info handle from FindResource
);
// Returns: Memory handle, or NULL on failure
```

### LockResource
```c
LPVOID LockResource(
    HGLOBAL hResData  // Memory handle from LoadResource
);
// Returns: Pointer to resource data, or NULL on failure
```

### SizeofResource
```c
DWORD SizeofResource(
    HMODULE hModule,  // Module handle
    HRSRC hResInfo    // Resource info handle
);
// Returns: Size of resource in bytes, or 0 on failure
```

## GDI Graphics

### CreateDIBitmap
```c
HBITMAP CreateDIBitmap(
    HDC hdc,                            // Device context
    CONST BITMAPINFOHEADER *pbmih,      // Bitmap info header
    DWORD flInit,                       // CBM_INIT to initialize
    CONST VOID *pjBits,                 // Bitmap bits
    CONST BITMAPINFO *pbmi,             // Bitmap info
    UINT usage                          // DIB_RGB_COLORS or DIB_PAL_COLORS
);
// Returns: Bitmap handle, or NULL on failure
```

### BitBlt
```c
BOOL BitBlt(
    HDC hdcDest,    // Destination DC
    int nXDest,     // Destination X
    int nYDest,     // Destination Y
    int nWidth,     // Width
    int nHeight,    // Height
    HDC hdcSrc,     // Source DC
    int nXSrc,      // Source X
    int nYSrc,      // Source Y
    DWORD dwRop     // Raster operation (SRCCOPY)
);
// Returns: TRUE on success, FALSE on failure
```

### StretchDIBits
```c
int StretchDIBits(
    HDC hdc,                    // Device context
    int XDest,                  // Destination X
    int YDest,                  // Destination Y
    int nDestWidth,             // Destination width
    int nDestHeight,            // Destination height
    int XSrc,                   // Source X
    int YSrc,                   // Source Y
    int nSrcWidth,              // Source width
    int nSrcHeight,             // Source height
    CONST VOID *lpBits,         // Bitmap bits
    CONST BITMAPINFO *lpBitsInfo, // Bitmap info
    UINT iUsage,                // DIB_RGB_COLORS
    DWORD dwRop                 // Raster operation (SRCCOPY)
);
// Returns: Number of scan lines copied, or 0 on failure
```

### CreateCompatibleDC
```c
HDC CreateCompatibleDC(
    HDC hdc  // Device context (NULL for screen)
);
// Returns: Memory DC handle, or NULL on failure
```

### DeleteDC
```c
BOOL DeleteDC(
    HDC hdc  // Device context to delete
);
// Returns: TRUE on success, FALSE on failure
```

### SelectObject
```c
HGDIOBJ SelectObject(
    HDC hdc,          // Device context
    HGDIOBJ hgdiobj   // GDI object (bitmap, pen, brush, etc.)
);
// Returns: Previous GDI object, or NULL on failure
```

## Registry

### RegOpenKeyExA
```c
LSTATUS RegOpenKeyExA(
    HKEY hKey,                // Parent key handle
    LPCSTR lpSubKey,          // Subkey name
    DWORD ulOptions,          // 0
    DWORD samDesired,         // KEY_READ, KEY_WRITE, KEY_ALL_ACCESS
    PHKEY phkResult           // Output key handle
);
// Returns: ERROR_SUCCESS on success
```

### RegCloseKey
```c
LSTATUS RegCloseKey(
    HKEY hKey  // Key handle to close
);
// Returns: ERROR_SUCCESS on success
```

### RegQueryValueExA
```c
LSTATUS RegQueryValueExA(
    HKEY hKey,            // Key handle
    LPCSTR lpValueName,   // Value name
    LPDWORD lpReserved,   // Reserved (NULL)
    LPDWORD lpType,       // Value type output
    LPBYTE lpData,        // Data buffer
    LPDWORD lpcbData      // Data buffer size
);
// Returns: ERROR_SUCCESS on success
```

### RegSetValueExA
```c
LSTATUS RegSetValueExA(
    HKEY hKey,            // Key handle
    LPCSTR lpValueName,   // Value name
    DWORD Reserved,       // Reserved (0)
    DWORD dwType,         // Value type (REG_SZ, REG_DWORD, etc.)
    CONST BYTE *lpData,   // Data to set
    DWORD cbData          // Data size
);
// Returns: ERROR_SUCCESS on success
```

### RegEnumKeyExA
```c
LSTATUS RegEnumKeyExA(
    HKEY hKey,            // Key handle
    DWORD dwIndex,        // Subkey index
    LPSTR lpName,         // Subkey name buffer
    LPDWORD lpcchName,    // Name buffer size
    LPDWORD lpReserved,   // Reserved (NULL)
    LPSTR lpClass,        // Class name buffer
    LPDWORD lpcchClass,   // Class buffer size
    PFILETIME lpftLastWriteTime // Last write time
);
// Returns: ERROR_SUCCESS on success, ERROR_NO_MORE_ITEMS when done
```

## Process Information

### GetCurrentProcessId
```c
DWORD GetCurrentProcessId(VOID);
// Returns: Current process ID
```

### GetCurrentThreadId
```c
DWORD GetCurrentThreadId(VOID);
// Returns: Current thread ID
```

## String Functions (CRT)

### lstrlenA / lstrlenW
```c
int lstrlenA(
    LPCSTR lpString  // String to measure
);
// Returns: String length in characters

int lstrlenW(
    LPCWSTR lpString  // Wide string to measure
);
// Returns: String length in characters
```

### lstrcpyA / lstrcpyW
```c
LPSTR lstrcpyA(
    LPSTR lpDest,     // Destination buffer
    LPCSTR lpSource   // Source string
);
// Returns: Destination string pointer

LPWSTR lstrcpyW(
    LPWSTR lpDest,    // Destination buffer
    LPCWSTR lpSource  // Source string
);
// Returns: Destination string pointer
```

### lstrcmpiA / lstrcmpiW
```c
int lstrcmpiA(
    LPCSTR lpString1,  // First string
    LPCSTR lpString2   // Second string
);
// Returns: 0 if equal, <0 if str1<str2, >0 if str1>str2

int lstrcmpiW(
    LPCWSTR lpString1,  // First wide string
    LPCWSTR lpString2   // Second wide string
);
// Returns: 0 if equal, <0 if str1<str2, >0 if str1>str2
```

### CharNextA
```c
LPSTR CharNextA(
    LPCSTR lpsz  // Current character position
);
// Returns: Pointer to next character
```

## Common Data Types

```c
// Basic types
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int BOOL;
typedef long LONG;
typedef unsigned long ULONG;

// Pointer types
typedef void *LPVOID;
typedef const void *LPCVOID;
typedef char *LPSTR;
typedef const char *LPCSTR;
typedef wchar_t *LPWSTR;
typedef const wchar_t *LPCWSTR;

// Handle types
typedef void *HANDLE;
typedef void *HWND;
typedef void *HDC;
typedef void *HBITMAP;
typedef void *HMODULE;
typedef void *HGLOBAL;
typedef void *HRSRC;
typedef void *HKEY;
typedef void *HGDIOBJ;
typedef void *HPALETTE;
typedef void *HBRUSH;
typedef void *HRGN;
typedef void *HMETAFILE;

// GDI types
typedef DWORD COLORREF;
typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

// Bitmap types
typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
} BITMAPINFO;

// Critical section
typedef struct _CRITICAL_SECTION {
    void *DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    DWORD SpinCount;
} CRITICAL_SECTION;

// Time types
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME;

// Large integer
typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    };
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    long long QuadPart;
} LARGE_INTEGER;
```

## Common Constants

```c
// Memory allocation flags
#define MEM_COMMIT      0x1000
#define MEM_RESERVE     0x2000
#define MEM_RELEASE     0x8000
#define MEM_DECOMMIT    0x4000

// Page protection flags
#define PAGE_NOACCESS       0x01
#define PAGE_READONLY       0x02
#define PAGE_READWRITE      0x04
#define PAGE_EXECUTE        0x10
#define PAGE_EXECUTE_READ   0x20

// Heap flags
#define HEAP_ZERO_MEMORY    0x00000008
#define HEAP_NO_SERIALIZE   0x00000001

// Synchronization
#define INFINITE    0xFFFFFFFF
#define WAIT_OBJECT_0   0
#define WAIT_TIMEOUT    258
#define WAIT_FAILED     0xFFFFFFFF

// Error codes
#define ERROR_SUCCESS           0L
#define ERROR_NO_MORE_ITEMS     259L
#define ERROR_MORE_DATA         234L

// Registry key access
#define KEY_READ        0x20019
#define KEY_WRITE       0x20006
#define KEY_ALL_ACCESS  0xF003F

// Registry value types
#define REG_NONE        0
#define REG_SZ          1
#define REG_EXPAND_SZ   2
#define REG_BINARY      3
#define REG_DWORD       4
#define REG_MULTI_SZ    7

// Code pages
#define CP_ACP      0
#define CP_UTF8     65001

// String mapping flags
#define NORM_IGNORECASE     0x00000001
#define NORM_IGNORENONSPACE 0x00000002
#define NORM_IGNORESYMBOLS  0x00000004
#define LINGUISTIC_IGNORECASE 0x00000010

// GDI raster operations
#define SRCCOPY     0x00CC0020
#define SRCPAINT    0x00EE0886
#define SRCAND      0x008800C6
#define SRCINVERT   0x00660046

// DIB usage
#define DIB_RGB_COLORS  0
#define DIB_PAL_COLORS  1

// TLS
#define TLS_OUT_OF_INDEXES (DWORD)0xFFFFFFFF
```
