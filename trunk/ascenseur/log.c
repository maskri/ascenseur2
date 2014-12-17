int log(int eCourant, char fonction, char message, char severity) {
  FILE *f;
  time_t temps;
  struct tm date;
  char time_now[30];
  char line[120];
  
  time(&temps);
  date=*localtime(&temps);

  sprintf(time_now, "%s", asctime(&date));
  sprintf(line, "%s : [ %s : appele de la fonction %s à l'étage %d ]",severity,
						    time_now, fonction, eCourant);
  sprintf(line, "Message: %s ", message);
  
  f = fopen("log.ini", "W");
  while(fgetc(f) != EOF) {
    
  }
  if (feof(f)) {
    fprintf(f, "%s\n", line);
  }
  fclose(f);
  
}