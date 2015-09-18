#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "../src/fileread.h"

START_TEST(test_textdump)
{
    char *files[] = { "nonexistent.txt", "empty.txt", "oneline.txt", "simple.bin", "testi.txt" };
    int refvals[] = { -1, 0, 41, 41, 213 };
    char *refouts[] = {
        "", "", "This file has text only on one line. Wow.",
        "?Teemu Teekkari00000A???ELEC-A1100???????",
        "#include <stdio.h>?#include \"fileread.h\"??int main(void)?{?    if (textdump(\"main.c\") == -1) {?        if (textdump(\"src/main.c\") == -1) {?            fprintf(stderr, \"Could not open main.c\\n\");?        }?    }?}?"
    };
    
    char buf[40];
    char stu[2048];
    int ret;
    for (int i = 0; i < 5; i++) {
        strcpy(buf, files[i]);
        freopen("mockoutput", "w", stdout);
        ret = textdump(buf);
        if (ret == -1) {
            strcpy(buf, "test/");
            strcat(buf, files[i]);
            ret = textdump(buf);
        }
        
        fail_unless(ret == refvals[i], "[Task 5.1.a] textdump(\"%s\") should return %d. You returned %d.",
                files[i], refvals[i], ret);
        
        read_stdout(stu, 2048);
        char infostr[100] = "";
        if (ret != -1 && mycompare(stu, refouts[i], infostr)) {
            remove_nonascii(stu);
            fail("[Task 5.1.a] Called textdump(\"%s\"). Your output:\n%s\nReference output:\n%s\nReason: %s\n",
                    files[i], stu, refouts[i], infostr);
        }
    }
}
END_TEST



int main(int argc, const char *argv[]) {
    Suite *s = suite_create("PrintTheFile");

    tmc_register_test(s, test_textdump, "printthefile");

    return tmc_run_tests(argc, argv, s);
}
