#include <emscripten/bind.h>
#include <emscripten/wire.h>

#include "libdeflate.h"

EMSCRIPTEN_BINDINGS(deflate) {
    using namespace emscripten;
    using namespace emscripten::internal;

#if LIBDEFLATE_COMPRESSION_SUPPORT
    function("allocCompressor", &libdeflate_alloc_compressor, allow_raw_pointers());
    function("freeCompressor", &libdeflate_free_compressor, allow_raw_pointers());

    function("compress", &libdeflate_deflate_compress, allow_raw_pointers());
    function("compressBound", &libdeflate_deflate_compress_bound, allow_raw_pointers());

    function("zlibCompress", &libdeflate_zlib_compress, allow_raw_pointers());
    function("zlibCompressBound", &libdeflate_zlib_compress_bound, allow_raw_pointers());
    function("gzipCompress", &libdeflate_gzip_compress, allow_raw_pointers());
    function("gzipCompressBound", &libdeflate_gzip_compress_bound, allow_raw_pointers());
#endif

#if LIBDEFLATE_DECOMPRESSION_SUPPORT
    function("decompress", &libdeflate_deflate_decompress, allow_raw_pointers());
    function("decompressEx", &libdeflate_deflate_decompress_ex, allow_raw_pointers());
    
    function("allocDecompressor", &libdeflate_alloc_decompressor, allow_raw_pointers());
    function("freeDecompressor", &libdeflate_free_decompressor, allow_raw_pointers());

    function("zlibDecompress", &libdeflate_zlib_decompress, allow_raw_pointers());
    function("zlibDecompressEx", &libdeflate_zlib_decompress_ex, allow_raw_pointers());
    
    function("gzipDecompress", &libdeflate_gzip_decompress, allow_raw_pointers());
    function("gzipDecompressEx", &libdeflate_gzip_decompress_ex, allow_raw_pointers());
#endif

    function("adler32", &libdeflate_adler32, allow_raw_pointers());
    function("crc32", &libdeflate_crc32, allow_raw_pointers());

    // function("setMemoryAllocator", &libdeflate_set_memory_allocator, allow_raw_pointers());
}