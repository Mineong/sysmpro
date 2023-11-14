#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char *, struct stat *, int);

void listNum(char *dir, int option);
void dirSlash(char *dir, int option);
void dirQuotes(char *dir, int option);

int main(int argc, char **argv)
{
    int option = 0;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-i") == 0)
            {
                option = 1;
            }
            else if (strcmp(argv[i], "-p") == 0)
            {
                dirSlash(".", option);
            }
            else if (strcmp(argv[i], "-Q") == 0)
            {
                dirQuotes(".", option);
            }
        }
    }

    
    listNum(".", option);

    exit(0);
}

void listNum(char *dir, int option)
{
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    if ((dp = opendir(dir)) == NULL)
        perror(dir);

    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        else
            printStat(d->d_name, &st, option);
    }

    closedir(dp);
}

void dirSlash(char *dir, int option)
{
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    if ((dp = opendir(dir)) == NULL)
        perror(dir);

    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        else
        {
            printf("%s", d->d_name);

            if (S_ISDIR(st.st_mode))
            {
                printf("/");
            }

            printf(" ");
            printStat(path, &st, option);
        }
    }

    closedir(dp);
}

void dirQuotes(char *dir, int option)
{
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    if ((dp = opendir(dir)) == NULL)
        perror(dir);

    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        else
        {
            printf("\"%s\" ", d->d_name);
            printStat(path, &st, option);
        }
    }

    closedir(dp);
}

void printStat(char *file, struct stat *st, int option)
{
    if (option)
    {
        printf("%ld ", st->st_ino); 
    }

    printf("%5ld", st->st_blocks);
    printf("%c%s", type(st->st_mode), perm(st->st_mode));
    printf("%3ld", st->st_nlink);
    printf("%s %s", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
    printf("%9ld", st->st_size);
    printf("%.12s", ctime(&st->st_mtime) + 4);
    printf("%s\n", file);
}

char type(mode_t mode)
{
    if (S_ISREG(mode))
        return ('-');
    if (S_ISDIR(mode))
        return ('d');
    if (S_ISCHR(mode))
        return ('c');
    if (S_ISBLK(mode))
        return ('b');
    if (S_ISLNK(mode))
        return ('l');
    if (S_ISFIFO(mode))
        return ('p');
    if (S_ISSOCK(mode))
        return ('s');
}

char *perm(mode_t mode)
{
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++)
    {
        if (mode & (S_IRUSR >> i * 3))
            perms[i * 3] = 'r';
        if (mode & (S_IWUSR >> i * 3))
            perms[i * 3 + 1] = 'w';
        if (mode & (S_IXUSR >> i * 3))
            perms[i * 3 + 2] = 'x';
    }
    return (perms);
}

