 #include "/home/e575/c/.h/zhanjiejuemigong.h"
// #include "/home/e575/c/.h/duiliejiejuemigong.h"

int main()
{
    int i,j,z;
   int maze[m+2][n+2]={
       1,1,1,1,1,1,1,1,1,1,
       1,0,1,1,1,0,1,1,1,1,
       1,0,0,0,0,1,1,1,1,1,
       1,0,1,0,0,0,0,0,1,1,
       1,0,1,1,1,0,0,1,1,1,
       1,1,0,0,1,1,0,0,0,1,
       1,0,1,1,0,0,1,1,0,1,
       1,1,1,1,1,1,1,1,1,1};
    xianshi (maze);
    mazepath ( maze,move,1,1);
    printf("\n");
   return 0;
}