#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum;
int csum;
int i;
void *runner(void *param);//child 
int main (int argc , char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid ,&attr , runner , argv[1]);//สร้างthread
    int num = atoi(argv[1]);
    printf ("Input number : %d\n",num);
    msum = 0;
    if(num > 0){
        for(i = 0; i <= num; i++ )
            msum +=1;
    }
    pthread_join(tid,NULL);
    printf("csum = %d\nmsum = %d\n",csum,msum );
    printf("Answer = %d\n",csum - msum);
    return 0;
}
void *runner(void *parum){
    int upper = atoi(parum);
    csum = 0;
    if(upper > 0){
        for(i = 0; i <= upper*2 ; i++ )
            csum +=1;
    }
    pthread_exit(0);
}