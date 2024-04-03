#include "types.h"
#include "user.h"
#include "stat.h"

int main()
{
    int i;
    int iswrongpid = 0;
    for (i=1; i<=11; i++) {
        printf(1, "%d: ", i);
        if (getpname(i)) {
            iswrongpid = 1;
        }

        int nice = getnice(i);
        if (getnice(i) == -1) {
            iswrongpid = 1;
        } else {
            printf(1, "Nice value: %d\n", nice);
        }

        setnice(i, 15);
        if (getnice(i) == -1) {
            iswrongpid = 1;
        } else {
            printf(1, "Nice value: %d\n", nice);
        }

        setnice(i, 40);

        if (iswrongpid) {
            printf(1, "Wrong pid\n");
        }

    }

    exit();
}