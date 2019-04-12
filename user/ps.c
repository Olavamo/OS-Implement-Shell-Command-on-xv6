#include "types.h"
#include "user.h"
#include "ProcessInfo.h"
#include "param.h"

int main() {

    enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
	 static char *states[] = {
  		[UNUSED]    "UNUSED  ",
  		[EMBRYO]    "EMBRYO  ",
  		[SLEEPING]  "SLEEPING",
  		[RUNNABLE]  "RUNNABLE",
  		[RUNNING]   "RUNNING ",
  		[ZOMBIE]    "ZOMBIE  "
  		};
    
    printf(1, "Testing ps function ...\n");
    struct ProcessInfo pInfo[NPROC];
    printf(1, "Entering getprocs function ...\n");
    int num = getprocs(pInfo);
    printf(1, "Getprocs() returns %d\n", num);

    int i;
    for (i=0; i < num; i++) {
        printf(1, "%d %d ", pInfo[i].pid, pInfo[i].ppid); // linenum and parentid printed
        printf(1, "%s ", states[pInfo[i].state]); // process state printed
        printf(1, "%d %s\n", pInfo[i].sz,pInfo[i].name); // process size and name printed
    }
    


    exit();
}
