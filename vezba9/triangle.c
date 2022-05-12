/************************************
 *******PLOT A PERIODIC FUNCTION*****
 ************TRIANGULAR WAVE*********
 ***********************************/
#include<stdio.h>
#include<math.h>
/**Function definition for the Triangular Wave(Periodic Function)**/
double f(double x){
  if(x>=0&&x<M_PI){
    return x;
  }
  else if(x>=M_PI&&x<2*M_PI){
    return 2*M_PI-x;
  }
  else if(x>=2*M_PI){
    return f(x-2*M_PI);
  }
  else if(x<0){
    return f(x+2*M_PI);
  }
}
main(){
  FILE *fp=NULL;
  /*To write the data points to a txt file [periodic.txt]**/
  fp=fopen("periodic.txt","w");
  double x;
  /**To plot in the rang of -6pi to 6pi **/
  for (x=-6*M_PI;x<=6*M_PI;x=x+0.1){
    fprintf(fp,"%lf\t%lf\n",x,f(x));
  }
}
