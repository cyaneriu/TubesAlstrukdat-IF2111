#include <stdio.h>
#include "boolean.h"
#include "map.h"

void CopyStringMap(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int CompareStrings(const char *key1, const char *key2) {
    int i = 0;
    while (key1[i] != '\0' && key2[i] != '\0') {
        if (key1[i] != key2[i]) {
            return key1[i] - key2[i];
        }
        i++;
    }
    return key1[i] - key2[i];
}

void CreateEmptyMap(Map *M){
    M->Count = Nil;
}

boolean IsMapEmpty(Map M){
    return (M.Count == Nil);
}

boolean IsMapFull(Map M){
    return (M.Count == MaxElm);
}

valuetype ValueMap(Map M, keytype k){
    if(IsMemberMap(M, k)){
        for(int i = 0; i<M.Count; i++){
        if(CompareStrings(M.Elements[i].Key, k) == 0){
            return M.Elements[i].Value;
            break;
        }
    }
    }
    else{
        return UndefMap;
    }
}

void InsertMap(Map *M, keytype k, valuetype v){
    if(!IsMemberMap(*M,k)){
        if(IsMapEmpty(*M)){
            M->Count = 1;
            CopyStringMap(M->Elements[0].Key, k);
            M->Elements[0].Value = v;
        }
        else{
            int idx = M->Count;
            M->Count++;
            CopyStringMap(M->Elements[idx].Key, k);
            M->Elements[idx].Value = v;
        }
    }
    else{
        int idx = GetIdxMap(*M, k);
        M->Elements[idx].Value+=v;
    }
}

void DeleteMap(Map *M, keytype k, valuetype v){
    if(IsMemberMap(*M, k)){
        int idx = GetIdxMap(*M, k);
        if(M->Elements[idx].Value-v<=0){
            M->Elements[idx].Value = 0;
            if(M->Count==1){
                M->Count = Nil;
            }
            else{
                for(int i = idx+1; i<M->Count; i++){
                    M->Elements[i-1] = M->Elements[i];
                }
                M->Count--;
            }
        }
        else{
            M->Elements[idx].Value-=v;
        }
    }
}

boolean IsMemberMap(Map M, keytype k){
    boolean member_found = false;
    for(int i = 0; i<M.Count; i++){
        if(CompareStrings(M.Elements[i].Key, k)==0){
            member_found = true;
            break;
        }
    }
    return member_found;
}

int GetIdxMap(Map M, keytype k){
    if(IsMemberMap(M, k)){
        for(int i = 0; i<M.Count; i++){
            if(CompareStrings(M.Elements[i].Key, k)==0){
                return i;
            }
        }
    }
}
