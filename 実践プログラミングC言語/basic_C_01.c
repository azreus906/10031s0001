#include <stdio.h>

int main() {
    
    FILE *src_file = NULL; /* コピー元のファイル型構造体 */
    FILE *dest_file = NULL; /* コピー先のファイル型構造体 */
    char source_file_name[256]; /* コピー元ファイルのファイル名 */
    char dest_file_name[256]; /* コピー先ファイルのファイル名 */
    char buffer[1024]; /* コピー元ファイルの内容を格納するための配列 */
    
    /* ファイル名の入力を受け付ける */
    printf("Enter the source file name: ");
    scanf("%s", source_file_name);
    printf("Enter the destination file name: ");
    scanf("%s", dest_file_name);
    
    /* コピー元ファイルを開く */
    src_file = fopen(source_file_name, "r");
    if (src_file == NULL) {
        printf("Error: File not found.");
        return 0;
    }

    /* コピー先ファイルを開く */
    dest_file = fopen(dest_file_name, "w");
    if (dest_file == NULL) {
        printf("Error: File not found.");
        fclose(src_file);
        return 0;
    }

    /* ファイルの内容をコピーする */
    while(fgets(buffer, sizeof(buffer), src_file) != NULL) {
        fputs(buffer, dest_file);
    }

    /* ファイルを閉じる */
    fclose(src_file);
    fclose(dest_file);
}