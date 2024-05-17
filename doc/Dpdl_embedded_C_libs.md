
# Dpdl embedded C libs

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003


## Minimal C library documentation for embedded C code execution (Mode 1 -> interpreted)

This is the minimal C library documentation for the Mode (1) (interpreted) embedded C code execution.

When executing embedded C code with interpreted Mode (1), all libraries are already defined and available in the native Dpdl runtime.


Example:
```c
println("embedding some C code...")

>>c
	#include <stdio.h>
	
	printf("Hello C\n");
<<
int exit_code = dpdl_exit_code()
println("finished with exit code" + exit_code)

```

The default configuration includes only a minimal set of library functions to keep the runtime as small as possible.

However more functions and libraries may be included in different distributions of the Dpdl native API library (dpdlnativeapi), see Download page.

NOTE: When executing C code with Mode (2), the standard C libraries of your compiler toolchain can be used.

## Currently supported C Libraries and Functions

```c
<stdio.h>
<stdlib.h>
<ctype.h>
<unistd.h>
<math.h>
<string.h>
<time.h>
<dpdl.h>
```

### <stdio.h>

```c
FILE *fopen(char *, char *);
FILE *freopen(char *, char *, FILE *);
int fclose(FILE *);
int fread(void *, int, int, FILE *);
int fwrite(void *, int, int, FILE *);
int fgetc(FILE *);
int getc(FILE *);
char *fgets(char *, int, FILE *);
int fputc(int, FILE *);
int fputs(char *, FILE *);
int putc(char *, FILE *);
int putchar(int);
int fputchar(int);
void setbuf(FILE *, char *);
void setvbuf(FILE *, char *, int, int);
int ungetc(int, FILE *);
int puts(char *);
char *gets(char *);
int getchar();
int remove(char *);
int rename(char *, char *);
void rewind(FILE *);
FILE *tmpfile();
void clearerr(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fileno(FILE *);
int fflush(FILE *);
int fgetpos(FILE *, int *);
int fsetpos(FILE *, int *);
int ftell(FILE *);
int fseek(FILE *, int, int);
void perror(char *);
int printf(char *, ...);
int fprintf(FILE *, char *, ...);
int sprintf(char *, char *, ...);
int snprintf(char *, int, char *, ...);
int scanf(char *, ...);
int fscanf(FILE *, char *, ...);
int sscanf(char *, char *, ...);
int vprintf(char *, va_list);
int vfprintf(FILE *, char *, va_list);
int vsprintf(char *, char *, va_list);
int vsnprintf(char *, int, char *, va_list);
int vscanf(char *, va_list);
int vfscanf(FILE *, char *, va_list);
int vsscanf(char *, char *, va_list);
```

### <stdlib.h>

```c
void *malloc(int);
void *calloc(int,int);
void *realloc(void *,int);
void free(void *);
int rand();
void srand(int);
float atof(char *);
float strtod(char *,char **);
int atoi(char *);
int atol(char *);
int strtol(char *,char **,int);
int strtoul(char *,char **,int);
void abort();
void exit(int);
char *getenv(char *);
int system(char *);
int abs(int);
int labs(int);
div_t div(int);
ldiv_t ldiv(int);
```

### <ctype.h>

```c
int isalnum(int);
int isalpha(int);
int isblank(int);
int tolower(int);
int toupper(int);
int isascii(int);
int toascii(int);
int isprint(int);
int ispunct(int);
int isspace(int);
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int isupper(int);
int isxdigit(int);
```
### <math.h>

```c
float acos(float);
float asin(float);
float atan(float);
float atan2(float, float);
float ceil(float);
float cos(float);"
float cosh(float);
float exp(float);
float modf(float, float *);
float pow(float, float);
float round(float);
float sin(float);
float sinh(float);
float sqrt(float);
float tan(float);
float tanh(float);
float fabs(float);
float floor(float);
float fmod(float, float);
float frexp(float, int *);
float ldexp(float, int);
float log(float);
float log10(float);
```
### <unistd.h>

```c
int access(char *, int);
unsigned int alarm(unsigned int);
int chdir(char *);
int chroot(char *);
int chown(char *, uid_t, gid_t);
int close(int);
long fpathconf(int, int);
int fsync(int);
int ftruncate(int, off_t);
char *getcwd(char *, size_t);
int getdtablesize(void);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);
long gethostid(void);
char *getlogin(void);
size_t confstr(int, char *, size_t);"
char *ctermid(char *);
int dup(int);
int dup2(int, int);
void _exit(int);
int fchown(int, uid_t, gid_t);
int fchdir(int);
int fdatasync(int);
pid_t fork(void);
int getlogin_r(char *, size_t);
int getpagesize(void);
char *getpass(char *);
pid_t getpgrp(void);    -> On Window: pid_t getpgrp(pid_t);  
pid_t getpid(void);
pid_t getppid(void);"
uid_t getuid(void);
char *getwd(char *);
int isatty(int);
int lchown(char *, uid_t, gid_t);
int link(char *, char *);
int lockf(int, int, off_t);"
off_t lseek(int, off_t, int);"
int nice(int);
unsigned int sleep(unsigned int);
int symlink(char *, char *);
void sync(void);
long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
int truncate(char *, off_t);
char *ttyname(int);
int ttyname_r(int, char *, size_t);
useconds_t ualarm(useconds_t, useconds_t);
int unlink(char *);
int usleep(useconds_t);
pid_t vfork(void);
ssize_t write(int, void *, size_t);
long pathconf(char *, int);
int pause(void);
ssize_t read(int, void *, size_t);
int readlink(char *, char *, size_t);
int rmdir(char *);
void *sbrk(intptr_t);
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setpgrp(void);      ->   On Windows: pid_t setpgrp(pid_t, pid_t);
int setregid(gid_t, gid_t);
int setreuid(uid_t, uid_t);
pid_t setsid(void);
int setuid(uid_t);
```

### <string.h>

```c
int memcmp(void *, void *, int);
void *memset(void *, int, int);
void *memcpy(void *, void *, int);
void *memmove(void *, void *, int);
void *memchr(char *, int, int);
char *strcat(char *, char *);
char *strncat(char *, char *, int);
char *strchr(char *, int);
char *strrchr(char *, int);
int strcmp(char *, char *);
int strncmp(char *, char *, int);
int strcoll(char *, char *);
char *strcpy(char *, char *);
char *strncpy(char *, char *, int);
char *strerror(int);
char *index(char *, int);
char *rindex(char *, int);
int strlen(char *);
int strspn(char *, char *);
int strcspn(char *, char *);
char *strpbrk(char *, char *);
char *strstr(char *, char *);
char *strtok(char *, char *);
int strxfrm(char *, char *, int);
char *strdup(char *);
char *strtok_r(char *, char *, char **);
```

### <time.h>

```c
char *ctime(int *);
double difftime(int, int);
char *asctime(struct tm *);
time_t clock();
int mktime(struct tm *ptm);
int time(int *);
int strftime(char *, int, char *, struct tm *);
char *strptime(char *, char *, struct tm *);
struct tm *gmtime_r(int *, struct tm *);
int timegm(struct tm *);
struct tm *gmtime(int *);
struct tm *localtime(int *);
```

### <dpdl.h>

```c
void dpdl_stack_buf_put(char*);
```