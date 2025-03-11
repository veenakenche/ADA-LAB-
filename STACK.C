/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) *(2*n));
    int sz=0;
    int input = 1; 
    for (register int i = 0; i < targetSize; i++) {
        while (target[i] > input) {
            ans[sz++]="Push";
            ans[sz++]="Pop";
            input++;
        }
        ans[sz++]="Push";
        input++;
    }

    *returnSize=sz;

    return ans;
}
