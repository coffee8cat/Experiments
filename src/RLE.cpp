#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "RLE.h"

size_t RLE_compressor(FILE *fp_source, FILE *fp_target)
{
    assert(fp_source);
    assert(fp_target);

    printf("got here\n");

    char ch_prev = ' ';
    fread((void*)&ch_prev, sizeof(char), 1, fp_source);

    char ch_curr = ' ';
    char counter = 1;
    char single_chars[128] = {};
    bool single = false;

    while(fread((void*)&ch_curr, sizeof(char), 1, fp_source) == 1)
    {
        if(ch_curr == ch_prev)
        {
            if(single)
            {
                counter = counter * (-1);
                fwrite((void*)&counter, sizeof(char), 1, fp_target);
                for(char i = 0; i < counter; i++)
                {
                    fwrite((void*)&single_chars[i], sizeof(char), 1, fp_target);
                }
                counter = (char)1;
                single = false;
            }
            else
            {
                counter++;
                single = false;
            }
        }
        else
        {
            if(single)
            {
                if(counter < 128)
                {
                    single_chars[counter] = ch_prev;
                    counter++;
                }
                else
                {
                    counter = counter * (-1);
                    fwrite((void*)&counter, sizeof(char), 1, fp_target);
                    for(char i = 0; i < counter; i++)
                    {
                        fwrite((void*)&single_chars[i], sizeof(char), 1, fp_target);
                    }
                    counter = (char)1;
                }
            }
            else
            {
                fwrite((void*)&counter, sizeof(char), 1, fp_target);
                fwrite((void*)&ch_prev, sizeof(char), 1, fp_target);
                counter = (char)1;
                single = false;
            }
        }
        ch_prev = ch_curr;
    }
}

void RLE_decompressor(FILE *fp_source, FILE *fp_target)
{
    assert(fp_source);
    assert(fp_target);

    size_t n_copies = 0;
    char ch = ' ';
    char counter = 0;

    while(fread((void*)&counter, sizeof(char), 1, fp_source))
    {
        if(counter < 0)
        {
            for(char i = 0; i < abs(counter); i++)
            {
                fread((void*)&ch, sizeof(char), 1, fp_source);
                fwrite((void*)&ch, sizeof(char), 1, fp_target);
            }
        }
        else
        {
            fread((void*)&ch, sizeof(char), 1, fp_source);
            for(size_t i = 0; i < counter; i++)
            {
                fwrite((void*)&ch, sizeof(char), 1, fp_target);
            }
        }

    }
}
