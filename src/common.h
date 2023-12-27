#ifndef COMMON_H
#define COMMON_H
#include <cstdint>
#include <string>

#define MEDIA_SIZE 0x200


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




std::string trim(const std::string& str);

int ishex(char c);
char hextoi(char c);



/* Beta NCA0 helpers */
const unsigned char *pki_get_beta_nca0_modulus(void);
void pki_set_beta_nca0_exponent(void *exponent);
const unsigned char *pki_get_beta_nca0_exponent(void);
const unsigned char *pki_get_beta_nca0_label_hash(void);

inline uint64_t media_to_real(uint64_t media) {
    return MEDIA_SIZE * media;
}

}

#define MAGIC_PFS0 0x30534650




#endif // COMMON_H
