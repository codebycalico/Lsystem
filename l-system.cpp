#include "FPToolkit.c"

char u[100000000];
char s[10];
char w[10][1000];
char temp[100000000];

void l_sys(int depth, int rules){
  if(depth == 0){
    return;
  }
  bool match = false;
  char nomatch[2];
  temp[0] = '\0';
  int stringsize = strlen(u);

  for(int i = 0; i < stringsize; i++){
    for(int j = 0; j < rules; j++){
      if(u[i] == s[j]){
        strcat(temp, w[j]);
        match = true;
        break;
      }else{
        match = false;
      }
    }
    if(match == false){
      // there was no rule for the character
      nomatch[0] = u[i];
      nomatch[1] = '\0';
      strcat(temp, nomatch);
    }
  }
  strcpy(u, temp);
  l_sys(depth-1, rules);
}

int main(){
  int numrules, depth;
  printf("Enter the original string: ");
  scanf("%s", u);
  printf("Enter number of rules: ");
  scanf("%d", &numrules);
  for(int i = 0; i < numrules; i++){
    printf("Rule #%d character: ", i);
    scanf("%s", &s[i]);
    printf("\nReplace character with: ");
    scanf("%s", &w[i][0]);
  }

  printf("Choose the depth: ");
  scanf("%d", &depth);
  
  l_sys(depth, numrules);

  printf("%s\n", u);

  G_save_image_to_file("lsys");
}