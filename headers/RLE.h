#ifndef _RLE_TEXT_COMPRESSION_H__
#define _RLE_TEXT_COMPRESSION_H__

size_t RLE_compressor(FILE *fp_source, FILE *fp_target);

void RLE_decompressor(FILE *fp_source, FILE *fp_target, size_t mem_size);

#endif //_RLE_TEXT_COMPRESSION_H__
