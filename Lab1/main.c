/*
Oświadczam, że niniejsza praca stanowiąca podstawę do uznania osiągnięcia efektówuczenia się z przedmiotu SOP2 
została wykonana przeze mnie samodzielnie.
Liavonik Aliaksei
302213
*/
#define _POSIX_SOURCE
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ftw.h>
#define MAXFD 20
#define SIZE "SIZE"
#define ERR(source) (perror(source),\
		     fprintf(stderr,"%s:%d\n",__FILE__,__LINE__),\
		     exit(EXIT_FAILURE))

FILE *s1;
char myType = ' ';
char *filename;
void usage(char* pname){
	fprintf(stderr,"USAGE:%s name times>0\n",pname);
	exit(EXIT_FAILURE);
}
int walk(const char *name, const struct stat *s, int type, struct FTW *f)
{
    int FindType;
    if(myType == 'd'){
        FindType = FTW_D;   
    }
    else if(myType == 'r'){
        FindType = FTW_F;
    }
    else if(myType == 's'){
        FindType = FTW_SL;
    }
    int size = 0;
    char *ssize = getenv(SIZE);

    if(ssize){
        size = atoi(ssize);
    }
    if(s1){
        if(size <= s->st_size){
            if(myType != ' '){
                if(type == FindType){
                    fprintf(s1,"%s\n",name);
                }
            }else{
                fprintf(s1,"%s\n",name);
            }
        }
    }else{
        if(size <= s->st_size){
            if(myType != ' '){
                if(type == FindType){
                    fprintf(stdout,"%s\n",name);
                }
            }else{
                fprintf(stdout,"%s\n",name);
            }
        }
    }


    return 0;
}
int main(int argc, char** argv) {

    int x = 1;
    char *path;
    int c;
    
	while ((c = getopt (argc, argv, "p:t:s:f:")) != -1){
		switch (c){
			case 'p':
				path = strdup(optarg);
				break;
            case 't':
                myType = optarg[0];
                break;

            case 's':
                setenv(SIZE,optarg,1);
                break;
            case 'f':
                filename = strdup(optarg);
                if(rand()%10 <=5){
                    strcat(filename,".txt");
                }else strcat(filename, ".opt");

                if((s1=fopen(filename,"w+"))==NULL) ERR("fopen");

                break;
			default: usage(argv[0]);
		}
    }
	if(argc>optind) usage(argv[0]);
    if(!path) ERR("Path does not exist");


    if(filename){
        bool itTxt = rand()%10 <=5;
    }

    int count;
    if(nftw(path,walk,MAXFD,FTW_PHYS)==0){}

    unsetenv(SIZE);
    if(s1 && fclose(s1))ERR("fclose");
	return EXIT_SUCCESS;
}