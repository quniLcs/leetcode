#include<stdio.h>


char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize){
    char **result = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    int *wordsLen = (int*)malloc(sizeof(int) * wordsSize);
    for (int index = 0; index < wordsSize; index++){
        wordsLen[index] = strlen(words[index]);
    }

    int index = 0;
    while (index < wordsSize){
        int start = index;
        int curWidth = -1;
        while (curWidth <= maxWidth && index < wordsSize){
            curWidth += wordsLen[index] + 1;
            index++;
        }
        int end = curWidth > maxWidth ? index - 1 : wordsSize;
        int wordsWidth = (curWidth > maxWidth ? curWidth - wordsLen[end] - 1 : curWidth) - (end - start - 1);

        result[*returnSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
        // only one word: left justify
        // towards the end: left justify
        // others: full justify

        if (start + 1 == end || end == wordsSize){
            int curWidth = 0;
            for (index = start; index < end; index++){
                strcpy(result[*returnSize] + curWidth, words[index]);
                curWidth += wordsLen[index];

                if (index != end - 1){
                    result[*returnSize][curWidth] = ' ';
                    curWidth++;
                }
            }
            memset(result[*returnSize] + curWidth, ' ', sizeof(char) * (maxWidth - curWidth));
        }
        else{
            int spacesWidth = maxWidth - wordsWidth;
            int spaceWidth = spacesWidth / (end - start - 1);
            int spaceRemain = spacesWidth % (end - start - 1);

            int curWidth = 0;
            for (index = start; index < end; index++){
                strcpy(result[*returnSize] + curWidth, words[index]);
                curWidth += wordsLen[index];

                if (spaceRemain){
                    memset(result[*returnSize] + curWidth, ' ', sizeof(char) * (spaceWidth + 1));
                    curWidth += spaceWidth + 1;
                    spaceRemain--;
                }
                else if (index != end - 1){
                    memset(result[*returnSize] + curWidth, ' ', sizeof(char) * spaceWidth);
                    curWidth += spaceWidth;
                }
            }
        }

        result[*returnSize][maxWidth] = '\0';
        (*returnSize)++;
    }

    return result;
}


void main(){
    int maxWidth = 16;
    int wordsSize = 7;

    char **words = (char**)malloc(sizeof(char*) * wordsSize);
    words[0] = "This";
    words[1] = "is";
    words[2] = "an";
    words[3] = "example";
    words[4] = "of";
    words[5] = "text";
    words[6] = "justification.";

    int returnSize = 0;
    char **result = fullJustify(words, wordsSize, maxWidth, &returnSize);

    for (int index = 0; index < returnSize; index++){
        printf("%s\n", result[index]);
    }
}