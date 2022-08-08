#include<stdio.h>

char *simplifyPath(char *path){
    int *slashPosition = (int*)malloc(sizeof(int) * (strlen(path) / 2 + 1));
    int slashNumber = 0;
    slashPosition[slashNumber] = 0;

    int index = 0;
    while (path[index]){
        while (path[index] == '/') index++;
        int start = index;

        while (path[index] && path[index] != '/') index++;
        int end = index;

        if (start == end){  // path[index] = path[start] = path[end] = '\0'
            path[slashPosition[slashNumber]] = '\0';
        }
        else if (start + 1 == end && path[start] == '.'){
            continue;
        }
        else if (start + 2 == end && path[start] == '.' && path[start + 1] == '.'){
            if (slashNumber > 0) slashNumber--;
        }
        else{
            path[slashPosition[slashNumber]] = '/';
            for (index = start; index < end; index++){
                path[slashPosition[slashNumber] + index - start + 1] = path[index];
            }
            slashNumber++;
            slashPosition[slashNumber] = slashPosition[slashNumber - 1] + end - start + 1;
        }
    }
    path[slashPosition[slashNumber]] = '\0';
    
    // always start with '/'
    if (slashNumber == 0) return "/";
    else return path;
}

void main(){
    printf("%s\n", simplifyPath("/home/"));
    printf("%s\n", simplifyPath("/../"));
    printf("%s\n", simplifyPath("/home//foo/"));
    printf("%s\n", simplifyPath("/a/./b/../../c/"));
    printf("%s\n", simplifyPath("/"));
}