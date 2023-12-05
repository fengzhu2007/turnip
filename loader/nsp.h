#ifndef NSP_H
#define NSP_H
#include "../common.h"
#include "loader.h"
#include <vector>
namespace turnip {

typedef struct {
    u32 magic;
    u32 num_files;
    u32 string_table_size;
    u32 reserved;
} nsp_header_t;

typedef struct {
    u64 offset;
    u64 size;
    u32 string_table_offset;
    u32 reserved;
} nsp_file_entry_t;

typedef struct {
    u8 master_hash[0x20]; /* SHA-256 hash of the hash table. */
    u32 block_size; /* In bytes. */
    u32 always_2;
    u64 hash_table_offset; /* Normally zero. */
    u64 hash_table_size;
    u64 pfs0_offset;
    u64 pfs0_size;
    u8 _0x48[0xF0];
} nsp_superblock_t;

class NSP :public Loader
{
public:
    NSP(std::string path);
    virtual ~NSP() override;
    virtual bool Parse() override;
    virtual size_t NumFiles() override;


    nsp_file_entry_t* FileEntry(size_t index);
    std::string FileName(size_t index);


private:
    nsp_header_t* header;
    std::vector<nsp_file_entry_t> entries;

    u64 headerSize;
    u64 stringTableOffset;

friend class NCA;
};


}


#endif // NSP_H
