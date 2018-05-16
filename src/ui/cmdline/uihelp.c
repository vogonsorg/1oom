#include "config.h"

#include <stdio.h>
#include <string.h>

#include "uihelp.h"
#include "uidefs.h"

/* -------------------------------------------------------------------------- */

static int get_cmds_w(const struct input_cmd_s *cmds, int lmax)
{
    int i = 0;
    while (cmds[i].str_cmd != NULL) {
        int l;
        l = strlen(cmds[i].str_cmd) + 1;
        if (cmds[i].str_param) {
            l += strlen(cmds[i].str_param);
        }
        if (l > lmax) {
            lmax = l;
        }
        ++i;
    }
    return lmax;
}

static void show_cmds(const struct input_cmd_s *cmds, int lmax)
{
    int i = 0;
    char fmt1[16];
    char fmt2[16];
    sprintf(fmt1, "    %%-%is ", lmax);
    sprintf(fmt2, "%%s\n%%-%is", lmax + 5);
    while (cmds[i].str_cmd != NULL) {
        char buf[128];
        if (cmds[i].str_help) {
            const char *p, *q;
            sprintf(buf, "%s %s", cmds[i].str_cmd, cmds[i].str_param ? cmds[i].str_param : "");
            printf(fmt1, buf);
            p = cmds[i].str_help;
            while ((q = strchr(p, '\n')) != NULL) {
                int len;
                len = q - p;
                memcpy(buf, p, len);
                buf[len] = '\0';
                printf(fmt2, buf, "");
                p = q + 1;
            }
            printf("%s\n", p);
        }
        ++i;
    }
}

/* -------------------------------------------------------------------------- */

int ui_cmd_help(struct game_s *g, int api, struct input_token_s *param, int num_param, void *var)
{
    const struct input_cmd_s *cmds = var;
    int w;
    w = get_cmds_w(cmds, 0) + 1;
    show_cmds(cmds, w);
    return 0;
}