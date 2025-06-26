#include <cstdint>
#include <uchar.h>

#include <iostream>
#include <iomanip>
#include <string>

// TODO: typedef instead of alias in comments?
// TODO: void type
// TODO: floating point types


// # Primitives
// ## Boolean Type
// | Type                          | Size         | Values      |
// |-------------------------------|--------------|-------------|
    bool flag;                  // | 8 bits*      | true, false |

// ## Basic Integers
// ### Signed Integer Types
// | Type                          | Minimum Size | Typical Size | Minimum Range         |
// |-------------------------------|--------------|--------------|-----------------------|
    signed char byte;           // | 8 bits       | 8 bits       | -127 to +127          |
    short small;                // | 16 bits      | 16 bits      | -2^15 to 2^15-1       |
    int integer;                // | 16 bits      | 32 bits      | -2^15 to 2^15-1       |
    long large;                 // | 32 bits      | 32/64 bits*  | -2^31 to 2^31-1       |
    long long max;              // | 64 bits      | 64 bits      | -2^63 to 2^63-1       |

// ### Unsigned Integer Types
// | Type                          | Minimum Size | Typical Size | Minimum Range         |
// |-------------------------------|--------------|--------------|-----------------------|
    unsigned char ubyte;        // | 8 bits       | 8 bits       | 0 to 255              |
    unsigned short usmall;      // | 16 bits      | 16 bits      | 0 to 2^16-1           |
    unsigned int uinteger;      // | 16 bits      | 32 bits      | 0 to 2^16-1           |
    unsigned long ularge;       // | 32 bits      | 32/64 bits** | 0 to 2^32-1           |
    unsigned long long umax;    // | 64 bits      | 64 bits      | 0 to 2^64-1           |


// ## C standard ints
// The following types allow the programmer to specify exactly what types he needs

// ### Fixed-width Integer Types
// Unlike the previous types, whose size depends on the CPU architecture, and/or implementation,
// the following types have exact width specified.

// | Type                          | Exact Size   | Range                     |
// |-------------------------------|--------------|---------------------------|
    int8_t tiny_int;            // | 8 bits       | -128 to 127               |
    int16_t small_int;          // | 16 bits      | -32,768 to 32,767         |
    int32_t medium_int;         // | 32 bits      | -2^31 to 2^31-1           |
    int64_t large_int;          // | 64 bits      | -2^63 to 2^63-1           |
// |                               |              |                           |
    uint8_t tiny_uint;          // | 8 bits       | 0 to 255                  |
    uint16_t small_uint;        // | 16 bits      | 0 to 65,535               |
    uint32_t medium_uint;       // | 32 bits      | 0 to 2^32-1               |
    uint64_t large_uint;        // | 64 bits      | 0 to 2^64-1               |

// ### Minimum-width Integer Types
// These types are aliases for the smallest types that are at least x bits wide.
// Imagine an atypical architecture that uses 36-bit numbers with 9-bit memory cells. Since
// `int8_t` will not exist as there's no way to represent that number in memory without padding.
// This is where minimum-width types come in. `int_least8_t` would be aliased as a 9-bit variable.

// Better explanation can be found [here](https://stackoverflow.com/questions/5254051/the-difference-of-int8-t-int-least8-t-and-int-fast8-t)

// | Type                          | Min Size     | Range                     |
// |-------------------------------|--------------|---------------------------|
    int_least8_t least8;        // | >=8 bits     | -127 to 127               |
    int_least16_t least16;      // | >=16 bits    | -2^15 to 2^15-1           |
    int_least32_t least32;      // | >=32 bits    | -2^31 to 2^31-1           |
    int_least64_t least64;      // | >=64 bits    | -2^63 to 2^63-1           |
// |                               |              |                           |
    uint_least8_t uleast8;      // | >=8 bits     | 0 to 255                  |
    uint_least16_t uleast16;    // | >=16 bits    | 0 to 2^16-1               |
    uint_least32_t uleast32;    // | >=32 bits    | 0 to 2^32-1               |
    uint_least64_t uleast64;    // | >=64 bits    | 0 to 2^64-1               |

// ### Fastest Integer Types
// This type is used to declare a variable with the fastest possible type. For example, imagine
// an architecture that requires for 8-bit numbers, requires first for these numbers to be cast
// to a bigger type, as the CPU doesn't support smaller types at the hardware level. The number
// If the programmer is unaware of this quirk in the hardware, he might be leaving performance on
// the table, albeit at the cost of higher memory consumption. This type allows programmer to
// specify the minimum size he requires, and for the compiler to determine the most optimal type
// for performance. In most circumstances, that would be an alias of `int`.
//
// | Type                          | Min Size     | Range                     |
// |-------------------------------|--------------|---------------------------|
    int_fast8_t fast8;          // | >=8 bits     | -127 to 127               |
    int_fast16_t fast16;        // | >=16 bits    | -2^15 to 2^15-1           |
    int_fast32_t fast32;        // | >=32 bits    | -2^31 to 2^31-1           |
    int_fast64_t fast64;        // | >=64 bits    | -2^63 to 2^63-1           |
// |                               |              |                           |
    uint_fast8_t ufast8;        // | >=8 bits     | 0 to 255                  |
    uint_fast16_t ufast16;      // | >=16 bits    | 0 to 2^16-1               |
    uint_fast32_t ufast32;      // | >=32 bits    | 0 to 2^32-1               |
    uint_fast64_t ufast64;      // | >=64 bits    | 0 to 2^64-1               |

// ### Pointer and Maximum Integer Types
// | Type                          | Size         | Range                     |
// |-------------------------------|--------------|---------------------------|
    intptr_t ptr_int;           // | Pointer size | Can hold pointer value    |
    uintptr_t ptr_uint;         // | Pointer size | Can hold pointer value    |
    intmax_t max_int;           // | Largest      | Maximum signed integer    |
    uintmax_t max_uint;         // | Largest      | Maximum unsigned integer  |


// ## Character Types
// | Type                          | Minimum Size | Typical Size  | Notes                 |
// |-------------------------------|--------------|---------------|-----------------------|
    char character;             // | 8 bits       | 8 bits        | Signed or unsigned    |
    signed char schar;          // | 8 bits       | 8 bits        | Always signed         |
    unsigned char uchar;        // | 8 bits       | 8 bits        | Always unsigned       |
    wchar_t wide_char;          // | Impl-defined | 16/32 bits*** | Wide character        |
    char8_t utf8_char;          // | 8 bits       | 8 bits        | UTF-8 (C++20)         |
    char16_t utf16_char;        // | 16 bits      | 16 bits       | UTF-16 (C++11)        |
    char32_t utf32_char;        // | 32 bits      | 32 bits       | UTF-32 (C++11)        |

// Notes:
// * Although in memory a bool type has allocated a byte, only the LSB is significant
// ** long: 32 bits on Windows (LLP64), 64 bits on Linux/macOS (LP64)
// *** wchar_t: 16 bits on Windows, 32 bits on Linux/macOS

void print_sizes() {
    std::cout << "## Sizes" << std::endl;

    // Boolean Type
    std::cout << "### Boolean Type" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `bool`                | " << std::setw(8) << std::left << (std::to_string(sizeof(bool)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(bool) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Signed Integer Types
    std::cout << "### Signed Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `signed char`         | " << std::setw(8) << std::left << (std::to_string(sizeof(signed char)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(signed char) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `short`               | " << std::setw(8) << std::left << (std::to_string(sizeof(short)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(short) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int`                 | " << std::setw(8) << std::left << (std::to_string(sizeof(int)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `long`                | " << std::setw(8) << std::left << (std::to_string(sizeof(long)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(long) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `long long`           | " << std::setw(8) << std::left << (std::to_string(sizeof(long long)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(long long) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Unsigned Integer Types
    std::cout << "### Unsigned Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `unsigned char`       | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned char)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned char) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `unsigned short`      | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned short)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned short) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `unsigned int`        | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned int)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned int) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `unsigned long`       | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned long)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned long) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `unsigned long long`  | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned long long)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned long long) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Fixed-width Integer Types
    std::cout << "### Fixed-width Signed Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `int8_t`              | " << std::setw(8) << std::left << (std::to_string(sizeof(int8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int16_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(int16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int32_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(int32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int64_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(int64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "|                       |          |          |" << std::endl;
    std::cout << "| `uint8_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(uint8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint16_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(uint16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint32_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(uint32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint64_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(uint64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Minimum-width Integer Types
    std::cout << "### Minimum-width Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `int_least8_t`        | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_least16_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_least32_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_least64_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_least64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "|                       |          |          |" << std::endl;
    std::cout << "| `uint_least8_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_least16_t`      | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_least32_t`      | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_least64_t`      | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_least64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Fastest Integer Types
    std::cout << "### Fastest Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `int_fast8_t`         | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_fast16_t`        | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_fast32_t`        | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `int_fast64_t`        | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(int_fast64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "|                       |          |          |" << std::endl;
    std::cout << "| `uint_fast8_t`        | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_fast16_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_fast32_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uint_fast64_t`       | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast64_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uint_fast64_t) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Pointer and Maximum Integer Types
    std::cout << "### Pointer and Maximum Integer Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `intptr_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(intptr_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(intptr_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uintptr_t`           | " << std::setw(8) << std::left << (std::to_string(sizeof(uintptr_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uintptr_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `intmax_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(intmax_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(intmax_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `uintmax_t`           | " << std::setw(8) << std::left << (std::to_string(sizeof(uintmax_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(uintmax_t) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;

    // Character Types
    std::cout << "### Character Types" << std::endl;
    std::cout << "| Type                  | Size     | Bits     |" << std::endl;
    std::cout << "|-----------------------|----------|----------|" << std::endl;
    std::cout << "| `char`                | " << std::setw(8) << std::left << (std::to_string(sizeof(char)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(char) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `signed char`         | " << std::setw(8) << std::left << (std::to_string(sizeof(signed char)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(signed char) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `unsigned char`       | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned char)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(unsigned char) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `wchar_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(wchar_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(wchar_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `char8_t`             | " << std::setw(8) << std::left << (std::to_string(sizeof(char8_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(char8_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `char16_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(char16_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(char16_t) * 8) + " bits") << " |" << std::endl;
    std::cout << "| `char32_t`            | " << std::setw(8) << std::left << (std::to_string(sizeof(char32_t)) + " bytes") << " | " << std::setw(8) << std::left << (std::to_string(sizeof(char32_t) * 8) + " bits") << " |" << std::endl;
    std::cout << std::endl;
}

int main() {
    print_sizes();
}
