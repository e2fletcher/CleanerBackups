#include <ftw.h>
#include <fnmatch.h>
#include <cstdio>

static const char *filters_executable[] = {
    "*.scr", "*.exe", "*.pif", "*.bat", 
    "*.reg", "*.dll", "*.vbs", "*.com",
    "*.xls", "*.msi", "*.eml"
};

/*static const char *filters_executable_directory[] = {
    "RECICLER"
};*/

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    /* if it's a file */
    if (typeflag == FTW_F) {
        int i;
        /* for each filter, */
        for (i = 0; i < sizeof(filters_executable) / sizeof(filters_executable[0]); i++) {
            /* if the filename matches the filter, */
            if (fnmatch(filters_executable[i], fpath, FNM_CASEFOLD) == 0) {
                /* do something */
                printf("Posible amenaza: %s\n", fpath);
                break;
            }
        }
    }

    //if (typeflag == FTW_D)
	//printf("\033[1;31m%s\033[0m\n", fpath);

    /* tell ftw to continue */
    return 0;
}

int main(int argc, char* argv[]) {

    if(argc < 3){
        ftw("./", callback, 16);
        return 0;
    }
    
    printf("%s", argv[1]);
    ftw(argv[2], callback, 16);
        
    return 0;
}
