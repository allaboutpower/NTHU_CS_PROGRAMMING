#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;

int cmp_a(const void *a, const void *b){
    Grade *pa = (Grade*)a;
    Grade *pb = (Grade*)b;
    
    if(pa->total != pb->total){
        return pa->total-pb->total;
    }
    else {
        if(pa->Chinese != pb->Chinese){
            return pa->Chinese - pb->Chinese;
        }
        else{
            if(pa->English != pb->English){
                return pa->English - pb->English;
            }   
            else{
                if(pa->math != pb->math){
                    return pa->math - pb->math;
                }
                else{
                    if(pa->science != pb->science)return pa->science-pb->science;
                    else{
                        return pa->ID-pb->ID;
                    }
                }
            }

        } 
    }
}

int cmp_b(const void *a, const void *b){
    Grade *pa = (Grade*)a;
    Grade *pb = (Grade*)b;
    
    if(pa->total != pb->total){
        return pb->total-pa->total;
    }
    else {
        if(pb->Chinese != pa->Chinese){
            return pb->Chinese - pa->Chinese;
        }
        else{
            if(pb->English != pa->English){
                return pb->English - pa->English;
            }   
            else{
                if(pb->math != pa->math){
                    return pb->math - pa->math;
                }
                else{
                    if(pb->science != pa->science)return pb->science-pa->science;
                    else{
                        return pa->ID-pb->ID;//題目說id要由低到高，跟上面條件不同
                    }
                }
            }

        } 
    }
}

void sortGrade(Grade g[], int n, char order[]){
    for(int i=0; i<n; i++){
        g[i].total = g[i].Chinese + g[i].English + g[i].math + g[i].science;
    }
    char asc[10] = "ascending";
    if(!strcmp(order , asc)){
        qsort(g, n ,sizeof(Grade), cmp_a );
    }
    else{
        qsort(g, n, sizeof(Grade), cmp_b);
    }
    return;
}

int main(){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    }
    sortGrade(gradeList, n, order);
    for(i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    }
    return 0;
}