#include <stdio.h>

int main() {
    
    FILE *srcFile = NULL; /* コピー元のファイル型構造体 */
    FILE *destFile = NULL; /* コピー先のファイル型構造体 */
    char sourceFilename[256]; /* コピー元ファイルのファイル名 */
    char destFilename[256]; /* コピー先ファイルのファイル名 */
    char buffer[1024]; /* コピー元ファイルの内容を格納するための配列 */
    
    /* ファイル名の入力を受け付ける */
    printf("Enter the source file name: ");
    scanf("%s", sourceFilename);
    printf("Enter the destination file name: ");
    scanf("%s", destFilename);
    
    /* コピー元ファイルを開く */
    srcFile = fopen(sourceFilename, "r");
    if (srcFile == NULL) {
        printf("Error: File not found.");
        return 0;
    }

    /* コピー先ファイルを開く */
    destFile = fopen(destFilename, "w");
    if (srcFile == NULL) {
        printf("Error: File not found.");
        return 0;
    }

    /* ファイルの内容をコピーする */
    while(fgets(buffer, sizeof(buffer), srcFile) != NULL) {
        fputs(buffer, destFile);
    }

    /* ファイルを閉じる */
    fclose(srcFile);
    fclose(destFile);
}