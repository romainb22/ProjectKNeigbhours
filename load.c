point ** loadFromfile(char * path){
  FILE *f = NULL;
  char c[MAX_LINE_LENGTH];
  int nbPoints, dimension, nbClasses,i,classe;
  float x,y;
  point * tab[nbPoints];


  i = -1;
  f = fopen(path,"r");
  if (f!=NULL){
    while (fgets(c,MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        sscanf(c,"%d %d %d", &nbPoints, &dimension, &nbClasses);
      }
      else{
        /* Do nothing */
      }
      i++;
    }
    fclose(f);
  }
  f=fopen(path,"r");
  i = -1;
  if (f!=NULL){
    while (fgets(c, MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        /* Do nothing */
      }
      else{
        sscanf(c,"%d %f %f", &classe, &x, &y);
        tab[i]= newPoint(x, y, classe);
      }
      i++;
    }
    fclose(f);
  }
  for(i=1;i<nbPoints;i++){
    printf("%f\n",getDistance(tab[i-1],tab[i]));
  }
  return tab;
}
