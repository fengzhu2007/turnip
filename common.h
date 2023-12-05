#ifndef COMMON_H
#define COMMON_H
#include <cstdint>


namespace turnip{
//using u128 = __uint128_t; //!< Unsigned 128-bit integer
using u64 = uint64_t; //!< Unsigned 64-bit integer
using u32 = uint32_t; //!< Unsigned 32-bit integer
using u16 = uint16_t; //!< Unsigned 16-bit integer
using u8 = uint8_t; //!< Unsigned 8-bit integer
//using i128 = int128_t; //!< Signed 128-bit integer
using i64 = int64_t; //!< Signed 64-bit integer
using i32 = int32_t; //!< Signed 32-bit integer
using i16 = int16_t; //!< Signed 16-bit integer
using i8 = int8_t; //!< Signed 8-bit integer
}

#define MAGIC_PFS0 0x30534650

#endif // COMMON_H
