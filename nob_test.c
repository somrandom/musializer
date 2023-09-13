#define NOB_IMPLEMENTATION
#include "nob.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "neofetch");

    Nob_String_Builder out = {0};
    nob_cmd_run_sync_io(cmd, NULL, &out);

    Nob_Cmd cmd2 = {0};
    nob_cmd_append(&cmd2, "rev");
    Nob_String_Builder out2 = {0};
    nob_cmd_run_sync_io(cmd2, &out, &out2);

    nob_log(NOB_INFO, "out2 count = %ld\n", out2.count);
    printf("%s", out2.items);

    return 0;
}
