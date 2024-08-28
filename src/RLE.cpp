#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "RLE.h"

size_t RLE_compressor(FILE *fp_source, FILE *fp_target)
{
    assert(fp_source);
    assert(fp_target);

    fseek(fp_source, 0, SEEK_END);
    const size_t mem_size = ftell(fp_source);
    rewind(fp_source);

    char *input = (char*)calloc(mem_size, sizeof(char));
    fread(input, sizeof(char), mem_size,fp_source);

    printf("got here\n");

    char ch_prev = input[0];
    char ch_curr = ' ';
    size_t counter = 1;

    for(size_t i = 1; i < mem_size; i++)
    {
        ch_curr = input[i];
        if(ch_curr == ch_prev)
        {
            counter++;
        }
        else
        {
            fprintf(fp_target, "%d%c%c", counter, '\0', ch_prev);
            counter = 1;
        }
        ch_prev = ch_curr;
    }

    //fprintf(fp_target, "%d%c", counter, ch_prev);

    return mem_size;
}

void RLE_decompressor(FILE *fp_source, FILE *fp_target, size_t mem_size)
{
    char *output = (char*)calloc(mem_size, sizeof(char));

    size_t n_copies = 0;
    char ch = ' ';
    size_t j = 0;

    while((fscanf(fp_source, "%d", &n_copies) == 1) && (getc(fp_source) == '\0')
           && (ch = getc(fp_source)) != EOF)
    {
        for(size_t i = 0; i < n_copies; i++)
        {
            output[j] = ch;
            j++;
        }
    }

    fwrite(output, sizeof(char), mem_size, fp_target);
}
