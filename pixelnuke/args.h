#include <argp.h>
#include <stdbool.h>
#include <stdlib.h>

struct arguments
{
    char *args[4];
    int port;
    int width;
    int height;
    int fps;
    int fullscreen;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;
    switch (key)
    {
    case 'f':
    {
        arguments->fullscreen = 1;
        break;
    }
    case 'p':
    {
        arguments->port = atoi(arg);
        break;
    }
    case 'w':
    {
        arguments->width = atoi(arg);
        break;
    }
    case 'h':
    {
        arguments->height = atoi(arg);
        break;
    }
    case 'F':
    {
        arguments->fps = true;
        break;
    }
    case ARGP_KEY_ARG >= 4:
    {
        argp_usage(state);
        arguments->args[state->arg_num] = arg;
        break;
    }
    case ARGP_KEY_END:
    {
        if (state->arg_num < 3)
        {
            argp_usage(state);
        }
        break;
    }
    default:
    {
        return ARGP_ERR_UNKNOWN;
    }
    }
    return EXIT_SUCCESS;
}
