#include <stdio.h>
#include <string.h>


char s[21];
int k;

    void permute(int id, char *output ){
        int len = strlen(s);
        if (id==k)
        {
            printf("%s\n", output);
            return;
        }
        else
        { 
            for(int i=0 ; i < len ; ++i){
                output[id] = s[i];
                permute(id+1, output);

            }
        }

    }



int main(void)
{
    scanf("%s %d", s, &k);
    char output[k+1];
    output[k]='\0';
    permute(0, output);
    return 0;
}