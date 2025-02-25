        #include<stdio.h>
        #include<stdlib.h>


        int cmp(const void *L, const void *R) {

            int l = *(int*)L;
            int r = *(int*)R;
            if(l>r) return 1;
            if(l<r) return -1;
            return 0;
        }

        //LB(a, 0, 6, 7); 1 4 4 7 7 7 8 tar=4
        int LB(int *a, int left, int right, int tar){
            int mid= (left+right)/2;
            if(mid == left) {
                if(a[left]==tar)return left;
                else return right; 
                }// 5 => return no.2

            if(a[mid] < tar){
                return LB(a, mid, right, tar);
            }

            else if(a[mid] == tar){
                if(a[mid-1] < tar) return mid; 
                else return LB(a, left, mid, tar);
            }

            else if(a[mid] > tar){
                return LB(a, left, mid, tar);

            }

            }


            //1 3 3 6 7 7 7 7 8 10 tar=1
        int UB(int *a, int left, int right, int tar){
            int mid = (left+right)/2;

            if(mid == left) return right;  // 5 return 3
            

            if(a[mid] < tar){
                return UB(a, mid, right, tar);
            }

            else if(a[mid] == tar){
                if(a[mid+1] > tar) {
                    return (mid+1); 
                }
                else return UB(a, mid, right, tar);
            }

            else if(a[mid] > tar){
                return UB(a, left, mid, tar);

            }
            

            }
            







        int main(){
            int n;
            
            scanf("%d", &n);
            int a[n+1];
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }

            int q;
            scanf("%d", &q);

            qsort(a, n, sizeof(int), cmp);
            while(q){
                int t;
                scanf("%d", &t);
                printf("%d\n",UB(a,0,n,t)-LB(a,0,n,t)) ;//n=10 t=1
                q--;
            }


            

            return 0;
        }