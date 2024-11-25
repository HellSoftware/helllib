#include <stdlib.h>
#include <stdio.h>

#define HELL_PARSER_IMPLEMENTATION
#include "../../hell_parser.h"

int main()
{
    char delim = '%';
    char *input_text = "background=%%color0.hex%%\n \
                        foreground=%%color15.hex%%";

    /* Initialize parser with input */
    hell_parser_t *parser = hell_parser_create(input_text);
    char *buffer = NULL;

    while (!hell_parser_eof(parser))
    {
        char ch;

        if (hell_parser_next(parser, &ch) == HELL_PARSER_OK)
        {
            if (ch == delim)
            {
                parser->pos -= 1; /* We have to do that so hell_parser_delim
                                     keeps track of the position */

                /* 
                 * Look out for delim, which is '%',
                 * count is set to 2, so it will trigger when it finds "%%"
                 */
                if (hell_parser_delim_buffer_between(parser, delim, 2, &buffer) == HELL_PARSER_OK)
                {
                    printf("Extracted content: '%s'\n", buffer);
                    free(buffer);
                }
            }
        }
    }

    hell_parser_destroy(parser);
    return 0;
}
