#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char KMPSearch(char* text, char* pattern){
    int lens = strlen(text);
    int lenn = strlen(pattern);
    int ps = 0; int pn = 0;
    
    if(!lenn) return "";
    int ffs[lenn];
    
    ffs[0] = -1;
    for(int i = 1; i < lenn; i++){
        int curpre = ffs[i - 1];
        while((pattern[i] != pattern[curpre + 1]) && (curpre >= 0))
            curpre = ffs[curpre];
        if(pattern[i] == pattern[curpre + 1])
            ffs[i] = curpre + 1;
        else ffs[i] = -1;
    }
    
    while((ps < lens) && (pn < lenn)){
        if(pattern[pn] == text[ps]){
            pn++; ps++;
        }     
        else{
            if(pn == 0)
            ps++;
            else
            pn = ffs[pn - 1] + 1;
        } 
    }
    
    if(pn < lenn) return -1;
    else return text;
}
