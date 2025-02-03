char* removeDuplicates(char* s) {
    int n=strlen(s);
    char *sta=(char*)malloc(sizeof(char)*n+1);
    int top=-1;
    for(int i=0;i<n;i++){
        if(top==-1){
            sta[++top]=s[i];
        }else if(sta[top]==s[i]){
            top--;
        }else{
            sta[++top]=s[i];
        }
    }
    sta[top+1]='\0';
    return sta;
}