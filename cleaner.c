#include <ftw.h>
#include <fnmatch.h>
#include <string.h>
#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <unistd.h>    /* for getopt */


int flag_delete, flag_music, flag_video, flag_error;

void help()
{
    printf("Ayuda\n");
}

void process()
{
    printf("Procesando...\n");
    if(flag_delete)
        printf("Se borraran archivos\n");
}

int main (int argc, char **argv) {
    int c;
    while ( (c = getopt(argc, argv, "Dmv")) != -1) {
        switch (c) {
            case 'D':
                flag_delete++;
                break;
            case 'm':
                flag_music++;
                break;
            case 'v':
                flag_video++;
            case '?':
                break;
                flag_error++;
            default:
                flag_error++;
        }
    }
    
    if(flag_error)
    {
        help();
        exit(0);
    }

    process();
    exit (0);
}


static const char *filters_executable[] = {
    "*.scr", "*.exe", "*.pif", "*.bat", 
    "*.reg", "*.dll", "*.vbs", "*.com",
    "*.xls", "*.msi", "*.eml"
};

static const char *filters_music[] = {
    "*.mp3", "*.dat", "*.wma"
};

static const char *filters_video[] = {
    "*.avi", "*.mp4", "*.dat", "*.mpg"
};

static const char *filters_directory[] = {
    "RECYCLER", 
    "Tacoma"
};

static const char *filters_others[] = {
    ".*lnk",".*mad",".*maf",".*mag",".*mam",".*maq",
    ".*mar",".*mas",".*mat",".*mau",".*mav",".*maw",
    ".*mda",".*mdz",".*mhtml",".*prf",".*pst",".*reg",
    ".*scf",".*sct",".*shb",".*shs", ".*vbe",
    ".*vbs",".*vsmacros",".*vss",".*vst",".*vsw",
    ".*wmf",".*ws",".*wsc",".*wsf",".*wsh",".*xnk",
    ".*ceo",".*cer",".*chm",".*cmd",".*cnf",".*cpl",
    ".*hta",".*ins",".*its",".*job",".*jse",".*ini",
    ".*bin",".*inf",".*db",".*dll", ".*vmx", ".*log",
    ".*sav",".*sqm",".*part", ".*tmp"
};

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    if (typeflag == FTW_D){
        int i;
        for (i = 0; i < sizeof(filters_directory) / sizeof(filters_directory[0]); i++) {
            if(strstr(fpath, filters_directory[i]) != NULL){
                printf("Directorio sospechoso: %s\n", fpath);
                break;
            }
        }
    }

    if (typeflag == FTW_F) {
        int i;
        for (i = 0; i < sizeof(filters_executable) / sizeof(filters_executable[0]); i++) {
            if (fnmatch(filters_executable[i], fpath, FNM_CASEFOLD) == 0) {
                printf("Posible amenaza: %s\n", fpath);
                break;
            }
        }

        for (i = 0; i < sizeof(filters_others) / sizeof(filters_others[0]); i++) {
            if (fnmatch(filters_others[i], fpath, FNM_CASEFOLD) == 0) {
                printf("Archivos basura: %s\n", fpath);
                break;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if(argc < 2){
        ftw("./", callback, 16);
        return 0;
    }
    ftw(argv[1], callback, 16);   
    return 0;
}

